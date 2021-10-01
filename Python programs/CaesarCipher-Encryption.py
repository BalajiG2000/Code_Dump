#Python program to illustrate Caesar Cipher Technique

# ---------------------------------------------
#Input 
# A String of lower case letters, called Text.
# An Integer between 0-25 denoting the required shift.
# ---------------------------------------------
#Output

# Traverse the given text one character at a time .
# For each character, transform the given character as per the rule, depending on whether we’re encrypting or decrypting the text.
# Return the new string generated.
# ---------------------------------------------


def encrypt(text,s):
    result = ""
 
    # traverse text
    for i in range(len(text)):
        char = text[i]
 
        # Encrypt uppercase characters
        if (char.isupper()):
            result += chr((ord(char) + s-65) % 26 + 65)
 
        # Encrypt lowercase characters
        else:
            result += chr((ord(char) + s - 97) % 26 + 97)
 
    return result
 
#check the above function
text = input("Enter Input :" )
s = 4
print ("Text  : " + text)
print ("Shift : " + str(s))
print ("Cipher: " + encrypt(text,s))