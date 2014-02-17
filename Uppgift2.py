# Programmeringsteknik webbkurs KTH inlämningsuppgift 2.
# David Bengtsson
# 2014-01-27
# Läser in 4 meningar och skapar en 'rondelet' dikt


# VARIABLER
sentence = 4*[None] # Antal meningar

# FUNKTIONER
def printHeader():
    print("\tDiktautomaten".upper())
    print("Skriv in fyra meningar och få ut en rondelet!")
    print("")
def readSentences():
    
    sentence[0] = input("Skriv mening nr 1: ")
    sentence[1] = input("Skriv mening nr 2: ")
    sentence[2] = input("Skriv mening nr 3: ")
    sentence[3] = input("Skriv mening nr 4: ")
    return sentence
    

def writeWords(iWords, iFrom, iTo, iUpperCase):
    # Funktion för att skriva ut olika delar av en mening
    # Mata in en lista med ord och positionerna som den ska skriva ut
    # samt ange 1 i iUpperCase om de ska skrivas ut med versaler
    if iTo < 0:
        lastWord = len(iWords)
    elif (len(iWords) - 1) < iTo:
        lastWord = len(iWords)
    else:    
        lastWord = iTo
        
    i = iFrom
    pos = 0
    # För att skriva ut orden
    formatted_words = (lastWord - iFrom)*[None]
    while i < lastWord:
        formatted_words[pos] = iWords[i]
        i += 1
        pos += 1

    # Formatera
    formatted_string = " ".join(formatted_words)
    if iUpperCase == 1:
        formatted_string = formatted_string.upper()
    # Skriv ut
    print(formatted_string)

def writeFourWords():
    writeWords(sentences[0].split(), 0, 4, 0)

# MAIN
# Körschema
printHeader()
# Läs in meningar
sentences = readSentences()
print("") # För att få lite luft

# 1. Textens fyra första ord med stora bokstäver
writeWords(sentences[0].split(), 0, 4, 1)
# 2. En tom rad
writeWords(sentences[0].split(), 0, 0, 0)
# 3. Textens fyra första ord
writeFourWords()
# 4. Resten av första meningen
writeWords(sentences[0].split(), 4, -1, 0)
# 5. Textens fyra första ord igen
writeFourWords()
# 6. Andra meningen
writeWords(sentences[1].split(), 0, -1, 0)
# 7. Tredje meningen
writeWords(sentences[2].split(), 0, -1, 0)
# 8. Fjärde meningen
writeWords(sentences[3].split(), 0, -1, 0)
# 9. Textens fyra första ord en sista gång
writeFourWords()


