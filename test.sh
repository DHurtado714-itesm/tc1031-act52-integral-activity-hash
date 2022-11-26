g++ -std=c++2a main.cpp -o app

for i in 1 2 3 4 
do
    ./app input$i.txt mysolution$i.txt
    diff mysolution$i.txt output$i.txt
done