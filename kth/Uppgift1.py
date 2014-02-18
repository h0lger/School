# Låter användaren mata in talet N och beräknar kvadraten på N

print("Välkommen till prat i kvadrat beta.")
input_user = input("Hur många kvadrattal vill du skriva ut idag? ")

#input_user borde valideras att det är ett heltal!
number = int(input_user)
i = 1
sqr = 0 #för att lagra kvadraten
sumsqr = 0 #för att lagra summan av kvadrattalen

if number < 1:
    print("Du måsta mata in ett heltal större än 0.")
else:    
    while i <= number:
        sqr = i * i
        sumsqr += sqr
        print(i, " * ", i, " = ", sqr)
        i += 1
    print("Summan av kvadrattalen: ", sumsqr)
    


