/**
 * @param {number[][]} conversions
 * @return {number[]}
 */
var baseUnitConversions = function(conversions) {
    const MOD = 1000000007n;
    const n = conversions.length + 1;

    const graph = Array.from({ length: n }, () => []);
    for (const [sourceUnit, targetUnit, conversionFactor] of conversions) {
        graph[sourceUnit].push([targetUnit, BigInt(conversionFactor)]);
    }

    const baseUnitConversion = new Array(n).fill(-1n);
    baseUnitConversion[0] = 1n;

    const queue = [0];

    while (queue.length > 0) {
        const currentUnit = queue.shift();
        const currentFactor = baseUnitConversion[currentUnit];

        for (const [neighborUnit, factor] of graph[currentUnit]) {
            const newFactor = (currentFactor * factor) % MOD;
            baseUnitConversion[neighborUnit] = newFactor;
            queue.push(neighborUnit);
        }
    }

    return baseUnitConversion.map(val => (val === -1n ? 0 : Number(val)));
};