
extern int foo_global;

void doubleFoo() {
    foo_global *= 2;
}

void halveFoo() {
    foo_global /= 2;
}

int isFooZero() {
    return (foo_global == 0);
}
