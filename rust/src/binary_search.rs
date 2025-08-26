#[derive(Debug)]
enum Ordering {
    Less,
    Greater,
    Equal,
}

fn compare_fn<T>(want: T) -> fn(T) -> Ordering {
    move |what: T| {
        if what < want {
            Ordering::Less
        } else if what > want {
            Ordering::Greater
        } else {
            Ordering::Equal
        }
    }
}

fn binary_search<T>(values: &[T], compare_fn: fn(T) -> Ordering) -> usize {
    let mut low = 0;
    let mut high = values.len();

    while (low < high) {
        let mid = low + (high - low) / 2;
        let value = values[mid];

        match compare_fn(value) {
            Ordering::Less => low = mid + 1,
            Ordering::Greater => high = mid,
            Ordering::Equal => return mid,
        }
    }
    low
}
