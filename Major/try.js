// ============================================================================
//                    EXACT SCRAP DATA
// ============================================================================

const SCRAP_MATERIALS = {
    'AA6061-I': { Si: 0.701, Fe: 0.843, Cu: 0.004, Mn: 0.888, Mg: 0.954, Cr: 0.0009, Zn: 0.069, Ti: 0.055, Al: 96.29 },
    'AARSNNE': { Si: 0.373, Fe: 0.205, Cu: 0.004, Mn: 0.004, Mg: 0.344, Cr: 0.0, Zn: 0.077, Ti: 0.018, Al: 98.93 },
    'AARSNNE-R': { Si: 0.339, Fe: 0.174, Cu: 0.004, Mn: 0.006, Mg: 0.394, Cr: 0.0, Zn: 0.074, Ti: 0.013, Al: 98.96 },
    'AAPSNNE': { Si: 0.611, Fe: 0.164, Cu: 0.004, Mn: 0.13, Mg: 0.811, Cr: 0.0002, Zn: 0.009, Ti: 0.023, Al: 98.16 },
    'AAPSNNE-R': { Si: 0.783, Fe: 0.136, Cu: 0.004, Mn: 0.046, Mg: 0.771, Cr: 0.0, Zn: 0.011, Ti: 0.019, Al: 98.45 },
    'AARSSPL': { Si: 4.447, Fe: 0.075, Cu: 0.004, Mn: 0.004, Mg: 0.317, Cr: 0.0, Zn: 0.005, Ti: 0.1, Al: 91.62 },
    'AARSSPL-R': { Si: 7.576, Fe: 0.08, Cu: 0.004, Mn: 0.004, Mg: 0.32, Cr: 0.0001, Zn: 0.004, Ti: 0.098, Al: 91.78 },
    'AA6061-IR': { Si: 0.665, Fe: 0.832, Cu: 0.004, Mn: 0.862, Mg: 0.962, Cr: 0.0008, Zn: 0.064, Ti: 0.043, Al: 96.39 },
    'AACAN-R': { Si: 0.152, Fe: 0.417, Cu: 0.004, Mn: 0.823, Mg: 0.979, Cr: 0.0009, Zn: 0.054, Ti: 0.025, Al: 97.47 }
};

const TARGET_6061 = {
    Si: [0.4, 0.8],
    Fe: [0.0, 1.0],
    Cu: [0.0, 0.40],
    Mn: [0.0, 1.0],
    Mg: [0.8, 1.2],
    Cr: [0.0, 0.35],
    Zn: [0.0, 0.25],
    Ti: [0.0, 0.15]
};

const ELEMENTS = ['Si', 'Fe', 'Cu', 'Mn', 'Mg', 'Cr', 'Zn', 'Ti'];

// ============================================================================
//                    CORE FUNCTIONS
// ============================================================================

function calculateMixedComposition(ingotFraction, otherFractions) {
    let composition = {};
    ELEMENTS.forEach(e => composition[e] = 0);

    ELEMENTS.forEach(elem => {
        composition[elem] += SCRAP_MATERIALS['AA6061-I'][elem] * ingotFraction;
    });

    for (let mat in otherFractions) {
        ELEMENTS.forEach(elem => {
            composition[elem] += SCRAP_MATERIALS[mat][elem] * otherFractions[mat];
        });
    }

    return composition;
}

function calculateCompositionScore(composition) {
    let score = 0;

    ELEMENTS.forEach(elem => {
        let [min, max] = TARGET_6061[elem];
        let center = (min + max) / 2;
        let range = max - min || 0.1;
        let val = composition[elem];

        if (val < min) score += Math.pow(((min - val) / range * 100), 2);
        else if (val > max) score += Math.pow(((val - max) / range * 100), 2);
        else score += Math.pow(((val - center) / range * 10), 2);
    });

    return score;
}

function checkCompliance(composition) {
    let violations = [];
    let ok = true;

    for (let elem in TARGET_6061) {
        let [min, max] = TARGET_6061[elem];
        let val = composition[elem];

        if (val < min) {
            violations.push([elem, val, min, max, "LOW"]);
            ok = false;
        } else if (val > max) {
            violations.push([elem, val, min, max, "HIGH"]);
            ok = false;
        }
    }

    return { ok, violations };
}

// ============================================================================
//                    OPTIMIZATION
// ============================================================================

function optimize(ingotFraction, quantities, targetWeight = 100) {
    let remainingFraction = 1 - ingotFraction;
    let solutions = [];

    let scraps = Object.keys(SCRAP_MATERIALS).filter(s => s !== 'AA6061-I' && quantities[s] > 0);

    // SINGLE
    scraps.forEach(scrap => {
        let frac = remainingFraction;
        let other = { [scrap]: frac };

        let comp = calculateMixedComposition(ingotFraction, other);
        let { ok, violations } = checkCompliance(comp);

        let feasible = (frac * targetWeight <= quantities[scrap]);

        solutions.push({
            other,
            comp,
            ok,
            violations,
            score: calculateCompositionScore(comp),
            feasible
        });
    });

    // DOUBLE
    for (let i = 0; i < scraps.length; i++) {
        for (let j = i + 1; j < scraps.length; j++) {
            for (let s = 0.1; s < 1.0; s += 0.1) {

                let f1 = remainingFraction * s;
                let f2 = remainingFraction * (1 - s);

                let other = {
                    [scraps[i]]: f1,
                    [scraps[j]]: f2
                };

                let comp = calculateMixedComposition(ingotFraction, other);
                let { ok, violations } = checkCompliance(comp);

                let feasible =
                    (f1 * targetWeight <= quantities[scraps[i]]) &&
                    (f2 * targetWeight <= quantities[scraps[j]]);

                solutions.push({
                    other,
                    comp,
                    ok,
                    violations,
                    score: calculateCompositionScore(comp),
                    feasible
                });
            }
        }
    }

    // SORT
    return solutions.sort((a, b) => {
        if (a.ok && a.feasible && !(b.ok && b.feasible)) return -1;
        if (!(a.ok && a.feasible) && (b.ok && b.feasible)) return 1;
        return a.score - b.score;
    });
}

// ============================================================================
//                    MAIN ENTRY FUNCTION (USE THIS IN HTML)
// ============================================================================

function runOptimizer(ingotPercent, quantities) {

    let ingotFraction = ingotPercent / 100;
    let results = optimize(ingotFraction, quantities);

    let best = results[0];

    return {
        bestMix: best.other,
        composition: best.comp,
        compliant: best.ok,
        violations: best.violations,
        feasible: best.feasible
    };
}