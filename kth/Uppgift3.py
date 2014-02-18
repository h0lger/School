# Simulerar ett nöjesfält med olika attraktioner

from random import *
import time

aLista = [] #För att lagra attraktionerna i

#En klass som ska representera en attraktion med dess attribut
class Attraktion:
    
    def __init__(self, namnet, minLangden, antaletP, pirrFaktor, reklamText):
        self.namn = namnet
        self.minLangd = minLangden #cm
        self.antal = antaletP
        self.reklam = reklamText
        self.pirr = pirrFaktor #0=inget 10=extremt
        self.skick = int(random() * 10) # 0=usel 10=bra
    
    #För lätt utskrift av klassen
    def __str__(self):
        output = self.namn;
        output += " '" + self.reklam + "'"
        output += " - Min längd:" + str(self.minLangd)
        output += " - Max antal personer:" + str(self.antal)        
        output += " - Pirrfaktor:" + str(self.pirr)       

        return output

#Denna klass hantera allt som har med simulering av en attraktion att göra
class Simulator:

    def __init__(self, attraktionen):
        self.attraktion = attraktionen

    def starta(self):
        #Skriv ut reklamen först
        self.skrivUtReklam(self.attraktion.reklam)
        print(self.attraktion.namn + " startar upp...\n")        
        i = 0
        while i < 20:            
            print('--|-', end='') #För att det ska synas att attraktionen är igång
            tal = int(random() * 10) #Används för att slumpa och simulera slitage           
            if(tal > 7):                
                self.attraktion.skick -= 1 #Skicket minskar
            if(self.attraktion.skick <= 0):                
                print('\nHAVERI! ni har blivit stående')
                break #Gå ur loopen
            i += 1
            time.sleep(0.1) #Så att det tar lite tid
        if(self.attraktion.skick <= 0):
            val = input('Personal påväg... Vill ni laga attraktionen? (J/N)') #Möjlighet att laga
            #Klara av att användaren matar in med stora och små bokstäver
            if(val == "J" or val == "j"):
                self.attraktion.skick = 10 #Lagad
                print(self.attraktion.namn + " har blivit lagad.")
        else:
            print('\nDen var väl kul!?')
    
    #För att skriva ut reklam på ett enhetligt sätt
    def skrivUtReklam(self, reklamtext):
        print('******************************')
        time.sleep(0.2)
        print(reklamtext)
        time.sleep(0.2)
        print('******************************\n')
        time.sleep(2)

#Skapar upp 3 attraktioner som ska användas senare
def initieraAttraktioner():
    #Vi skapar 3 attraktioner
    attr = Attraktion("Bergis", 100, 30, 7, "Dalbanan i bergen")
    aLista.append(attr)
    attr = Attraktion("Uppskjutet", 130, 10, 10, "The sky is the limit")
    aLista.append(attr)
    attr = Attraktion("Landet", 80, 20, 2, "Landet för länge sedan")
    aLista.append(attr)

#Loopar igenom alla skapade attraktioner och presenterar dem
def presenteraAttraktioner():
    i = 0
    while( i < len(aLista)):
        print(str(i + 1) + ". ")
        print(aLista[i])
        print("\n")
        i +=1

#Hanterar så att användaren kan åka flera attraktioner efter varandra
def hanterare():    
    val = 0
    #Tvingar användaren att mata in rätt (enkel validering)
    while(val < 1 or val > 4):
        val = int(input('Vilken attraktion vill du åka?'))
    
    if(val == 1):
        sim = Simulator(aLista[0])
        sim.starta()
    elif(val == 2):
        sim = Simulator(aLista[1])
        sim.starta()
    elif(val == 3):
        sim = Simulator(aLista[2])
        sim.starta()
    elif(val == 4):
        print("Välkommen åter!")
        
    return val
    
#Main
print("VÄLKOMMEN TILL DEN ULTIMATA VIRTUELLA NÖJSENPARKEN!!\n\n")
initieraAttraktioner()
presenteraAttraktioner()
print("4.\nFör att avsluta programmet")
val = 0
while(val != 4):
    val = hanterare()

    
