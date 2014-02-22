# P-uppgift "bulgarisk patiens" - KTH

hogar = [] #En lista med alla högar (klasser)

# En klass som ska representera en hög med kort
class Hog:
    def __init__(self, kort):
        self.antalKort = kort #Antal kort som högen innehåller
        
    def str(self):
        return self.antalKort

# Ska slumpa fram startfördelningen med högar och kort
def slumpaStartfordelning():
    #1. Slumpa fram antalet kort 2-52
    #2. Slumpa fram antalet högar 2-5
    #3. Fyll högarna med kort
    return 0

# Tar ett kort från varje hög och skapar en ny hög
def taKort():
    return 0

# Går igenom högarna för att kontrollera om vi har ett stabilt läge
# Stabilt läge uppnås när antalet högar och antalet kort är konstant
def kontrolleraStabiltLage():
    return 0

# Går igenom samtliga högar och tar bort högar med 0 kort
def taBortTommaHogar():
    return 0

# Srkiver ut samtliga högar, dvs antalet kort i alla högar (i storleksordning).
# T.ex. 4 3 2 1
def skrivUtHogar():
    return 0

#Huvudprogram
slumpaStartfordelning()
antalSteg = 0
while(antalSteg <= 25):
    kontrolleraStabiltLage()
    taKort()
    taBortTommaHogar()
    skrivUtHogar()
    antalSteg += 1
