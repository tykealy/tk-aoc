const fs = require("fs");

const filename = "input.txt";
const instructions = parseInput(filename);
let memo = new Map();

function parseInput(filename) {
    const instructions = new Map();
    const lines = fs.readFileSync(filename, "utf-8").trim().split("\n");

    for (const line of lines) {
        const parts = line.split(" ");
        let dest, expr;

        if (parts[0] === "NOT") {
            // "NOT x -> y"
            dest = parts[3];
            expr = ["NOT", parts[1]];
        } else if (parts[1] === "->") {
            // "123 -> x" or "a -> b"
            dest = parts[2];
            expr = ["ASSIGN", parts[0]];
        } else {
            // "x AND y -> z"
            dest = parts[4];
            expr = [parts[1], parts[0], parts[2]];
        }

        instructions.set(dest, expr);
    }

    return instructions;
}

function get_value(token,){
    
    let value = /^\d+$/.test(token) ? parseInt(token, 10) : token;

    if(typeof(value) == 'number'){
        return value
    }
    
    if (memo.has(token)) {
        return memo.get(token);
    }

    let data = instructions.get(token)

    if (!data) {
        console.error(`No instruction found for token: ${token}`);
        return 0;
    }

    let val;
    
    if(data[0] == 'ASSIGN'){
        val = get_value(data[1])
    } else if (data[0] === 'NOT') {
        val = ~get_value(data[1]) & 0xFFFF
    }else{
        let op = data[0]
        let rightValue = get_value(data[2])
        let leftValue = get_value(data[1])
        if(op == "AND"){
            val = (leftValue & rightValue ) & 0xFFFF
        }else if(op == "OR"){
            val = (leftValue | rightValue ) & 0xFFFF
        }else if(op == "LSHIFT"){
            val = (leftValue << rightValue ) & 0xFFFF
        }else if(op == "RSHIFT"){
            val = (leftValue >> rightValue ) & 0xFFFF
        }
    }
    memo.set(token, val);
    return val
}
console.log(instructions.get('b'))
let b = get_value('a')
instructions.set('b', ['ASSIGN', b.toString()])
console.log(instructions.get('b'))
memo.clear()
console.log(get_value('a'))






