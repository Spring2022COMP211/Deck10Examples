
extern int foo_global;
extern void report();
extern void doubleFoo();
extern void halveFoo();
extern int isFooZero();

int main() {
    report();

    doubleFoo();
    foo_global += 3;

    report();

    while (!isFooZero()) {
        halveFoo();
        report();
    }
}

