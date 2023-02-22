use std::time::Instant;

fn seed_array(arr_size: usize, num_size: u32) -> Vec<u32> {
    let mut seeded = vec![];
    for _ in 0..arr_size {
        seeded.push((rand::random::<u32>() % num_size) + 1);
    }
    seeded
}

fn run_measurement(a: &[u32]) {
    let t1 = Instant::now();
    let copy1 = a.to_vec();
    let t2 = Instant::now();
    println!("\tto_vec:\t{:?}\tmilliseconds {}", t2.duration_since(t1).as_micros(), copy1.len());

    let t3 = Instant::now();
    let copy2 = a.to_owned();
    let t4 = Instant::now();
    println!("\tto_owned:\t{:?}\tmilliseconds {}", t4.duration_since(t3).as_micros(), copy2.len());

    let t5 = Instant::now();
    let mut copy3 = Vec::new();
    for i in a {
        copy3.push(*i);
    }
    let t6 = Instant::now();
    println!("\tfor_loop:\t{:?}\tmilliseconds {}", t6.duration_since(t5).as_micros(), copy3.len());

    let t7 = Instant::now();
    let copy4 = a.iter().copied().collect::<Vec<u32>>();
    let t8 = Instant::now();
    println!("\titer_copied:\t{:?}\tmilliseconds {}", t8.duration_since(t7).as_micros(), copy4.len());
}

fn main() {
    let sizes = [10, 100, 1000, 1_000_000, 10_000_000];
    for size in &sizes {
        println!("Running Measure for size: {}", size);
        let arr = seed_array(*size as usize, 100);
        run_measurement(&arr);
    }
}

