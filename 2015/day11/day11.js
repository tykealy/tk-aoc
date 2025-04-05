//inintizlize
let password = 'ksfjlkaa'
let passwordInHex = []
let prohibited = ['69', '6f', '6c']
for (let i = 0; i < password.length; i++) {
    passwordInHex.push(password[i].charCodeAt(0).toString(16))
}


//increment password by 1
function increment(i) {
    passwordInHex[i] = (parseInt(passwordInHex[i], 16) + 1).toString(16)

    if (parseInt(passwordInHex[i], 16) > parseInt('7a', 16)) {
        passwordInHex[i] = '61'
        if (i > 0) {
            increment(i - 1)
        }
    }
}

//check if the conditon are all match
const check = () => {
    let c1 = false
    let pairs = 0
    //condition 2
    if (prohibited.some(p => passwordInHex.includes(p))) {
        return false
    }

    for (let i = 0; i < passwordInHex.length; i++) {
        let last = (i > 0) ? parseInt(passwordInHex[i - 1], 16) : ''
        let first = parseInt(passwordInHex[i], 16)
        let second = parseInt(passwordInHex[i + 1], 16)
        let third = parseInt(passwordInHex[i + 2], 16)
        //condition 1
        if ((first + 1) == second && (first + 2) == third) {
            c1 = true
        }
        //condition 3
        if (first == second && first != last) {
            pairs++
        }
    }

    if (c1 && pairs >= 2) {
        return true
    }
    return false
}



function main() {
    let passed = false
    let lastIndex = passwordInHex.length - 1

    while (!passed) {
        increment(lastIndex)

        passed = check()
    }

    return passwordInHex.map(hex => String.fromCharCode(parseInt(hex, 16))).join('')
}

console.log(main());




