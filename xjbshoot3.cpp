template<typename Tuple, std::size_t N>
struct tuple_printer
{
    static void print(const Tuple& t)
    {
        tuple_printer<Tuple, N - 1>::print(t);
        std::cout << ", " << std::get<N - 1>(t);
    }
};

template<typename Tuple>
struct tuple_printer<Tuple, 1>
{
    static void print(const Tuple& t)
    {
        std::cout << std::get<0>(t);
    }
};

template<typename... Args>
void print_tuple(const std::tuple<Args...>& t)
{
    tuple_printer<decltype(t), sizeof...(Args)>::print(t);
    std::cout << std::endl;
}

// 这是不明角力的代码，回头自己能力上去了，再回来拜读吧
// https://www.cnblogs.com/highway-9/p/5955692.html
