#include <iostream>
#include <list>
#include <stack>
#include <initializer_list>

using namespace std;

#define StatesPtr States*

template <int _states_count>
class NFA {
  class States {
  list<int>* data;
  public:
    States(): data(nullptr) {}
    States(const initializer_list<int>& states) { data = new list<int>(states); }
    ~States() { cout << "delete state" << endl; delete data; }
  };
  StatesPtr (*_transition_table) [128];
  StatesPtr* _e_transition_table;
public:
  NFA() {
    _transition_table = new StatesPtr[_states_count][128];
    _e_transition_table = new StatesPtr[_states_count];
  }
  ~NFA() {
    for (int s = 0; s < _states_count; s++) {
      for (int c = 0; c < 128; c++) {
        delete _transition_table[s][c];
      }
      if  (_e_transition_table[s]) {
        cout << "delete" << s << endl;
        delete _e_transition_table[s];
      } else {
        cout << "not delete" << s << endl;
      }
    }
    delete _e_transition_table;
    delete[] _transition_table;
  }
  void set_transition(const int& from_state, const initializer_list<int>& to_state, const char& chr) {
    _transition_table[from_state][chr] = new States(to_state);
  }
  void set_transition(const int& from_state, const initializer_list<int>& to_state) {
    _e_transition_table[from_state] = new States(to_state);
  }
  // list<int> e_closure(const list<int>& states) {
  //   stack<int> state_stack;
  //   list<int> e_closure_res;
  //   for (const int& state: states) {
  //     state_stack.push_back(state);
  //     e_closure_res.push_back(state);
  //   }
  //   while (!state_stack.empty()) {
  //     auto curr_state = state_stack.top();
  //     state_stack.pop();
  //     for (const s _e_transition_table[curr_state];
  //   }
  // }
  // list<int> e_closure(const int& state) {
  //   list<int> states{state};
  //   return e_closure(states);
  // }
};

int main() {
  NFA<11> nfa1{};
  nfa1.set_transition(0, {1, 7});
  nfa1.set_transition(1, {2, 4});
  nfa1.set_transition(2, {3}, 'a');
  nfa1.set_transition(3, {6});
  nfa1.set_transition(4, {5}, 'b');
  nfa1.set_transition(5, {6});
  nfa1.set_transition(6, {1, 7});
  nfa1.set_transition(7, {8}, 'a');
  nfa1.set_transition(8, {9}, 'b');
  nfa1.set_transition(9, {10}, 'b');
}
