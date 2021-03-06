#ifndef RPE_HPP
#define RPE_HPP

#include "base_input_manager.hpp"
#include "base_output_manager.hpp"

#include <string>
#include <array>
#include <cmath>

namespace bcalc
{

// Boolean Reverse Polish Notation Interpreter
class BoolRPN
{
public:
    ~BoolRPN () = default;

    BoolRPN () = default;

    BoolRPN ( std::string const & );

    void setExpression ( std::string const & ); // TODO: Upgrade

    void set ( BaseInputManager & );

    void get ( BaseOutputManager & ) const noexcept;

    Table const & getVariables () const noexcept;
    
    LineOfTable const & getAnswer () const noexcept;

    void calculateExpression ();

    constexpr static int prior ( char const c ) noexcept;

    constexpr static bool is_num ( char const c ) noexcept;

    constexpr static bool is_number ( char const c ) noexcept;

    constexpr static bool is_var ( char const c ) noexcept;

    constexpr static bool is_oper ( char const c ) noexcept;

    constexpr static bool is_unar_oper ( char const c ) noexcept;

    constexpr static bool is_other ( char const c ) noexcept;

private:
    // TODO: Change the order of members to make class more compact

    // Number of bits in variables ( m )
    std::size_t m_size = 0;

    Table m_expressions; // Should be map of vectors
    /*
        Variable '0'   = a(0),a(1)...a(m-1)
        Variable '1'   = a(0),a(1)...a(m-1)
        ...
        Variable 'n-1' = a(0),a(1)...a(m-1)
    */

    LineOfTable m_answers;
    /*
        Answer = a(0),a(1)...a(m-1)
    */

    std::string m_formula;
    std::array< bool, 5 > m_classes; // TODO: Should be map and removed from class
    bool m_classP = false; // TODO: This too

    void analyze (); // TODO: RegExp

    constexpr bool calc ( bool second, char oper, bool first ) const noexcept;
};

} // namespace bcalc

#endif // RPE_HPP //
