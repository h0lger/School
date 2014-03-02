# P-uppgift "bulgarisk patiens" - KTH

#Importera biblotek
from random import randint
import operator
from audioop import reverse

# En klass som ska representera en hög med kort
class Hog:
    def __init__(self, i_kort):
        self.antal_kort = i_kort #Antal kort som högen innehåller
        
    def __str__(self):
        return str(self.antal_kort)   
    


# Ska slumpa fram startfördelningen med högar och kort
def slumpa_startfordelning():
    tmp_hogar = [] #Lokal variabel för att skapa högar
    #1. Slumpa fram antalet kort 2-52
    antalKort = randint(2,52)
    #2. Slumpa fram antalet högar 2-5
    antalHogar = randint(2,5)
    #3. Fyll högarna med kort
    for i in range(0, antalHogar):
        #Kontroll måste göras då den sista iterationen kan korten vara slut
        if antalKort > 0:        
            antalKortIHog = randint(1, antalKort) #Antal kort vi ska stoppa i denna högen
            enHog = Hog(antalKortIHog) #Skapa en hög
            antalKort -= antalKortIHog #Ta bort korten som vi lagt i aktuell hög
            tmp_hogar.append(enHog)
        i += 1    
    
    return tmp_hogar

# Tar ett kort från varje hög och skapar en ny hög
def ta_kort(i_hogar):
    tmp_hogar = i_hogar #Den nya fördelningen efter vi tagit ett kort från varje hög
    tagna_kort = 0
    
    for hog in tmp_hogar:
        tagna_kort += 1 #Ta ett kort från varje hög
        hog.antal_kort -= 1 #Minska varje hög med ett kort      
        
    tmp_hogar.append(Hog(tagna_kort)) #Skapa en ny hög med de tagna korten
    
    #Ta bort eventuella tomma högar
    tmp_hogar = tabort_tomma_hogar(tmp_hogar)
        
    return tmp_hogar

# Går igenom högarna för att kontrollera om vi har ett stabilt läge
# Stabilt läge uppnås när antalet högar och antalet kort är konstant
def kontrollera_stabiltLage(i_hogar):
    stabilt_lage_funnit = 0
    tmp_hog = ta_kort(i_hogar)
    if jamfor_hogar(tmp_hog, i_hogar) == 1:
        #De är lika vilken innebär att det mycket väl kan vara ett stabilt läge
        # Vi testar ytterligare ett steg för att se om vi funnit ett stabilt läge
        tmp_hog2 = ta_kort(tmp_hog)
        if jamfor_hogar(tmp_hog, tmp_hog2) == 1:
            stabilt_lage_funnit = 1
    
    
    return stabilt_lage_funnit

# Jämför 2 st högar med kort. Returnerar 1 om de är lika annars 0.
def jamfor_hogar(i_hog_1, i_hog_2):
    lika = 0
    langd_hog_1 = len(i_hog_1)
    langd_hog_2 = len(i_hog_2)
    
    # Om de har samma antalet högar i sig, är de kandidater för att vara lika
    if langd_hog_1 == langd_hog_2:
        for i in range(langd_hog_1):
            # Om de har samma antal kort på samma positioner är de lika
            if i_hog_1[i].antal_kort == i_hog_2[i].antal_kort:
                lika = 1
            # Men så fort de inte har samma antal kort på samma position är de inte lika
            else:
                break
            i += 1
    
    return lika

# Går igenom samtliga högar och tar bort högar med 0 kort
def tabort_tomma_hogar(i_hogar):
    tmp_hogar = i_hogar #Lista där vi tar bort de tomma högarna
    
    for hog in tmp_hogar:
        # Om högen inte har några kort så tar vi bort den
        if hog.antal_kort < 1:
            tmp_hogar.remove(hog)
    
    return tmp_hogar

# Srkiver ut samtliga högar i en lista, dvs antalet kort i alla högar (i storleksordning).
# T.ex. 4 3 2 1
def skriv_ut_hogar(i_hogar):
    #Sortera högarna i fallande ordning
    sorterade_hogar = sorted(i_hogar, key=operator.attrgetter('antal_kort'), reverse=True)
    #Skriv ut alla högar i listan
    for hog in sorterade_hogar:
        print(hog, end=' ')
    
    print("\n")

#Huvudprogram
hogar = [] #En lista med alla högar (klasser)
hogar =  slumpa_startfordelning()

#TEST
skriv_ut_hogar(hogar)
hogar = ta_kort(hogar)
skriv_ut_hogar(hogar)
print(str(kontrollera_stabiltLage(hogar)))

antalSteg = 0

# while(antalSteg <= 25):
#     kontrollera_stabiltLage()
#     ta_kort()
#     tabort_tomma_hogar()
#     skriv_ut_hogar(hogar)
#     antalSteg += 1
