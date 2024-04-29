keypad = {
    "2": "abc",
    "3": "def",
    "4": "ghi",
    "5": "jkl",
    "6": "mno",
    "7": "pqrs",
    "8": "tuv",
    "9": "wxyz"
}

def get_possible_words(number, words):
    dp = {0: {""}}
    for i in range(len(number)):
        dp[i+1] = set()
        for j in range(i+1):
            if number[j:i+1] in keypad.keys():
                for possible_word in words:
                    if all(ch in keypad[number[k]] for k, ch in enumerate(possible_word[:i-j+1])):
                        dp[i+1].add(possible_word)
        if not dp[i+1]:
            return set()
    return dp[len(number)]

number = "3662277"
words = ["foo","bar","baz","foobar","emo","cap","car","cat"]
result = get_possible_words(number, words)
print(result)