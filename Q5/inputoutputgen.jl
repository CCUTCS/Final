
srand(5)

for cnt in 2:5

    inputio = open("input$cnt", "w")
    outputio = open("output$cnt", "w")

    dinclist = rand('a':'z', 50, rand(2:9))

    for i in 1 : 50
        x = dinclist[i, :]
        for letter in x
            print(inputio, letter)
        end
        println(inputio)
    end
    dinclist = sortrows(dinclist)
    println("Sorted!")
    for i in 1 : 50
        x = dinclist[i, :]
        for letter in x
            print(outputio, letter)
        end
        println(outputio)
    end

    close(inputio)
    close(outputio)

end