# Engg1340-35-
HKU ENGG1340 Project TOPIC:3
Problem statement

Setting: 
1. This market owner is in debt of $100000 at first
2. Every Trolly can at most store 10 products
3. The highest price and lowest price of different types of grocery are stated in the grocery_file.txt
4. Whatever gorcery type it is, the only factor of affecting the process time/waiting time is its price ONLY
5. Price and time needed are directly proportional
6. Customer number must be an non-negative integer
7. Cashier line can be adjusted to different number, but it must be > 1
8. More cashier lines will increase daily expenses
9. It is totally an RNG event, the days needed for you to make the net profit > 0 may differ in differnt trials
10. If number of cashier lines is larger than it actually needs, cashier line with no customer will appear and you still need to pay for the cashier expenses
11. Only the top n (n = number of cashier lines) highest total grocery price customers' moeny will be counted as income, the rest will be used for buying the grocery and workers' income
12. Every cashier line should have less than 900s waiting time (It's cumulative, the first customer of the cashier line has the whole cashier line total waiting time)
13. Customer number MUST >= cashier number

Goal:
Try to use as little time as possible to pay back all the debt and start making money





WARNING: We suggest you to not use our default input as it is a random event code, with the same input there is a very high chance of different output

How To Run:
Command: 
make mainfunction
./mainfunction
