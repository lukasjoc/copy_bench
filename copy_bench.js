const { performance } = require('perf_hooks')

function seedArray(arrsize, numsize = 100) {
    let seeded = [];
    for(let i = 0; i < arrsize; i++) seeded.push(Math.abs(Math.round(Math.random()*numsize)))
    return seeded;
}

function runMeasurement(a) {
    const t1 = performance.now()
    const copy1 = a.map(_ => _)
    const t2 = performance.now()
    console.log(`\tmap:\t${(t2 - t1) * 1000}\tmicroseconds`, copy1.length)
    
    const t3 = performance.now()
    const copy2 = [...a]
    const t4 = performance.now()
    console.log(`\t...:\t${(t4 - t3) * 1000}\tmicroseconds`, copy2.length)
    
    const t5 = performance.now()
    const copy3 = [];
    for(const i of a) copy3.push(i)
    const t6 = performance.now()
    console.log(`\tfor-of:\t${(t6 - t5) * 1000}\tmicroseconds`, copy3.length)
    
    const t7 = performance.now()
    const copy4 = [];
    for(let i = 0; i<a.length; i++) copy4[i] = a[i];
    const t8 = performance.now()
    console.log(`\tfor:\t${(t8 - t7) * 1000}\tmicroseconds`, copy4.length)
    
    const t9 = performance.now()
    const copy5 = [];
    for(const i in a) copy5[i] = a[i];
    const t10 = performance.now()
    console.log(`\tfor-in:\t${(t10 - t9) * 1000}\tmicroseconds`, copy5.length)
}


function main() {
    const sizes = [10, 100, 1e3, 1e6, 1e7]
    for (let size of sizes) {
        console.log("Running Measure for size: ", size.toExponential())
        runMeasurement(seedArray(size))
    }
}

main()

