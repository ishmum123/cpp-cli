#include "autoparser.h"
#include <rfl.hpp>
#include <rfl/json.hpp>
#include <string>
#include <vector>
#include <rfl/to_view.hpp>

struct Box{
  std::string a;
  std::string b;
  rfl::ExtraFields<rfl::Generic> extra_fields;
};
struct Person {
  std::string first_name;
  std::string last_name = "Simpson";
  std::string town = "Springfield";
  unsigned int age;
  std::vector<Person> children;
};

void foo_box() {
    auto box = Box{.a="A", .b="B"};
    box.extra_fields["c"] = 5;
    box.extra_fields["d"] = "D";

    const auto box_view = rfl::to_view(box);
    *std::get<0>(box_view.values()) = "A'";
    *box_view.get<1>() = "B'";

    box_view.apply([](const auto &f) {
        std::cout << f.name() << ": " << rfl::json::write(*f.value()) << std::endl;
    });

    std::cout << "\n";

//    for (const auto& f : rfl::fields<Person>()) {
//      std::cout << "name: " << f.name() << ", type: " << f.type() << std::endl;
//    }
}
void foo_person(){
    auto lisa = Person{.first_name = "Lisa", .last_name="Simpson", .age=8};
    const auto view = rfl::to_view(lisa);
    *std::get<0>(view.values()) = "Maggie";
    *view.get<1>() = "Simpson";
    *view.get<"age">() = 40;
    *rfl::get<0>(view) = "Maggie";
    *rfl::get<"first_name">(view)= "Maggie";

    view.apply([](const auto& f){
       std::cout<< f.name() <<": " <<rfl::json::write(*f.value())<<std::endl;
    });
    std::cout<<"\n";

    const auto maggie = rfl::replace(
            lisa, rfl::make_field<"first_name">(std::string("Lisa"))
            );
    const auto view_maggie = rfl::to_view(maggie);
    view_maggie.apply([](const auto& f){
        std::cout<< f.name() <<": " <<rfl::json::write(*f.value())<<std::endl;
    });

}

struct A {
    std::string f1;
    std::string f2;
};
struct B {
    std::string f3;
    std::string f4;
};
struct C {
    std::string f1;
    std::string f2;
    std::string f4;
};

void foo_reuse(){
const auto a = A{.f1 = "Hello", .f2 = "World"};
const auto b = B{.f3 = "Hello", .f4 = "World"};
// f1 and f2 are taken from a, f4 is taken from b, f3 is ignored.
const auto c = rfl::as<C>(a, b);
}

void foo_replace(){
    const auto a = A{.f1 = "Hello", .f2 = "World"};

    const auto c = C{.f1 = "C++", .f2 = "is", .f4 = "great"};

// The fields f1 and f2 are replaced with the fields f1 and f2 in a.
    const auto c2 = rfl::replace(c, a);
}

int main(){
    foo_replace();
//    foo_reuse();
//    foo_box();
//    foo_person();

}