# Programmeringsteknik webbkurs KTH inlämningsuppgift 3.
# David Bengtsson
# 2014-02-15
# Simulerar ett nöjesfält med olika attraktioner

from random import *
import time

aLista = [] #För att lagra attraktionerna i

class Attraktion:
    
    def __init__(self, namnet, minLangden, antaletP, pirrFaktor, reklamText):
        self.namn = namnet
        self.minLangd = minLangden #cm
        self.antal = antaletP
        self.reklam = reklamText
        self.pirr = pirrFaktor #0=inget 10=extremt
        self.skick = int(random() * 10) # 0=usel 10=bra

    def __str__(self):
        output = self.namn;
        output += " '" + self.reklam + "'"
        output += " - Min längd:" + str(self.minLangd)
        output += " - Max antal personer:" + str(self.antal)        
        output += " - Pirrfaktor:" + str(self.pirr)       

        return output

class Simulator:

    def __init__(self, attraktionen):
        self.attraktion = attraktionen

    def starta(self):
        #Skriv ut
        self.skrivUtReklam(self.attraktion.reklam)
        print(self.attraktion.namn + " startar upp...\n")        
        i = 0
        while i < 20:            
            print('--|-', end='')
            tal = int(random() * 10)            
            if(tal > 7):                
                self.attraktion.skick -= 1
            if(self.attraktion.skick == 0):                
                print('\nHAVERI! ni har blivit stående')
                break
            i += 1
            time.sleep(0.1) #Så att det tar lite tid
        if(self.attraktion.skick == 0):
            print('Personal påväg')
        else:
            print('\nDen var väl kul!?')

    def skrivUtReklam(self, reklamtext):
        print('******************************')
        time.sleep(0.2)
        print(reklamtext)
        time.sleep(0.2)
        print('******************************\n')
        time.sleep(2)

def initieraAttraktioner():
    #Vi skapar 3 attraktioner
    attr = Attraktion("Bergis", 100, 30, 7, "Dalbanan i bergen")
    aLista.append(attr)
    attr = Attraktion("Uppskjutet", 130, 10, 10, "The sky is the limit")
    aLista.append(attr)
    attr = Attraktion("Landet", 80, 20, 2, "Landet för länge sedan")
    aLista.append(attr)
def presenteraAttraktioner():
    i = 0
    while( i < len(aLista)):
        print(str(i + 1) + ". ")
        print(aLista[i])
        print("\n")
        i +=1
    
#Main
print("VÄLKOMMEN TILL DEN ULTIMATA VIRTUELLA NÖJSENPARKEN!!\n\n")
initieraAttraktioner()
presenteraAttraktioner()
val = 0
#Tvingar användaren att mata in rätt (enkel validering)
while(val < 1 or val > 3):
    val = int(input('Vilken attraktion vill du åka idag?'))

if(val == 1):
    sim = Simulator(aLista[0])
    sim.starta()
elif(val == 2):
    sim = Simulator(aLista[1])
    sim.starta()
elif(val == 3):
    sim = Simulator(aLista[2])
    sim.starta()




