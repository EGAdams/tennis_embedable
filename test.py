
import openai

openai.api_key = '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'


def chat_with_openai():
    conversation = [
        {"role": "system", "content": "You are a world-class experienced auto mechanic."},
        {"role": "user", "content": "My car is making a strange noise when I brake.  Can you help?"},
    ]

    response = openai.ChatCompletion.create(
        model="gpt-3.5-turbo",
        messages=conversation
    )

    # Print the assistant's reply
    print( "printing response... " )
    print(response['choices'][0]['message']['content'])


if __name__ == '__main__':
    
    # Call the function
    print( "calling function... " )
    chat_with_openai()
    print ( "done" )
