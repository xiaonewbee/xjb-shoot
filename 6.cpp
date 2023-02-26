#include <iostream>

template<typename... Values> class tuple;
template<> class tuple<> {};

template<typename Head, typename... Tail>
class tuple<Head, Tail...>
  : private tuple<Tail...>
{
  typedef tuple<Tail...> inherited;
  public:
    tuple() {}
    tuple(Head v, Tail... vtail) : m_head(v), inherited(vtail...) {}
    Head& head() {return m_head;}
    inherited& tail() {return *this;}
  protected:
    Head m_head;
};

int main(int argc, char *argv[]) {
	tuple<int, float, std::string> t(1, 2.3, "hello");
	std::cout << t.head() << " " << t.tail().head() << " " << t.tail().tail().head() << std::endl;

	return 0;
}




template<typename... Values> class tup;
template<> class tup<> {};

template<typename Head, typename... Tail>
class tup<Head, Tail...>
{
  typedef tup<Tail...> composited;
  public:
    tup() {}
    tup(Head v, Tail... vtail) : m_head(v), m_tail(vtail...) {}
    Head& head() {return m_head;}
    composited& tail() {return m_tail;}
  protected:
    Head m_head;
    composited m_tail;
};

