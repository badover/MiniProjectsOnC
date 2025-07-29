#include <stdio.h>

int persistence(long num) {
    int steps = 0;  
    

    while (num > 9) {
        long product = 1;  
        
        
        while (num > 0) {
            product *= num % 10; 
            num /= 10;           
        }
        
        num = product;  
        steps++;       
    }
    
    return steps;
}


int main() {
    printf("Persistence of 39: %d\n", persistence(39));    
    printf("Persistence of 999: %d\n", persistence(999));  
    printf("Persistence of 4: %d\n", persistence(4));      
    return 0;
}