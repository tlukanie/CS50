# TODO
from cs50 import get_string


def count_letters(text):
    letters = 0
    for element in text:
        if ((element >= 'a' and element <= 'z') or (element >= 'A' and element <= 'Z')):
            letters += 1
    return (letters)


def count_words(text):
    words = 1
    for word in text:
        if (word == ' '):
            words += 1
    return (words)


def count_sentences(text):
    sentences = 0
    for el in text:
        if (el == '!' or el == '.' or el == '?'):
            sentences += 1
    return (sentences)


def get_grade(letters, words, sentences):
    grade = 0
    l = 0
    l = letters / words * 100
    s = sentences / words * 100
    grade = round(0.0588 * l - 0.296 * s - 15.8)
    return int(grade)


text = get_string("Text: ")
letters = count_letters(text)
words = count_words(text)
sentences = count_sentences(text)
grade = get_grade(letters, words, sentences)
if (grade < 1):
    print("Before Grade 1")
elif (grade >= 16):
    print("Grade 16+")
else:
    print(f"Grade {grade}")