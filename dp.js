// let coins = [1, 4, 5, 8];
// target = 87
// dict = {0:1}

// const nWays = (coins, target) => {
//     if (dict[target] != undefined) return dict[target]
//     sum = 0
//     for (let coin of coins) {
//         let subProblem = target - coin
//         if (subProblem < 0) {
//             continue
//         }
//         if (subProblem == 0) {
//             sum++
//         }
//         if (subProblem > 0) {
//             sum += nWays(coins, subProblem)
//         }
//     }
//     dict[target] = sum
//     return sum
// }

// console.log(nWays(coins, target
// ));


// const bu = (coins, target) => {
//     for (let i = 1; i <= target; i++) {
//         let sum = 0;
//         for (let  coin of coins) {
//             let sub = i - coin
//             if(sub< 0){
//                 continue
//             }
//             sum+= dict[sub]
//         }
//         dict[i] = sum
//     }
// }

// bu(coins, target)
// console.log(dict[target]);


x=75
y=19
let waysDict = {}

for (let i = 0; i <= x; i++) {
    waysDict[i] = {}  // Create nested object for each row
    for (let j = 0; j <= y; j++) {
        waysDict[i][j] = BigInt(0)  // Initialize each position with 0
    }
}

function ways(x,y){
    for(let i = 1; i <= x; i++){

        waysDict[i][1] = BigInt(1)
    }

    for(let i = 1; i <= y; i++){
        waysDict[1][i] = BigInt(1)
    }

    for(let i = 2; i<= x; i++){
        for (let j = 2; j<= y; j++){    
            waysDict[i][j] = waysDict[i][j-1] + waysDict[i-1][j]
        }
    }
}

ways(x,y)

console.log(waysDict[x][y].toString());
