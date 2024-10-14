/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maxKelements = function (nums, k) {
    const pq = new MaxPriorityQueue({ compare: (a, b) => b - a })
    for (const e of nums) {
        pq.enqueue(e)
    }

    let s = 0
    while (k--) {
        const e = pq.dequeue()
        s += e
        pq.enqueue(Math.ceil(e / 3))
    }
    return s
};