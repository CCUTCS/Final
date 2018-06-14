
import Primes: isprime

srand(2)

for cnt in 1:5
    inputio = open("input$cnt", "w")
    outputio = open("output$cnt", "w")
    nums = rand(0: 1005, 6)
    println(nums)
    for x in nums
        println(inputio, x)
        if isprime(x)
            println(outputio, x)
        end
    end
    close(inputio)
    close(outputio)
end