#include <vector>

struct Foo
{
    int a = 0;
    uint64_t b = 0;
    uint64_t c = 0;
};

int main()
{
    std::vector<Foo> bar = { Foo{} };

    // The following line generates warning C26820
    auto const x = bar.back();

    bar.emplace_back(Foo{1,1,1});

    // If x is made a reference instead of a copy, the following line might use an
    // invalid reference because the container bar has been modified.
    printf("%d, %llu, %llu\n", x.a, x.b, x.c);

    return 0;
}
