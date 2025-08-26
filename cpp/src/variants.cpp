#include <iostream>
#include <string>
#include <variant>

template <class... Ts>
struct overloaded : Ts... {
  using Ts::operator()...;
};
template <class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;

template <typename Variant, typename... Matchers>
decltype(auto) match(Variant&& v, Matchers&&... ms) {
  return std::visit(overloaded{std::forward<Matchers>(ms)...},
                    std::forward<Variant>(v));
}

int main(int argc, char* argv[]) {
  std::variant<int, std::string> foo;

  foo = 42;
  const int test = 44;

  const std::string result = match(
      foo,
      [&](const int number) { return "int: " + std::to_string(number + test); },
      [&](const std::string str) { return "string: " + str; });

  std::cout << result << std::endl;

  return 0;
}
