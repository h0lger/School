# P-uppgift "bulgarisk patiens" - KTH
# David Bengtsson 

#Importera biblotek
from random import randint
import operator
from audioop import reverse
from copy import deepcopy

#Globala variabler
MAX_STEG = 25

# En klass som ska representera en hög med kort
class Hog:
    def __init__(self, i_kort):
        self.antal_kort = i_kort #Antal kort som högen innehåller
        
    def __str__(self):
        return str(self.antal_kort)   
    


# Ska slumpa fram startfördelningen med högar och kort
def slumpa_startfordelning(antalKort):
    tmp_hogar = [] #Lokal variabel för att skapa högar    
    #1. Slumpa fram antalet högar 2-5
    antalHogar = randint(2,5)
    #2. Fyll högarna med kort
    for i in range(0, antalHogar):
        i += 1
        #Kontroll måste göras då den sista iterationen kan korten vara slut
        if antalKort > 0:
            #Om vi är på sista högen
            if i == antalHogar:
                enHog = Hog(antalKort) #Skapa en hög med de sista korten
            else:
                antalKortIHog = randint(1, antalKort) #Antal kort vi ska stoppa i denna högen            
                enHog = Hog(antalKortIHog) #Skapa en hög
                antalKort -= antalKortIHog #Ta bort korten som vi lagt i aktuell hög
            tmp_hogar.append(enHog)            
    
    return tmp_hogar

# Tar ett kort från varje hög och skapar en ny hög
def ta_kort(i_hogar):
    #Skapa en kopia först för att inte manipulera ursprunget
    #Kopian ska innehålla den nya fördelningen efter vi tagit ett kort från varje hög
    tmp_hogar = deepcopy(i_hogar) 
    tagna_kort = 0
    
    for hog in tmp_hogar:
        if hog.antal_kort > 0:
            tagna_kort += 1 #Ta ett kort från varje hög
            hog.antal_kort -= 1 #Minska varje hög med ett kort      
    
    if tagna_kort > 0:
        tmp_hogar.append(Hog(tagna_kort)) #Skapa en ny hög med de tagna korten
    
    #Ta bort eventuella tomma högar
    tmp_hogar_utan_tomma = tabort_tomma_hogar(tmp_hogar)
    
    #Sortera högarna i fallande ordning
    sorterade_hogar = sorted(tmp_hogar_utan_tomma, key=operator.attrgetter('antal_kort'), reverse=True)
        
    return sorterade_hogar

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
    #Först skapar vi upp en kopia av listan, då vi inte vill manipulera ursprungslistan
    tmp_hogar = deepcopy(i_hogar)   
    
    for hog in tmp_hogar[:]:
        # Om högen inte har några kort så tar vi bort den
        if hog.antal_kort < 1:
            tmp_hogar.remove(hog)
    
    return tmp_hogar

# Srkiver ut samtliga högar i en lista, dvs antalet kort i alla högar (i storleksordning).
# T.ex. 4 3 2 1
def skriv_ut_hogar(i_hogar):    
    #Skriv ut alla högar i listan
    for hog in i_hogar:
        print(hog, end=' ')
    
    print("\n")
    
def skriv_ut_programinfo():
    print("*************************************************")
    print("* Välkommen till bulgarisk patiens              *")
    print("* Du kommer att få välja antalet kort att spela *")
    print("* med, därefter kommer spelet slumpa ut dina    *")
    print("* kort i 2-5 olika högar.                       *")
    print("*************************************************")
    print("")

#Huvudprogram

skriv_ut_programinfo()

hogar = [] #En lista med alla högar (klasser)
antalKort = 0
#Låter användaren välja hur många kort denne vill spela med
while((antalKort < 2) or (antalKort > 52)):
    antalKort = int(input("Hur många kort vill du spela med?"))
    if((antalKort < 2) or (antalKort > 52)):
        print("Du måste spela med 2-52 kort")


hogar =  slumpa_startfordelning(int(antalKort))

skriv_ut_hogar(hogar)
antal_steg = 0

while(antal_steg < MAX_STEG):    
    
    if kontrollera_stabiltLage(hogar) == 1:
        print("Patiensen har gått ut efter {0} steg".format(str(antal_steg)))        
        break    
    
    hogar = ta_kort(hogar)    
    skriv_ut_hogar(hogar)
    antal_steg += 1
    if antal_steg == MAX_STEG:
        print("Maximalt antal steg uppnått, bättre lycka nästa gång")
    
