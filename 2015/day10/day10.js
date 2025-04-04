
let value = '1113222113'
let newValue = ''
let lastNumber = ''

for(i=1; i<= 40; i++){
    count=0
    for(j=0; j < value.length; j++){
        if(j == 0){
            count = 1
            lastNumber = value[j]
            continue
        }
        if(value[j] == value[j-1]){
            count++
            continue
        }
        if(value[j] != value[j-1]){
            newValue = newValue + count.toString() + lastNumber
            count = 1
            lastNumber = value[j]
        }
    }
    newValue = newValue + count.toString() + lastNumber
    value = newValue
    newValue = ''
}

console.log(value.length);






