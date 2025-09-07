# ai_tool.py
import openai

# Set your OpenAI API key
openai.api_key = "YOUR_API_KEY_HERE"

def chat_with_ai(prompt):
    """
    Send a prompt to OpenAI's GPT model and return the response.
    """
    response = openai.ChatCompletion.create(
        model="gpt-5-mini",  # GPT-5-mini
        messages=[
            {"role": "system", "content": "You are a helpful assistant."},
            {"role": "user", "content": prompt}
        ],
        max_tokens=150
    )
    return response['choices'][0]['message']['content']

def main():
    print("🤖 Welcome to your AI tool! Type 'exit' to quit.")
    while True:
        user_input = input("You: ")
        if user_input.lower() == "exit":
            print("Goodbye! 👋")
            break
        answer = chat_with_ai(user_input)
        print(f"AI: {answer}")

if __name__ == "__main__":
    main()
