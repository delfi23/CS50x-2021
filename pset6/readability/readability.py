from cs50 import get_string

def main():
    
    text = get_string("TEXT: ")
    
    letters = countLetters(text)
    words = countWords(text)
    sentences = countSentences(text)
    
    L = float (letters / words * 100)
    S = float (sentences / words * 100)
    
    grade = round(0.0588 * L - 0.296 * S - 15.8)
    
    if grade >= 16:
        print("Grade 16+")
    elif grade < 1:
        print("Before Grade 1")
    else:
        print("Grade: ", grade)

def countLetters(text):
    totLetters = 0
    for i in range(len(text)):
        if text[i].isalpha():
            totLetters += 1
    return totLetters

def countWords(text):
    totWords = 1
    for i in range(len(text)):
        if text[i] == ' ':
            totWords += 1
    return totWords

def countSentences(text):
    totSentences = 0
    for i in range(len(text)):
        if text[i] == '.' or text[i] == '?' or text[i] == '!':
            totSentences += 1
    return totSentences
    
main()