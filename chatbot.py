import random

# Dictionary containing predefined responses
responses = {
    "hi": ["Hello!", "Hi there!", "Hey!"],
    "how are you": ["I'm fine, thank you!", "Doing well, thanks!", "I'm good, how about you?"],
    "bye": ["Goodbye!", "See you later!", "Bye bye!"],
    "default": ["I'm sorry, I didn't understand that.", "Could you please rephrase that?", "I'm not sure what you mean."]
}

def chatbot():
    print("Chatbot: Hello! How can I assist you today?")
    while True:
        user_input = input("You: ").lower()
        if user_input == "quit":
            print("Chatbot: Goodbye!")
            break
        response = responses.get(user_input, responses["default"])
        print("Chatbot:", random.choice(response))

if __name__ == "__main__":
    chatbot()
