const fs = require("fs");
const { inflate } = require("zlib");
const filename = "input.txt";
const cost = {}
const cities = []
const points = [];

const getCities = () => {
    const lines = fs.readFileSync(filename, "utf-8").trim().split("\n");

    for (const line of lines) {
        const [a, _, b, __, distance] = line.split(' ');

        // Initialize if not exists
        if (!cost[a]) cost[a] = {};
        if (!cost[b]) cost[b] = {};

        if (!points.includes(a)) points.push(a);
        if (!points.includes(b)) points.push(b);

        // Add both directions
        cost[a][b] = Number(distance);
        cost[b][a] = Number(distance);
    }

    for (let c in cost) {
        cities.push(c)
    }
}

getCities()

function shortest(city, cities) {
    if (cities.length == 0) {
        return 0
    }
    let allSum = []
    for (let i = 0; i < cities.length; i++) {
        let new_city = cities[i]
        let remainingCities = [...cities]
        remainingCities.splice(i, 1)

        let sum = cost[city][new_city] + shortest(new_city, remainingCities)
        allSum.push(sum)
    }
    return Math.min(...allSum)
}

function longest(city, cities) {
    if (cities.length == 0) {
        return 0
    }
    let allSum = []
    for (let i = 0; i < cities.length; i++) {
        let new_city = cities[i]
        let remainingCities = [...cities]
        remainingCities.splice(i, 1)

        let sum = cost[city][new_city] + longest(new_city, remainingCities)
        allSum.push(sum)
    }
    return Math.max(...allSum)
}


function findShortestPath() {
    let minDistance = Infinity;

    // Try each city as the starting point
    for (let startCity of cities) {
        // Create array of remaining cities (excluding start city)
        let remainingCities = cities.filter(city => city !== startCity);
        // Find shortest path starting from this city
        let distance = shortest(startCity, remainingCities);
        minDistance = Math.min(minDistance, distance);
    }

    return minDistance;
}


function findLongest() {
    let minDistance = 0;

    // Try each city as the starting point
    for (let startCity of cities) {
        // Create array of remaining cities (excluding start city)
        let remainingCities = cities.filter(city => city !== startCity);
        // Find shortest path starting from this city
        let distance = longest(startCity, remainingCities);
        minDistance = Math.max(minDistance, distance);
    }

    return minDistance;
}

console.log(findShortestPath());
console.log(findLongest());


// let testingCity = cities[2]
// let testCities = [...cities]
// testCities.splice(2,1)

// console.log("cities:", cities);

// console.log(shortest(testingCity,testCities));

// let latestSumCollection = []
// let latestSum = 0
// for(let i =0; i<=cities.length; i++) {
//     latestSum+= shortest(i, )
// }


//[1,2,3,4]

//shortest([2,3,4], 1)
// shortest([3,4], 2)
// shortest([4], 3)









