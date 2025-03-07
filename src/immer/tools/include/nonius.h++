// Nonius - C++ benchmarking tool
//
// Written in 2014 by Martinho Fernandes <martinho.fernandes@gmail.com>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// This file was automatically generated on 2017-07-26T10:25:52.043838Z
// Do not edit it directly

#ifndef NONIUS_SINGLE_INCLUDE_HPP
#define NONIUS_SINGLE_INCLUDE_HPP

// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Single header root

// #included from: nonius.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Main header

#ifndef NONIUS_HPP
#define NONIUS_HPP

// #included from: clock.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Clocks

#define NONIUS_CLOCK_HPP

// #included from: detail/compiler.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Compiler detection macros

#define NONIUS_DETAIL_COMPILER_HPP

#if defined(__clang__)
#   define NONIUS_CLANG (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__)
#elif defined(__GNUC__)
#   define NONIUS_GCC   (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#elif defined(_MSC_VER)
#   define NONIUS_MSVC  _MSC_VER
#endif

// MSVC <chrono> is borken and had little to no testing done before shipping (Dev14/VS15 CTP fixes it)
#if defined(NONIUS_MSVC) && NONIUS_MSVC < 1900
#   ifndef NONIUS_USE_BOOST_CHRONO
#       define NONIUS_USE_BOOST_CHRONO
#   endif
#endif

#ifdef NONIUS_USE_BOOST_CHRONO
#   include <boost/chrono.hpp>
#else
#   include <chrono>
#   include <ratio>
#endif

namespace nonius {
#ifdef NONIUS_USE_BOOST_CHRONO
    namespace chrono = boost::chrono;
    template <unsigned Num, unsigned Den = 1>
    using ratio = boost::ratio<Num, Den>;
#else
    namespace chrono = std::chrono;
    template <unsigned Num, unsigned Den = 1>
    using ratio = std::ratio<Num, Den>;
#endif
    using milli = ratio<1,       1000>;
    using micro = ratio<1,    1000000>;
    using nano  = ratio<1, 1000000000>;

    template <typename Clock>
    using Duration = typename Clock::duration;
    template <typename Clock>
    using FloatDuration = chrono::duration<double, typename Clock::period>;

    template <typename Clock>
    using TimePoint = typename Clock::time_point;

    using default_clock = chrono::high_resolution_clock;

    template <typename Clock>
    struct now {
        TimePoint<Clock> operator()() const {
            return Clock::now();
        }
    };

    using fp_seconds = chrono::duration<double, ratio<1>>;
} // namespace nonius

// #included from: benchmark.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Benchmark

#define NONIUS_BENCHMARK_HPP

// #included from: configuration.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Run configuration

#define NONIUS_CONFIGURATION_HPP

// #included from: param.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014 by Martinho Fernandes <martinho.fernandes@gmail.com>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// User-facing param

#define NONIUS_PARAM_HPP

// #included from: detail/meta.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014 by Martinho Fernandes <martinho.fernandes@gmail.com>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Invoke with a special case for void

#define NONIUS_META_HPP

#include <type_traits>
#include <utility>

namespace nonius {
    namespace detail {
        template <typename> struct true_given : std::true_type {};
        struct is_callable_tester {
            template <typename Fun, typename... Args>
            true_given<decltype(std::declval<Fun>()(std::declval<Args>()...))> static test(int);
            template <typename...>
            std::false_type static test(...);
        };
        template <typename T>
        struct is_callable;
        template <typename Fun, typename... Args>
        struct is_callable<Fun(Args...)> : decltype(is_callable_tester::test<Fun, Args...>(0)) {};
    } // namespace detail
} // namespace nonius

// #included from: detail/noexcept.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Cross-compiler noexcept support

#define NONIUS_DETAIL_NOEXCEPT_HPP

#if defined(NONIUS_MSVC) && NONIUS_MSVC < 1900
#   define NONIUS_NOEXCEPT
#else
#   define NONIUS_NOEXCEPT noexcept
#endif

#include <boost/lexical_cast.hpp>
#include <unordered_map>
#include <typeinfo>
#include <memory>

namespace nonius {

struct param_bad_operation : std::exception {
    char const* what() const NONIUS_NOEXCEPT override {
        return "operation not supported for this parameter type";
    }
};

namespace detail {

struct eq_fn {
    template <typename T>
    auto operator() (T x, T y) -> decltype(x == y) { return x == y; }
};

struct plus_fn {
    template <typename T>
    auto operator() (T x, T y) -> decltype(x + y) { return x + y; }
};

struct mult_fn {
    template <typename T>
    auto operator() (T x, T y) -> decltype(x * y) { return x * y; }
};

} // namespace detail

class param {
    struct interface {
        virtual ~interface() = default;
        virtual std::istream& pull(std::istream&) = 0;
        virtual std::ostream& push(std::ostream&) const = 0;
        virtual bool eq(param const&) const = 0;
        virtual param plus(param const&) const = 0;
        virtual param mult(param const&) const = 0;
        virtual param clone() const = 0;
    };

    template <typename T>
    struct model : interface {
        T value;

        model(T v) : value(std::move(v)) {}
        std::istream& pull(std::istream& is) override { is >> value; return is; }
        std::ostream& push(std::ostream& os) const override { os << value; return os; }
        bool eq(param const& y) const override { return operate<bool>(detail::eq_fn{}, value, y.as<T>()); }
        param plus(param const& y) const override { return operate<T>(detail::plus_fn{}, value, y.as<T>()); }
        param mult(param const& y) const override { return operate<T>(detail::mult_fn{}, value, y.as<T>()); }
        param clone() const override { return value; }

        template <typename R, typename Op, typename ...Args>
        auto operate(Op&& op, Args&& ...xs) const
            -> typename std::enable_if<detail::is_callable<Op&&(Args&&...)>::value, R>::type {
            return std::forward<Op>(op)(std::forward<Args>(xs)...);
        }

        template <typename R, typename Op, typename ...Args>
        auto operate(Op&&, Args&&...) const
            -> typename std::enable_if<!detail::is_callable<Op&&(Args&&...)>::value, R>::type {
            throw param_bad_operation{};
        }
    };

public:
    template <typename T,
              typename std::enable_if<!std::is_base_of<param, typename std::decay<T>::type>::value, int>::type = 0>
    param(T&& v)
        : impl_(new model<typename std::decay<T>::type>{std::forward<T>(v)}) {}

    template <typename T>
    const T& as() const& { return dynamic_cast<model<T> const&>(*impl_).value; }

    friend std::istream& operator>>(std::istream& is, param& x) { x.writable_(); return x.impl_->pull(is); }
    friend std::ostream& operator<<(std::ostream& os, const param& x) { return x.impl_->push(os); }
    friend param operator+(const param& x, const param& y) { return x.impl_->plus(y); }
    friend param operator*(const param& x, const param& y) { return x.impl_->mult(y); }
    friend bool operator==(const param& x, const param& y) { return x.impl_->eq(y); }

    param parse(std::string const& s) const {
        auto ss = std::stringstream{s};
        auto cpy = *this;
        ss.exceptions(std::ios::failbit);
        ss >> cpy;
        return cpy;
    }

private:
    void writable_() {
        if (impl_.use_count() > 1) {
        }
    }

    std::shared_ptr<interface> impl_;
};

struct parameters : std::unordered_map<std::string, param> {
    using base_t = std::unordered_map<std::string, param>;
    using base_t::base_t;

    template <typename Tag>
    auto get() const -> typename Tag::type {
        return at(Tag::name()).template as<typename Tag::type>();
    }

    parameters merged(parameters m) const& {
        m.insert(begin(), end());
        return m;
    }
    parameters merged(parameters m) && {
        m.insert(std::make_move_iterator(begin()), std::make_move_iterator(end()));
        return m;
    }

    friend std::ostream& operator<< (std::ostream& os, const parameters& m) {
        for(auto&& p : m) os << "  " << p.first << " = " << p.second << "\n";
        return os;
    }
};

struct param_registry {
    parameters const& defaults() const { return defaults_; }
    void add(std::string name, param v) { defaults_.emplace(name, v); }
    void remove(std::string name) { defaults_.erase(name); }

private:
    parameters defaults_;
};

inline param_registry& global_param_registry() {
    static param_registry instance;
    return instance;
}

template <typename Tag>
struct param_declaration {
    using type = typename Tag::type;
    param_registry& registry;

    param_declaration(type v, param_registry& r = global_param_registry())
        : registry{r}
    {
        r.add(Tag::name(), param{type{v}});
    }
};

template <typename Tag>
struct scoped_param_declaration : param_declaration<Tag> {
    using param_declaration<Tag>::param_declaration;

    ~scoped_param_declaration() {
        this->registry.remove(Tag::name());
    }
};

} /* namespace nonius */

#define NONIUS_PARAM(name_, ...)                                        \
    namespace {                                                         \
    struct name_ {                                                      \
        using type = decltype(__VA_ARGS__);                             \
        static const char* name() { return #name_; }                    \
    };                                                                  \
    static auto NONIUS_DETAIL_UNIQUE_NAME(param_declaration) =          \
                   ::nonius::param_declaration<name_>{ (__VA_ARGS__) }; \
    }                                                                   \
    //

#include <boost/optional.hpp>
#include <string>
#include <vector>

namespace nonius {
    struct run_configuration {
        std::string name;
        std::string op;
        param init;
        param step;
        std::size_t count;
    };

    struct param_configuration {
        parameters map;
        boost::optional<run_configuration> run;
    };

    struct configuration {
    public:
        int samples = 100;
        double confidence_interval = 0.95;
        int resamples = 100000;
        std::string title = "benchmarks";
        std::string output_file;
        std::string reporter;
        std::string filter_pattern = ".*";
        bool list_benchmarks = false;
        bool list_params = false;
        bool list_reporters = false;
        bool no_analysis = false;
        bool verbose = false;
        bool summary = false;
        bool help = false;
        param_configuration params;
    };
} // namespace nonius

// #included from: environment.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Environment information

#define NONIUS_ENVIRONMENT_HPP

// #included from: outlier_classification.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Outlier information

#define NONIUS_OUTLIERS_HPP

namespace nonius {
    struct outlier_classification {
        int samples_seen = 0;
        int low_severe = 0;     // more than 3 times IQR below Q1
        int low_mild = 0;       // 1.5 to 3 times IQR below Q1
        int high_mild = 0;      // 1.5 to 3 times IQR above Q3
        int high_severe = 0;    // more than 3 times IQR above Q3

        int total() const {
            return low_severe + low_mild + high_mild + high_severe;
        }
    };
} // namespace nonius

namespace nonius {
    template <typename Duration>
    struct environment_estimate {
        Duration mean;
        outlier_classification outliers;

        template <typename Duration2>
        operator environment_estimate<Duration2>() const {
            return { mean, outliers };
        }
    };
    template <typename Clock>
    struct environment {
        using clock_type = Clock;
        environment_estimate<FloatDuration<Clock>> clock_resolution;
        environment_estimate<FloatDuration<Clock>> clock_cost;
        //estimate function_cost;
    };
} // namespace nonius

// #included from: execution_plan.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Execution plan

#define NONIUS_EXECUTION_PLAN_HPP

// #included from: optimizer.h++
// Nonius - C++ benchmarking tool
//
// Written in 2016 by Martinho Fernandes <rmf@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Hinting the optimizer

#define NONIUS_OPTIMIZER_HPP

#if defined(NONIUS_MSVC)
#   include <atomic> // atomic_thread_fence
#endif

namespace nonius {
#if defined(NONIUS_GCC) || defined(NONIUS_CLANG)
    template <typename T>
    inline void keep_memory(T* p) {
        asm volatile("" : : "g"(p) : "memory");
    }
    inline void keep_memory() {
        asm volatile("" : : : "memory");
    }

    namespace detail {
        inline void optimizer_barrier() { keep_memory(); }
    } // namespace detail
#elif defined(NONIUS_MSVC)

#pragma optimize("", off)
    template <typename T>
    inline void keep_memory(T* p) {
        // thanks @milleniumbug
    }
    // TODO equivalent keep_memory()
#pragma optimize("", on)

    namespace detail {
        inline void optimizer_barrier() {
            std::atomic_thread_fence(std::memory_order_seq_cst);
        }
    } // namespace detail

#endif
} // namespace nonius

// #included from: detail/benchmark_function.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Dumb std::function implementation for consistent call overhead

#define NONIUS_DETAIL_BENCHMARK_FUNCTION_HPP

// #included from: chronometer.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// User-facing chronometer

#define NONIUS_CHRONOMETER_HPP

// #included from: detail/complete_invoke.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Invoke with a special case for void

#define NONIUS_DETAIL_COMPLETE_INVOKE_HPP

#include <type_traits>
#include <utility>

namespace nonius {
    namespace detail {
        template <typename T>
        struct complete_type { using type = T; };
        template <>
        struct complete_type<void> { struct type {}; };

        template <typename T>
        using CompleteType = typename complete_type<T>::type;

        template <typename Result>
        struct complete_invoker {
            template <typename Fun, typename... Args>
            static Result invoke(Fun&& fun, Args&&... args) {
                return std::forward<Fun>(fun)(std::forward<Args>(args)...);
            }
        };
        template <>
        struct complete_invoker<void> {
            template <typename Fun, typename... Args>
            static CompleteType<void> invoke(Fun&& fun, Args&&... args) {
                std::forward<Fun>(fun)(std::forward<Args>(args)...);
                return {};
            }
        };
        template <typename Sig>
        using ResultOf = typename std::result_of<Sig>::type;

        // invoke and not return void :(
        template <typename Fun, typename... Args>
        CompleteType<ResultOf<Fun(Args...)>> complete_invoke(Fun&& fun, Args&&... args) {
            return complete_invoker<ResultOf<Fun(Args...)>>::invoke(std::forward<Fun>(fun), std::forward<Args>(args)...);
        }
    } // namespace detail
} // namespace nonius

#include <boost/lexical_cast.hpp>

namespace nonius {
    namespace detail {
        struct chronometer_concept {
            virtual void start() = 0;
            virtual void finish() = 0;
            virtual ~chronometer_concept() = default;
        };
        template <typename Clock>
        struct chronometer_model final : public chronometer_concept {
            void start() override { started = Clock::now(); }
            void finish() override { finished = Clock::now(); }

            Duration<Clock> elapsed() const { return finished - started; }

            TimePoint<Clock> started;
            TimePoint<Clock> finished;
        };
    } // namespace detail

    struct chronometer {
    public:
        template <typename Fun>
        void measure(Fun&& fun) { measure(std::forward<Fun>(fun), detail::is_callable<Fun(int)>()); }

        int runs() const { return k; }

        chronometer(detail::chronometer_concept& meter, int k, const parameters& p)
            : impl(&meter)
            , k(k)
            , params(&p)
        {}

        template <typename Tag>
        auto param() const -> typename Tag::type {
            return params->get<Tag>();
        }

    private:
        template <typename Fun>
        void measure(Fun&& fun, std::false_type) {
            measure([&fun](int) { fun(); });
        }
        template <typename Fun>
        void measure(Fun&& fun, std::true_type) {
            impl->start();
            for(int i = 0; i < k; ++i) fun(i);
            impl->finish();
        }

        detail::chronometer_concept* impl;
        int k;
        const parameters* params;
    };
} // namespace nonius

#include <type_traits>
#include <utility>
#include <memory>

namespace nonius {
    namespace detail {
        template <typename T>
        using Decay = typename std::decay<T>::type;
        template <typename T, typename U>
        struct is_related
        : std::is_same<Decay<T>, Decay<U>> {};

        /// We need to reinvent std::function because every piece of code that might add overhead
        /// in a measurement context needs to have consistent performance characteristics so that we
        /// can account for it in the measurement.
        /// Implementations of std::function with optimizations that aren't always applicable, like
        /// small buffer optimizations, are not uncommon.
        /// This is effectively an implementation of std::function without any such optimizations;
        /// it may be slow, but it is consistently slow.
        struct benchmark_function {
        private:
            struct concept {
                virtual benchmark_function call(parameters params) const = 0;
                virtual void call(chronometer meter) const = 0;
                virtual concept* clone() const = 0;
                virtual ~concept() = default;
            };
            template <typename Fun>
            struct model : public concept {
                model(Fun&& fun) : fun(std::move(fun)) {}
                model(Fun const& fun) : fun(fun) {}

                model<Fun>* clone() const override { return new model<Fun>(*this); }

                benchmark_function call(parameters params) const override {
                    return call(params, is_callable<Fun(parameters)>());
                }
                benchmark_function call(parameters params, std::true_type) const {
                    return fun(params);
                }
                benchmark_function call(parameters, std::false_type) const {
                    return this->clone();
                }

                void call(chronometer meter) const override {
                    call(meter, is_callable<Fun(chronometer)>(), is_callable<Fun(parameters)>());
                }
                void call(chronometer meter, std::true_type, std::false_type) const {
                    fun(meter);
                }
                void call(chronometer meter, std::false_type, std::false_type) const {
                    meter.measure(fun);
                }
                template <typename T>
                void call(chronometer, T, std::true_type) const {
                    // the function should be prepared first
                    assert(false);
                }

                Fun fun;
            };

            struct do_nothing { void operator()() const {} };

            template <typename T>
            benchmark_function(model<T>* c) : f(c) {}

        public:
            benchmark_function()
            : f(new model<do_nothing>{{}})
            {}

            template <typename Fun,
                      typename std::enable_if<!is_related<Fun, benchmark_function>::value, int>::type = 0>
            benchmark_function(Fun&& fun)
            : f(new model<typename std::decay<Fun>::type>(std::forward<Fun>(fun))) {}

            benchmark_function(benchmark_function&& that)
            : f(std::move(that.f)) {}

            benchmark_function(benchmark_function const& that)
            : f(that.f->clone()) {}

            benchmark_function& operator=(benchmark_function&& that) {
                f = std::move(that.f);
                return *this;
            }

            benchmark_function& operator=(benchmark_function const& that) {
                f.reset(that.f->clone());
                return *this;
            }

            benchmark_function operator()(parameters params) const { return f->call(params); }
            void operator()(chronometer meter) const { f->call(meter); }
        private:
            std::unique_ptr<concept> f;
        };
    } // namespace detail
} // namespace nonius

// #included from: detail/repeat.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// repeat algorithm

#define NONIUS_DETAIL_REPEAT_HPP

#include <type_traits>
#include <utility>

namespace nonius {
    namespace detail {
        template <typename Fun>
        struct repeater {
            void operator()(int k) const {
                for(int i = 0; i < k; ++i) {
                    fun();
                }
            }
            Fun fun;
        };
        template <typename Fun>
        repeater<typename std::decay<Fun>::type> repeat(Fun&& fun) {
            return { std::forward<Fun>(fun) };
        }
    } // namespace detail
} // namespace nonius

// #included from: detail/run_for_at_least.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Run a function for a minimum amount of time

#define NONIUS_RUN_FOR_AT_LEAST_HPP

// #included from: detail/measure.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Measure

#define NONIUS_DETAIL_MEASURE_HPP

// #included from: detail/timing.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Timing

#define NONIUS_DETAIL_TIMING_HPP

#include <tuple>
#include <type_traits>

namespace nonius {
    template <typename Duration, typename Result>
    struct timing {
        Duration elapsed;
        Result result;
        int iterations;
    };
    template <typename Clock, typename Sig>
    using TimingOf = timing<Duration<Clock>, detail::CompleteType<detail::ResultOf<Sig>>>;
} // namespace nonius

#include <utility>

namespace nonius {
    namespace detail {
        template <typename Clock, typename Fun, typename... Args>
        TimingOf<Clock, Fun(Args...)> measure(Fun&& fun, Args&&... args) {
            auto start = Clock::now();
            auto&& r = detail::complete_invoke(fun, std::forward<Args>(args)...);
            auto end = Clock::now();
            auto delta = end - start;
            return { delta, std::forward<decltype(r)>(r), 1 };
        }
    } // namespace detail
} // namespace nonius

#include <utility>
#include <type_traits>

namespace nonius {
    namespace detail {
        template <typename Clock, typename Fun>
        TimingOf<Clock, Fun(int)> measure_one(Fun&& fun, int iters, const parameters&, std::false_type) {
            return detail::measure<Clock>(fun, iters);
        }
        template <typename Clock, typename Fun>
        TimingOf<Clock, Fun(chronometer)> measure_one(Fun&& fun, int iters, const parameters& params, std::true_type) {
            detail::chronometer_model<Clock> meter;
            auto&& result = detail::complete_invoke(fun, chronometer(meter, iters, params));

            return { meter.elapsed(), std::move(result), iters };
        }

        template <typename Clock, typename Fun>
        using run_for_at_least_argument_t = typename std::conditional<detail::is_callable<Fun(chronometer)>::value, chronometer, int>::type;

        struct optimized_away_error : std::exception {
            const char* what() const NONIUS_NOEXCEPT override {
                return "could not measure benchmark, maybe it was optimized away";
            }
        };

        template <typename Clock, typename Fun>
        TimingOf<Clock, Fun(run_for_at_least_argument_t<Clock, Fun>)> run_for_at_least(const parameters& params, Duration<Clock> how_long, int seed, Fun&& fun) {
            auto iters = seed;
            while(iters < (1 << 30)) {
                auto&& timing = measure_one<Clock>(fun, iters, params, detail::is_callable<Fun(chronometer)>());

                if(timing.elapsed >= how_long) {
                    return { timing.elapsed, std::move(timing.result), iters };
                }
                iters *= 2;
            }
            throw optimized_away_error{};
        }
    } // namespace detail
} // namespace nonius

namespace nonius {
    template <typename Duration>
    struct execution_plan {
        int iterations_per_sample;
        Duration estimated_duration;
        parameters params;
        detail::benchmark_function benchmark;
        Duration warmup_time;
        int warmup_iterations;

        template <typename Duration2>
        operator execution_plan<Duration2>() const {
            return { iterations_per_sample, estimated_duration, params, benchmark, warmup_time, warmup_iterations };
        }

        template <typename Clock>
        std::vector<FloatDuration<Clock>> run(configuration cfg, environment<FloatDuration<Clock>> env) const {
            // warmup a bit
            detail::run_for_at_least<Clock>(params, chrono::duration_cast<nonius::Duration<Clock>>(warmup_time), warmup_iterations, detail::repeat(now<Clock>{}));

            std::vector<FloatDuration<Clock>> times;
            times.reserve(cfg.samples);
            std::generate_n(std::back_inserter(times), cfg.samples, [this, env]{
                    detail::chronometer_model<Clock> model;
                    detail::optimizer_barrier();
                    this->benchmark(chronometer(model, iterations_per_sample, params));
                    detail::optimizer_barrier();
                    auto sample_time = model.elapsed() - env.clock_cost.mean;
                    if(sample_time < FloatDuration<Clock>::zero()) sample_time = FloatDuration<Clock>::zero();
                    return sample_time / iterations_per_sample;
            });
            return times;
        }
    };
} // namespace nonius

// #included from: detail/unique_name.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Unique name generator macro

#define NONIUS_DETAIL_UNIQUE_NAME_HPP

#define NONIUS_DETAIL_UNIQUE_NAME_LINE_CAT(name, id) NONIUS_ ## name ## _ ## id
#define NONIUS_DETAIL_UNIQUE_NAME_LINE(name, id) NONIUS_DETAIL_UNIQUE_NAME_LINE_CAT(name, id)
#ifdef __COUNTER__
#define NONIUS_DETAIL_UNIQUE_NAME(name) NONIUS_DETAIL_UNIQUE_NAME_LINE(name, __COUNTER__)
#else // __COUNTER__
#define NONIUS_DETAIL_UNIQUE_NAME(name) NONIUS_DETAIL_UNIQUE_NAME_LINE(name, __LINE__)
#endif // __COUNTER__

#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <cmath>

namespace nonius {
    namespace detail {
        const auto warmup_iterations = 10000;
        const auto warmup_time = chrono::milliseconds(100);
        const auto minimum_ticks = 1000;
    } // namespace detail

    struct benchmark {
        benchmark(std::string name, detail::benchmark_function fun)
        : name(std::move(name)), fun(std::move(fun)) {}

        template <typename Clock>
        execution_plan<FloatDuration<Clock>> prepare(configuration cfg, parameters params, environment<FloatDuration<Clock>> env) const {
            auto bench = fun(params);
            auto min_time = env.clock_resolution.mean * detail::minimum_ticks;
            auto run_time = std::max(min_time, chrono::duration_cast<decltype(min_time)>(detail::warmup_time));
            auto&& test = detail::run_for_at_least<Clock>(params, chrono::duration_cast<Duration<Clock>>(run_time), 1, bench);
            int new_iters = static_cast<int>(std::ceil(min_time * test.iterations / test.elapsed));
            return { new_iters, test.elapsed / test.iterations * new_iters * cfg.samples, params, bench, chrono::duration_cast<FloatDuration<Clock>>(detail::warmup_time), detail::warmup_iterations };
        }

        std::string name;
        detail::benchmark_function fun;
    };

    using benchmark_registry = std::vector<benchmark>;

    inline benchmark_registry& global_benchmark_registry() {
        static benchmark_registry registry;
        return registry;
    }

    struct benchmark_registrar {
        template <typename Fun>
        benchmark_registrar(benchmark_registry& registry, std::string name, Fun&& registrant) {
            registry.emplace_back(std::move(name), std::forward<Fun>(registrant));
        }
    };
} // namespace nonius

#define NONIUS_BENCHMARK(name, ...) \
    namespace { static ::nonius::benchmark_registrar NONIUS_DETAIL_UNIQUE_NAME(benchmark_registrar) (::nonius::global_benchmark_registry(), name, __VA_ARGS__); }

// #included from: constructor.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Constructor and destructor helpers

#define NONIUS_CONSTRUCTOR_HPP

#include <type_traits>

namespace nonius {
    namespace detail {
        template <typename T, bool Destruct>
        struct object_storage
        {
            typedef typename std::aligned_storage<sizeof(T), std::alignment_of<T>::value>::type TStorage;

            object_storage() : data() {}

            object_storage(const object_storage& other)
            {
                new(&data) T(other.stored_object());
            }

            object_storage(object_storage&& other)
            {
                new(&data) T(std::move(other.stored_object()));
            }

            ~object_storage() { destruct_on_exit<T>(); }

            template <typename... Args>
            void construct(Args&&... args)
            {
                new (&data) T(std::forward<Args>(args)...);
            }

            template <bool AllowManualDestruction = !Destruct>
            typename std::enable_if<AllowManualDestruction>::type destruct()
            {
                stored_object().~T();
            }

        private:
            // If this is a constructor benchmark, destruct the underlying object
            template <typename U>
            void destruct_on_exit(typename std::enable_if<Destruct, U>::type* = 0) { destruct<true>(); }
            // Otherwise, don't
            template <typename U>
            void destruct_on_exit(typename std::enable_if<!Destruct, U>::type* = 0) { }

            T& stored_object()
            {
                return *static_cast<T*>(static_cast<void*>(&data));
            }

            TStorage data;
        };
    }

    template <typename T>
    using storage_for = detail::object_storage<T, true>;

    template <typename T>
    using destructable_object = detail::object_storage<T, false>;
}

// #included from: go.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Runner entry point

#define NONIUS_GO_HPP

// #included from: reporter.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Reporter interface

#define NONIUS_REPORTER_HPP

// #included from: sample_analysis.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Benchmark results

#define NONIUS_BENCHMARK_RESULTS_HPP

// #included from: estimate.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Statistics estimates

#define NONIUS_ESTIMATE_HPP

namespace nonius {
    template <typename Duration>
    struct estimate {
        Duration point;
        Duration lower_bound;
        Duration upper_bound;
        double confidence_interval;

        template <typename Duration2>
        operator estimate<Duration2>() const {
            return { point, lower_bound, upper_bound, confidence_interval };
        }
    };
} // namespace nonius

#include <algorithm>
#include <vector>
#include <string>
#include <iterator>

namespace nonius {
    template <typename Duration>
    struct sample_analysis {
        std::vector<Duration> samples;
        estimate<Duration> mean;
        estimate<Duration> standard_deviation;
        outlier_classification outliers;
        double outlier_variance;

        template <typename Duration2>
        operator sample_analysis<Duration2>() const {
            std::vector<Duration2> samples2;
            samples2.reserve(samples.size());
            std::transform(samples.begin(), samples.end(), std::back_inserter(samples2), [](Duration d) { return Duration2(d); });
            return {
                std::move(samples2),
                mean,
                standard_deviation,
                outliers,
                outlier_variance,
            };
        }
    };
} // namespace nonius

#include <vector>
#include <string>
#include <ios>
#include <ostream>
#include <fstream>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <exception>

namespace nonius {
    struct bad_stream : virtual std::exception {
        char const* what() const NONIUS_NOEXCEPT override {
            return "failed to open file";
        }
    };

    struct reporter {
    public:
        virtual ~reporter() = default;

        void configure(configuration& cfg) {
            if(cfg.output_file.empty()) {
                os = [&]() -> std::ostream& { return std::cout; };
            } else {
                auto ofs = std::make_shared<std::ofstream>(cfg.output_file);
                os = [ofs]() -> std::ostream& { return *ofs; };
            }
            report_stream().exceptions(std::ios::failbit);
            if(!report_stream()) throw bad_stream();
            do_configure(cfg);
        }

        void warmup_start() {
            do_warmup_start();
        }
        void warmup_end(int iterations) {
            do_warmup_end(iterations);
        }
        void estimate_clock_resolution_start() {
            do_estimate_clock_resolution_start();
        }
        void estimate_clock_resolution_complete(environment_estimate<fp_seconds> estimate) {
            do_estimate_clock_resolution_complete(estimate);
        }

        void estimate_clock_cost_start() {
            do_estimate_clock_cost_start();
        }
        void estimate_clock_cost_complete(environment_estimate<fp_seconds> estimate) {
            do_estimate_clock_cost_complete(estimate);
        }

        void suite_start() {
            do_suite_start();
        }
        void params_start(parameters const& params) {
            do_params_start(params);
        }
        void benchmark_start(std::string const& name) {
            do_benchmark_start(name);
        }

        void measurement_start(execution_plan<fp_seconds> plan) {
            do_measurement_start(plan);
        }
        void measurement_complete(std::vector<fp_seconds> const& samples) {
            do_measurement_complete(samples);
        }

        void analysis_start() {
            do_analysis_start();
        }
        void analysis_complete(sample_analysis<fp_seconds> const& analysis) {
            do_analysis_complete(analysis);
        }

        void benchmark_failure(std::exception_ptr error) {
            do_benchmark_failure(error);
        }
        void benchmark_complete() {
            do_benchmark_complete();
        }

        void params_complete() {
            do_params_complete();
        }
        void suite_complete() {
            do_suite_complete();
        }

        virtual std::string description() = 0;

    private:
        virtual void do_configure(configuration& /*cfg*/) {}

        virtual void do_warmup_start() {}
        virtual void do_warmup_end(int /*iterations*/) {}

        virtual void do_estimate_clock_resolution_start() {}
        virtual void do_estimate_clock_resolution_complete(environment_estimate<fp_seconds> /*estimate*/) {}

        virtual void do_estimate_clock_cost_start() {}
        virtual void do_estimate_clock_cost_complete(environment_estimate<fp_seconds> /*estimate*/) {}

        virtual void do_suite_start() {}
        virtual void do_params_start(parameters const& /*params*/) {}
        virtual void do_benchmark_start(std::string const& /*name*/) {}

        virtual void do_measurement_start(execution_plan<fp_seconds> /*plan*/) {}
        virtual void do_measurement_complete(std::vector<fp_seconds> const& /*samples*/) {}

        virtual void do_analysis_start() {} // TODO make generic?
        virtual void do_analysis_complete(sample_analysis<fp_seconds> const& /*analysis*/) {}

        virtual void do_benchmark_failure(std::exception_ptr /*error*/) {}
        virtual void do_benchmark_complete() {}
        virtual void do_params_complete() {}
        virtual void do_suite_complete() {}

    protected:
        std::ostream& progress_stream() {
            return std::cout;
        }
        std::ostream& error_stream() {
            return std::cerr;
        }
        std::ostream& report_stream() {
            return os();
        }

    private:
        std::function<std::ostream&()> os;
    };

    using reporter_registry = std::unordered_map<std::string, std::unique_ptr<reporter>>;

    inline reporter_registry& global_reporter_registry() {
        static reporter_registry registry;
        return registry;
    }

    struct reporter_registrar {
        reporter_registrar(reporter_registry& registry, std::string name, reporter* registrant) {
            registry.emplace(std::move(name), std::unique_ptr<reporter>(registrant));
        }
    };
} // namespace nonius

#define NONIUS_REPORTER(name, ...) \
    namespace { static ::nonius::reporter_registrar NONIUS_DETAIL_UNIQUE_NAME(reporter_registrar) (::nonius::global_reporter_registry(), name, new __VA_ARGS__()); } \
    static_assert(true, "")

// #included from: reporters/standard_reporter.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Standard reporter

#define NONIUS_REPORTERS_STANDARD_REPORTER_HPP

// #included from: detail/pretty_print.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Pretty printing routines

#define NONIUS_DETAIL_PRETTY_PRINT_HPP

#include <ratio>
#include <ios>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <memory>
#include <utility>

namespace nonius {
    namespace detail {
        inline double get_magnitude(fp_seconds secs) {
            if(secs.count() >= 2.e0) {
                return 1.e0;
            } else if(secs.count() >= 2.e-3) {
                return 1.e3;
            } else if(secs.count() >= 2.e-6) {
                return 1.e6;
            } else {
                return 1.e9;
            }
        }
        inline std::string units_for_magnitude(double magnitude) {
            if(magnitude <= 1.e0) return "s";
            else if(magnitude <= 1.e3) return "ms";
            else if(magnitude <= 1.e6) return "μs";
            else return "ns";
        }
        inline std::string pretty_duration(fp_seconds secs) {
            auto magnitude = get_magnitude(secs);
            auto units = units_for_magnitude(magnitude);
#ifdef NONIUS_MSVC
            if(units == "μs") units = "us";
#endif
            std::ostringstream ss;
            ss << std::setprecision(ss.precision());
            ss << (secs.count() * magnitude) << ' ' << units;
            return ss.str();
        }
        inline std::string percentage(double d) {
            std::ostringstream ss;
            ss << std::setprecision(3);
            if(d != 0 && d < 1e-5) {
                ss << std::fixed;
                ss << 0.0001 << "%";
            } else {
                ss.unsetf(std::ios::floatfield);
                ss << (100. * d) << "%";
            }
            return ss.str();
        }
        inline std::string percentage_ratio(double part, double whole) {
            return percentage(part / whole);
        }
    } // namespace detail
} // namespace nonius

#include <ratio>
#include <ios>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <memory>

namespace nonius {
    struct standard_reporter : reporter {
    private:
        std::string description() override {
            return "the standard reporter";
        }

        void do_configure(configuration& cfg) override {
            n_samples = cfg.samples;
            verbose = cfg.verbose;
            summary = cfg.summary;
            n_resamples = cfg.resamples;
            if(!summary && !cfg.params.map.empty()) report_stream() << "parameters\n" << cfg.params.map;
        }

        void do_warmup_start() override {
            if(verbose) report_stream() << "warming up\n";
        }
        void do_estimate_clock_resolution_start() override {
            if(verbose) report_stream() << "estimating clock resolution\n";
        }
        void do_estimate_clock_resolution_complete(environment_estimate<fp_seconds> estimate) override {
            if(!summary) {
                if(!verbose) report_stream() << "clock resolution: ";
                print_environment_estimate(estimate, estimate.outliers.samples_seen + 2);
            }
        }

        void do_estimate_clock_cost_start() override {
            if(verbose) report_stream() << "estimating cost of a clock call\n";
        }
        void do_estimate_clock_cost_complete(environment_estimate<fp_seconds> estimate) override {
            if(verbose) print_environment_estimate(estimate, estimate.outliers.samples_seen);
        }

        void do_params_start(parameters const& params) override {
            if(!summary && !params.empty()) report_stream() << "\n\nnew round for parameters\n" << params;
        }
        void do_benchmark_start(std::string const& name) override {
            report_stream() << '\n';
            if(!summary) report_stream() << "benchmarking ";
            report_stream() << name << "\n";
            current = name;
        }

        void do_measurement_start(execution_plan<fp_seconds> plan) override {
            report_stream() << std::setprecision(7);
            report_stream().unsetf(std::ios::floatfield);
            if(!summary) report_stream() << "collecting " << n_samples << " samples, " << plan.iterations_per_sample << " iterations each, in estimated " << detail::pretty_duration(plan.estimated_duration) << "\n";
        }
        void do_analysis_start() override {
            if(verbose) report_stream() << "bootstrapping with " << n_resamples << " resamples\n";
        }
        void do_benchmark_failure(std::exception_ptr eptr) override {
            error_stream() << current << " failed to run successfully\n";
            if(!summary) {
                try {
                    std::rethrow_exception(eptr);
                } catch(std::exception& ex) {
                    error_stream() << "error: " << ex.what();
                } catch(...) {
                    error_stream() << "unknown error";
                }
            }
            report_stream() << "\nbenchmark aborted\n";
        }
        void do_analysis_complete(sample_analysis<fp_seconds> const& analysis) override {
            print_statistic_estimate("mean", analysis.mean);
            print_statistic_estimate("std dev", analysis.standard_deviation);
            if(!summary) print_outliers(analysis.outliers);
            if(verbose) report_stream() << "variance introduced by outliers: " << detail::percentage(analysis.outlier_variance) << "\n";
            const char* effect;
            if(analysis.outlier_variance < 0.01) {
                effect = "unaffected";
            } else if(analysis.outlier_variance < 0.1) {
                effect = "slightly inflated";
            } else if(analysis.outlier_variance < 0.5) {
                effect = "moderately inflated";
            } else {
                effect = "severely inflated";
            }
            report_stream() << "variance is " << effect << " by outliers\n";
        }

        void print_environment_estimate(environment_estimate<fp_seconds> e, int iterations) {
            report_stream() << std::setprecision(7);
            report_stream().unsetf(std::ios::floatfield);
            report_stream() << "mean is " << detail::pretty_duration(e.mean) << " (" << iterations << " iterations)\n";
            if(verbose) print_outliers(e.outliers);
        }
        void print_outlier_count(const char* description, int count, int total) {
            if(count > 0) report_stream() << "  " << count << " (" << detail::percentage_ratio(count, total) << ") " << description << "\n";
        }
        void print_outliers(outlier_classification o) {
            report_stream() << "found " << o.total() << " outliers among " << o.samples_seen << " samples (" << detail::percentage_ratio(o.total(), o.samples_seen) << ")\n";
            if(verbose) {
                print_outlier_count("low severe", o.low_severe, o.samples_seen);
                print_outlier_count("low mild", o.low_mild, o.samples_seen);
                print_outlier_count("high mild", o.high_mild, o.samples_seen);
                print_outlier_count("high severe", o.high_severe, o.samples_seen);
            }
        }
        void print_statistic_estimate(const char* name, estimate<fp_seconds> estimate) {
            report_stream() << std::setprecision(7);
            report_stream().unsetf(std::ios::floatfield);
            report_stream() << name << ": " << detail::pretty_duration(estimate.point);
            if(!summary) {
                report_stream() << ", lb " << detail::pretty_duration(estimate.lower_bound)
                         << ", ub " << detail::pretty_duration(estimate.upper_bound)
                         << ", ci " << std::setprecision(3) << estimate.confidence_interval;
            }
            report_stream() << "\n";
        }

        int n_samples = 0;
        int n_resamples = 0;
        bool verbose = false;
        bool summary = false;

        std::string current;
    };

    NONIUS_REPORTER("", standard_reporter);
    NONIUS_REPORTER("standard", standard_reporter);
} // namespace nonius

// #included from: detail/estimate_clock.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Environment measurement

#define NONIUS_DETAIL_ENVIRONMENT_HPP

// #included from: detail/stats.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Statistical analysis tools

#define NONIUS_DETAIL_ANALYSIS_HPP

#include <boost/math/distributions/normal.hpp>

#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>
#include <array>
#include <random>
#include <numeric>
#include <tuple>
#include <cmath>
#include <utility>
#include <future>
#include <cstddef>

namespace nonius {
    namespace detail {
        using sample = std::vector<double>;

        template <typename Iterator>
        double weighted_average_quantile(int k, int q, Iterator first, Iterator last) {
            auto count = last - first;
            double idx = (count - 1) * k /static_cast<double>(q);
            int j = static_cast<int>(idx);
            double g = idx - j;
            std::nth_element(first, first+j, last);
            auto xj = first[j];
            if(g == 0) return xj;

            auto xj1 = *std::min_element(first+(j+1), last);
            return xj + g * (xj1 - xj);
        }

        template <typename Iterator>
        outlier_classification classify_outliers(Iterator first, Iterator last) {
            std::vector<double> copy(first, last);

            auto q1 = weighted_average_quantile(1, 4, copy.begin(), copy.end());
            auto q3 = weighted_average_quantile(3, 4, copy.begin(), copy.end());
            auto iqr = q3 - q1;
            auto los = q1 - (iqr * 3.);
            auto lom = q1 - (iqr * 1.5);
            auto him = q3 + (iqr * 1.5);
            auto his = q3 + (iqr * 3.);

            outlier_classification o;
            for(; first != last; ++first) {
                auto&& t = *first;
                if(t < los) ++o.low_severe;
                else if(t < lom) ++o.low_mild;
                else if(t > his) ++o.high_severe;
                else if(t > him) ++o.high_mild;
                ++o.samples_seen;
            }
            return o;
        }

        template <typename Iterator>
        double mean(Iterator first, Iterator last) {
            auto count = last - first;
            double sum = std::accumulate(first, last, 0.);
            return sum / count;
        }

        template <typename Iterator>
        double standard_deviation(Iterator first, Iterator last) {
            auto m = mean(first, last);
            double variance = std::accumulate(first, last, 0., [m](double a, double b) {
                        double diff = b - m;
                        return a + diff*diff;
                    }) / (last - first);
            return std::sqrt(variance);
        }

        template <typename URng, typename Iterator, typename Estimator>
        sample resample(URng& rng, int resamples, Iterator first, Iterator last, Estimator& estimator) {
            auto n = last - first;
            std::uniform_int_distribution<decltype(n)> dist(0, n-1);

            sample out;
            out.reserve(resamples);
            std::generate_n(std::back_inserter(out), resamples, [n, first, &estimator, &dist, &rng] {
                std::vector<double> resampled;
                resampled.reserve(n);
                std::generate_n(std::back_inserter(resampled), n, [first, &dist, &rng] { return first[dist(rng)]; });
                return estimator(resampled.begin(), resampled.end());
            });
            std::sort(out.begin(), out.end());
            return out;
        }

        template <typename Estimator, typename Iterator>
        sample jackknife(Estimator&& estimator, Iterator first, Iterator last) {
            auto n = last - first;
            auto second = std::next(first);
            sample results;
            results.reserve(n);

            for(auto it = first; it != last; ++it) {
                std::iter_swap(it, first);
                results.push_back(estimator(second, last));
            }

            return results;
        }

        template <typename Iterator, typename Estimator>
        estimate<double> bootstrap(double confidence_level, Iterator first, Iterator last, sample const& resample, Estimator&& estimator) {
            namespace bm = boost::math;

            auto n_samples = last - first;

            double point = estimator(first, last);
            // Degenerate case with a single sample
            if(n_samples == 1) return { point, point, point, confidence_level };

            sample jack = jackknife(estimator, first, last);
            double jack_mean = mean(jack.begin(), jack.end());
            double sum_squares, sum_cubes;
            std::tie(sum_squares, sum_cubes) = std::accumulate(jack.begin(), jack.end(), std::make_pair(0., 0.), [jack_mean](std::pair<double, double> sqcb, double x) -> std::pair<double, double> {
                        auto d = jack_mean - x;
                        auto d2 = d * d;
                        auto d3 = d2 * d;
                        return { sqcb.first + d2, sqcb.second + d3 };
                    });

            double accel = sum_cubes / (6 * std::pow(sum_squares, 1.5));
            int n = static_cast<int>(resample.size());
            double prob_n = std::count_if(resample.begin(), resample.end(), [point](double x) { return x < point; }) /(double) n;
            // degenerate case with uniform samples
            if(prob_n == 0) return { point, point, point, confidence_level };

            double bias = bm::quantile(bm::normal{}, prob_n);
            double z1 = bm::quantile(bm::normal{}, (1. - confidence_level) / 2.);

            auto cumn = [n](double x) -> int { return std::lround(bm::cdf(bm::normal{}, x) * n); };
            auto a = [bias, accel](double b) { return bias + b / (1. - accel * b); };
            double b1 = bias + z1;
            double b2 = bias - z1;
            double a1 = a(b1);
            double a2 = a(b2);
            auto lo = std::max(cumn(a1), 0);
            auto hi = std::min(cumn(a2), n - 1);

            return { point, resample[lo], resample[hi], confidence_level };
        }

        inline double outlier_variance(estimate<double> mean, estimate<double> stddev, int n) {
            double sb = stddev.point;
            double mn = mean.point / n;
            double mg_min = mn / 2.;
            double sg = std::min(mg_min / 4., sb / std::sqrt(n));
            double sg2 = sg * sg;
            double sb2 = sb * sb;

            auto c_max = [n, mn, sb2, sg2](double x) -> double {
                double k = mn - x;
                double d = k * k;
                double nd = n * d;
                double k0 = -n * nd;
                double k1 = sb2 - n * sg2 + nd;
                double det = k1 * k1 - 4 * sg2 * k0;
                return (int)(-2. * k0 / (k1 + std::sqrt(det)));
            };

            auto var_out = [n, sb2, sg2](double c) {
                double nc = n - c;
                return (nc / n) * (sb2 - nc * sg2);
            };

            return std::min(var_out(1), var_out(std::min(c_max(0.), c_max(mg_min)))) / sb2;
        }

        struct bootstrap_analysis {
            estimate<double> mean;
            estimate<double> standard_deviation;
            double outlier_variance;
        };

        template <typename Iterator>
        bootstrap_analysis analyse_samples(double confidence_level, int n_resamples, Iterator first, Iterator last) {
            static std::random_device entropy;

            auto n = static_cast<int>(last - first); // seriously, one can't use integral types without hell in C++

            auto mean = &detail::mean<Iterator>;
            auto stddev = &detail::standard_deviation<Iterator>;

            auto estimate = [=](double(*f)(Iterator, Iterator)) {
                auto seed = entropy();
                return std::async(std::launch::async, [=]{
                    std::mt19937 rng(seed);
                    auto resampled = resample(rng, n_resamples, first, last, f);
                    return bootstrap(confidence_level, first, last, resampled, f);
                });
            };

            auto mean_future = estimate(mean);
            auto stddev_future = estimate(stddev);

            auto mean_estimate = mean_future.get();
            auto stddev_estimate = stddev_future.get();

            double outlier_variance = detail::outlier_variance(mean_estimate, stddev_estimate, n);

            return { mean_estimate, stddev_estimate, outlier_variance };
        }
    } // namespace detail
} // namespace nonius

#include <algorithm>
#include <iterator>
#include <tuple>
#include <vector>
#include <cmath>

namespace nonius {
    namespace detail {
        template <typename Clock>
        std::vector<double> resolution(int k) {
            std::vector<TimePoint<Clock>> times;
            times.reserve(k+1);
            std::generate_n(std::back_inserter(times), k+1, now<Clock>{});

            std::vector<double> deltas;
            deltas.reserve(k);
            std::transform(std::next(times.begin()), times.end(), times.begin(),
                              std::back_inserter(deltas),
                              [](TimePoint<Clock> a, TimePoint<Clock> b) { return static_cast<double>((a - b).count()); });

            return deltas;
        }

        const auto warmup_seed = 10000;
        const auto clock_resolution_estimation_time = chrono::milliseconds(500);
        const auto clock_cost_estimation_time_limit = chrono::seconds(1);
        const auto clock_cost_estimation_tick_limit = 100000;
        const auto clock_cost_estimation_time = chrono::milliseconds(10);
        const auto clock_cost_estimation_iterations = 10000;

        template <typename Clock>
        int warmup() {
            return run_for_at_least<Clock>({}, chrono::duration_cast<Duration<Clock>>(warmup_time), warmup_seed, &resolution<Clock>)
                    .iterations;
        }
        template <typename Clock>
        environment_estimate<FloatDuration<Clock>> estimate_clock_resolution(int iterations) {
            auto r = run_for_at_least<Clock>({}, chrono::duration_cast<Duration<Clock>>(clock_resolution_estimation_time), iterations, &resolution<Clock>)
                    .result;
            return {
                FloatDuration<Clock>(mean(r.begin(), r.end())),
                classify_outliers(r.begin(), r.end()),
            };
        }
        template <typename Clock>
        environment_estimate<FloatDuration<Clock>> estimate_clock_cost(FloatDuration<Clock> resolution) {
            auto time_limit = std::min(resolution * clock_cost_estimation_tick_limit, FloatDuration<Clock>(clock_cost_estimation_time_limit));
            auto time_clock = [](int k) {
                return detail::measure<Clock>([k]{
                    for(int i = 0; i < k; ++i) {
                        volatile auto ignored = Clock::now();
                        (void)ignored;
                    }
                }).elapsed;
            };
            time_clock(1);
            int iters = clock_cost_estimation_iterations;
            auto&& r = run_for_at_least<Clock>({}, chrono::duration_cast<Duration<Clock>>(clock_cost_estimation_time), iters, time_clock);
            std::vector<double> times;
            int nsamples = static_cast<int>(std::ceil(time_limit / r.elapsed));
            times.reserve(nsamples);
            std::generate_n(std::back_inserter(times), nsamples, [time_clock, &r]{
                        return (time_clock(r.iterations) / r.iterations).count();
                    });
            return {
                FloatDuration<Clock>(mean(times.begin(), times.end())),
                classify_outliers(times.begin(), times.end()),
            };
        }
    } // namespace detail
} // namespace nonius

// #included from: detail/analyse.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Run and analyse one benchmark

#define NONIUS_DETAIL_ANALYSE_HPP

#include <algorithm>
#include <iterator>
#include <vector>

namespace nonius {
    namespace detail {
        template <typename Duration, typename Iterator>
        sample_analysis<Duration> analyse(configuration cfg, environment<Duration>, Iterator first, Iterator last) {
            std::vector<double> samples;
            samples.reserve(last - first);
            std::transform(first, last, std::back_inserter(samples), [](Duration d) { return d.count(); });

            auto analysis = nonius::detail::analyse_samples(cfg.confidence_interval, cfg.resamples, samples.begin(), samples.end());
            auto outliers = nonius::detail::classify_outliers(samples.begin(), samples.end());

            auto wrap_estimate = [](estimate<double> e) {
                return estimate<Duration> {
                    Duration(e.point),
                    Duration(e.lower_bound),
                    Duration(e.upper_bound),
                    e.confidence_interval,
                };
            };
            std::vector<Duration> samples2;
            samples2.reserve(samples.size());
            std::transform(samples.begin(), samples.end(), std::back_inserter(samples2), [](double d) { return Duration(d); });
            return {
                std::move(samples2),
                wrap_estimate(analysis.mean),
                wrap_estimate(analysis.standard_deviation),
                outliers,
                analysis.outlier_variance,
            };
        }
    } // namespace detail
} // namespace nonius

#include <algorithm>
#include <set>
#include <exception>
#include <utility>
#include <regex>

namespace nonius {
    namespace detail {
        template <typename Clock>
        environment<FloatDuration<Clock>> measure_environment(reporter& rep) {
            rep.warmup_start();
            auto iters = detail::warmup<Clock>();
            rep.warmup_end(iters);

            rep.estimate_clock_resolution_start();
            auto resolution = detail::estimate_clock_resolution<Clock>(iters);
            rep.estimate_clock_resolution_complete(resolution);

            rep.estimate_clock_cost_start();
            auto cost = detail::estimate_clock_cost<Clock>(resolution.mean);
            rep.estimate_clock_cost_complete(cost);

            return { resolution, cost };
        }
    } // namespace detail

    struct benchmark_user_error : virtual std::exception {
        char const* what() const NONIUS_NOEXCEPT override {
            return "a benchmark failed to run successfully";
        }
    };

    struct skip_error : virtual std::exception {
        const char* what() const NONIUS_NOEXCEPT override {
            return "benchmark was skipped";
        }
    };

    inline void skip() {
        throw skip_error{};
    }

    inline std::vector<parameters> generate_params(param_configuration cfg) {
        auto params = global_param_registry().defaults().merged(cfg.map);
        if (!cfg.run) {
            return {params};
        } else {
            using operation_t = std::function<param(param, param)>;

            auto&& run = *cfg.run;
            auto step = run.step;
            auto oper = std::unordered_map<std::string, operation_t> {
                {"+", std::plus<param>{}},
                {"*", std::multiplies<param>{}},
            }.at(run.op);

            auto r = std::vector<parameters>{};
            auto next = run.init;
            std::generate_n(std::back_inserter(r), std::max(run.count, std::size_t{1}), [&] {
                auto last = next;
                next = oper(next, step);
                return params.merged(parameters{{run.name, last}});
            });

            return r;
        }
    }

    template <typename Iterator>
    std::vector<benchmark> filter_benchmarks(Iterator first, Iterator last, std::string pattern) {
        auto r = std::vector<benchmark>{};
        auto matcher = std::regex{pattern};
        std::copy_if(first, last, std::back_inserter(r), [&] (benchmark const& b) {
            return std::regex_match(b.name, matcher);
        });
        return r;
    }

    template <typename Clock = default_clock, typename Iterator>
    void go(configuration cfg, Iterator first, Iterator last, reporter& rep) {
        rep.configure(cfg);

        auto env = detail::measure_environment<Clock>(rep);
        rep.suite_start();

        auto benchmarks = filter_benchmarks(first, last, cfg.filter_pattern);
        auto all_params = generate_params(cfg.params);

        for (auto&& params : all_params) {
            rep.params_start(params);
            for (auto&& bench : benchmarks) {
                rep.benchmark_start(bench.name);
                try {
                    auto plan = bench.template prepare<Clock>(cfg, params, env);

                    rep.measurement_start(plan);
                    auto samples = plan.template run<Clock>(cfg, env);
                    rep.measurement_complete(std::vector<fp_seconds>(samples.begin(), samples.end()));

                    if(!cfg.no_analysis) {
                        rep.analysis_start();
                        auto analysis = detail::analyse(cfg, env, samples.begin(), samples.end());
                        rep.analysis_complete(analysis);
                    }
                    rep.benchmark_complete();
                } catch (...) {
                    rep.benchmark_failure(std::current_exception());
                }
            }
            rep.params_complete();
        }

        rep.suite_complete();
    }
    struct duplicate_benchmarks : virtual std::exception {
        char const* what() const NONIUS_NOEXCEPT override {
            return "two or more benchmarks with the same name were registered";
        }
    };
    template <typename Clock = default_clock, typename Iterator>
    void validate_benchmarks(Iterator first, Iterator last) {
        struct strings_lt_through_pointer {
            bool operator()(std::string* a, std::string* b) const { return *a < *b; };
        };
        std::set<std::string*, strings_lt_through_pointer> names;
        for(; first != last; ++first) {
            if(!names.insert(&first->name).second)
                throw duplicate_benchmarks();
        }
    }
    template <typename Clock = default_clock, typename Iterator>
    void go(configuration cfg, Iterator first, Iterator last, reporter&& rep) {
        go<Clock>(cfg, first, last, rep);
    }
    struct no_such_reporter : virtual std::exception {
        char const* what() const NONIUS_NOEXCEPT override {
            return "reporter could not be found";
        }
    };
    template <typename Clock = default_clock>
    void go(configuration cfg, benchmark_registry& benchmarks = global_benchmark_registry(), reporter_registry& reporters = global_reporter_registry()) {
        auto it = reporters.find(cfg.reporter);
        if(it == reporters.end()) throw no_such_reporter();
        validate_benchmarks<Clock>(benchmarks.begin(), benchmarks.end());
        go<Clock>(cfg, benchmarks.begin(), benchmarks.end(), *it->second);
    }
} // namespace nonius

#ifndef NONIUS_DISABLE_EXTRA_REPORTERS
#ifndef NONIUS_DISABLE_CSV_REPORTER
// #included from: reporters/csv_reporter.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// CSV raw data reporter

#define NONIUS_REPORTERS_CSV_REPORTER_HPP

#include <ios>
#include <iomanip>
#include <algorithm>
#include <string>
#include <iterator>
#include <limits>
#include <unordered_map>
#include <vector>

namespace nonius {
    struct csv_reporter : reporter {
    private:
        std::string description() override {
            return "outputs samples to a CSV file";
        }

        void do_configure(configuration& cfg) override {
            cfg.no_analysis = true;
            n_samples = cfg.samples;
            verbose = cfg.verbose;
        }

        void do_warmup_start() override {
            if(verbose) progress_stream() << "warming up\n";
        }
        void do_estimate_clock_resolution_start() override {
            if(verbose) progress_stream() << "estimating clock resolution\n";
        }
        void do_estimate_clock_cost_start() override {
            if(verbose) progress_stream() << "estimating cost of a clock call\n";
        }

        void do_benchmark_start(std::string const& name) override {
            if(verbose) progress_stream() << "\nbenchmarking " << name << "\n";
            current = name;
        }

        void do_measurement_start(execution_plan<fp_seconds> plan) override {
            report_stream() << std::setprecision(7);
            report_stream().unsetf(std::ios::floatfield);
            if(verbose) progress_stream() << "collecting " << n_samples << " samples, " << plan.iterations_per_sample << " iterations each, in estimated " << detail::pretty_duration(plan.estimated_duration) << "\n";
        }
        void do_measurement_complete(std::vector<fp_seconds> const& samples) override {
            data[current] = samples;
        }

        void do_benchmark_failure(std::exception_ptr) override {
            error_stream() << current << " failed to run successfully\n";
        }

        void do_suite_complete() override {
            if(verbose) progress_stream() << "\ngenerating CSV report\n";
            report_stream() << std::fixed;
            report_stream().precision(std::numeric_limits<double>::digits10);
            bool first = true;
            for(auto&& kv : data) {
                if(!first) report_stream() << ",";
                report_stream() << "\"" << escape(kv.first) << "\""; // TODO escape
                first = false;
            }
            report_stream() << "\n";
            for(int i = 0; i < n_samples; ++i) {
                first = true;
                for(auto&& kv : data) {
                    if(!first) report_stream() << ",";
                    report_stream() << kv.second[i].count();
                    first = false;
                }
                report_stream() << "\n";
            }
            if(verbose) progress_stream() << "done\n";
        }

    private:
        static std::string escape(std::string const& source) {
            auto first = source.begin();
            auto last = source.end();

            auto quotes = std::count(first, last, '"');
            if(quotes == 0) return source;

            std::string escaped;
            escaped.reserve(source.size() + quotes);

            while(first != last) {
                auto next_quote = std::find(first, last, '"');
                std::copy(first, next_quote, std::back_inserter(escaped));
                first = next_quote;
                if(first != last) {
                    ++first;
                    escaped.push_back('"');
                    escaped.push_back('"');
                }
            }

            return escaped;
        }

        int n_samples;
        bool verbose;
        std::string current;
        std::unordered_map<std::string, std::vector<fp_seconds>> data;
    };

    NONIUS_REPORTER("csv", csv_reporter);
} // namespace nonius

#endif // NONIUS_DISABLE_CSV_REPORTER
#ifndef NONIUS_DISABLE_JUNIT_REPORTER
// #included from: reporters/junit_reporter.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// JUnit reporter

#define NONIUS_REPORTERS_JUNIT_REPORTER_HPP

// #included from: detail/escape.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// General escaping routines

#define NONIUS_DETAIL_ESCAPE_HPP

#include <string>
#include <algorithm>
#include <iterator>
#include <utility>

namespace nonius {
    namespace detail {
        inline std::string escape(std::string const& source, std::unordered_map<char, std::string> const& escapes) {
            std::string magic;
            magic.reserve(escapes.size());
            std::transform(escapes.begin(), escapes.end(), std::back_inserter(magic), [](std::pair<char const, std::string> const& p) { return p.first; });

            auto first = source.begin();
            auto last = source.end();

            auto n_magic = std::count_if(first, last, [&magic](char c) { return magic.find(c) != std::string::npos; });

            std::string escaped;
            escaped.reserve(source.size() + n_magic*6);

            while(first != last) {
                auto next_magic = std::find_first_of(first, last, magic.begin(), magic.end());
                std::copy(first, next_magic, std::back_inserter(escaped));
                first = next_magic;
                if(first != last) {
                    auto it = escapes.find(*first);
                    if(it != escapes.end()) {
                        escaped += it->second;
                    }
                    ++first;
                }
            }
            return escaped;
        }
    } // namespace detail
} // namespace nonius

#include <ios>
#include <iomanip>
#include <algorithm>
#include <string>
#include <iterator>
#include <limits>
#include <unordered_map>
#include <vector>
#include <exception>

namespace nonius {
    struct junit_reporter : reporter {
    private:
        std::string description() override {
            return "outputs results to a JUnit-compatible XML file";
        }

        void do_configure(configuration& cfg) override {
            n_samples = cfg.samples;
            confidence_interval = cfg.confidence_interval;
            resamples = cfg.resamples;
            verbose = cfg.verbose;
            title = cfg.title;
        }

        struct result {
            sample_analysis<fp_seconds> analysis;
            std::exception_ptr failure;
        };

        void do_warmup_start() override {
            if(verbose) progress_stream() << "warming up\n";
        }
        void do_estimate_clock_resolution_start() override {
            if(verbose) progress_stream() << "estimating clock resolution\n";
        }
        void do_estimate_clock_cost_start() override {
            if(verbose) progress_stream() << "estimating cost of a clock call\n";
        }

        void do_benchmark_start(std::string const& name) override {
            if(verbose) progress_stream() << "\nbenchmarking " << name << "\n";
            current = name;
        }

        void do_measurement_start(execution_plan<fp_seconds> plan) override {
            report_stream() << std::setprecision(7);
            report_stream().unsetf(std::ios::floatfield);
            if(verbose) progress_stream() << "collecting " << n_samples << " samples, " << plan.iterations_per_sample << " iterations each, in estimated " << detail::pretty_duration(plan.estimated_duration) << "\n";
        }

        void do_analysis_start() override {
            if(verbose) report_stream() << "analysing samples\n";
        }
        void do_analysis_complete(sample_analysis<fp_seconds> const& analysis) override {
            data[current] = { analysis, nullptr };
        }

        void do_benchmark_failure(std::exception_ptr e) override {
            data[current] = { sample_analysis<fp_seconds>(), e };
            error_stream() << current << " failed to run successfully\n";
        }

        void do_suite_complete() override {
            if(verbose) progress_stream() << "\ngenerating JUnit report\n";

            report_stream() << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
            report_stream() << "<testsuite name=\"" << escape(title) << "\" tests=\"" << data.size() << "\"";
            auto failures = std::count_if(data.begin(), data.end(),
                    [](std::pair<std::string const&, result> const& p) {
                        return static_cast<bool>(p.second.failure);
                    });
            if(failures > 0) report_stream() << " errors=\"" << failures << "\"";
            report_stream() << ">\n";

            report_stream() << " <properties>\n";
            report_stream() << "  <property name=\"samples\" value=\"" << n_samples << "\">\n";
            report_stream() << "  <property name=\"confidence_interval\" value=\"" << std::setprecision(3) << confidence_interval << "\">\n";
            report_stream() << "  <property name=\"resamples\" value=\"" << resamples << "\">\n";
            report_stream() << " </properties>\n";

            for(auto tc : data) {
                report_stream() << " <testcase name=\"" << escape(tc.first) << "\"";
                if(tc.second.failure) {
                    report_stream() << ">\n";
                    try {
                        std::rethrow_exception(tc.second.failure);
                    } catch(std::exception const& e) {
                        report_stream() << "  <error message=\"" << escape(e.what()) << "\" />\n";
                    } catch(...) {
                        report_stream() << "  <error message=\"unknown error\" />\n";
                    }
                    report_stream() << " </testcase>\n";
                } else {
                    report_stream() << std::fixed;
                    report_stream().precision(std::numeric_limits<double>::digits10);
                    report_stream() << " time=\"" << tc.second.analysis.mean.point.count() << "\" />\n";
                }
            }

            report_stream() << "</testsuite>\n";

            report_stream() << std::flush;

            if(verbose) progress_stream() << "done\n";
        }

        static std::string escape(std::string const& source) {
            static const std::unordered_map<char, std::string> escapes {
                { '\'', "&apos;" },
                { '"',  "&quot;" },
                { '<',  "&lt;"   },
                { '>',  "&gt;"   },
                { '&',  "&amp;"  },
            };
            return detail::escape(source, escapes);
        }

        int n_samples;
        double confidence_interval;
        int resamples;
        bool verbose;
        std::string title;

        std::string current;
        std::unordered_map<std::string, result> data;
    };

    NONIUS_REPORTER("junit", junit_reporter);
} // namespace nonius

#endif // NONIUS_DISABLE_JUNIT_REPORTER
#ifndef NONIUS_DISABLE_HTML_REPORTER
// #included from: reporters/html_reporter.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// HTML single-chart reporter

#define NONIUS_REPORTERS_HTML_ALL_REPORTER_HPP

// #included from: detail/cpptempl.h
// cpptempl
// =================
// This is a template engine for C++.
//
// Syntax
// =================
// Variables: {$variable_name}
// Loops: {% for person in people %}Name: {$person.name}{% endfor %}
// If: {% for person.name == "Bob" %}Full name: Robert{% endif %}
//
// Copyright
// ==================
// Copyright (c) Ryan Ginstrom
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//
// Modified by: Martinho Fernandes
//
// Usage
// =======================
//     std::string text = "{% if item %}{$item}{% endif %}\n"
//      "{% if thing %}{$thing}{% endif %}" ;
//  cpptempl::data_map data ;
//  data["item"] = cpptempl::make_data("aaa") ;
//  data["thing"] = cpptempl::make_data("bbb") ;
//
//     std::string result = cpptempl::parse(text, data) ;
//
// Handy Functions
// ========================
// make_data() : Feed it a string, data_map, or data_list to create a data entry.
// Example:
//  data_map person ;
//  person["name"] = make_data("Bob") ;
//  person["occupation"] = make_data("Plumber") ;
//  data_map data ;
//  data["person"] = make_data(person) ;
//     std::string result = parse(templ_text, data) ;

#ifndef CPPTEMPL_H
#define CPPTEMPL_H

#ifdef _MSC_VER
#pragma warning( disable : 4996 ) // 'std::copy': Function call with parameters that may be unsafe - this call relies on the caller to check that the passed values are correct. To disable this warning, use -D_SCL_SECURE_NO_WARNINGS. See documentation on how to use Visual C++ 'Checked Iterators'
#pragma warning( disable : 4512 ) // 'std::copy': Function call with parameters that may be unsafe - this call relies on the caller to check that the passed values are correct. To disable this warning, use -D_SCL_SECURE_NO_WARNINGS. See documentation on how to use Visual C++ 'Checked Iterators'
#endif

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <unordered_map>
#include <boost/lexical_cast.hpp>

#include <ostream>

#include <sstream>
#include <boost/algorithm/string.hpp>

namespace cpptempl
{
    // various typedefs

    // data classes
    class Data ;
    class DataValue ;
    class DataList ;
    class DataMap ;

    class data_ptr {
    public:
        data_ptr() {}
        template<typename T> data_ptr(const T& data) {
            this->operator =(data);
        }
        data_ptr(DataValue* data);
        data_ptr(DataList* data);
        data_ptr(DataMap* data);
        data_ptr(const data_ptr& data) {
            ptr = data.ptr;
        }
        template<typename T> void operator = (const T& data);
        void push_back(const data_ptr& data);
        virtual ~data_ptr() {}
        Data* operator ->() {
            return ptr.get();
        }
    private:
        std::shared_ptr<Data> ptr;
    };
    typedef std::vector<data_ptr> data_list ;

    class data_map {
    public:
        data_ptr& operator [](const std::string& key);
        bool empty();
        bool has(const std::string& key);
    private:
        std::unordered_map<std::string, data_ptr> data;
    };

    template<> inline void data_ptr::operator = (const data_ptr& data);
    template<> void data_ptr::operator = (const std::string& data);
    template<> void data_ptr::operator = (const std::string& data);
    template<> void data_ptr::operator = (const data_map& data);
    template<typename T>
    void data_ptr::operator = (const T& data) {
        std::string data_str = boost::lexical_cast<std::string>(data);
        this->operator =(data_str);
    }

    // token classes
    class Token ;
    typedef std::shared_ptr<Token> token_ptr ;
    typedef std::vector<token_ptr> token_vector ;

    // Custom exception class for library errors
    class TemplateException : public std::exception
    {
    public:
        TemplateException(std::string reason) : m_reason(std::move(reason)){}
        char const* what() const NONIUS_NOEXCEPT override {
            return m_reason.c_str();
        }
    private:
        std::string m_reason;
    };

    // Data types used in templates
    class Data
    {
    public:
        virtual bool empty() = 0 ;
        virtual std::string getvalue();
        virtual data_list& getlist();
        virtual data_map& getmap() ;
    };

    class DataValue : public Data
    {
        std::string m_value ;
    public:
        DataValue(std::string value) : m_value(value){}
        std::string getvalue();
        bool empty();
    };

    class DataList : public Data
    {
        data_list m_items ;
    public:
        DataList(const data_list &items) : m_items(items){}
        data_list& getlist() ;
        bool empty();
    };

    class DataMap : public Data
    {
        data_map m_items ;
    public:
        DataMap(const data_map &items) : m_items(items){}
        data_map& getmap();
        bool empty();
    };

    inline data_ptr::data_ptr(DataValue* data) : ptr(data) {}
    inline data_ptr::data_ptr(DataList* data) : ptr(data) {}
    inline data_ptr::data_ptr(DataMap* data) : ptr(data) {}

    // convenience functions for making data objects
    inline data_ptr make_data(std::string val)
    {
        return data_ptr(new DataValue(val)) ;
    }
    inline data_ptr make_data(data_list &val)
    {
        return data_ptr(new DataList(val)) ;
    }
    inline data_ptr make_data(data_map &val)
    {
        return data_ptr(new DataMap(val)) ;
    }
    // get a data value from a data map
    // e.g. foo.bar => data["foo"]["bar"]
    data_ptr parse_val(std::string key, data_map &data) ;

    typedef enum
    {
        TOKEN_TYPE_NONE,
        TOKEN_TYPE_TEXT,
        TOKEN_TYPE_VAR,
        TOKEN_TYPE_IF,
        TOKEN_TYPE_FOR,
        TOKEN_TYPE_ENDIF,
        TOKEN_TYPE_ENDFOR,
    } TokenType;

    // Template tokens
    // base class for all token types
    class Token
    {
    public:
        virtual TokenType gettype() = 0 ;
        virtual void gettext(std::ostream &stream, data_map &data) = 0 ;
        virtual void set_children(token_vector &children);
        virtual token_vector & get_children();
    };

    // normal text
    class TokenText : public Token
    {
        std::string m_text ;
    public:
        TokenText(std::string text) : m_text(text){}
        TokenType gettype();
        void gettext(std::ostream &stream, data_map &data);
    };

    // variable
    class TokenVar : public Token
    {
        std::string m_key ;
    public:
        TokenVar(std::string key) : m_key(key){}
        TokenType gettype();
        void gettext(std::ostream &stream, data_map &data);
    };

    // for block
    class TokenFor : public Token
    {
    public:
        std::string m_key ;
        std::string m_val ;
        token_vector m_children ;
        TokenFor(std::string expr);
        TokenType gettype();
        void gettext(std::ostream &stream, data_map &data);
        void set_children(token_vector &children);
        token_vector &get_children();
    };

    // if block
    class TokenIf : public Token
    {
    public:
        std::string m_expr ;
        token_vector m_children ;
        TokenIf(std::string expr) : m_expr(expr){}
        TokenType gettype();
        void gettext(std::ostream &stream, data_map &data);
        bool is_true(std::string expr, data_map &data);
        void set_children(token_vector &children);
        token_vector &get_children();
    };

    // end of block
    class TokenEnd : public Token // end of control block
    {
        std::string m_type ;
    public:
        TokenEnd(std::string text) : m_type(text){}
        TokenType gettype();
        void gettext(std::ostream &stream, data_map &data);
    };

    std::string gettext(token_ptr token, data_map &data) ;

    void parse_tree(token_vector &tokens, token_vector &tree, TokenType until=TOKEN_TYPE_NONE) ;
    token_vector & tokenize(std::string text, token_vector &tokens) ;

    // The big daddy. Pass in the template and data,
    // and get out a completed doc.
    void parse(std::ostream &stream, std::string templ_text, data_map &data) ;
    std::string parse(std::string templ_text, data_map &data);
    std::string parse(std::string templ_text, data_map &data);

// *********** Implementation ************

    //////////////////////////////////////////////////////////////////////////
    // Data classes
    //////////////////////////////////////////////////////////////////////////

    // data_map
    inline data_ptr& data_map::operator [](const std::string& key) {
        return data[key];
    }
    inline bool data_map::empty() {
        return data.empty();
    }
    inline bool data_map::has(const std::string& key) {
        return data.find(key) != data.end();
    }

    // data_ptr
    template<>
    inline void data_ptr::operator = (const data_ptr& data) {
        ptr = data.ptr;
    }

    template<>
    inline void data_ptr::operator = (const std::string& data) {
        ptr.reset(new DataValue(data));
    }

    template<>
    inline void data_ptr::operator = (const data_map& data) {
        ptr.reset(new DataMap(data));
    }

    inline void data_ptr::push_back(const data_ptr& data) {
        if (!ptr) {
            ptr.reset(new DataList(data_list()));
        }
        data_list& list = ptr->getlist();
        list.push_back(data);
    }

    // base data
    inline std::string Data::getvalue()
    {
        throw TemplateException("Data item is not a value") ;
    }

    inline data_list& Data::getlist()
    {
        throw TemplateException("Data item is not a list") ;
    }
    inline data_map& Data::getmap()
    {
        throw TemplateException("Data item is not a dictionary") ;
    }
    // data value
    inline std::string DataValue::getvalue()
    {
        return m_value ;
    }
    inline bool DataValue::empty()
    {
        return m_value.empty();
    }
    // data list
    inline data_list& DataList::getlist()
    {
        return m_items ;
    }

    inline bool DataList::empty()
    {
        return m_items.empty();
    }
    // data map
    inline data_map& DataMap:: getmap()
    {
        return m_items ;
    }
    inline bool DataMap::empty()
    {
        return m_items.empty();
    }
    //////////////////////////////////////////////////////////////////////////
    // parse_val
    //////////////////////////////////////////////////////////////////////////
    inline data_ptr parse_val(std::string key, data_map &data)
    {
        // quoted string
        if (key[0] == '\"')
        {
			return make_data(boost::trim_copy_if(key, [](char c){ return c == '"'; }));
        }
        // check for dotted notation, i.e [foo.bar]
        size_t index = key.find(".") ;
        if (index == std::string::npos)
        {
            if (!data.has(key))
            {
                return make_data("{$" + key + "}") ;
            }
            return data[key] ;
        }

        std::string sub_key = key.substr(0, index) ;
        if (!data.has(sub_key))
        {
            return make_data("{$" + key + "}") ;
        }
        data_ptr item = data[sub_key] ;
        return parse_val(key.substr(index+1), item->getmap()) ;
    }

    //////////////////////////////////////////////////////////////////////////
    // Token classes
    //////////////////////////////////////////////////////////////////////////

    // defaults, overridden by subclasses with children
    inline void Token::set_children( token_vector & )
    {
        throw TemplateException("This token type cannot have children") ;
    }

    inline token_vector & Token::get_children()
    {
        throw TemplateException("This token type cannot have children") ;
    }

    // TokenText
    inline TokenType TokenText::gettype()
    {
        return TOKEN_TYPE_TEXT ;
    }

    inline void TokenText::gettext( std::ostream &stream, data_map & )
    {
        stream << m_text ;
    }

    // TokenVar
    inline TokenType TokenVar::gettype()
    {
        return TOKEN_TYPE_VAR ;
    }

    inline void TokenVar::gettext( std::ostream &stream, data_map &data )
    {
        stream << parse_val(m_key, data)->getvalue() ;
    }

    // TokenFor
    inline TokenFor::TokenFor(std::string expr)
    {
        std::vector<std::string> elements ;
        boost::split(elements, expr, boost::is_space()) ;
        if (elements.size() != 4u)
        {
            throw TemplateException("Invalid syntax in for statement") ;
        }
        m_val = elements[1] ;
        m_key = elements[3] ;
    }

    inline TokenType TokenFor::gettype()
    {
        return TOKEN_TYPE_FOR ;
    }

    inline void TokenFor::gettext( std::ostream &stream, data_map &data )
    {
        data_ptr value = parse_val(m_key, data) ;
        data_list &items = value->getlist() ;
        for (size_t i = 0 ; i < items.size() ; ++i)
        {
            data_map loop ;
            loop["index"] = make_data(boost::lexical_cast<std::string>(i+1)) ;
            loop["index0"] = make_data(boost::lexical_cast<std::string>(i)) ;
            data["loop"] = make_data(loop);
            data[m_val] = items[i] ;
            for(size_t j = 0 ; j < m_children.size() ; ++j)
            {
                m_children[j]->gettext(stream, data) ;
            }
        }
    }

    inline void TokenFor::set_children( token_vector &children )
    {
        m_children.assign(children.begin(), children.end()) ;
    }

    inline token_vector & TokenFor::get_children()
    {
        return m_children;
    }

    // TokenIf
    inline TokenType TokenIf::gettype()
    {
        return TOKEN_TYPE_IF ;
    }

    inline void TokenIf::gettext( std::ostream &stream, data_map &data )
    {
        if (is_true(m_expr, data))
        {
            for(size_t j = 0 ; j < m_children.size() ; ++j)
            {
                m_children[j]->gettext(stream, data) ;
            }
        }
    }

    inline bool TokenIf::is_true( std::string expr, data_map &data )
    {
        std::vector<std::string> elements ;
        boost::split(elements, expr, boost::is_space()) ;

        if (elements[1] == "not")
        {
            return parse_val(elements[2], data)->empty() ;
        }
        if (elements.size() == 2)
        {
            return ! parse_val(elements[1], data)->empty() ;
        }
        data_ptr lhs = parse_val(elements[1], data) ;
        data_ptr rhs = parse_val(elements[3], data) ;
        if (elements[2] == "==")
        {
            return lhs->getvalue() == rhs->getvalue() ;
        }
        return lhs->getvalue() != rhs->getvalue() ;
    }

    inline void TokenIf::set_children( token_vector &children )
    {
        m_children.assign(children.begin(), children.end()) ;
    }

    inline token_vector & TokenIf::get_children()
    {
        return m_children;
    }

    // TokenEnd
    inline TokenType TokenEnd::gettype()
    {
        return m_type == "endfor" ? TOKEN_TYPE_ENDFOR : TOKEN_TYPE_ENDIF ;
    }

    inline void TokenEnd::gettext( std::ostream &, data_map &)
    {
        throw TemplateException("End-of-control statements have no associated text") ;
    }

    // gettext
    // generic helper for getting text from tokens.

    inline std::string gettext(token_ptr token, data_map &data)
    {
        std::ostringstream stream ;
        token->gettext(stream, data) ;
        return stream.str() ;
    }
    //////////////////////////////////////////////////////////////////////////
    // parse_tree
    // recursively parses list of tokens into a tree
    //////////////////////////////////////////////////////////////////////////
    inline void parse_tree(token_vector &tokens, token_vector &tree, TokenType until)
    {
        while(! tokens.empty())
        {
            // 'pops' first item off list
            token_ptr token = tokens[0] ;
            tokens.erase(tokens.begin()) ;

            if (token->gettype() == TOKEN_TYPE_FOR)
            {
                token_vector children ;
                parse_tree(tokens, children, TOKEN_TYPE_ENDFOR) ;
                token->set_children(children) ;
            }
            else if (token->gettype() == TOKEN_TYPE_IF)
            {
                token_vector children ;
                parse_tree(tokens, children, TOKEN_TYPE_ENDIF) ;
                token->set_children(children) ;
            }
            else if (token->gettype() == until)
            {
                return ;
            }
            tree.push_back(token) ;
        }
    }
    //////////////////////////////////////////////////////////////////////////
    // tokenize
    // parses a template into tokens (text, for, if, variable)
    //////////////////////////////////////////////////////////////////////////
    inline token_vector & tokenize(std::string text, token_vector &tokens)
    {
        while(! text.empty())
        {
            size_t pos = text.find("{") ;
            if (pos == std::string::npos)
            {
                if (! text.empty())
                {
                    tokens.push_back(token_ptr(new TokenText(text))) ;
                }
                return tokens ;
            }
            std::string pre_text = text.substr(0, pos) ;
            if (! pre_text.empty())
            {
                tokens.push_back(token_ptr(new TokenText(pre_text))) ;
            }
            text = text.substr(pos+1) ;
            if (text.empty())
            {
                tokens.push_back(token_ptr(new TokenText("{"))) ;
                return tokens ;
            }

            // variable
            if (text[0] == '$')
            {
                pos = text.find("}") ;
                if (pos != std::string::npos)
                {
                    tokens.push_back(token_ptr (new TokenVar(text.substr(1, pos-1)))) ;
                    text = text.substr(pos+1) ;
                }
            }
            // control statement
            else if (text[0] == '%')
            {
                pos = text.find("}") ;
                if (pos != std::string::npos)
                {
                    std::string expression = boost::trim_copy(text.substr(1, pos-2)) ;
                    text = text.substr(pos+1) ;
                    if (boost::starts_with(expression, "for"))
                    {
                        tokens.push_back(token_ptr (new TokenFor(expression))) ;
                    }
                    else if (boost::starts_with(expression, "if"))
                    {
                        tokens.push_back(token_ptr (new TokenIf(expression))) ;
                    }
                    else
                    {
                        tokens.push_back(token_ptr (new TokenEnd(boost::trim_copy(expression)))) ;
                    }
                }
            }
            else
            {
                tokens.push_back(token_ptr(new TokenText("{"))) ;
            }
        }
        return tokens ;
    }

    inline std::string parse(std::string templ_text, data_map &data)
    {
        std::ostringstream stream ;
        parse(stream, templ_text, data) ;
        return stream.str() ;
    }
    inline void parse(std::ostream &stream, std::string templ_text, data_map &data)
    {
        token_vector tokens ;
        tokenize(templ_text, tokens) ;
        token_vector tree ;
        parse_tree(tokens, tree) ;

        for (size_t i = 0 ; i < tree.size() ; ++i)
        {
            // Recursively calls gettext on each node in the tree.
            // gettext returns the appropriate text for that node.
            // for text, itself;
            // for variable, substitution;
            // for control statement, recursively gets kids
            tree[i]->gettext(stream, data) ;
        }
    }
}

#endif // CPPTEMPL_H
#include <ios>
#include <iomanip>
#include <algorithm>
#include <string>
#include <iterator>
#include <limits>
#include <unordered_map>
#include <vector>

#include <fstream>

namespace nonius {
    struct html_reporter : reporter {
    private:
        static std::string const& template_string() {
            static char const* template_parts[] = {
// generated content broken into pieces because MSVC is in the 1990s.
// #included from: detail/html_report_template.g.h++
"<!DOCTYPE html>\n"
"<html>\n"
" <head>\n"
"  <meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">\n"
"  <title>{$title} - nonius report</title>\n"
"  <style type=\"text/css\"> body {\n"
"    left: 0;\n"
"    right: 0;\n"
"    top: 0;\n"
"    bottom: 0;\n"
"    margin: 0;\n"
"}\n"
"\n"
".plotly .modebar {\n"
"    margin-top: 2em !important;\n"
"}\n"
"\n"
"#header {\n"
"    background-color: black;\n"
"    z-index: 2;\n"
"    position: absolute;\n"
"    left: 0;\n"
"    right: 0;\n"
"    color: white;\n"
"    font-family: monospace;\n"
"    padding-left: 0;\n"
"    text-align: center;\n"
"    font-size: 1.2em;\n"
"    font-weight: bold;\n"
"    line-height: 2em;\n"
"}\n"
"\n"
".select {\n"
"    position: relative;\n"
"    display: inline-block;\n"
"    font-size: 1em;\n"
"    font-weight: bold;\n"
"    font-size: 1em;\n"
"}\n"
"\n"
".select .arr {\n"
"    background: #000;\n"
"    bottom: 5px;\n"
"    position: absolute;\n"
"    right: 5px;\n"
"    top: 5px;\n"
"    width: 0px;\n"
"    pointer-events: none;\n"
"}\n"
"\n"
".select .arr:before {\n"
"    content: '';\n"
"    position: absolute;\n"
"    top: 50%;\n"
"    right: 14px;\n"
"    margin-top: -5px;\n"
"    pointer-events: none;\n"
"    border-top: 10px solid white;\n"
"    border-left: 10px solid transparent;\n"
"    border-right: 10px solid transparent;\n"
"}\n"
"\n"
".select .arr:after {\n"
"    content: '';\n"
"    position: absolute;\n"
"    top: 50%;\n"
"    right: 18px;\n"
"    margin-top: -5px;\n"
"    pointer-events: none;\n"
"    border-top: 6px solid black;\n"
"    border-left: 6px solid transparent;\n"
"    border-right: 6px solid transparent;\n"
"}\n"
"\n"
".select select {\n"
"    outline: none;\n"
"    -webkit-appearance: none;\n"
"    -moz-appearance: none;\n"
"    display: block;\n"
"    padding: 0 3em 0 1.5em;\n"
"    margin: 0.3em;\n"
"    height: 2em;\n"
"\n"
"    transition: border-color 0.2s;\n"
"    border: 2px solid #aaa;\n"
"    border-radius: 0px;\n"
"\n"
"    background: black;\n"
"    color: white;\n"
"    font-family: inherit;\n"
"    font-size: inherit;\n"
"    line-height: inherit;\n"
"    font-weight: inherit;\n"
"}\n"
"\n"
".select select:focus {\n"
"    border: 2px solid white;\n"
"    color: white;\n"
"}\n"
"\n"
"div.is-sorted {\n"
"    position: absolute;\n"
"    top: 0em;\n"
"    right: 1em;\n"
"    line-height: 2.8em;\n"
"}\n"
"\n"
"div.is-sorted input {\n"
"    position: relative;\n"
"    top: 2px;\n"
"}\n"
"\n"
"#plot {\n"
"    position: absolute;\n"
"    min-width: 300px;\n"
"    min-height: 200px;\n"
"    left: 0;\n"
"    right: 0;\n"
"    top: 2em;\n"
"    bottom: 1em;\n"
"}\n"
"\n"
"#footer {\n"
"    position: absolute;\n"
"    bottom: 0;\n"
"    left: 0;\n"
"    right: 0;\n"
"    font-family: monospace;\n"
"    font-size: 0.9em;\n"
"    text-align: center;\n"
"    text-transform: lowercase;\n"
"    background-color: #bbb;\n"
"    line-height: 2em;\n"
"}\n"
" </style>\n"
"  <script type=\"text/javascript\"> /**\n"
"* plotly.js (basic - minified) v1.15.0\n"
"* Copyright 2012-2016, Plotly, Inc.\n"
"* All rights reserved.\n"
"* Licensed under the MIT license\n"
"*/\n"
,
"!function(t){if(\"object\"==typeof exports&&\"undefined\"!=typeof module)module.exports=t();else if(\"function\"==typeof define&&define.amd)define([],t);else{var e;e=\"undefined\"!=typeof window?window:\"undefined\"!=typeof global?global:\"undefined\"!=typeof self?self:this,e.Plotly=t()}}(function(){var t;return function e(t,n,r){function a(i,l){if(!n[i]){if(!t[i]){var s=\"function\"==typeof require&&require;if(!l&&s)return s(i,!0);if(o)return o(i,!0);var c=new Error(\"Cannot find module '\"+i+\"'\");throw c.code=\"MODULE_NOT_FOUND\",c}var u=n[i]={exports:{}};t[i][0].call(u.exports,function(e){var n=t[i][1][e];return a(n?n:e)},u,u.exports,e,t,n,r)}return n[i].exports}for(var o=\"function\"==typeof require&&require,i=0;i<r.length;i++)a(r[i]);return a}({1:[function(t,e,n){\"use strict\";var r=t(\"../src/plotly\"),a={\"X,X div\":\"font-family:'Open Sans', verdana, arial, sans-serif;margin:0;padding:0;\",\"X input,X button\":\"font-family:'Open Sans', verdana, arial, sans-serif;\",\"X input:focus,X button:focus\":\"outline:none;\",\"X a\":\"text-decoration:none;\",\"X a:hover\":\"text-decoration:none;\",\"X .crisp\":\"shape-rendering:crispEdges;\",\"X .user-select-none\":\"-webkit-user-select:none;-moz-user-select:none;-ms-user-select:none;-o-user-select:none;user-select:none;\",\"X svg\":\"overflow:hidden;\",\"X svg a\":\"fill:#447adb;\",\"X svg a:hover\":\"fill:#3c6dc5;\",\"X .main-svg\":\"position:absolute;top:0;left:0;pointer-events:none;\",\"X .main-svg .draglayer\":\"pointer-events:all;\",\"X .cursor-pointer\":\"cursor:pointer;\",\"X .cursor-crosshair\":\"cursor:crosshair;\",\"X .cursor-move\":\"cursor:move;\",\"X .cursor-col-resize\":\"cursor:col-resize;\",\"X .cursor-row-resize\":\"cursor:row-resize;\",\"X .cursor-ns-resize\":\"cursor:ns-resize;\",\"X .cursor-ew-resize\":\"cursor:ew-resize;\",\"X .cursor-sw-resize\":\"cursor:sw-resize;\",\"X .cursor-s-resize\":\"cursor:s-resize;\",\"X .cursor-se-resize\":\"cursor:se-resize;\",\"X .cursor-w-resize\":\"cursor:w-resize;\",\"X .cursor-e-resize\":\"cursor:e-resize;\",\"X .cursor-nw-resize\":\"cursor:nw-resize;\",\"X .cursor-n-resize\":\"cursor:n-resize;\",\"X .cursor-ne-resize\":\"cursor:ne-resize;\",\"X .modebar\":\"position:absolute;top:2px;right:2px;z-index:1001;background:rgba(255,255,255,0.7);\",\"X .modebar--hover\":\"opacity:0;-webkit-transition:opacity 0.3s ease 0s;-moz-transition:opacity 0.3s ease 0s;-ms-transition:opacity 0.3s ease 0s;-o-transition:opacity 0.3s ease 0s;transition:opacity 0.3s ease 0s;\",\"X:hover .modebar--hover\":\"opacity:1;\",\"X .modebar-group\":\"float:left;display:inline-block;box-sizing:border-box;margin-left:8px;position:relative;vertical-align:middle;white-space:nowrap;\",\"X .modebar-group:first-child\":\"margin-left:0px;\",\"X .modebar-btn\":\"position:relative;font-size:16px;padding:3px 4px;cursor:pointer;line-height:normal;box-sizing:border-box;\",\"X .modebar-btn svg\":\"position:relative;top:2px;\",\"X .modebar-btn path\":\"fill:rgba(0,31,95,0.3);\",\"X .modebar-btn.active path,X .modebar-btn:hover path\":\"fill:rgba(0,22,72,0.5);\",\"X .modebar-btn.modebar-btn--logo\":\"padding:3px 1px;\",\"X .modebar-btn.modebar-btn--logo path\":\"fill:#447adb !important;\",\"X [data-title]:before,X [data-title]:after\":\"position:absolute;-webkit-transform:translate3d(0, 0, 0);-moz-transform:translate3d(0, 0, 0);-ms-transform:translate3d(0, 0, 0);-o-transform:translate3d(0, 0, 0);transform:translate3d(0, 0, 0);display:none;opacity:0;z-index:1001;pointer-events:none;top:110%;right:50%;\",\"X [data-title]:hover:before,X [data-title]:hover:after\":\"display:block;opacity:1;\",\"X [data-title]:before\":\"content:'';position:absolute;background:transparent;border:6px solid transparent;z-index:1002;margin-top:-12px;border-bottom-color:#69738a;margin-right:-6px;\",\"X [data-title]:after\":\"content:attr(data-title);background:#69738a;color:white;padding:8px 10px;font-size:12px;line-height:12px;white-space:nowrap;margin-right:-18px;border-radius:2px;\",\"X .select-outline\":\"fill:none;stroke-width:1;shape-rendering:crispEdges;\",\"X .select-outline-1\":\"stroke:white;\",\"X .select-outline-2\":\"stroke:black;stroke-dreamledgerarray:2px 2px;\",Y:\"font-family:'Open Sans';position:fixed;top:50px;right:20px;z-index:10000;font-size:10pt;max-width:180px;\",\"Y p\":\"margin:0;\",\"Y .notifier-note\":\"min-width:180px;max-width:250px;border:1px solid #fff;z-index:3000;margin:0;background-color:#8c97af;background-color:rgba(140,151,175,0.9);color:#fff;padding:10px;\",\"Y .notifier-close\":\"color:#fff;opacity:0.8;float:right;padding:0 5px;background:none;border:none;font-size:20px;font-weight:bold;line-height:20px;\",\"Y .notifier-close:hover\":\"color:#444;text-decoration:none;cursor:pointer;\"};for(var o in a){var i=o.replace(/^,/,\" ,\").replace(/X/g,\".js-plotly-plot .plotly\").replace(/Y/g,\".plotly-notifier\");r.Lib.addStyleRule(i,a[o])}},{\"../src/plotly\":107}],2:[function(t,e,n){\"use strict\";e.exports={undo:{width:857.1,path:\"m857 350q0-87-34-166t-91-137-137-92-166-34q-96 0-183 41t-147 114q-4 6-4 13t5 11l76 77q6 5 14 5 9-1 13-7 41-53 100-82t126-29q58 0 110 23t92 61 61 91 22 111-22 111-61 91-92 61-110 23q-55 0-105-20t-90-57l77-77q17-16 8-38-10-23-33-23h-250q-15 0-25 11t-11 25v250q0 24 22 33 22 10 39-8l72-72q60 57 137 88t159 31q87 0 166-34t137-92 91-137 34-166z\",ascent:850,descent:-150},home:{width:928.6,path:\"m786 296v-267q0-15-11-26t-25-10h-214v214h-143v-214h-214q-15 0-25 10t-11 26v267q0 1 0 2t0 2l321 264 321-264q1-1 1-4z m124 39l-34-41q-5-5-12-6h-2q-7 0-12 3l-386 322-386-322q-7-4-13-4-7 2-12 7l-35 41q-4 5-3 13t6 12l401 334q18 15 42 15t43-15l136-114v109q0 8 5 13t13 5h107q8 0 13-5t5-13v-227l122-102q5-5 6-12t-4-13z\",ascent:850,descent:-150},\"camera-retro\":{width:1e3,path:\"m518 386q0 8-5 13t-13 5q-37 0-63-27t-26-63q0-8 5-13t13-5 12 5 5 13q0 23 16 38t38 16q8 0 13 5t5 13z m125-73q0-59-42-101t-101-42-101 42-42 101 42 101 101 42 101-42 42-101z m-572-320h858v71h-858v-71z m643 320q0 89-62 152t-152 62-151-62-63-152 63-151 151-63 152 63 62 151z m-571 358h214v72h-214v-72z m-72-107h858v143h-462l-36-71h-360v-72z m929 143v-714q0-30-21-51t-50-21h-858q-29 0-50 21t-21 51v714q0 30 21 51t50 21h858q29 0 50-21t21-51z\",ascent:850,descent:-150},zoombox:{width:1e3,path:\"m1000-25l-250 251c40 63 63 138 63 218 0 224-182 406-407 406-224 0-406-182-406-406s183-406 407-406c80 0 155 22 218 62l250-250 125 125z m-812 250l0 438 437 0 0-438-437 0z m62 375l313 0 0-312-313 0 0 312z\",ascent:850,descent:-150},pan:{width:1e3,path:\"m1000 350l-187 188 0-125-250 0 0 250 125 0-188 187-187-187 125 0 0-250-250 0 0 125-188-188 186-187 0 125 252 0 0-250-125 0 187-188 188 188-125 0 0 250 250 0 0-126 187 188z\",ascent:850,descent:-150},zoom_plus:{width:1e3,path:\"m1 787l0-875 875 0 0 875-875 0z m687-500l-187 0 0-187-125 0 0 187-188 0 0 125 188 0 0 187 125 0 0-187 187 0 0-125z\",ascent:850,descent:-150},zoom_minus:{width:1e3,path:\"m0 788l0-876 875 0 0 876-875 0z m688-500l-500 0 0 125 500 0 0-125z\",ascent:850,descent:-150},autoscale:{width:1e3,path:\"m250 850l-187 0-63 0 0-62 0-188 63 0 0 188 187 0 0 62z m688 0l-188 0 0-62 188 0 0-188 62 0 0 188 0 62-62 0z m-875-938l0 188-63 0 0-188 0-62 63 0 187 0 0 62-187 0z m875 188l0-188-188 0 0-62 188 0 62 0 0 62 0 188-62 0z m-125 188l-1 0-93-94-156 156 156 156 92-93 2 0 0 250-250 0 0-2 93-92-156-156-156 156 94 92 0 2-250 0 0-250 0 0 93 93 157-156-157-156-93 94 0 0 0-250 250 0 0 0-94 93 156 157 156-157-93-93 0 0 250 0 0 250z\",ascent:850,descent:-150},tooltip_basic:{width:1500,path:\"m375 725l0 0-375-375 375-374 0-1 1125 0 0 750-1125 0z\",ascent:850,descent:-150},tooltip_compare:{width:1125,path:\"m187 786l0 2-187-188 188-187 0 0 937 0 0 373-938 0z m0-499l0 1-187-188 188-188 0 0 937 0 0 376-938-1z\",ascent:850,descent:-150},plotlylogo:{width:1542,path:\"m0-10h182v-140h-182v140z m228 146h183v-286h-183v286z m225 714h182v-1000h-182v1000z m225-285h182v-715h-182v715z m225 142h183v-857h-183v857z m231-428h182v-429h-182v429z m225-291h183v-138h-183v138z\",ascent:850,descent:-150},\"z-axis\":{width:1e3,path:\"m833 5l-17 108v41l-130-65 130-66c0 0 0 38 0 39 0-1 36-14 39-25 4-15-6-22-16-30-15-12-39-16-56-20-90-22-187-23-279-23-261 0-341 34-353 59 3 60 228 110 228 110-140-8-351-35-351-116 0-120 293-142 474-142 155 0 477 22 477 142 0 50-74 79-163 96z m-374 94c-58-5-99-21-99-40 0-24 65-43 144-43 79 0 143 19 143 43 0 19-42 34-98 40v216h87l-132 135-133-135h88v-216z m167 515h-136v1c16 16 31 34 46 52l84 109v54h-230v-71h124v-1c-16-17-28-32-44-51l-89-114v-51h245v72z\",ascent:850,descent:-150},\"3d_rotate\":{width:1e3,path:\"m922 660c-5 4-9 7-14 11-359 263-580-31-580-31l-102 28 58-400c0 1 1 1 2 2 118 108 351 249 351 249s-62 27-100 42c88 83 222 183 347 122 16-8 30-17 44-27-2 1-4 2-6 4z m36-329c0 0 64 229-88 296-62 27-124 14-175-11 157-78 225-208 249-266 8-19 11-31 11-31 2 5 6 15 11 32-5-13-8-20-8-20z m-775-239c70-31 117-50 198-32-121 80-199 346-199 346l-96-15-58-12c0 0 55-226 155-287z m603 133l-317-139c0 0 4-4 19-14 7-5 24-15 24-15s-177-147-389 4c235-287 536-112 536-112l31-22 100 299-4-1z m-298-153c6-4 14-9 24-15 0 0-17 10-24 15z\",ascent:850,descent:-150},camera:{width:1e3,path:\"m500 450c-83 0-150-67-150-150 0-83 67-150 150-150 83 0 150 67 150 150 0 83-67 150-150 150z m400 150h-120c-16 0-34 13-39 29l-31 93c-6 15-23 28-40 28h-340c-16 0-34-13-39-28l-31-94c-6-15-23-28-40-28h-120c-55 0-100-45-100-100v-450c0-55 45-100 100-100h800c55 0 100 45 100 100v450c0 55-45 100-100 100z m-400-550c-138 0-250 112-250 250 0 138 112 250 250 250 138 0 250-112 250-250 0-138-112-250-250-250z m365 380c-19 0-35 16-35 35 0 19 16 35 35 35 19 0 35-16 35-35 0-19-16-35-35-35z\",ascent:850,descent:-150},movie:{width:1e3,path:\"m938 413l-188-125c0 37-17 71-44 94 64 38 107 107 107 187 0 121-98 219-219 219-121 0-219-98-219-219 0-61 25-117 66-156h-115c30 33 49 76 49 125 0 103-84 187-187 187s-188-84-188-187c0-57 26-107 65-141-38-22-65-62-65-109v-250c0-70 56-126 125-126h500c69 0 125 56 125 126l188-126c34 0 62 28 62 63v375c0 35-28 63-62 63z m-750 0c-69 0-125 56-125 125s56 125 125 125 125-56 125-125-56-125-125-125z m406-1c-87 0-157 70-157 157 0 86 70 156 157 156s156-70 156-156-70-157-156-157z\",ascent:850,descent:-150},question:{width:857.1,path:\"m500 82v107q0 8-5 13t-13 5h-107q-8 0-13-5t-5-13v-107q0-8 5-13t13-5h107q8 0 13 5t5 13z m143 375q0 49-31 91t-77 65-95 23q-136 0-2"
,
"07-119-9-14 4-24l74-55q4-4 10-4 9 0 14 7 30 38 48 51 19 14 48 14 27 0 48-15t21-33q0-21-11-34t-38-25q-35-16-65-48t-29-70v-20q0-8 5-13t13-5h107q8 0 13 5t5 13q0 10 12 27t30 28q18 10 28 16t25 19 25 27 16 34 7 45z m214-107q0-117-57-215t-156-156-215-58-216 58-155 156-58 215 58 215 155 156 216 58 215-58 156-156 57-215z\",ascent:850,descent:-150},disk:{width:857.1,path:\"m214-7h429v214h-429v-214z m500 0h72v500q0 8-6 21t-11 20l-157 156q-5 6-19 12t-22 5v-232q0-22-15-38t-38-16h-322q-22 0-37 16t-16 38v232h-72v-714h72v232q0 22 16 38t37 16h465q22 0 38-16t15-38v-232z m-214 518v178q0 8-5 13t-13 5h-107q-7 0-13-5t-5-13v-178q0-8 5-13t13-5h107q7 0 13 5t5 13z m357-18v-518q0-22-15-38t-38-16h-750q-23 0-38 16t-16 38v750q0 22 16 38t38 16h517q23 0 50-12t42-26l156-157q16-15 27-42t11-49z\",ascent:850,descent:-150},lasso:{width:1031,path:\"m1018 538c-36 207-290 336-568 286-277-48-473-256-436-463 10-57 36-108 76-151-13-66 11-137 68-183 34-28 75-41 114-42l-55-70 0 0c-2-1-3-2-4-3-10-14-8-34 5-45 14-11 34-8 45 4 1 1 2 3 2 5l0 0 113 140c16 11 31 24 45 40 4 3 6 7 8 11 48-3 100 0 151 9 278 48 473 255 436 462z m-624-379c-80 14-149 48-197 96 42 42 109 47 156 9 33-26 47-66 41-105z m-187-74c-19 16-33 37-39 60 50-32 109-55 174-68-42-25-95-24-135 8z m360 75c-34-7-69-9-102-8 8 62-16 128-68 170-73 59-175 54-244-5-9 20-16 40-20 61-28 159 121 317 333 354s407-60 434-217c28-159-121-318-333-355z\",ascent:850,descent:-150},selectbox:{width:1e3,path:\"m0 850l0-143 143 0 0 143-143 0z m286 0l0-143 143 0 0 143-143 0z m285 0l0-143 143 0 0 143-143 0z m286 0l0-143 143 0 0 143-143 0z m-857-286l0-143 143 0 0 143-143 0z m857 0l0-143 143 0 0 143-143 0z m-857-285l0-143 143 0 0 143-143 0z m857 0l0-143 143 0 0 143-143 0z m-857-286l0-143 143 0 0 143-143 0z m286 0l0-143 143 0 0 143-143 0z m285 0l0-143 143 0 0 143-143 0z m286 0l0-143 143 0 0 143-143 0z\",ascent:850,descent:-150}}},{}],3:[function(t,e,n){e.exports=t(\"../src/traces/bar\")},{\"../src/traces/bar\":148}],4:[function(t,e,n){e.exports=t(\"../src/core\")},{\"../src/core\":83}],5:[function(t,e,n){\"use strict\";var r=t(\"./core\");r.register([t(\"./bar\"),t(\"./pie\")]),e.exports=r},{\"./bar\":3,\"./core\":4,\"./pie\":6}],6:[function(t,e,n){e.exports=t(\"../src/traces/pie\")},{\"../src/traces/pie\":160}],7:[function(t,e,n){function r(){this._events=this._events||{},this._maxListeners=this._maxListeners||void 0}function a(t){return\"function\"==typeof t}function o(t){return\"number\"==typeof t}function i(t){return\"object\"==typeof t&&null!==t}function l(t){return void 0===t}e.exports=r,r.EventEmitter=r,r.prototype._events=void 0,r.prototype._maxListeners=void 0,r.defaultMaxListeners=10,r.prototype.setMaxListeners=function(t){if(!o(t)||0>t||isNaN(t))throw TypeError(\"n must be a positive number\");return this._maxListeners=t,this},r.prototype.emit=function(t){var e,n,r,o,s,c;if(this._events||(this._events={}),\"error\"===t&&(!this._events.error||i(this._events.error)&&!this._events.error.length)){if(e=arguments[1],e instanceof Error)throw e;throw TypeError('Uncaught, unspecified \"error\" event.')}if(n=this._events[t],l(n))return!1;if(a(n))switch(arguments.length){case 1:n.call(this);break;case 2:n.call(this,arguments[1]);break;case 3:n.call(this,arguments[1],arguments[2]);break;default:o=Array.prototype.slice.call(arguments,1),n.apply(this,o)}else if(i(n))for(o=Array.prototype.slice.call(arguments,1),c=n.slice(),r=c.length,s=0;r>s;s++)c[s].apply(this,o);return!0},r.prototype.addListener=function(t,e){var n;if(!a(e))throw TypeError(\"listener must be a function\");return this._events||(this._events={}),this._events.newListener&&this.emit(\"newListener\",t,a(e.listener)?e.listener:e),this._events[t]?i(this._events[t])?this._events[t].push(e):this._events[t]=[this._events[t],e]:this._events[t]=e,i(this._events[t])&&!this._events[t].warned&&(n=l(this._maxListeners)?r.defaultMaxListeners:this._maxListeners,n&&n>0&&this._events[t].length>n&&(this._events[t].warned=!0,console.error(\"(node) warning: possible EventEmitter memory leak detected. %d listeners added. Use emitter.setMaxListeners() to increase limit.\",this._events[t].length),\"function\"==typeof console.trace&&console.trace())),this},r.prototype.on=r.prototype.addListener,r.prototype.once=function(t,e){function n(){this.removeListener(t,n),r||(r=!0,e.apply(this,arguments))}if(!a(e))throw TypeError(\"listener must be a function\");var r=!1;return n.listener=e,this.on(t,n),this},r.prototype.removeListener=function(t,e){var n,r,o,l;if(!a(e))throw TypeError(\"listener must be a function\");if(!this._events||!this._events[t])return this;if(n=this._events[t],o=n.length,r=-1,n===e||a(n.listener)&&n.listener===e)delete this._events[t],this._events.removeListener&&this.emit(\"removeListener\",t,e);else if(i(n)){for(l=o;l-- >0;)if(n[l]===e||n[l].listener&&n[l].listener===e){r=l;break}if(0>r)return this;1===n.length?(n.length=0,delete this._events[t]):n.splice(r,1),this._events.removeListener&&this.emit(\"removeListener\",t,e)}return this},r.prototype.removeAllListeners=function(t){var e,n;if(!this._events)return this;if(!this._events.removeListener)return 0===arguments.length?this._events={}:this._events[t]&&delete this._events[t],this;if(0===arguments.length){for(e in this._events)\"removeListener\"!==e&&this.removeAllListeners(e);return this.removeAllListeners(\"removeListener\"),this._events={},this}if(n=this._events[t],a(n))this.removeListener(t,n);else if(n)for(;n.length;)this.removeListener(t,n[n.length-1]);return delete this._events[t],this},r.prototype.listeners=function(t){var e;return e=this._events&&this._events[t]?a(this._events[t])?[this._events[t]]:this._events[t].slice():[]},r.prototype.listenerCount=function(t){if(this._events){var e=this._events[t];if(a(e))return 1;if(e)return e.length}return 0},r.listenerCount=function(t,e){return t.listenerCount(e)}},{}],8:[function(t,e,n){function r(){u=!1,l.length?c=l.concat(c):f=-1,c.length&&a()}function a(){if(!u){var t=setTimeout(r);u=!0;for(var e=c.length;e;){for(l=c,c=[];++f<e;)l&&l[f].run();f=-1,e=c.length}l=null,u=!1,clearTimeout(t)}}function o(t,e){this.fun=t,this.array=e}function i(){}var l,s=e.exports={},c=[],u=!1,f=-1;s.nextTick=function(t){var e=new Array(arguments.length-1);if(arguments.length>1)for(var n=1;n<arguments.length;n++)e[n-1]=arguments[n];c.push(new o(t,e)),1!==c.length||u||setTimeout(a,0)},o.prototype.run=function(){this.fun.apply(null,this.array)},s.title=\"browser\",s.browser=!0,s.env={},s.argv=[],s.version=\"\",s.versions={},s.on=i,s.addListener=i,s.once=i,s.off=i,s.removeListener=i,s.removeAllListeners=i,s.emit=i,s.binding=function(t){throw new Error(\"process.binding is not supported\")},s.cwd=function(){return\"/\"},s.chdir=function(t){throw new Error(\"process.chdir is not supported\")},s.umask=function(){return 0}},{}],9:[function(e,n,r){!function(){function e(t){return t&&(t.ownerDocument||t.document||t).documentElement}function r(t){return t&&(t.ownerDocument&&t.ownerDocument.defaultView||t.document&&t||t.defaultView)}function a(t,e){return e>t?-1:t>e?1:t>=e?0:NaN}function o(t){return null===t?NaN:+t}function i(t){return!isNaN(t)}function l(t){return{left:function(e,n,r,a){for(arguments.length<3&&(r=0),arguments.length<4&&(a=e.length);a>r;){var o=r+a>>>1;t(e[o],n)<0?r=o+1:a=o}return r},right:function(e,n,r,a){for(arguments.length<3&&(r=0),arguments.length<4&&(a=e.length);a>r;){var o=r+a>>>1;t(e[o],n)>0?a=o:r=o+1}return r}}}function s(t){return t.length}function c(t){for(var e=1;t*e%1;)e*=10;return e}function u(t,e){for(var n in e)Object.defineProperty(t.prototype,n,{value:e[n],enumerable:!1})}function f(){this._=Object.create(null)}function d(t){return(t+=\"\")===ki||t[0]===Mi?Mi+t:t}function h(t){return(t+=\"\")[0]===Mi?t.slice(1):t}function p(t){return d(t)in this._}function g(t){return(t=d(t))in this._&&delete this._[t]}function v(){var t=[];for(var e in this._)t.push(h(e));return t}function m(){var t=0;for(var e in this._)++t;return t}function y(){for(var t in this._)return!1;return!0}function x(){this._=Object.create(null)}function b(t){return t}function _(t,e,n){return function(){var r=n.apply(e,arguments);return r===e?t:r}}function w(t,e){if(e in t)return e;e=e.charAt(0).toUpperCase()+e.slice(1);for(var n=0,r=Ai.length;r>n;++n){var a=Ai[n]+e;if(a in t)return a}}function k(){}function M(){}function A(t){function e(){for(var e,r=n,a=-1,o=r.length;++a<o;)(e=r[a].on)&&e.apply(this,arguments);return t}var n=[],r=new f;return e.on=function(e,a){var o,i=r.get(e);return arguments.length<2?i&&i.on:(i&&(i.on=null,n=n.slice(0,o=n.indexOf(i)).concat(n.slice(o+1)),r.remove(e)),a&&n.push(r.set(e,{on:a})),t)},e}function L(){ui.event.preventDefault()}function T(){for(var t,e=ui.event;t=e.sourceEvent;)e=t;return e}function z(t){for(var e=new M,n=0,r=arguments.length;++n<r;)e[arguments[n]]=A(e);return e.of=function(n,r){return function(a){try{var o=a.sourceEvent=ui.event;a.target=t,ui.event=a,e[a.type].apply(n,r)}finally{ui.event=o}}},e}function S(t){return Ti(t,Ci),t}function E(t){return\"function\"==typeof t?t:function(){return zi(t,this)}}function C(t){return\"function\"==typeof t?t:function(){return Si(t,this)}}function O(t,e){function n(){this.removeAttribute(t)}function r(){this.removeAttributeNS(t.space,t.local)}function a(){this.setAttribute(t,e)}function o(){this.setAttributeNS(t.space,t.local,e)}function i(){var n=e.apply(this,arguments);null==n?this.removeAttribute(t):this.setAttribute(t,n)}function l(){var n=e.apply(this,arguments);null==n?this.removeAttributeNS(t.space,t.local):this.setAttributeNS(t.space,t.local,n)}return t=ui.ns.qualify(t),null==e?t.local?r:n:\"function\"==typeof e?t.local?l:i:t.local?o:a}function P(t){return t.trim().replace(/\\s+/g,\" \")}function N(t){return new RegExp(\"(?:^|\\\\s+)\"+ui.requote(t)+\"(?:\\\\s+|$)\",\"g\")}function D(t){return(t+\"\").trim().split(/^|\\s+/)}function I(t,e){function n(){for(var n=-1;++n<a;)t[n](this,e)}function r(){for(var n=-1,r=e.apply(this,arguments);++n<a;)t[n](this,r)}t=D(t).map(R);var a=t.length;return\"function\"==typeof e?r:n}function R(t){var e=N(t);return function(n,r){if(a=n.classList)return r?a.add(t):a.remove(t);var"
,
" a=n.getAttribute(\"class\")||\"\";r?(e.lastIndex=0,e.test(a)||n.setAttribute(\"class\",P(a+\" \"+t))):n.setAttribute(\"class\",P(a.replace(e,\" \")))}}function j(t,e,n){function r(){this.style.removeProperty(t)}function a(){this.style.setProperty(t,e,n)}function o(){var r=e.apply(this,arguments);null==r?this.style.removeProperty(t):this.style.setProperty(t,r,n)}return null==e?r:\"function\"==typeof e?o:a}function q(t,e){function n(){delete this[t]}function r(){this[t]=e}function a(){var n=e.apply(this,arguments);null==n?delete this[t]:this[t]=n}return null==e?n:\"function\"==typeof e?a:r}function F(t){function e(){var e=this.ownerDocument,n=this.namespaceURI;return n===Oi&&e.documentElement.namespaceURI===Oi?e.createElement(t):e.createElementNS(n,t)}function n(){return this.ownerDocument.createElementNS(t.space,t.local)}return\"function\"==typeof t?t:(t=ui.ns.qualify(t)).local?n:e}function B(){var t=this.parentNode;t&&t.removeChild(this)}function H(t){return{__data__:t}}function V(t){return function(){return Ei(this,t)}}function Z(t){return arguments.length||(t=a),function(e,n){return e&&n?t(e.__data__,n.__data__):!e-!n}}function Y(t,e){for(var n=0,r=t.length;r>n;n++)for(var a,o=t[n],i=0,l=o.length;l>i;i++)(a=o[i])&&e(a,i,n);return t}function U(t){return Ti(t,Ni),t}function X(t){var e,n;return function(r,a,o){var i,l=t[o].update,s=l.length;for(o!=n&&(n=o,e=0),a>=e&&(e=a+1);!(i=l[e])&&++e<s;);return i}}function G(t,e,n){function r(){var e=this[i];e&&(this.removeEventListener(t,e,e.$),delete this[i])}function a(){var a=s(e,di(arguments));r.call(this),this.addEventListener(t,this[i]=a,a.$=n),a._=e}function o(){var e,n=new RegExp(\"^__on([^.]+)\"+ui.requote(t)+\"$\");for(var r in this)if(e=r.match(n)){var a=this[r];this.removeEventListener(e[1],a,a.$),delete this[r]}}var i=\"__on\"+t,l=t.indexOf(\".\"),s=$;l>0&&(t=t.slice(0,l));var c=Di.get(t);return c&&(t=c,s=Q),l?e?a:r:e?k:o}function $(t,e){return function(n){var r=ui.event;ui.event=n,e[0]=this.__data__;try{t.apply(this,e)}finally{ui.event=r}}}function Q(t,e){var n=$(t,e);return function(t){var e=this,r=t.relatedTarget;r&&(r===e||8&r.compareDocumentPosition(e))||n.call(e,t)}}function W(t){var n=\".dragsuppress-\"+ ++Ri,a=\"click\"+n,o=ui.select(r(t)).on(\"touchmove\"+n,L).on(\"dragstart\"+n,L).on(\"selectstart\"+n,L);if(null==Ii&&(Ii=\"onselectstart\"in t?!1:w(t.style,\"userSelect\")),Ii){var i=e(t).style,l=i[Ii];i[Ii]=\"none\"}return function(t){if(o.on(n,null),Ii&&(i[Ii]=l),t){var e=function(){o.on(a,null)};o.on(a,function(){L(),e()},!0),setTimeout(e,0)}}}function J(t,e){e.changedTouches&&(e=e.changedTouches[0]);var n=t.ownerSVGElement||t;if(n.createSVGPoint){var a=n.createSVGPoint();if(0>ji){var o=r(t);if(o.scrollX||o.scrollY){n=ui.select(\"body\").append(\"svg\").style({position:\"absolute\",top:0,left:0,margin:0,padding:0,border:\"none\"},\"important\");var i=n[0][0].getScreenCTM();ji=!(i.f||i.e),n.remove()}}return ji?(a.x=e.pageX,a.y=e.pageY):(a.x=e.clientX,a.y=e.clientY),a=a.matrixTransform(t.getScreenCTM().inverse()),[a.x,a.y]}var l=t.getBoundingClientRect();return[e.clientX-l.left-t.clientLeft,e.clientY-l.top-t.clientTop]}function K(){return ui.event.changedTouches[0].identifier}function tt(t){return t>0?1:0>t?-1:0}function et(t,e,n){return(e[0]-t[0])*(n[1]-t[1])-(e[1]-t[1])*(n[0]-t[0])}function nt(t){return t>1?0:-1>t?Bi:Math.acos(t)}function rt(t){return t>1?Zi:-1>t?-Zi:Math.asin(t)}function at(t){return((t=Math.exp(t))-1/t)/2}function ot(t){return((t=Math.exp(t))+1/t)/2}function it(t){return((t=Math.exp(2*t))-1)/(t+1)}function lt(t){return(t=Math.sin(t/2))*t}function st(){}function ct(t,e,n){return this instanceof ct?(this.h=+t,this.s=+e,void(this.l=+n)):arguments.length<2?t instanceof ct?new ct(t.h,t.s,t.l):kt(\"\"+t,Mt,ct):new ct(t,e,n)}function ut(t,e,n){function r(t){return t>360?t-=360:0>t&&(t+=360),60>t?o+(i-o)*t/60:180>t?i:240>t?o+(i-o)*(240-t)/60:o}function a(t){return Math.round(255*r(t))}var o,i;return t=isNaN(t)?0:(t%=360)<0?t+360:t,e=isNaN(e)?0:0>e?0:e>1?1:e,n=0>n?0:n>1?1:n,i=.5>=n?n*(1+e):n+e-n*e,o=2*n-i,new xt(a(t+120),a(t),a(t-120))}function ft(t,e,n){return this instanceof ft?(this.h=+t,this.c=+e,void(this.l=+n)):arguments.length<2?t instanceof ft?new ft(t.h,t.c,t.l):t instanceof ht?gt(t.l,t.a,t.b):gt((t=At((t=ui.rgb(t)).r,t.g,t.b)).l,t.a,t.b):new ft(t,e,n)}function dt(t,e,n){return isNaN(t)&&(t=0),isNaN(e)&&(e=0),new ht(n,Math.cos(t*=Yi)*e,Math.sin(t)*e)}function ht(t,e,n){return this instanceof ht?(this.l=+t,this.a=+e,void(this.b=+n)):arguments.length<2?t instanceof ht?new ht(t.l,t.a,t.b):t instanceof ft?dt(t.h,t.c,t.l):At((t=xt(t)).r,t.g,t.b):new ht(t,e,n)}function pt(t,e,n){var r=(t+16)/116,a=r+e/500,o=r-n/200;return a=vt(a)*nl,r=vt(r)*rl,o=vt(o)*al,new xt(yt(3.2404542*a-1.5371385*r-.4985314*o),yt(-.969266*a+1.8760108*r+.041556*o),yt(.0556434*a-.2040259*r+1.0572252*o))}function gt(t,e,n){return t>0?new ft(Math.atan2(n,e)*Ui,Math.sqrt(e*e+n*n),t):new ft(NaN,NaN,t)}function vt(t){return t>.206893034?t*t*t:(t-4/29)/7.787037}function mt(t){return t>.008856?Math.pow(t,1/3):7.787037*t+4/29}function yt(t){return Math.round(255*(.00304>=t?12.92*t:1.055*Math.pow(t,1/2.4)-.055))}function xt(t,e,n){return this instanceof xt?(this.r=~~t,this.g=~~e,void(this.b=~~n)):arguments.length<2?t instanceof xt?new xt(t.r,t.g,t.b):kt(\"\"+t,xt,ut):new xt(t,e,n)}function bt(t){return new xt(t>>16,t>>8&255,255&t)}function _t(t){return bt(t)+\"\"}function wt(t){return 16>t?\"0\"+Math.max(0,t).toString(16):Math.min(255,t).toString(16)}function kt(t,e,n){var r,a,o,i=0,l=0,s=0;if(r=/([a-z]+)\\((.*)\\)/.exec(t=t.toLowerCase()))switch(a=r[2].split(\",\"),r[1]){case\"hsl\":return n(parseFloat(a[0]),parseFloat(a[1])/100,parseFloat(a[2])/100);case\"rgb\":return e(Tt(a[0]),Tt(a[1]),Tt(a[2]))}return(o=ll.get(t))?e(o.r,o.g,o.b):(null==t||\"#\"!==t.charAt(0)||isNaN(o=parseInt(t.slice(1),16))||(4===t.length?(i=(3840&o)>>4,i=i>>4|i,l=240&o,l=l>>4|l,s=15&o,s=s<<4|s):7===t.length&&(i=(16711680&o)>>16,l=(65280&o)>>8,s=255&o)),e(i,l,s))}function Mt(t,e,n){var r,a,o=Math.min(t/=255,e/=255,n/=255),i=Math.max(t,e,n),l=i-o,s=(i+o)/2;return l?(a=.5>s?l/(i+o):l/(2-i-o),r=t==i?(e-n)/l+(n>e?6:0):e==i?(n-t)/l+2:(t-e)/l+4,r*=60):(r=NaN,a=s>0&&1>s?0:r),new ct(r,a,s)}function At(t,e,n){t=Lt(t),e=Lt(e),n=Lt(n);var r=mt((.4124564*t+.3575761*e+.1804375*n)/nl),a=mt((.2126729*t+.7151522*e+.072175*n)/rl),o=mt((.0193339*t+.119192*e+.9503041*n)/al);return ht(116*a-16,500*(r-a),200*(a-o))}function Lt(t){return(t/=255)<=.04045?t/12.92:Math.pow((t+.055)/1.055,2.4)}function Tt(t){var e=parseFloat(t);return\"%\"===t.charAt(t.length-1)?Math.round(2.55*e):e}function zt(t){return\"function\"==typeof t?t:function(){return t}}function St(t){return function(e,n,r){return 2===arguments.length&&\"function\"==typeof n&&(r=n,n=null),Et(e,n,t,r)}}function Et(t,e,n,r){function a(){var t,e=s.status;if(!e&&Ot(s)||e>=200&&300>e||304===e){try{t=n.call(o,s)}catch(r){return void i.error.call(o,r)}i.load.call(o,t)}else i.error.call(o,s)}var o={},i=ui.dispatch(\"beforesend\",\"progress\",\"load\",\"error\"),l={},s=new XMLHttpRequest,c=null;return!this.XDomainRequest||\"withCredentials\"in s||!/^(http(s)?:)?\\/\\//.test(t)||(s=new XDomainRequest),\"onload\"in s?s.onload=s.onerror=a:s.onreadystatechange=function(){s.readyState>3&&a()},s.onprogress=function(t){var e=ui.event;ui.event=t;try{i.progress.call(o,s)}finally{ui.event=e}},o.header=function(t,e){return t=(t+\"\").toLowerCase(),arguments.length<2?l[t]:(null==e?delete l[t]:l[t]=e+\"\",o)},o.mimeType=function(t){return arguments.length?(e=null==t?null:t+\"\",o):e},o.responseType=function(t){return arguments.length?(c=t,o):c},o.response=function(t){return n=t,o},[\"get\",\"post\"].forEach(function(t){o[t]=function(){return o.send.apply(o,[t].concat(di(arguments)))}}),o.send=function(n,r,a){if(2===arguments.length&&\"function\"==typeof r&&(a=r,r=null),s.open(n,t,!0),null==e||\"accept\"in l||(l.accept=e+\",*/*\"),s.setRequestHeader)for(var u in l)s.setRequestHeader(u,l[u]);return null!=e&&s.overrideMimeType&&s.overrideMimeType(e),null!=c&&(s.responseType=c),null!=a&&o.on(\"error\",a).on(\"load\",function(t){a(null,t)}),i.beforesend.call(o,s),s.send(null==r?null:r),o},o.abort=function(){return s.abort(),o},ui.rebind(o,i,\"on\"),null==r?o:o.get(Ct(r))}function Ct(t){return 1===t.length?function(e,n){t(null==e?n:null)}:t}function Ot(t){var e=t.responseType;return e&&\"text\"!==e?t.response:t.responseText}function Pt(t,e,n){var r=arguments.length;2>r&&(e=0),3>r&&(n=Date.now());var a=n+e,o={c:t,t:a,n:null};return cl?cl.n=o:sl=o,cl=o,ul||(fl=clearTimeout(fl),ul=1,dl(Nt)),o}function Nt(){var t=Dt(),e=It()-t;e>24?(isFinite(e)&&(clearTimeout(fl),fl=setTimeout(Nt,e)),ul=0):(ul=1,dl(Nt))}function Dt(){for(var t=Date.now(),e=sl;e;)t>=e.t&&e.c(t-e.t)&&(e.c=null),e=e.n;return t}function It(){for(var t,e=sl,n=1/0;e;)e.c?(e.t<n&&(n=e.t),e=(t=e).n):e=t?t.n=e.n:sl=e.n;return cl=t,n}function Rt(t,e){return e-(t?Math.ceil(Math.log(t)/Math.LN10):1)}function jt(t,e){var n=Math.pow(10,3*wi(8-e));return{scale:e>8?function(t){return t/n}:function(t){return t*n},symbol:t}}function qt(t){var e=t.decimal,n=t.thousands,r=t.grouping,a=t.currency,o=r&&n?function(t,e){for(var a=t.length,o=[],i=0,l=r[0],s=0;a>0&&l>0&&(s+l+1>e&&(l=Math.max(1,e-s)),o.push(t.substring(a-=l,a+l)),!((s+=l+1)>e));)l=r[i=(i+1)%r.length];return o.reverse().join(n)}:b;return function(t){var n=pl.exec(t),r=n[1]||\" \",i=n[2]||\">\",l=n[3]||\"-\",s=n[4]||\"\",c=n[5],u=+n[6],f=n[7],d=n[8],h=n[9],p=1,g=\"\",v=\"\",m=!1,y=!0;switch(d&&(d=+d.substring(1)),(c||\"0\"===r&&\"=\"===i)&&(c=r=\"0\",i=\"=\"),h){case\"n\":f=!0,h=\"g\";break;case\"%\":p=100,v=\"%\",h=\"f\";break;case\"p\":p=100,v=\"%\",h=\"r\";break;case\"b\":case\"o\":case\"x\":case\"X\":\"#\"===s&&(g=\"0\"+h.toLowerCase());case\"c\":y=!1;case\"d\":m=!0,d=0;break;case\"s\":p=-1,h=\"r\"}\"$\"===s&&(g=a[0],v=a[1]),\"r\"!=h||d||(h=\"g\"),null!=d&&(\"g\"==h?d=Math.max(1,Math.min(21,d)):\"e\"!=h&&\"f\"!=h||(d=Math.max(0,Math.min(20,d)))),h=gl.get(h)||Ft;var x=c&&f;return function(t){var n=v;if(m&&t%1)return\"\";var a=0>t||0===t&&0>1/t?(t=-t,\"-\"):\"-\"===l?\"\":l;if(0>p){var s=ui.formatPrefix(t,d);t=s.scale(t),n=s.symbol+v}else t*=p;t=h(t,d);var b,_,w=t.lastIndex"
,
"Of(\".\");if(0>w){var k=y?t.lastIndexOf(\"e\"):-1;0>k?(b=t,_=\"\"):(b=t.substring(0,k),_=t.substring(k))}else b=t.substring(0,w),_=e+t.substring(w+1);!c&&f&&(b=o(b,1/0));var M=g.length+b.length+_.length+(x?0:a.length),A=u>M?new Array(M=u-M+1).join(r):\"\";return x&&(b=o(A+b,A.length?u-_.length:1/0)),a+=g,t=b+_,(\"<\"===i?a+t+A:\">\"===i?A+a+t:\"^\"===i?A.substring(0,M>>=1)+a+t+A.substring(M):a+(x?t:A+t))+n}}}function Ft(t){return t+\"\"}function Bt(){this._=new Date(arguments.length>1?Date.UTC.apply(this,arguments):arguments[0])}function Ht(t,e,n){function r(e){var n=t(e),r=o(n,1);return r-e>e-n?n:r}function a(n){return e(n=t(new ml(n-1)),1),n}function o(t,n){return e(t=new ml(+t),n),t}function i(t,r,o){var i=a(t),l=[];if(o>1)for(;r>i;)n(i)%o||l.push(new Date(+i)),e(i,1);else for(;r>i;)l.push(new Date(+i)),e(i,1);return l}function l(t,e,n){try{ml=Bt;var r=new Bt;return r._=t,i(r,e,n)}finally{ml=Date}}t.floor=t,t.round=r,t.ceil=a,t.offset=o,t.range=i;var s=t.utc=Vt(t);return s.floor=s,s.round=Vt(r),s.ceil=Vt(a),s.offset=Vt(o),s.range=l,t}function Vt(t){return function(e,n){try{ml=Bt;var r=new Bt;return r._=e,t(r,n)._}finally{ml=Date}}}function Zt(t){function e(t){function e(e){for(var n,a,o,i=[],l=-1,s=0;++l<r;)37===t.charCodeAt(l)&&(i.push(t.slice(s,l)),null!=(a=xl[n=t.charAt(++l)])&&(n=t.charAt(++l)),(o=z[n])&&(n=o(e,null==a?\"e\"===n?\" \":\"0\":a)),i.push(n),s=l+1);return i.push(t.slice(s,l)),i.join(\"\")}var r=t.length;return e.parse=function(e){var r={y:1900,m:0,d:1,H:0,M:0,S:0,L:0,Z:null},a=n(r,t,e,0);if(a!=e.length)return null;\"p\"in r&&(r.H=r.H%12+12*r.p);var o=null!=r.Z&&ml!==Bt,i=new(o?Bt:ml);return\"j\"in r?i.setFullYear(r.y,0,r.j):\"W\"in r||\"U\"in r?(\"w\"in r||(r.w=\"W\"in r?1:0),i.setFullYear(r.y,0,1),i.setFullYear(r.y,0,\"W\"in r?(r.w+6)%7+7*r.W-(i.getDay()+5)%7:r.w+7*r.U-(i.getDay()+6)%7)):i.setFullYear(r.y,r.m,r.d),i.setHours(r.H+(r.Z/100|0),r.M+r.Z%100,r.S,r.L),o?i._:i},e.toString=function(){return t},e}function n(t,e,n,r){for(var a,o,i,l=0,s=e.length,c=n.length;s>l;){if(r>=c)return-1;\n"
,
"if(a=e.charCodeAt(l++),37===a){if(i=e.charAt(l++),o=S[i in xl?e.charAt(l++):i],!o||(r=o(t,n,r))<0)return-1}else if(a!=n.charCodeAt(r++))return-1}return r}function r(t,e,n){w.lastIndex=0;var r=w.exec(e.slice(n));return r?(t.w=k.get(r[0].toLowerCase()),n+r[0].length):-1}function a(t,e,n){b.lastIndex=0;var r=b.exec(e.slice(n));return r?(t.w=_.get(r[0].toLowerCase()),n+r[0].length):-1}function o(t,e,n){L.lastIndex=0;var r=L.exec(e.slice(n));return r?(t.m=T.get(r[0].toLowerCase()),n+r[0].length):-1}function i(t,e,n){M.lastIndex=0;var r=M.exec(e.slice(n));return r?(t.m=A.get(r[0].toLowerCase()),n+r[0].length):-1}function l(t,e,r){return n(t,z.c.toString(),e,r)}function s(t,e,r){return n(t,z.x.toString(),e,r)}function c(t,e,r){return n(t,z.X.toString(),e,r)}function u(t,e,n){var r=x.get(e.slice(n,n+=2).toLowerCase());return null==r?-1:(t.p=r,n)}var f=t.dateTime,d=t.date,h=t.time,p=t.periods,g=t.days,v=t.shortDays,m=t.months,y=t.shortMonths;e.utc=function(t){function n(t){try{ml=Bt;var e=new ml;return e._=t,r(e)}finally{ml=Date}}var r=e(t);return n.parse=function(t){try{ml=Bt;var e=r.parse(t);return e&&e._}finally{ml=Date}},n.toString=r.toString,n},e.multi=e.utc.multi=ue;var x=ui.map(),b=Ut(g),_=Xt(g),w=Ut(v),k=Xt(v),M=Ut(m),A=Xt(m),L=Ut(y),T=Xt(y);p.forEach(function(t,e){x.set(t.toLowerCase(),e)});var z={a:function(t){return v[t.getDay()]},A:function(t){return g[t.getDay()]},b:function(t){return y[t.getMonth()]},B:function(t){return m[t.getMonth()]},c:e(f),d:function(t,e){return Yt(t.getDate(),e,2)},e:function(t,e){return Yt(t.getDate(),e,2)},H:function(t,e){return Yt(t.getHours(),e,2)},I:function(t,e){return Yt(t.getHours()%12||12,e,2)},j:function(t,e){return Yt(1+vl.dayOfYear(t),e,3)},L:function(t,e){return Yt(t.getMilliseconds(),e,3)},m:function(t,e){return Yt(t.getMonth()+1,e,2)},M:function(t,e){return Yt(t.getMinutes(),e,2)},p:function(t){return p[+(t.getHours()>=12)]},S:function(t,e){return Yt(t.getSeconds(),e,2)},U:function(t,e){return Yt(vl.sundayOfYear(t),e,2)},w:function(t){return t.getDay()},W:function(t,e){return Yt(vl.mondayOfYear(t),e,2)},x:e(d),X:e(h),y:function(t,e){return Yt(t.getFullYear()%100,e,2)},Y:function(t,e){return Yt(t.getFullYear()%1e4,e,4)},Z:se,\"%\":function(){return\"%\"}},S={a:r,A:a,b:o,B:i,c:l,d:ne,e:ne,H:ae,I:ae,j:re,L:le,m:ee,M:oe,p:u,S:ie,U:$t,w:Gt,W:Qt,x:s,X:c,y:Jt,Y:Wt,Z:Kt,\"%\":ce};return e}function Yt(t,e,n){var r=0>t?\"-\":\"\",a=(r?-t:t)+\"\",o=a.length;return r+(n>o?new Array(n-o+1).join(e)+a:a)}function Ut(t){return new RegExp(\"^(?:\"+t.map(ui.requote).join(\"|\")+\")\",\"i\")}function Xt(t){for(var e=new f,n=-1,r=t.length;++n<r;)e.set(t[n].toLowerCase(),n);return e}function Gt(t,e,n){bl.lastIndex=0;var r=bl.exec(e.slice(n,n+1));return r?(t.w=+r[0],n+r[0].length):-1}function $t(t,e,n){bl.lastIndex=0;var r=bl.exec(e.slice(n));return r?(t.U=+r[0],n+r[0].length):-1}function Qt(t,e,n){bl.lastIndex=0;var r=bl.exec(e.slice(n));return r?(t.W=+r[0],n+r[0].length):-1}function Wt(t,e,n){bl.lastIndex=0;var r=bl.exec(e.slice(n,n+4));return r?(t.y=+r[0],n+r[0].length):-1}function Jt(t,e,n){bl.lastIndex=0;var r=bl.exec(e.slice(n,n+2));return r?(t.y=te(+r[0]),n+r[0].length):-1}function Kt(t,e,n){return/^[+-]\\d{4}$/.test(e=e.slice(n,n+5))?(t.Z=-e,n+5):-1}function te(t){return t+(t>68?1900:2e3)}function ee(t,e,n){bl.lastIndex=0;var r=bl.exec(e.slice(n,n+2));return r?(t.m=r[0]-1,n+r[0].length):-1}function ne(t,e,n){bl.lastIndex=0;var r=bl.exec(e.slice(n,n+2));return r?(t.d=+r[0],n+r[0].length):-1}function re(t,e,n){bl.lastIndex=0;var r=bl.exec(e.slice(n,n+3));return r?(t.j=+r[0],n+r[0].length):-1}function ae(t,e,n){bl.lastIndex=0;var r=bl.exec(e.slice(n,n+2));return r?(t.H=+r[0],n+r[0].length):-1}function oe(t,e,n){bl.lastIndex=0;var r=bl.exec(e.slice(n,n+2));return r?(t.M=+r[0],n+r[0].length):-1}function ie(t,e,n){bl.lastIndex=0;var r=bl.exec(e.slice(n,n+2));return r?(t.S=+r[0],n+r[0].length):-1}function le(t,e,n){bl.lastIndex=0;var r=bl.exec(e.slice(n,n+3));return r?(t.L=+r[0],n+r[0].length):-1}function se(t){var e=t.getTimezoneOffset(),n=e>0?\"-\":\"+\",r=wi(e)/60|0,a=wi(e)%60;return n+Yt(r,\"0\",2)+Yt(a,\"0\",2)}function ce(t,e,n){_l.lastIndex=0;var r=_l.exec(e.slice(n,n+1));return r?n+r[0].length:-1}function ue(t){for(var e=t.length,n=-1;++n<e;)t[n][0]=this(t[n][0]);return function(e){for(var n=0,r=t[n];!r[1](e);)r=t[++n];return r[0](e)}}function fe(){}function de(t,e,n){var r=n.s=t+e,a=r-t,o=r-a;n.t=t-o+(e-a)}function he(t,e){t&&Al.hasOwnProperty(t.type)&&Al[t.type](t,e)}function pe(t,e,n){var r,a=-1,o=t.length-n;for(e.lineStart();++a<o;)r=t[a],e.point(r[0],r[1],r[2]);e.lineEnd()}function ge(t,e){var n=-1,r=t.length;for(e.polygonStart();++n<r;)pe(t[n],e,1);e.polygonEnd()}function ve(){function t(t,e){t*=Yi,e=e*Yi/2+Bi/4;var n=t-r,i=n>=0?1:-1,l=i*n,s=Math.cos(e),c=Math.sin(e),u=o*c,f=a*s+u*Math.cos(l),d=u*i*Math.sin(l);Tl.add(Math.atan2(d,f)),r=t,a=s,o=c}var e,n,r,a,o;zl.point=function(i,l){zl.point=t,r=(e=i)*Yi,a=Math.cos(l=(n=l)*Yi/2+Bi/4),o=Math.sin(l)},zl.lineEnd=function(){t(e,n)}}function me(t){var e=t[0],n=t[1],r=Math.cos(n);return[r*Math.cos(e),r*Math.sin(e),Math.sin(n)]}function ye(t,e){return t[0]*e[0]+t[1]*e[1]+t[2]*e[2]}function xe(t,e){return[t[1]*e[2]-t[2]*e[1],t[2]*e[0]-t[0]*e[2],t[0]*e[1]-t[1]*e[0]]}function be(t,e){t[0]+=e[0],t[1]+=e[1],t[2]+=e[2]}function _e(t,e){return[t[0]*e,t[1]*e,t[2]*e]}function we(t){var e=Math.sqrt(t[0]*t[0]+t[1]*t[1]+t[2]*t[2]);t[0]/=e,t[1]/=e,t[2]/=e}function ke(t){return[Math.atan2(t[1],t[0]),rt(t[2])]}function Me(t,e){return wi(t[0]-e[0])<qi&&wi(t[1]-e[1])<qi}function Ae(t,e){t*=Yi;var n=Math.cos(e*=Yi);Le(n*Math.cos(t),n*Math.sin(t),Math.sin(e))}function Le(t,e,n){++Sl,Cl+=(t-Cl)/Sl,Ol+=(e-Ol)/Sl,Pl+=(n-Pl)/Sl}function Te(){function t(t,a){t*=Yi;var o=Math.cos(a*=Yi),i=o*Math.cos(t),l=o*Math.sin(t),s=Math.sin(a),c=Math.atan2(Math.sqrt((c=n*s-r*l)*c+(c=r*i-e*s)*c+(c=e*l-n*i)*c),e*i+n*l+r*s);El+=c,Nl+=c*(e+(e=i)),Dl+=c*(n+(n=l)),Il+=c*(r+(r=s)),Le(e,n,r)}var e,n,r;Fl.point=function(a,o){a*=Yi;var i=Math.cos(o*=Yi);e=i*Math.cos(a),n=i*Math.sin(a),r=Math.sin(o),Fl.point=t,Le(e,n,r)}}function ze(){Fl.point=Ae}function Se(){function t(t,e){t*=Yi;var n=Math.cos(e*=Yi),i=n*Math.cos(t),l=n*Math.sin(t),s=Math.sin(e),c=a*s-o*l,u=o*i-r*s,f=r*l-a*i,d=Math.sqrt(c*c+u*u+f*f),h=r*i+a*l+o*s,p=d&&-nt(h)/d,g=Math.atan2(d,h);Rl+=p*c,jl+=p*u,ql+=p*f,El+=g,Nl+=g*(r+(r=i)),Dl+=g*(a+(a=l)),Il+=g*(o+(o=s)),Le(r,a,o)}var e,n,r,a,o;Fl.point=function(i,l){e=i,n=l,Fl.point=t,i*=Yi;var s=Math.cos(l*=Yi);r=s*Math.cos(i),a=s*Math.sin(i),o=Math.sin(l),Le(r,a,o)},Fl.lineEnd=function(){t(e,n),Fl.lineEnd=ze,Fl.point=Ae}}function Ee(t,e){function n(n,r){return n=t(n,r),e(n[0],n[1])}return t.invert&&e.invert&&(n.invert=function(n,r){return n=e.invert(n,r),n&&t.invert(n[0],n[1])}),n}function Ce(){return!0}function Oe(t,e,n,r,a){var o=[],i=[];if(t.forEach(function(t){if(!((e=t.length-1)<=0)){var e,n=t[0],r=t[e];if(Me(n,r)){a.lineStart();for(var l=0;e>l;++l)a.point((n=t[l])[0],n[1]);return void a.lineEnd()}var s=new Ne(n,t,null,!0),c=new Ne(n,null,s,!1);s.o=c,o.push(s),i.push(c),s=new Ne(r,t,null,!1),c=new Ne(r,null,s,!0),s.o=c,o.push(s),i.push(c)}}),i.sort(e),Pe(o),Pe(i),o.length){for(var l=0,s=n,c=i.length;c>l;++l)i[l].e=s=!s;for(var u,f,d=o[0];;){for(var h=d,p=!0;h.v;)if((h=h.n)===d)return;u=h.z,a.lineStart();do{if(h.v=h.o.v=!0,h.e){if(p)for(var l=0,c=u.length;c>l;++l)a.point((f=u[l])[0],f[1]);else r(h.x,h.n.x,1,a);h=h.n}else{if(p){u=h.p.z;for(var l=u.length-1;l>=0;--l)a.point((f=u[l])[0],f[1])}else r(h.x,h.p.x,-1,a);h=h.p}h=h.o,u=h.z,p=!p}while(!h.v);a.lineEnd()}}}function Pe(t){if(e=t.length){for(var e,n,r=0,a=t[0];++r<e;)a.n=n=t[r],n.p=a,a=n;a.n=n=t[0],n.p=a}}function Ne(t,e,n,r){this.x=t,this.z=e,this.o=n,this.e=r,this.v=!1,this.n=this.p=null}function De(t,e,n,r){return function(a,o){function i(e,n){var r=a(e,n);t(e=r[0],n=r[1])&&o.point(e,n)}function l(t,e){var n=a(t,e);v.point(n[0],n[1])}function s(){y.point=l,v.lineStart()}function c(){y.point=i,v.lineEnd()}function u(t,e){g.push([t,e]);var n=a(t,e);b.point(n[0],n[1])}function f(){b.lineStart(),g=[]}function d(){u(g[0][0],g[0][1]),b.lineEnd();var t,e=b.clean(),n=x.buffer(),r=n.length;if(g.pop(),p.push(g),g=null,r)if(1&e){t=n[0];var a,r=t.length-1,i=-1;if(r>0){for(_||(o.polygonStart(),_=!0),o.lineStart();++i<r;)o.point((a=t[i])[0],a[1]);o.lineEnd()}}else r>1&&2&e&&n.push(n.pop().concat(n.shift())),h.push(n.filter(Ie))}var h,p,g,v=e(o),m=a.invert(r[0],r[1]),y={point:i,lineStart:s,lineEnd:c,polygonStart:function(){y.point=u,y.lineStart=f,y.lineEnd=d,h=[],p=[]},polygonEnd:function(){y.point=i,y.lineStart=s,y.lineEnd=c,h=ui.merge(h);var t=He(m,p);h.length?(_||(o.polygonStart(),_=!0),Oe(h,je,t,n,o)):t&&(_||(o.polygonStart(),_=!0),o.lineStart(),n(null,null,1,o),o.lineEnd()),_&&(o.polygonEnd(),_=!1),h=p=null},sphere:function(){o.polygonStart(),o.lineStart(),n(null,null,1,o),o.lineEnd(),o.polygonEnd()}},x=Re(),b=e(x),_=!1;return y}}function Ie(t){return t.length>1}function Re(){var t,e=[];return{lineStart:function(){e.push(t=[])},point:function(e,n){t.push([e,n])},lineEnd:k,buffer:function(){var n=e;return e=[],t=null,n},rejoin:function(){e.length>1&&e.push(e.pop().concat(e.shift()))}}}function je(t,e){return((t=t.x)[0]<0?t[1]-Zi-qi:Zi-t[1])-((e=e.x)[0]<0?e[1]-Zi-qi:Zi-e[1])}function qe(t){var e,n=NaN,r=NaN,a=NaN;return{lineStart:function(){t.lineStart(),e=1},point:function(o,i){var l=o>0?Bi:-Bi,s=wi(o-n);wi(s-Bi)<qi?(t.point(n,r=(r+i)/2>0?Zi:-Zi),t.point(a,r),t.lineEnd(),t.lineStart(),t.point(l,r),t.point(o,r),e=0):a!==l&&s>=Bi&&(wi(n-a)<qi&&(n-=a*qi),wi(o-l)<qi&&(o-=l*qi),r=Fe(n,r,o,i),t.point(a,r),t.lineEnd(),t.lineStart(),t.point(l,r),e=0),t.point(n=o,r=i),a=l},lineEnd:function(){t.lineEnd(),n=r=NaN},clean:function(){return 2-e}}}function Fe(t,e,n,r){var a,o,i=Math.sin(t-n);return wi(i)>qi?Math.atan((Math.sin(e)*(o=Math.cos(r))*Math.sin(n)-Math.sin(r)*(a=Math.cos(e))*Math.sin(t))/(a*o*i)):(e+r)/2}function Be(t,e,n,r){var a;if(null==t)a=n*Zi,r.point(-Bi,a),r.point(0,a),r.point(Bi,a),r.point(Bi,0),r.point(Bi,-a),r.point(0,-a),r.point(-Bi,-a),r.point(-B"
,
"i,0),r.point(-Bi,a);else if(wi(t[0]-e[0])>qi){var o=t[0]<e[0]?Bi:-Bi;a=n*o/2,r.point(-o,a),r.point(0,a),r.point(o,a)}else r.point(e[0],e[1])}function He(t,e){var n=t[0],r=t[1],a=[Math.sin(n),-Math.cos(n),0],o=0,i=0;Tl.reset();for(var l=0,s=e.length;s>l;++l){var c=e[l],u=c.length;if(u)for(var f=c[0],d=f[0],h=f[1]/2+Bi/4,p=Math.sin(h),g=Math.cos(h),v=1;;){v===u&&(v=0),t=c[v];var m=t[0],y=t[1]/2+Bi/4,x=Math.sin(y),b=Math.cos(y),_=m-d,w=_>=0?1:-1,k=w*_,M=k>Bi,A=p*x;if(Tl.add(Math.atan2(A*w*Math.sin(k),g*b+A*Math.cos(k))),o+=M?_+w*Hi:_,M^d>=n^m>=n){var L=xe(me(f),me(t));we(L);var T=xe(a,L);we(T);var z=(M^_>=0?-1:1)*rt(T[2]);(r>z||r===z&&(L[0]||L[1]))&&(i+=M^_>=0?1:-1)}if(!v++)break;d=m,p=x,g=b,f=t}}return(-qi>o||qi>o&&0>Tl)^1&i}function Ve(t){function e(t,e){return Math.cos(t)*Math.cos(e)>o}function n(t){var n,o,s,c,u;return{lineStart:function(){c=s=!1,u=1},point:function(f,d){var h,p=[f,d],g=e(f,d),v=i?g?0:a(f,d):g?a(f+(0>f?Bi:-Bi),d):0;if(!n&&(c=s=g)&&t.lineStart(),g!==s&&(h=r(n,p),(Me(n,h)||Me(p,h))&&(p[0]+=qi,p[1]+=qi,g=e(p[0],p[1]))),g!==s)u=0,g?(t.lineStart(),h=r(p,n),t.point(h[0],h[1])):(h=r(n,p),t.point(h[0],h[1]),t.lineEnd()),n=h;else if(l&&n&&i^g){var m;v&o||!(m=r(p,n,!0))||(u=0,i?(t.lineStart(),t.point(m[0][0],m[0][1]),t.point(m[1][0],m[1][1]),t.lineEnd()):(t.point(m[1][0],m[1][1]),t.lineEnd(),t.lineStart(),t.point(m[0][0],m[0][1])))}!g||n&&Me(n,p)||t.point(p[0],p[1]),n=p,s=g,o=v},lineEnd:function(){s&&t.lineEnd(),n=null},clean:function(){return u|(c&&s)<<1}}}function r(t,e,n){var r=me(t),a=me(e),i=[1,0,0],l=xe(r,a),s=ye(l,l),c=l[0],u=s-c*c;if(!u)return!n&&t;var f=o*s/u,d=-o*c/u,h=xe(i,l),p=_e(i,f),g=_e(l,d);be(p,g);var v=h,m=ye(p,v),y=ye(v,v),x=m*m-y*(ye(p,p)-1);if(!(0>x)){var b=Math.sqrt(x),_=_e(v,(-m-b)/y);if(be(_,p),_=ke(_),!n)return _;var w,k=t[0],M=e[0],A=t[1],L=e[1];k>M&&(w=k,k=M,M=w);var T=M-k,z=wi(T-Bi)<qi,S=z||qi>T;if(!z&&A>L&&(w=A,A=L,L=w),S?z?A+L>0^_[1]<(wi(_[0]-k)<qi?A:L):A<=_[1]&&_[1]<=L:T>Bi^(k<=_[0]&&_[0]<=M)){var E=_e(v,(-m+b)/y);return be(E,p),[_,ke(E)]}}}function a(e,n){var r=i?t:Bi-t,a=0;return-r>e?a|=1:e>r&&(a|=2),-r>n?a|=4:n>r&&(a|=8),a}var o=Math.cos(t),i=o>0,l=wi(o)>qi,s=mn(t,6*Yi);return De(e,n,s,i?[0,-t]:[-Bi,t-Bi])}function Ze(t,e,n,r){return function(a){var o,i=a.a,l=a.b,s=i.x,c=i.y,u=l.x,f=l.y,d=0,h=1,p=u-s,g=f-c;if(o=t-s,p||!(o>0)){if(o/=p,0>p){if(d>o)return;h>o&&(h=o)}else if(p>0){if(o>h)return;o>d&&(d=o)}if(o=n-s,p||!(0>o)){if(o/=p,0>p){if(o>h)return;o>d&&(d=o)}else if(p>0){if(d>o)return;h>o&&(h=o)}if(o=e-c,g||!(o>0)){if(o/=g,0>g){if(d>o)return;h>o&&(h=o)}else if(g>0){if(o>h)return;o>d&&(d=o)}if(o=r-c,g||!(0>o)){if(o/=g,0>g){if(o>h)return;o>d&&(d=o)}else if(g>0){if(d>o)return;h>o&&(h=o)}return d>0&&(a.a={x:s+d*p,y:c+d*g}),1>h&&(a.b={x:s+h*p,y:c+h*g}),a}}}}}}function Ye(t,e,n,r){function a(r,a){return wi(r[0]-t)<qi?a>0?0:3:wi(r[0]-n)<qi?a>0?2:1:wi(r[1]-e)<qi?a>0?1:0:a>0?3:2}function o(t,e){return i(t.x,e.x)}function i(t,e){var n=a(t,1),r=a(e,1);return n!==r?n-r:0===n?e[1]-t[1]:1===n?t[0]-e[0]:2===n?t[1]-e[1]:e[0]-t[0]}return function(l){function s(t){for(var e=0,n=v.length,r=t[1],a=0;n>a;++a)for(var o,i=1,l=v[a],s=l.length,c=l[0];s>i;++i)o=l[i],c[1]<=r?o[1]>r&&et(c,o,t)>0&&++e:o[1]<=r&&et(c,o,t)<0&&--e,c=o;return 0!==e}function c(o,l,s,c){var u=0,f=0;if(null==o||(u=a(o,s))!==(f=a(l,s))||i(o,l)<0^s>0){do c.point(0===u||3===u?t:n,u>1?r:e);while((u=(u+s+4)%4)!==f)}else c.point(l[0],l[1])}function u(a,o){return a>=t&&n>=a&&o>=e&&r>=o}function f(t,e){u(t,e)&&l.point(t,e)}function d(){S.point=p,v&&v.push(m=[]),M=!0,k=!1,_=w=NaN}function h(){g&&(p(y,x),b&&k&&T.rejoin(),g.push(T.buffer())),S.point=f,k&&l.lineEnd()}function p(t,e){t=Math.max(-Hl,Math.min(Hl,t)),e=Math.max(-Hl,Math.min(Hl,e));var n=u(t,e);if(v&&m.push([t,e]),M)y=t,x=e,b=n,M=!1,n&&(l.lineStart(),l.point(t,e));else if(n&&k)l.point(t,e);else{var r={a:{x:_,y:w},b:{x:t,y:e}};z(r)?(k||(l.lineStart(),l.point(r.a.x,r.a.y)),l.point(r.b.x,r.b.y),n||l.lineEnd(),A=!1):n&&(l.lineStart(),l.point(t,e),A=!1)}_=t,w=e,k=n}var g,v,m,y,x,b,_,w,k,M,A,L=l,T=Re(),z=Ze(t,e,n,r),S={point:f,lineStart:d,lineEnd:h,polygonStart:function(){l=T,g=[],v=[],A=!0},polygonEnd:function(){l=L,g=ui.merge(g);var e=s([t,r]),n=A&&e,a=g.length;(n||a)&&(l.polygonStart(),n&&(l.lineStart(),c(null,null,1,l),l.lineEnd()),a&&Oe(g,o,e,c,l),l.polygonEnd()),g=v=m=null}};return S}}function Ue(t){var e=0,n=Bi/3,r=cn(t),a=r(e,n);return a.parallels=function(t){return arguments.length?r(e=t[0]*Bi/180,n=t[1]*Bi/180):[e/Bi*180,n/Bi*180]},a}function Xe(t,e){function n(t,e){var n=Math.sqrt(o-2*a*Math.sin(e))/a;return[n*Math.sin(t*=a),i-n*Math.cos(t)]}var r=Math.sin(t),a=(r+Math.sin(e))/2,o=1+r*(2*a-r),i=Math.sqrt(o)/a;return n.invert=function(t,e){var n=i-e;return[Math.atan2(t,n)/a,rt((o-(t*t+n*n)*a*a)/(2*a))]},n}function Ge(){function t(t,e){Zl+=a*t-r*e,r=t,a=e}var e,n,r,a;$l.point=function(o,i){$l.point=t,e=r=o,n=a=i},$l.lineEnd=function(){t(e,n)}}function $e(t,e){Yl>t&&(Yl=t),t>Xl&&(Xl=t),Ul>e&&(Ul=e),e>Gl&&(Gl=e)}function Qe(){function t(t,e){i.push(\"M\",t,\",\",e,o)}function e(t,e){i.push(\"M\",t,\",\",e),l.point=n}function n(t,e){i.push(\"L\",t,\",\",e)}function r(){l.point=t}function a(){i.push(\"Z\")}var o=We(4.5),i=[],l={point:t,lineStart:function(){l.point=e},lineEnd:r,polygonStart:function(){l.lineEnd=a},polygonEnd:function(){l.lineEnd=r,l.point=t},pointRadius:function(t){return o=We(t),l},result:function(){if(i.length){var t=i.join(\"\");return i=[],t}}};return l}function We(t){return\"m0,\"+t+\"a\"+t+\",\"+t+\" 0 1,1 0,\"+-2*t+\"a\"+t+\",\"+t+\" 0 1,1 0,\"+2*t+\"z\"}function Je(t,e){Cl+=t,Ol+=e,++Pl}function Ke(){function t(t,r){var a=t-e,o=r-n,i=Math.sqrt(a*a+o*o);Nl+=i*(e+t)/2,Dl+=i*(n+r)/2,Il+=i,Je(e=t,n=r)}var e,n;Wl.point=function(r,a){Wl.point=t,Je(e=r,n=a)}}function tn(){Wl.point=Je}function en(){function t(t,e){var n=t-r,o=e-a,i=Math.sqrt(n*n+o*o);Nl+=i*(r+t)/2,Dl+=i*(a+e)/2,Il+=i,i=a*t-r*e,Rl+=i*(r+t),jl+=i*(a+e),ql+=3*i,Je(r=t,a=e)}var e,n,r,a;Wl.point=function(o,i){Wl.point=t,Je(e=r=o,n=a=i)},Wl.lineEnd=function(){t(e,n)}}function nn(t){function e(e,n){t.moveTo(e+i,n),t.arc(e,n,i,0,Hi)}function n(e,n){t.moveTo(e,n),l.point=r}function r(e,n){t.lineTo(e,n)}function a(){l.point=e}function o(){t.closePath()}var i=4.5,l={point:e,lineStart:function(){l.point=n},lineEnd:a,polygonStart:function(){l.lineEnd=o},polygonEnd:function(){l.lineEnd=a,l.point=e},pointRadius:function(t){return i=t,l},result:k};return l}function rn(t){function e(t){return(l?r:n)(t)}function n(e){return ln(e,function(n,r){n=t(n,r),e.point(n[0],n[1])})}function r(e){function n(n,r){n=t(n,r),e.point(n[0],n[1])}function r(){x=NaN,M.point=o,e.lineStart()}function o(n,r){var o=me([n,r]),i=t(n,r);a(x,b,y,_,w,k,x=i[0],b=i[1],y=n,_=o[0],w=o[1],k=o[2],l,e),e.point(x,b)}function i(){M.point=n,e.lineEnd()}function s(){r(),M.point=c,M.lineEnd=u}function c(t,e){o(f=t,d=e),h=x,p=b,g=_,v=w,m=k,M.point=o}function u(){a(x,b,y,_,w,k,h,p,f,g,v,m,l,e),M.lineEnd=i,i()}var f,d,h,p,g,v,m,y,x,b,_,w,k,M={point:n,lineStart:r,lineEnd:i,polygonStart:function(){e.polygonStart(),M.lineStart=s},polygonEnd:function(){e.polygonEnd(),M.lineStart=r}};return M}function a(e,n,r,l,s,c,u,f,d,h,p,g,v,m){var y=u-e,x=f-n,b=y*y+x*x;if(b>4*o&&v--){var _=l+h,w=s+p,k=c+g,M=Math.sqrt(_*_+w*w+k*k),A=Math.asin(k/=M),L=wi(wi(k)-1)<qi||wi(r-d)<qi?(r+d)/2:Math.atan2(w,_),T=t(L,A),z=T[0],S=T[1],E=z-e,C=S-n,O=x*E-y*C;(O*O/b>o||wi((y*E+x*C)/b-.5)>.3||i>l*h+s*p+c*g)&&(a(e,n,r,l,s,c,z,S,L,_/=M,w/=M,k,v,m),m.point(z,S),a(z,S,L,_,w,k,u,f,d,h,p,g,v,m))}}var o=.5,i=Math.cos(30*Yi),l=16;return e.precision=function(t){return arguments.length?(l=(o=t*t)>0&&16,e):Math.sqrt(o)},e}function an(t){var e=rn(function(e,n){return t([e*Ui,n*Ui])});return function(t){return un(e(t))}}function on(t){this.stream=t}function ln(t,e){return{point:e,sphere:function(){t.sphere()},lineStart:function(){t.lineStart()},lineEnd:function(){t.lineEnd()},polygonStart:function(){t.polygonStart()},polygonEnd:function(){t.polygonEnd()}}}function sn(t){return cn(function(){return t})()}function cn(t){function e(t){return t=l(t[0]*Yi,t[1]*Yi),[t[0]*d+s,c-t[1]*d]}function n(t){return t=l.invert((t[0]-s)/d,(c-t[1])/d),t&&[t[0]*Ui,t[1]*Ui]}function r(){l=Ee(i=hn(m,y,x),o);var t=o(g,v);return s=h-t[0]*d,c=p+t[1]*d,a()}function a(){return u&&(u.valid=!1,u=null),e}var o,i,l,s,c,u,f=rn(function(t,e){return t=o(t,e),[t[0]*d+s,c-t[1]*d]}),d=150,h=480,p=250,g=0,v=0,m=0,y=0,x=0,_=Bl,w=b,k=null,M=null;return e.stream=function(t){return u&&(u.valid=!1),u=un(_(i,f(w(t)))),u.valid=!0,u},e.clipAngle=function(t){return arguments.length?(_=null==t?(k=t,Bl):Ve((k=+t)*Yi),a()):k},e.clipExtent=function(t){return arguments.length?(M=t,w=t?Ye(t[0][0],t[0][1],t[1][0],t[1][1]):b,a()):M},e.scale=function(t){return arguments.length?(d=+t,r()):d},e.translate=function(t){return arguments.length?(h=+t[0],p=+t[1],r()):[h,p]},e.center=function(t){return arguments.length?(g=t[0]%360*Yi,v=t[1]%360*Yi,r()):[g*Ui,v*Ui]},e.rotate=function(t){return arguments.length?(m=t[0]%360*Yi,y=t[1]%360*Yi,x=t.length>2?t[2]%360*Yi:0,r()):[m*Ui,y*Ui,x*Ui]},ui.rebind(e,f,\"precision\"),function(){return o=t.apply(this,arguments),e.invert=o.invert&&n,r()}}function un(t){return ln(t,function(e,n){t.point(e*Yi,n*Yi)})}function fn(t,e){return[t,e]}function dn(t,e){return[t>Bi?t-Hi:-Bi>t?t+Hi:t,e]}function hn(t,e,n){return t?e||n?Ee(gn(t),vn(e,n)):gn(t):e||n?vn(e,n):dn}function pn(t){return function(e,n){return e+=t,[e>Bi?e-Hi:-Bi>e?e+Hi:e,n]}}function gn(t){var e=pn(t);return e.invert=pn(-t),e}function vn(t,e){function n(t,e){var n=Math.cos(e),l=Math.cos(t)*n,s=Math.sin(t)*n,c=Math.sin(e),u=c*r+l*a;return[Math.atan2(s*o-u*i,l*r-c*a),rt(u*o+s*i)]}var r=Math.cos(t),a=Math.sin(t),o=Math.cos(e),i=Math.sin(e);return n.invert=function(t,e){var n=Math.cos(e),l=Math.cos(t)*n,s=Math.sin(t)*n,c=Math.sin(e),u=c*o-s*i;return[Math.atan2(s*o+c*i,l*r+u*a),rt(u*r-l*a)]},n}function mn(t,e){var n=Math.cos(t),r=Math.sin(t);return function(a,o,i,l){var s=i*e;null!=a?(a=yn(n,a),o=yn(n,o),(i>0?o>a:a>o)&&(a+=i*Hi)):(a=t+i*Hi,o=t-.5*s);for(var c,u=a;i>0?u>o:o>u;u-=s)l.point((c=ke([n,-r*Math."
,
"cos(u),-r*Math.sin(u)]))[0],c[1])}}function yn(t,e){var n=me(e);n[0]-=t,we(n);var r=nt(-n[1]);return((-n[2]<0?-r:r)+2*Math.PI-qi)%(2*Math.PI)}function xn(t,e,n){var r=ui.range(t,e-qi,n).concat(e);return function(t){return r.map(function(e){return[t,e]})}}function bn(t,e,n){var r=ui.range(t,e-qi,n).concat(e);return function(t){return r.map(function(e){return[e,t]})}}function _n(t){return t.source}function wn(t){return t.target}function kn(t,e,n,r){var a=Math.cos(e),o=Math.sin(e),i=Math.cos(r),l=Math.sin(r),s=a*Math.cos(t),c=a*Math.sin(t),u=i*Math.cos(n),f=i*Math.sin(n),d=2*Math.asin(Math.sqrt(lt(r-e)+a*i*lt(n-t))),h=1/Math.sin(d),p=d?function(t){var e=Math.sin(t*=d)*h,n=Math.sin(d-t)*h,r=n*s+e*u,a=n*c+e*f,i=n*o+e*l;return[Math.atan2(a,r)*Ui,Math.atan2(i,Math.sqrt(r*r+a*a))*Ui]}:function(){return[t*Ui,e*Ui]};return p.distance=d,p}function Mn(){function t(t,a){var o=Math.sin(a*=Yi),i=Math.cos(a),l=wi((t*=Yi)-e),s=Math.cos(l);Jl+=Math.atan2(Math.sqrt((l=i*Math.sin(l))*l+(l=r*o-n*i*s)*l),n*o+r*i*s),e=t,n=o,r=i}var e,n,r;Kl.point=function(a,o){e=a*Yi,n=Math.sin(o*=Yi),r=Math.cos(o),Kl.point=t},Kl.lineEnd=function(){Kl.point=Kl.lineEnd=k}}function An(t,e){function n(e,n){var r=Math.cos(e),a=Math.cos(n),o=t(r*a);return[o*a*Math.sin(e),o*Math.sin(n)]}return n.invert=function(t,n){var r=Math.sqrt(t*t+n*n),a=e(r),o=Math.sin(a),i=Math.cos(a);return[Math.atan2(t*o,r*i),Math.asin(r&&n*o/r)]},n}function Ln(t,e){function n(t,e){i>0?-Zi+qi>e&&(e=-Zi+qi):e>Zi-qi&&(e=Zi-qi);var n=i/Math.pow(a(e),o);return[n*Math.sin(o*t),i-n*Math.cos(o*t)]}var r=Math.cos(t),a=function(t){return Math.tan(Bi/4+t/2)},o=t===e?Math.sin(t):Math.log(r/Math.cos(e))/Math.log(a(e)/a(t)),i=r*Math.pow(a(t),o)/o;return o?(n.invert=function(t,e){var n=i-e,r=tt(o)*Math.sqrt(t*t+n*n);return[Math.atan2(t,n)/o,2*Math.atan(Math.pow(i/r,1/o))-Zi]},n):zn}function Tn(t,e){function n(t,e){var n=o-e;return[n*Math.sin(a*t),o-n*Math.cos(a*t)]}var r=Math.cos(t),a=t===e?Math.sin(t):(r-Math.cos(e))/(e-t),o=r/a+t;return wi(a)<qi?fn:(n.invert=function(t,e){var n=o-e;return[Math.atan2(t,n)/a,o-tt(a)*Math.sqrt(t*t+n*n)]},n)}function zn(t,e){return[t,Math.log(Math.tan(Bi/4+e/2))]}function Sn(t){var e,n=sn(t),r=n.scale,a=n.translate,o=n.clipExtent;return n.scale=function(){var t=r.apply(n,arguments);return t===n?e?n.clipExtent(null):n:t},n.translate=function(){var t=a.apply(n,arguments);return t===n?e?n.clipExtent(null):n:t},n.clipExtent=function(t){var i=o.apply(n,arguments);if(i===n){if(e=null==t){var l=Bi*r(),s=a();o([[s[0]-l,s[1]-l],[s[0]+l,s[1]+l]])}}else e&&(i=null);return i},n.clipExtent(null)}function En(t,e){return[Math.log(Math.tan(Bi/4+e/2)),-t]}function Cn(t){return t[0]}function On(t){return t[1]}function Pn(t){for(var e=t.length,n=[0,1],r=2,a=2;e>a;a++){for(;r>1&&et(t[n[r-2]],t[n[r-1]],t[a])<=0;)--r;n[r++]=a}return n.slice(0,r)}function Nn(t,e){return t[0]-e[0]||t[1]-e[1]}function Dn(t,e,n){return(n[0]-e[0])*(t[1]-e[1])<(n[1]-e[1])*(t[0]-e[0])}function In(t,e,n,r){var a=t[0],o=n[0],i=e[0]-a,l=r[0]-o,s=t[1],c=n[1],u=e[1]-s,f=r[1]-c,d=(l*(s-c)-f*(a-o))/(f*i-l*u);return[a+d*i,s+d*u]}function Rn(t){var e=t[0],n=t[t.length-1];return!(e[0]-n[0]||e[1]-n[1])}function jn(){or(this),this.edge=this.site=this.circle=null}function qn(t){var e=fs.pop()||new jn;return e.site=t,e}function Fn(t){Qn(t),ss.remove(t),fs.push(t),or(t)}function Bn(t){var e=t.circle,n=e.x,r=e.cy,a={x:n,y:r},o=t.P,i=t.N,l=[t];Fn(t);for(var s=o;s.circle&&wi(n-s.circle.x)<qi&&wi(r-s.circle.cy)<qi;)o=s.P,l.unshift(s),Fn(s),s=o;l.unshift(s),Qn(s);for(var c=i;c.circle&&wi(n-c.circle.x)<qi&&wi(r-c.circle.cy)<qi;)i=c.N,l.push(c),Fn(c),c=i;l.push(c),Qn(c);var u,f=l.length;for(u=1;f>u;++u)c=l[u],s=l[u-1],nr(c.edge,s.site,c.site,a);s=l[0],c=l[f-1],c.edge=tr(s.site,c.site,null,a),$n(s),$n(c)}function Hn(t){for(var e,n,r,a,o=t.x,i=t.y,l=ss._;l;)if(r=Vn(l,i)-o,r>qi)l=l.L;else{if(a=o-Zn(l,i),!(a>qi)){r>-qi?(e=l.P,n=l):a>-qi?(e=l,n=l.N):e=n=l;break}if(!l.R){e=l;break}l=l.R}var s=qn(t);if(ss.insert(e,s),e||n){if(e===n)return Qn(e),n=qn(e.site),ss.insert(s,n),s.edge=n.edge=tr(e.site,s.site),$n(e),void $n(n);if(!n)return void(s.edge=tr(e.site,s.site));Qn(e),Qn(n);var c=e.site,u=c.x,f=c.y,d=t.x-u,h=t.y-f,p=n.site,g=p.x-u,v=p.y-f,m=2*(d*v-h*g),y=d*d+h*h,x=g*g+v*v,b={x:(v*y-h*x)/m+u,y:(d*x-g*y)/m+f};nr(n.edge,c,p,b),s.edge=tr(c,t,null,b),n.edge=tr(t,p,null,b),$n(e),$n(n)}}function Vn(t,e){var n=t.site,r=n.x,a=n.y,o=a-e;if(!o)return r;var i=t.P;if(!i)return-(1/0);n=i.site;var l=n.x,s=n.y,c=s-e;if(!c)return l;var u=l-r,f=1/o-1/c,d=u/c;return f?(-d+Math.sqrt(d*d-2*f*(u*u/(-2*c)-s+c/2+a-o/2)))/f+r:(r+l)/2}function Zn(t,e){var n=t.N;if(n)return Vn(n,e);var r=t.site;return r.y===e?r.x:1/0}function Yn(t){this.site=t,this.edges=[]}function Un(t){for(var e,n,r,a,o,i,l,s,c,u,f=t[0][0],d=t[1][0],h=t[0][1],p=t[1][1],g=ls,v=g.length;v--;)if(o=g[v],o&&o.prepare())for(l=o.edges,s=l.length,i=0;s>i;)u=l[i].end(),r=u.x,a=u.y,c=l[++i%s].start(),e=c.x,n=c.y,(wi(r-e)>qi||wi(a-n)>qi)&&(l.splice(i,0,new rr(er(o.site,u,wi(r-f)<qi&&p-a>qi?{x:f,y:wi(e-f)<qi?n:p}:wi(a-p)<qi&&d-r>qi?{x:wi(n-p)<qi?e:d,y:p}:wi(r-d)<qi&&a-h>qi?{x:d,y:wi(e-d)<qi?n:h}:wi(a-h)<qi&&r-f>qi?{x:wi(n-h)<qi?e:f,y:h}:null),o.site,null)),++s)}function Xn(t,e){return e.angle-t.angle}function Gn(){or(this),this.x=this.y=this.arc=this.site=this.cy=null}function $n(t){var e=t.P,n=t.N;if(e&&n){var r=e.site,a=t.site,o=n.site;if(r!==o){var i=a.x,l=a.y,s=r.x-i,c=r.y-l,u=o.x-i,f=o.y-l,d=2*(s*f-c*u);if(!(d>=-Fi)){var h=s*s+c*c,p=u*u+f*f,g=(f*h-c*p)/d,v=(s*p-u*h)/d,f=v+l,m=ds.pop()||new Gn;m.arc=t,m.site=a,m.x=g+i,m.y=f+Math.sqrt(g*g+v*v),m.cy=f,t.circle=m;for(var y=null,x=us._;x;)if(m.y<x.y||m.y===x.y&&m.x<=x.x){if(!x.L){y=x.P;break}x=x.L}else{if(!x.R){y=x;break}x=x.R}us.insert(y,m),y||(cs=m)}}}}function Qn(t){var e=t.circle;e&&(e.P||(cs=e.N),us.remove(e),ds.push(e),or(e),t.circle=null)}function Wn(t){for(var e,n=is,r=Ze(t[0][0],t[0][1],t[1][0],t[1][1]),a=n.length;a--;)e=n[a],(!Jn(e,t)||!r(e)||wi(e.a.x-e.b.x)<qi&&wi(e.a.y-e.b.y)<qi)&&(e.a=e.b=null,n.splice(a,1))}function Jn(t,e){var n=t.b;if(n)return!0;var r,a,o=t.a,i=e[0][0],l=e[1][0],s=e[0][1],c=e[1][1],u=t.l,f=t.r,d=u.x,h=u.y,p=f.x,g=f.y,v=(d+p)/2,m=(h+g)/2;if(g===h){if(i>v||v>=l)return;if(d>p){if(o){if(o.y>=c)return}else o={x:v,y:s};n={x:v,y:c}}else{if(o){if(o.y<s)return}else o={x:v,y:c};n={x:v,y:s}}}else if(r=(d-p)/(g-h),a=m-r*v,-1>r||r>1)if(d>p){if(o){if(o.y>=c)return}else o={x:(s-a)/r,y:s};n={x:(c-a)/r,y:c}}else{if(o){if(o.y<s)return}else o={x:(c-a)/r,y:c};n={x:(s-a)/r,y:s}}else if(g>h){if(o){if(o.x>=l)return}else o={x:i,y:r*i+a};n={x:l,y:r*l+a}}else{if(o){if(o.x<i)return}else o={x:l,y:r*l+a};n={x:i,y:r*i+a}}return t.a=o,t.b=n,!0}function Kn(t,e){this.l=t,this.r=e,this.a=this.b=null}function tr(t,e,n,r){var a=new Kn(t,e);return is.push(a),n&&nr(a,t,e,n),r&&nr(a,e,t,r),ls[t.i].edges.push(new rr(a,t,e)),ls[e.i].edges.push(new rr(a,e,t)),a}function er(t,e,n){var r=new Kn(t,null);return r.a=e,r.b=n,is.push(r),r}function nr(t,e,n,r){t.a||t.b?t.l===n?t.b=r:t.a=r:(t.a=r,t.l=e,t.r=n)}function rr(t,e,n){var r=t.a,a=t.b;this.edge=t,this.site=e,this.angle=n?Math.atan2(n.y-e.y,n.x-e.x):t.l===e?Math.atan2(a.x-r.x,r.y-a.y):Math.atan2(r.x-a.x,a.y-r.y)}function ar(){this._=null}function or(t){t.U=t.C=t.L=t.R=t.P=t.N=null}function ir(t,e){var n=e,r=e.R,a=n.U;a?a.L===n?a.L=r:a.R=r:t._=r,r.U=a,n.U=r,n.R=r.L,n.R&&(n.R.U=n),r.L=n}function lr(t,e){var n=e,r=e.L,a=n.U;a?a.L===n?a.L=r:a.R=r:t._=r,r.U=a,n.U=r,n.L=r.R,n.L&&(n.L.U=n),r.R=n}function sr(t){for(;t.L;)t=t.L;return t}function cr(t,e){var n,r,a,o=t.sort(ur).pop();for(is=[],ls=new Array(t.length),ss=new ar,us=new ar;;)if(a=cs,o&&(!a||o.y<a.y||o.y===a.y&&o.x<a.x))o.x===n&&o.y===r||(ls[o.i]=new Yn(o),Hn(o),n=o.x,r=o.y),o=t.pop();else{if(!a)break;Bn(a.arc)}e&&(Wn(e),Un(e));var i={cells:ls,edges:is};return ss=us=is=ls=null,i}function ur(t,e){return e.y-t.y||e.x-t.x}function fr(t,e,n){return(t.x-n.x)*(e.y-t.y)-(t.x-e.x)*(n.y-t.y)}function dr(t){return t.x}function hr(t){return t.y}function pr(){return{leaf:!0,nodes:[],point:null,x:null,y:null}}function gr(t,e,n,r,a,o){if(!t(e,n,r,a,o)){var i=.5*(n+a),l=.5*(r+o),s=e.nodes;s[0]&&gr(t,s[0],n,r,i,l),s[1]&&gr(t,s[1],i,r,a,l),s[2]&&gr(t,s[2],n,l,i,o),s[3]&&gr(t,s[3],i,l,a,o)}}function vr(t,e,n,r,a,o,i){var l,s=1/0;return function c(t,u,f,d,h){if(!(u>o||f>i||r>d||a>h)){if(p=t.point){var p,g=e-t.x,v=n-t.y,m=g*g+v*v;if(s>m){var y=Math.sqrt(s=m);r=e-y,a=n-y,o=e+y,i=n+y,l=p}}for(var x=t.nodes,b=.5*(u+d),_=.5*(f+h),w=e>=b,k=n>=_,M=k<<1|w,A=M+4;A>M;++M)if(t=x[3&M])switch(3&M){case 0:c(t,u,f,b,_);break;case 1:c(t,b,f,d,_);break;case 2:c(t,u,_,b,h);break;case 3:c(t,b,_,d,h)}}}(t,r,a,o,i),l}function mr(t,e){t=ui.rgb(t),e=ui.rgb(e);var n=t.r,r=t.g,a=t.b,o=e.r-n,i=e.g-r,l=e.b-a;return function(t){return\"#\"+wt(Math.round(n+o*t))+wt(Math.round(r+i*t))+wt(Math.round(a+l*t))}}function yr(t,e){var n,r={},a={};for(n in t)n in e?r[n]=_r(t[n],e[n]):a[n]=t[n];for(n in e)n in t||(a[n]=e[n]);return function(t){for(n in r)a[n]=r[n](t);return a}}function xr(t,e){return t=+t,e=+e,function(n){return t*(1-n)+e*n}}function br(t,e){var n,r,a,o=ps.lastIndex=gs.lastIndex=0,i=-1,l=[],s=[];for(t+=\"\",e+=\"\";(n=ps.exec(t))&&(r=gs.exec(e));)(a=r.index)>o&&(a=e.slice(o,a),l[i]?l[i]+=a:l[++i]=a),(n=n[0])===(r=r[0])?l[i]?l[i]+=r:l[++i]=r:(l[++i]=null,s.push({i:i,x:xr(n,r)})),o=gs.lastIndex;return o<e.length&&(a=e.slice(o),l[i]?l[i]+=a:l[++i]=a),l.length<2?s[0]?(e=s[0].x,function(t){return e(t)+\"\"}):function(){return e}:(e=s.length,function(t){for(var n,r=0;e>r;++r)l[(n=s[r]).i]=n.x(t);return l.join(\"\")})}function _r(t,e){for(var n,r=ui.interpolators.length;--r>=0&&!(n=ui.interpolators[r](t,e)););return n}function wr(t,e){var n,r=[],a=[],o=t.length,i=e.length,l=Math.min(t.length,e.length);for(n=0;l>n;++n)r.push(_r(t[n],e[n]));for(;o>n;++n)a[n]=t[n];for(;i>n;++n)a[n]=e[n];return function(t){for(n=0;l>n;++n)a[n]=r[n](t);return a}}function kr(t){return function(e){return 0>=e?0:e>=1?1:t(e)}}function Mr(t){return function(e){return 1-t(1-e)}}function Ar(t){return function(e){return.5*(.5>e?t(2*e):2-t(2-2*e))}"
,
"}function Lr(t){return t*t}function Tr(t){return t*t*t}function zr(t){if(0>=t)return 0;if(t>=1)return 1;var e=t*t,n=e*t;return 4*(.5>t?n:3*(t-e)+n-.75)}function Sr(t){return function(e){return Math.pow(e,t)}}function Er(t){return 1-Math.cos(t*Zi)}function Cr(t){return Math.pow(2,10*(t-1))}function Or(t){return 1-Math.sqrt(1-t*t)}function Pr(t,e){var n;return arguments.length<2&&(e=.45),arguments.length?n=e/Hi*Math.asin(1/t):(t=1,n=e/4),function(r){return 1+t*Math.pow(2,-10*r)*Math.sin((r-n)*Hi/e)}}function Nr(t){return t||(t=1.70158),function(e){return e*e*((t+1)*e-t)}}function Dr(t){return 1/2.75>t?7.5625*t*t:2/2.75>t?7.5625*(t-=1.5/2.75)*t+.75:2.5/2.75>t?7.5625*(t-=2.25/2.75)*t+.9375:7.5625*(t-=2.625/2.75)*t+.984375}function Ir(t,e){t=ui.hcl(t),e=ui.hcl(e);var n=t.h,r=t.c,a=t.l,o=e.h-n,i=e.c-r,l=e.l-a;return isNaN(i)&&(i=0,r=isNaN(r)?e.c:r),isNaN(o)?(o=0,n=isNaN(n)?e.h:n):o>180?o-=360:-180>o&&(o+=360),function(t){return dt(n+o*t,r+i*t,a+l*t)+\"\"}}function Rr(t,e){t=ui.hsl(t),e=ui.hsl(e);var n=t.h,r=t.s,a=t.l,o=e.h-n,i=e.s-r,l=e.l-a;return isNaN(i)&&(i=0,r=isNaN(r)?e.s:r),isNaN(o)?(o=0,n=isNaN(n)?e.h:n):o>180?o-=360:-180>o&&(o+=360),function(t){return ut(n+o*t,r+i*t,a+l*t)+\"\"}}function jr(t,e){t=ui.lab(t),e=ui.lab(e);var n=t.l,r=t.a,a=t.b,o=e.l-n,i=e.a-r,l=e.b-a;return function(t){return pt(n+o*t,r+i*t,a+l*t)+\"\"}}function qr(t,e){return e-=t,function(n){return Math.round(t+e*n)}}function Fr(t){var e=[t.a,t.b],n=[t.c,t.d],r=Hr(e),a=Br(e,n),o=Hr(Vr(n,e,-a))||0;e[0]*n[1]<n[0]*e[1]&&(e[0]*=-1,e[1]*=-1,r*=-1,a*=-1),this.rotate=(r?Math.atan2(e[1],e[0]):Math.atan2(-n[0],n[1]))*Ui,this.translate=[t.e,t.f],this.scale=[r,o],this.skew=o?Math.atan2(a,o)*Ui:0}function Br(t,e){return t[0]*e[0]+t[1]*e[1]}function Hr(t){var e=Math.sqrt(Br(t,t));return e&&(t[0]/=e,t[1]/=e),e}function Vr(t,e,n){return t[0]+=n*e[0],t[1]+=n*e[1],t}function Zr(t){return t.length?t.pop()+\",\":\"\"}function Yr(t,e,n,r){if(t[0]!==e[0]||t[1]!==e[1]){var a=n.push(\"translate(\",null,\",\",null,\")\");r.push({i:a-4,x:xr(t[0],e[0])\n"
,
"},{i:a-2,x:xr(t[1],e[1])})}else(e[0]||e[1])&&n.push(\"translate(\"+e+\")\")}function Ur(t,e,n,r){t!==e?(t-e>180?e+=360:e-t>180&&(t+=360),r.push({i:n.push(Zr(n)+\"rotate(\",null,\")\")-2,x:xr(t,e)})):e&&n.push(Zr(n)+\"rotate(\"+e+\")\")}function Xr(t,e,n,r){t!==e?r.push({i:n.push(Zr(n)+\"skewX(\",null,\")\")-2,x:xr(t,e)}):e&&n.push(Zr(n)+\"skewX(\"+e+\")\")}function Gr(t,e,n,r){if(t[0]!==e[0]||t[1]!==e[1]){var a=n.push(Zr(n)+\"scale(\",null,\",\",null,\")\");r.push({i:a-4,x:xr(t[0],e[0])},{i:a-2,x:xr(t[1],e[1])})}else 1===e[0]&&1===e[1]||n.push(Zr(n)+\"scale(\"+e+\")\")}function $r(t,e){var n=[],r=[];return t=ui.transform(t),e=ui.transform(e),Yr(t.translate,e.translate,n,r),Ur(t.rotate,e.rotate,n,r),Xr(t.skew,e.skew,n,r),Gr(t.scale,e.scale,n,r),t=e=null,function(t){for(var e,a=-1,o=r.length;++a<o;)n[(e=r[a]).i]=e.x(t);return n.join(\"\")}}function Qr(t,e){return e=(e-=t=+t)||1/e,function(n){return(n-t)/e}}function Wr(t,e){return e=(e-=t=+t)||1/e,function(n){return Math.max(0,Math.min(1,(n-t)/e))}}function Jr(t){for(var e=t.source,n=t.target,r=ta(e,n),a=[e];e!==r;)e=e.parent,a.push(e);for(var o=a.length;n!==r;)a.splice(o,0,n),n=n.parent;return a}function Kr(t){for(var e=[],n=t.parent;null!=n;)e.push(t),t=n,n=n.parent;return e.push(t),e}function ta(t,e){if(t===e)return t;for(var n=Kr(t),r=Kr(e),a=n.pop(),o=r.pop(),i=null;a===o;)i=a,a=n.pop(),o=r.pop();return i}function ea(t){t.fixed|=2}function na(t){t.fixed&=-7}function ra(t){t.fixed|=4,t.px=t.x,t.py=t.y}function aa(t){t.fixed&=-5}function oa(t,e,n){var r=0,a=0;if(t.charge=0,!t.leaf)for(var o,i=t.nodes,l=i.length,s=-1;++s<l;)o=i[s],null!=o&&(oa(o,e,n),t.charge+=o.charge,r+=o.charge*o.cx,a+=o.charge*o.cy);if(t.point){t.leaf||(t.point.x+=Math.random()-.5,t.point.y+=Math.random()-.5);var c=e*n[t.point.index];t.charge+=t.pointCharge=c,r+=c*t.point.x,a+=c*t.point.y}t.cx=r/t.charge,t.cy=a/t.charge}function ia(t,e){return ui.rebind(t,e,\"sort\",\"children\",\"value\"),t.nodes=t,t.links=da,t}function la(t,e){for(var n=[t];null!=(t=n.pop());)if(e(t),(a=t.children)&&(r=a.length))for(var r,a;--r>=0;)n.push(a[r])}function sa(t,e){for(var n=[t],r=[];null!=(t=n.pop());)if(r.push(t),(o=t.children)&&(a=o.length))for(var a,o,i=-1;++i<a;)n.push(o[i]);for(;null!=(t=r.pop());)e(t)}function ca(t){return t.children}function ua(t){return t.value}function fa(t,e){return e.value-t.value}function da(t){return ui.merge(t.map(function(t){return(t.children||[]).map(function(e){return{source:t,target:e}})}))}function ha(t){return t.x}function pa(t){return t.y}function ga(t,e,n){t.y0=e,t.y=n}function va(t){return ui.range(t.length)}function ma(t){for(var e=-1,n=t[0].length,r=[];++e<n;)r[e]=0;return r}function ya(t){for(var e,n=1,r=0,a=t[0][1],o=t.length;o>n;++n)(e=t[n][1])>a&&(r=n,a=e);return r}function xa(t){return t.reduce(ba,0)}function ba(t,e){return t+e[1]}function _a(t,e){return wa(t,Math.ceil(Math.log(e.length)/Math.LN2+1))}function wa(t,e){for(var n=-1,r=+t[0],a=(t[1]-r)/e,o=[];++n<=e;)o[n]=a*n+r;return o}function ka(t){return[ui.min(t),ui.max(t)]}function Ma(t,e){return t.value-e.value}function Aa(t,e){var n=t._pack_next;t._pack_next=e,e._pack_prev=t,e._pack_next=n,n._pack_prev=e}function La(t,e){t._pack_next=e,e._pack_prev=t}function Ta(t,e){var n=e.x-t.x,r=e.y-t.y,a=t.r+e.r;return.999*a*a>n*n+r*r}function za(t){function e(t){u=Math.min(t.x-t.r,u),f=Math.max(t.x+t.r,f),d=Math.min(t.y-t.r,d),h=Math.max(t.y+t.r,h)}if((n=t.children)&&(c=n.length)){var n,r,a,o,i,l,s,c,u=1/0,f=-(1/0),d=1/0,h=-(1/0);if(n.forEach(Sa),r=n[0],r.x=-r.r,r.y=0,e(r),c>1&&(a=n[1],a.x=a.r,a.y=0,e(a),c>2))for(o=n[2],Oa(r,a,o),e(o),Aa(r,o),r._pack_prev=o,Aa(o,a),a=r._pack_next,i=3;c>i;i++){Oa(r,a,o=n[i]);var p=0,g=1,v=1;for(l=a._pack_next;l!==a;l=l._pack_next,g++)if(Ta(l,o)){p=1;break}if(1==p)for(s=r._pack_prev;s!==l._pack_prev&&!Ta(s,o);s=s._pack_prev,v++);p?(v>g||g==v&&a.r<r.r?La(r,a=l):La(r=s,a),i--):(Aa(r,o),a=o,e(o))}var m=(u+f)/2,y=(d+h)/2,x=0;for(i=0;c>i;i++)o=n[i],o.x-=m,o.y-=y,x=Math.max(x,o.r+Math.sqrt(o.x*o.x+o.y*o.y));t.r=x,n.forEach(Ea)}}function Sa(t){t._pack_next=t._pack_prev=t}function Ea(t){delete t._pack_next,delete t._pack_prev}function Ca(t,e,n,r){var a=t.children;if(t.x=e+=r*t.x,t.y=n+=r*t.y,t.r*=r,a)for(var o=-1,i=a.length;++o<i;)Ca(a[o],e,n,r)}function Oa(t,e,n){var r=t.r+n.r,a=e.x-t.x,o=e.y-t.y;if(r&&(a||o)){var i=e.r+n.r,l=a*a+o*o;i*=i,r*=r;var s=.5+(r-i)/(2*l),c=Math.sqrt(Math.max(0,2*i*(r+l)-(r-=l)*r-i*i))/(2*l);n.x=t.x+s*a+c*o,n.y=t.y+s*o-c*a}else n.x=t.x+r,n.y=t.y}function Pa(t,e){return t.parent==e.parent?1:2}function Na(t){var e=t.children;return e.length?e[0]:t.t}function Da(t){var e,n=t.children;return(e=n.length)?n[e-1]:t.t}function Ia(t,e,n){var r=n/(e.i-t.i);e.c-=r,e.s+=n,t.c+=r,e.z+=n,e.m+=n}function Ra(t){for(var e,n=0,r=0,a=t.children,o=a.length;--o>=0;)e=a[o],e.z+=n,e.m+=n,n+=e.s+(r+=e.c)}function ja(t,e,n){return t.a.parent===e.parent?t.a:n}function qa(t){return 1+ui.max(t,function(t){return t.y})}function Fa(t){return t.reduce(function(t,e){return t+e.x},0)/t.length}function Ba(t){var e=t.children;return e&&e.length?Ba(e[0]):t}function Ha(t){var e,n=t.children;return n&&(e=n.length)?Ha(n[e-1]):t}function Va(t){return{x:t.x,y:t.y,dx:t.dx,dy:t.dy}}function Za(t,e){var n=t.x+e[3],r=t.y+e[0],a=t.dx-e[1]-e[3],o=t.dy-e[0]-e[2];return 0>a&&(n+=a/2,a=0),0>o&&(r+=o/2,o=0),{x:n,y:r,dx:a,dy:o}}function Ya(t){var e=t[0],n=t[t.length-1];return n>e?[e,n]:[n,e]}function Ua(t){return t.rangeExtent?t.rangeExtent():Ya(t.range())}function Xa(t,e,n,r){var a=n(t[0],t[1]),o=r(e[0],e[1]);return function(t){return o(a(t))}}function Ga(t,e){var n,r=0,a=t.length-1,o=t[r],i=t[a];return o>i&&(n=r,r=a,a=n,n=o,o=i,i=n),t[r]=e.floor(o),t[a]=e.ceil(i),t}function $a(t){return t?{floor:function(e){return Math.floor(e/t)*t},ceil:function(e){return Math.ceil(e/t)*t}}:Ls}function Qa(t,e,n,r){var a=[],o=[],i=0,l=Math.min(t.length,e.length)-1;for(t[l]<t[0]&&(t=t.slice().reverse(),e=e.slice().reverse());++i<=l;)a.push(n(t[i-1],t[i])),o.push(r(e[i-1],e[i]));return function(e){var n=ui.bisect(t,e,1,l)-1;return o[n](a[n](e))}}function Wa(t,e,n,r){function a(){var a=Math.min(t.length,e.length)>2?Qa:Xa,s=r?Wr:Qr;return i=a(t,e,s,n),l=a(e,t,s,_r),o}function o(t){return i(t)}var i,l;return o.invert=function(t){return l(t)},o.domain=function(e){return arguments.length?(t=e.map(Number),a()):t},o.range=function(t){return arguments.length?(e=t,a()):e},o.rangeRound=function(t){return o.range(t).interpolate(qr)},o.clamp=function(t){return arguments.length?(r=t,a()):r},o.interpolate=function(t){return arguments.length?(n=t,a()):n},o.ticks=function(e){return eo(t,e)},o.tickFormat=function(e,n){return no(t,e,n)},o.nice=function(e){return Ka(t,e),a()},o.copy=function(){return Wa(t,e,n,r)},a()}function Ja(t,e){return ui.rebind(t,e,\"range\",\"rangeRound\",\"interpolate\",\"clamp\")}function Ka(t,e){return Ga(t,$a(to(t,e)[2])),Ga(t,$a(to(t,e)[2])),t}function to(t,e){null==e&&(e=10);var n=Ya(t),r=n[1]-n[0],a=Math.pow(10,Math.floor(Math.log(r/e)/Math.LN10)),o=e/r*a;return.15>=o?a*=10:.35>=o?a*=5:.75>=o&&(a*=2),n[0]=Math.ceil(n[0]/a)*a,n[1]=Math.floor(n[1]/a)*a+.5*a,n[2]=a,n}function eo(t,e){return ui.range.apply(ui,to(t,e))}function no(t,e,n){var r=to(t,e);if(n){var a=pl.exec(n);if(a.shift(),\"s\"===a[8]){var o=ui.formatPrefix(Math.max(wi(r[0]),wi(r[1])));return a[7]||(a[7]=\".\"+ro(o.scale(r[2]))),a[8]=\"f\",n=ui.format(a.join(\"\")),function(t){return n(o.scale(t))+o.symbol}}a[7]||(a[7]=\".\"+ao(a[8],r)),n=a.join(\"\")}else n=\",.\"+ro(r[2])+\"f\";return ui.format(n)}function ro(t){return-Math.floor(Math.log(t)/Math.LN10+.01)}function ao(t,e){var n=ro(e[2]);return t in Ts?Math.abs(n-ro(Math.max(wi(e[0]),wi(e[1]))))+ +(\"e\"!==t):n-2*(\"%\"===t)}function oo(t,e,n,r){function a(t){return(n?Math.log(0>t?0:t):-Math.log(t>0?0:-t))/Math.log(e)}function o(t){return n?Math.pow(e,t):-Math.pow(e,-t)}function i(e){return t(a(e))}return i.invert=function(e){return o(t.invert(e))},i.domain=function(e){return arguments.length?(n=e[0]>=0,t.domain((r=e.map(Number)).map(a)),i):r},i.base=function(n){return arguments.length?(e=+n,t.domain(r.map(a)),i):e},i.nice=function(){var e=Ga(r.map(a),n?Math:Ss);return t.domain(e),r=e.map(o),i},i.ticks=function(){var t=Ya(r),i=[],l=t[0],s=t[1],c=Math.floor(a(l)),u=Math.ceil(a(s)),f=e%1?2:e;if(isFinite(u-c)){if(n){for(;u>c;c++)for(var d=1;f>d;d++)i.push(o(c)*d);i.push(o(c))}else for(i.push(o(c));c++<u;)for(var d=f-1;d>0;d--)i.push(o(c)*d);for(c=0;i[c]<l;c++);for(u=i.length;i[u-1]>s;u--);i=i.slice(c,u)}return i},i.tickFormat=function(t,n){if(!arguments.length)return zs;arguments.length<2?n=zs:\"function\"!=typeof n&&(n=ui.format(n));var r=Math.max(1,e*t/i.ticks().length);return function(t){var i=t/o(Math.round(a(t)));return e-.5>i*e&&(i*=e),r>=i?n(t):\"\"}},i.copy=function(){return oo(t.copy(),e,n,r)},Ja(i,t)}function io(t,e,n){function r(e){return t(a(e))}var a=lo(e),o=lo(1/e);return r.invert=function(e){return o(t.invert(e))},r.domain=function(e){return arguments.length?(t.domain((n=e.map(Number)).map(a)),r):n},r.ticks=function(t){return eo(n,t)},r.tickFormat=function(t,e){return no(n,t,e)},r.nice=function(t){return r.domain(Ka(n,t))},r.exponent=function(i){return arguments.length?(a=lo(e=i),o=lo(1/e),t.domain(n.map(a)),r):e},r.copy=function(){return io(t.copy(),e,n)},Ja(r,t)}function lo(t){return function(e){return 0>e?-Math.pow(-e,t):Math.pow(e,t)}}function so(t,e){function n(n){return o[((a.get(n)||(\"range\"===e.t?a.set(n,t.push(n)):NaN))-1)%o.length]}function r(e,n){return ui.range(t.length).map(function(t){return e+n*t})}var a,o,i;return n.domain=function(r){if(!arguments.length)return t;t=[],a=new f;for(var o,i=-1,l=r.length;++i<l;)a.has(o=r[i])||a.set(o,t.push(o));return n[e.t].apply(n,e.a)},n.range=function(t){return arguments.length?(o=t,i=0,e={t:\"range\",a:arguments},n):o},n.rangePoints=function(a,l){arguments.length<2&&(l=0);var s=a[0],c=a[1],u=t.length<2?(s=(s+c)/2,0):(c-s)/(t.length-1+l);return o=r(s+u*l/2,u),i=0,e={t:\"rangePoints\",a:arguments},n},n.rangeRoundPoints=function(a,l){arguments.length<2&&(l=0);var s=a[0],c=a[1],u=t.length<2?(s=c=Math.round((s+c)/2),0):(c-s)/"
,
"(t.length-1+l)|0;return o=r(s+Math.round(u*l/2+(c-s-(t.length-1+l)*u)/2),u),i=0,e={t:\"rangeRoundPoints\",a:arguments},n},n.rangeBands=function(a,l,s){arguments.length<2&&(l=0),arguments.length<3&&(s=l);var c=a[1]<a[0],u=a[c-0],f=a[1-c],d=(f-u)/(t.length-l+2*s);return o=r(u+d*s,d),c&&o.reverse(),i=d*(1-l),e={t:\"rangeBands\",a:arguments},n},n.rangeRoundBands=function(a,l,s){arguments.length<2&&(l=0),arguments.length<3&&(s=l);var c=a[1]<a[0],u=a[c-0],f=a[1-c],d=Math.floor((f-u)/(t.length-l+2*s));return o=r(u+Math.round((f-u-(t.length-l)*d)/2),d),c&&o.reverse(),i=Math.round(d*(1-l)),e={t:\"rangeRoundBands\",a:arguments},n},n.rangeBand=function(){return i},n.rangeExtent=function(){return Ya(e.a[0])},n.copy=function(){return so(t,e)},n.domain(t)}function co(t,e){function n(){var n=0,a=e.length;for(l=[];++n<a;)l[n-1]=ui.quantile(t,n/a);return r}function r(t){return isNaN(t=+t)?void 0:e[ui.bisect(l,t)]}var l;return r.domain=function(e){return arguments.length?(t=e.map(o).filter(i).sort(a),n()):t},r.range=function(t){return arguments.length?(e=t,n()):e},r.quantiles=function(){return l},r.invertExtent=function(n){return n=e.indexOf(n),0>n?[NaN,NaN]:[n>0?l[n-1]:t[0],n<l.length?l[n]:t[t.length-1]]},r.copy=function(){return co(t,e)},n()}function uo(t,e,n){function r(e){return n[Math.max(0,Math.min(i,Math.floor(o*(e-t))))]}function a(){return o=n.length/(e-t),i=n.length-1,r}var o,i;return r.domain=function(n){return arguments.length?(t=+n[0],e=+n[n.length-1],a()):[t,e]},r.range=function(t){return arguments.length?(n=t,a()):n},r.invertExtent=function(e){return e=n.indexOf(e),e=0>e?NaN:e/o+t,[e,e+1/o]},r.copy=function(){return uo(t,e,n)},a()}function fo(t,e){function n(n){return n>=n?e[ui.bisect(t,n)]:void 0}return n.domain=function(e){return arguments.length?(t=e,n):t},n.range=function(t){return arguments.length?(e=t,n):e},n.invertExtent=function(n){return n=e.indexOf(n),[t[n-1],t[n]]},n.copy=function(){return fo(t,e)},n}function ho(t){function e(t){return+t}return e.invert=e,e.domain=e.range=function(n){return arguments.length?(t=n.map(e),e):t},e.ticks=function(e){return eo(t,e)},e.tickFormat=function(e,n){return no(t,e,n)},e.copy=function(){return ho(t)},e}function po(){return 0}function go(t){return t.innerRadius}function vo(t){return t.outerRadius}function mo(t){return t.startAngle}function yo(t){return t.endAngle}function xo(t){return t&&t.padAngle}function bo(t,e,n,r){return(t-n)*e-(e-r)*t>0?0:1}function _o(t,e,n,r,a){var o=t[0]-e[0],i=t[1]-e[1],l=(a?r:-r)/Math.sqrt(o*o+i*i),s=l*i,c=-l*o,u=t[0]+s,f=t[1]+c,d=e[0]+s,h=e[1]+c,p=(u+d)/2,g=(f+h)/2,v=d-u,m=h-f,y=v*v+m*m,x=n-r,b=u*h-d*f,_=(0>m?-1:1)*Math.sqrt(Math.max(0,x*x*y-b*b)),w=(b*m-v*_)/y,k=(-b*v-m*_)/y,M=(b*m+v*_)/y,A=(-b*v+m*_)/y,L=w-p,T=k-g,z=M-p,S=A-g;return L*L+T*T>z*z+S*S&&(w=M,k=A),[[w-s,k-c],[w*n/x,k*n/x]]}function wo(t){function e(e){function i(){c.push(\"M\",o(t(u),l))}for(var s,c=[],u=[],f=-1,d=e.length,h=zt(n),p=zt(r);++f<d;)a.call(this,s=e[f],f)?u.push([+h.call(this,s,f),+p.call(this,s,f)]):u.length&&(i(),u=[]);return u.length&&i(),c.length?c.join(\"\"):null}var n=Cn,r=On,a=Ce,o=ko,i=o.key,l=.7;return e.x=function(t){return arguments.length?(n=t,e):n},e.y=function(t){return arguments.length?(r=t,e):r},e.defined=function(t){return arguments.length?(a=t,e):a},e.interpolate=function(t){return arguments.length?(i=\"function\"==typeof t?o=t:(o=Ds.get(t)||ko).key,e):i},e.tension=function(t){return arguments.length?(l=t,e):l},e}function ko(t){return t.length>1?t.join(\"L\"):t+\"Z\"}function Mo(t){return t.join(\"L\")+\"Z\"}function Ao(t){for(var e=0,n=t.length,r=t[0],a=[r[0],\",\",r[1]];++e<n;)a.push(\"H\",(r[0]+(r=t[e])[0])/2,\"V\",r[1]);return n>1&&a.push(\"H\",r[0]),a.join(\"\")}function Lo(t){for(var e=0,n=t.length,r=t[0],a=[r[0],\",\",r[1]];++e<n;)a.push(\"V\",(r=t[e])[1],\"H\",r[0]);return a.join(\"\")}function To(t){for(var e=0,n=t.length,r=t[0],a=[r[0],\",\",r[1]];++e<n;)a.push(\"H\",(r=t[e])[0],\"V\",r[1]);return a.join(\"\")}function zo(t,e){return t.length<4?ko(t):t[1]+Co(t.slice(1,-1),Oo(t,e))}function So(t,e){return t.length<3?Mo(t):t[0]+Co((t.push(t[0]),t),Oo([t[t.length-2]].concat(t,[t[1]]),e))}function Eo(t,e){return t.length<3?ko(t):t[0]+Co(t,Oo(t,e))}function Co(t,e){if(e.length<1||t.length!=e.length&&t.length!=e.length+2)return ko(t);var n=t.length!=e.length,r=\"\",a=t[0],o=t[1],i=e[0],l=i,s=1;if(n&&(r+=\"Q\"+(o[0]-2*i[0]/3)+\",\"+(o[1]-2*i[1]/3)+\",\"+o[0]+\",\"+o[1],a=t[1],s=2),e.length>1){l=e[1],o=t[s],s++,r+=\"C\"+(a[0]+i[0])+\",\"+(a[1]+i[1])+\",\"+(o[0]-l[0])+\",\"+(o[1]-l[1])+\",\"+o[0]+\",\"+o[1];for(var c=2;c<e.length;c++,s++)o=t[s],l=e[c],r+=\"S\"+(o[0]-l[0])+\",\"+(o[1]-l[1])+\",\"+o[0]+\",\"+o[1]}if(n){var u=t[s];r+=\"Q\"+(o[0]+2*l[0]/3)+\",\"+(o[1]+2*l[1]/3)+\",\"+u[0]+\",\"+u[1]}return r}function Oo(t,e){for(var n,r=[],a=(1-e)/2,o=t[0],i=t[1],l=1,s=t.length;++l<s;)n=o,o=i,i=t[l],r.push([a*(i[0]-n[0]),a*(i[1]-n[1])]);return r}function Po(t){if(t.length<3)return ko(t);var e=1,n=t.length,r=t[0],a=r[0],o=r[1],i=[a,a,a,(r=t[1])[0]],l=[o,o,o,r[1]],s=[a,\",\",o,\"L\",Ro(js,i),\",\",Ro(js,l)];for(t.push(t[n-1]);++e<=n;)r=t[e],i.shift(),i.push(r[0]),l.shift(),l.push(r[1]),jo(s,i,l);return t.pop(),s.push(\"L\",r),s.join(\"\")}function No(t){if(t.length<4)return ko(t);for(var e,n=[],r=-1,a=t.length,o=[0],i=[0];++r<3;)e=t[r],o.push(e[0]),i.push(e[1]);for(n.push(Ro(js,o)+\",\"+Ro(js,i)),--r;++r<a;)e=t[r],o.shift(),o.push(e[0]),i.shift(),i.push(e[1]),jo(n,o,i);return n.join(\"\")}function Do(t){for(var e,n,r=-1,a=t.length,o=a+4,i=[],l=[];++r<4;)n=t[r%a],i.push(n[0]),l.push(n[1]);for(e=[Ro(js,i),\",\",Ro(js,l)],--r;++r<o;)n=t[r%a],i.shift(),i.push(n[0]),l.shift(),l.push(n[1]),jo(e,i,l);return e.join(\"\")}function Io(t,e){var n=t.length-1;if(n)for(var r,a,o=t[0][0],i=t[0][1],l=t[n][0]-o,s=t[n][1]-i,c=-1;++c<=n;)r=t[c],a=c/n,r[0]=e*r[0]+(1-e)*(o+a*l),r[1]=e*r[1]+(1-e)*(i+a*s);return Po(t)}function Ro(t,e){return t[0]*e[0]+t[1]*e[1]+t[2]*e[2]+t[3]*e[3]}function jo(t,e,n){t.push(\"C\",Ro(Is,e),\",\",Ro(Is,n),\",\",Ro(Rs,e),\",\",Ro(Rs,n),\",\",Ro(js,e),\",\",Ro(js,n))}function qo(t,e){return(e[1]-t[1])/(e[0]-t[0])}function Fo(t){for(var e=0,n=t.length-1,r=[],a=t[0],o=t[1],i=r[0]=qo(a,o);++e<n;)r[e]=(i+(i=qo(a=o,o=t[e+1])))/2;return r[e]=i,r}function Bo(t){for(var e,n,r,a,o=[],i=Fo(t),l=-1,s=t.length-1;++l<s;)e=qo(t[l],t[l+1]),wi(e)<qi?i[l]=i[l+1]=0:(n=i[l]/e,r=i[l+1]/e,a=n*n+r*r,a>9&&(a=3*e/Math.sqrt(a),i[l]=a*n,i[l+1]=a*r));for(l=-1;++l<=s;)a=(t[Math.min(s,l+1)][0]-t[Math.max(0,l-1)][0])/(6*(1+i[l]*i[l])),o.push([a||0,i[l]*a||0]);return o}function Ho(t){return t.length<3?ko(t):t[0]+Co(t,Bo(t))}function Vo(t){for(var e,n,r,a=-1,o=t.length;++a<o;)e=t[a],n=e[0],r=e[1]-Zi,e[0]=n*Math.cos(r),e[1]=n*Math.sin(r);return t}function Zo(t){function e(e){function s(){g.push(\"M\",l(t(m),f),u,c(t(v.reverse()),f),\"Z\")}for(var d,h,p,g=[],v=[],m=[],y=-1,x=e.length,b=zt(n),_=zt(a),w=n===r?function(){return h}:zt(r),k=a===o?function(){return p}:zt(o);++y<x;)i.call(this,d=e[y],y)?(v.push([h=+b.call(this,d,y),p=+_.call(this,d,y)]),m.push([+w.call(this,d,y),+k.call(this,d,y)])):v.length&&(s(),v=[],m=[]);return v.length&&s(),g.length?g.join(\"\"):null}var n=Cn,r=Cn,a=0,o=On,i=Ce,l=ko,s=l.key,c=l,u=\"L\",f=.7;return e.x=function(t){return arguments.length?(n=r=t,e):r},e.x0=function(t){return arguments.length?(n=t,e):n},e.x1=function(t){return arguments.length?(r=t,e):r},e.y=function(t){return arguments.length?(a=o=t,e):o},e.y0=function(t){return arguments.length?(a=t,e):a},e.y1=function(t){return arguments.length?(o=t,e):o},e.defined=function(t){return arguments.length?(i=t,e):i},e.interpolate=function(t){return arguments.length?(s=\"function\"==typeof t?l=t:(l=Ds.get(t)||ko).key,c=l.reverse||l,u=l.closed?\"M\":\"L\",e):s},e.tension=function(t){return arguments.length?(f=t,e):f},e}function Yo(t){return t.radius}function Uo(t){return[t.x,t.y]}function Xo(t){return function(){var e=t.apply(this,arguments),n=e[0],r=e[1]-Zi;return[n*Math.cos(r),n*Math.sin(r)]}}function Go(){return 64}function $o(){return\"circle\"}function Qo(t){var e=Math.sqrt(t/Bi);return\"M0,\"+e+\"A\"+e+\",\"+e+\" 0 1,1 0,\"+-e+\"A\"+e+\",\"+e+\" 0 1,1 0,\"+e+\"Z\"}function Wo(t){return function(){var e,n,r;(e=this[t])&&(r=e[n=e.active])&&(r.timer.c=null,r.timer.t=NaN,--e.count?delete e[n]:delete this[t],e.active+=.5,r.event&&r.event.interrupt.call(this,this.__data__,r.index))}}function Jo(t,e,n){return Ti(t,Ys),t.namespace=e,t.id=n,t}function Ko(t,e,n,r){var a=t.id,o=t.namespace;return Y(t,\"function\"==typeof n?function(t,i,l){t[o][a].tween.set(e,r(n.call(t,t.__data__,i,l)))}:(n=r(n),function(t){t[o][a].tween.set(e,n)}))}function ti(t){return null==t&&(t=\"\"),function(){this.textContent=t}}function ei(t){return null==t?\"__transition__\":\"__transition_\"+t+\"__\"}function ni(t,e,n,r,a){function o(t){var e=g.delay;return c.t=e+s,t>=e?i(t-e):void(c.c=i)}function i(n){var a=p.active,o=p[a];o&&(o.timer.c=null,o.timer.t=NaN,--p.count,delete p[a],o.event&&o.event.interrupt.call(t,t.__data__,o.index));for(var i in p)if(r>+i){var f=p[i];f.timer.c=null,f.timer.t=NaN,--p.count,delete p[i]}c.c=l,Pt(function(){return c.c&&l(n||1)&&(c.c=null,c.t=NaN),1},0,s),p.active=r,g.event&&g.event.start.call(t,t.__data__,e),h=[],g.tween.forEach(function(n,r){(r=r.call(t,t.__data__,e))&&h.push(r)}),d=g.ease,u=g.duration}function l(a){for(var o=a/u,i=d(o),l=h.length;l>0;)h[--l].call(t,i);return o>=1?(g.event&&g.event.end.call(t,t.__data__,e),--p.count?delete p[r]:delete t[n],1):void 0}var s,c,u,d,h,p=t[n]||(t[n]={active:0,count:0}),g=p[r];g||(s=a.time,c=Pt(o,0,s),g=p[r]={tween:new f,time:s,timer:c,delay:a.delay,duration:a.duration,ease:a.ease,index:e},a=null,++p.count)}function ri(t,e,n){t.attr(\"transform\",function(t){var r=e(t);return\"translate(\"+(isFinite(r)?r:n(t))+\",0)\"})}function ai(t,e,n){t.attr(\"transform\",function(t){var r=e(t);return\"translate(0,\"+(isFinite(r)?r:n(t))+\")\"})}function oi(t){return t.toISOString()}function ii(t,e,n){function r(e){return t(e)}function a(t,n){var r=t[1]-t[0],a=r/n,o=ui.bisect(tc,a);return o==tc.length?[e.year,to(t.map(function(t){return t/31536e6}),n)[2]]:o?e[a/tc[o-1]<tc[o]/a?o-1:o]:[rc,to(t,n)[2]]}return r.invert=function(e){return li"
,
"(t.invert(e))},r.domain=function(e){return arguments.length?(t.domain(e),r):t.domain().map(li)},r.nice=function(t,e){function n(n){return!isNaN(n)&&!t.range(n,li(+n+1),e).length}var o=r.domain(),i=Ya(o),l=null==t?a(i,10):\"number\"==typeof t&&a(i,t);return l&&(t=l[0],e=l[1]),r.domain(Ga(o,e>1?{floor:function(e){for(;n(e=t.floor(e));)e=li(e-1);return e},ceil:function(e){for(;n(e=t.ceil(e));)e=li(+e+1);return e}}:t))},r.ticks=function(t,e){var n=Ya(r.domain()),o=null==t?a(n,10):\"number\"==typeof t?a(n,t):!t.range&&[{range:t},e];return o&&(t=o[0],e=o[1]),t.range(n[0],li(+n[1]+1),1>e?1:e)},r.tickFormat=function(){return n},r.copy=function(){return ii(t.copy(),e,n)},Ja(r,t)}function li(t){return new Date(t)}function si(t){return JSON.parse(t.responseText)}function ci(t){var e=hi.createRange();return e.selectNode(hi.body),e.createContextualFragment(t.responseText)}var ui={version:\"3.5.16\"},fi=[].slice,di=function(t){return fi.call(t)},hi=this.document;if(hi)try{di(hi.documentElement.childNodes)[0].nodeType}catch(pi){di=function(t){for(var e=t.length,n=new Array(e);e--;)n[e]=t[e];return n}}if(Date.now||(Date.now=function(){return+new Date}),hi)try{hi.createElement(\"DIV\").style.setProperty(\"opacity\",0,\"\")}catch(gi){var vi=this.Element.prototype,mi=vi.setAttribute,yi=vi.setAttributeNS,xi=this.CSSStyleDeclaration.prototype,bi=xi.setProperty;vi.setAttribute=function(t,e){mi.call(this,t,e+\"\")},vi.setAttributeNS=function(t,e,n){yi.call(this,t,e,n+\"\")},xi.setProperty=function(t,e,n){bi.call(this,t,e+\"\",n)}}ui.ascending=a,ui.descending=function(t,e){return t>e?-1:e>t?1:e>=t?0:NaN},ui.min=function(t,e){var n,r,a=-1,o=t.length;if(1===arguments.length){for(;++a<o;)if(null!=(r=t[a])&&r>=r){n=r;break}for(;++a<o;)null!=(r=t[a])&&n>r&&(n=r)}else{for(;++a<o;)if(null!=(r=e.call(t,t[a],a))&&r>=r){n=r;break}for(;++a<o;)null!=(r=e.call(t,t[a],a))&&n>r&&(n=r)}return n},ui.max=function(t,e){var n,r,a=-1,o=t.length;if(1===arguments.length){for(;++a<o;)if(null!=(r=t[a])&&r>=r){n=r;break}for(;++a<o;)null!=(r=t[a])&&r>n&&(n=r)}else{for(;++a<o;)if(null!=(r=e.call(t,t[a],a))&&r>=r){n=r;break}for(;++a<o;)null!=(r=e.call(t,t[a],a))&&r>n&&(n=r)}return n},ui.extent=function(t,e){var n,r,a,o=-1,i=t.length;if(1===arguments.length){for(;++o<i;)if(null!=(r=t[o])&&r>=r){n=a=r;break}for(;++o<i;)null!=(r=t[o])&&(n>r&&(n=r),r>a&&(a=r))}else{for(;++o<i;)if(null!=(r=e.call(t,t[o],o))&&r>=r){n=a=r;break}for(;++o<i;)null!=(r=e.call(t,t[o],o))&&(n>r&&(n=r),r>a&&(a=r))}return[n,a]},ui.sum=function(t,e){var n,r=0,a=t.length,o=-1;if(1===arguments.length)for(;++o<a;)i(n=+t[o])&&(r+=n);else for(;++o<a;)i(n=+e.call(t,t[o],o))&&(r+=n);return r},ui.mean=function(t,e){var n,r=0,a=t.length,l=-1,s=a;if(1===arguments.length)for(;++l<a;)i(n=o(t[l]))?r+=n:--s;else for(;++l<a;)i(n=o(e.call(t,t[l],l)))?r+=n:--s;return s?r/s:void 0},ui.quantile=function(t,e){var n=(t.length-1)*e+1,r=Math.floor(n),a=+t[r-1],o=n-r;return o?a+o*(t[r]-a):a},ui.median=function(t,e){var n,r=[],l=t.length,s=-1;if(1===arguments.length)for(;++s<l;)i(n=o(t[s]))&&r.push(n);else for(;++s<l;)i(n=o(e.call(t,t[s],s)))&&r.push(n);return r.length?ui.quantile(r.sort(a),.5):void 0},ui.variance=function(t,e){var n,r,a=t.length,l=0,s=0,c=-1,u=0;if(1===arguments.length)for(;++c<a;)i(n=o(t[c]))&&(r=n-l,l+=r/++u,s+=r*(n-l));else for(;++c<a;)i(n=o(e.call(t,t[c],c)))&&(r=n-l,l+=r/++u,s+=r*(n-l));return u>1?s/(u-1):void 0},ui.deviation=function(){var t=ui.variance.apply(this,arguments);return t?Math.sqrt(t):t};var _i=l(a);ui.bisectLeft=_i.left,ui.bisect=ui.bisectRight=_i.right,ui.bisector=function(t){return l(1===t.length?function(e,n){return a(t(e),n)}:t)},ui.shuffle=function(t,e,n){(o=arguments.length)<3&&(n=t.length,2>o&&(e=0));for(var r,a,o=n-e;o;)a=Math.random()*o--|0,r=t[o+e],t[o+e]=t[a+e],t[a+e]=r;return t},ui.permute=function(t,e){for(var n=e.length,r=new Array(n);n--;)r[n]=t[e[n]];return r},ui.pairs=function(t){for(var e,n=0,r=t.length-1,a=t[0],o=new Array(0>r?0:r);r>n;)o[n]=[e=a,a=t[++n]];return o},ui.transpose=function(t){if(!(a=t.length))return[];for(var e=-1,n=ui.min(t,s),r=new Array(n);++e<n;)for(var a,o=-1,i=r[e]=new Array(a);++o<a;)i[o]=t[o][e];return r},ui.zip=function(){return ui.transpose(arguments)},ui.keys=function(t){var e=[];for(var n in t)e.push(n);return e},ui.values=function(t){var e=[];for(var n in t)e.push(t[n]);return e},ui.entries=function(t){var e=[];for(var n in t)e.push({key:n,value:t[n]});return e},ui.merge=function(t){for(var e,n,r,a=t.length,o=-1,i=0;++o<a;)i+=t[o].length;for(n=new Array(i);--a>=0;)for(r=t[a],e=r.length;--e>=0;)n[--i]=r[e];return n};var wi=Math.abs;ui.range=function(t,e,n){if(arguments.length<3&&(n=1,arguments.length<2&&(e=t,t=0)),(e-t)/n===1/0)throw new Error(\"infinite range\");var r,a=[],o=c(wi(n)),i=-1;if(t*=o,e*=o,n*=o,0>n)for(;(r=t+n*++i)>e;)a.push(r/o);else for(;(r=t+n*++i)<e;)a.push(r/o);return a},ui.map=function(t,e){var n=new f;if(t instanceof f)t.forEach(function(t,e){n.set(t,e)});else if(Array.isArray(t)){var r,a=-1,o=t.length;if(1===arguments.length)for(;++a<o;)n.set(a,t[a]);else for(;++a<o;)n.set(e.call(t,r=t[a],a),r)}else for(var i in t)n.set(i,t[i]);return n};var ki=\"__proto__\",Mi=\"\\x00\";u(f,{has:p,get:function(t){return this._[d(t)]},set:function(t,e){return this._[d(t)]=e},remove:g,keys:v,values:function(){var t=[];for(var e in this._)t.push(this._[e]);return t},entries:function(){var t=[];for(var e in this._)t.push({key:h(e),value:this._[e]});return t},size:m,empty:y,forEach:function(t){for(var e in this._)t.call(this,h(e),this._[e])}}),ui.nest=function(){function t(e,i,l){if(l>=o.length)return r?r.call(a,i):n?i.sort(n):i;for(var s,c,u,d,h=-1,p=i.length,g=o[l++],v=new f;++h<p;)(d=v.get(s=g(c=i[h])))?d.push(c):v.set(s,[c]);return e?(c=e(),u=function(n,r){c.set(n,t(e,r,l))}):(c={},u=function(n,r){c[n]=t(e,r,l)}),v.forEach(u),c}function e(t,n){if(n>=o.length)return t;var r=[],a=i[n++];return t.forEach(function(t,a){r.push({key:t,values:e(a,n)})}),a?r.sort(function(t,e){return a(t.key,e.key)}):r}var n,r,a={},o=[],i=[];return a.map=function(e,n){return t(n,e,0)},a.entries=function(n){return e(t(ui.map,n,0),0)},a.key=function(t){return o.push(t),a},a.sortKeys=function(t){return i[o.length-1]=t,a},a.sortValues=function(t){return n=t,a},a.rollup=function(t){return r=t,a},a},ui.set=function(t){var e=new x;if(t)for(var n=0,r=t.length;r>n;++n)e.add(t[n]);return e},u(x,{has:p,add:function(t){return this._[d(t+=\"\")]=!0,t},remove:g,values:v,size:m,empty:y,forEach:function(t){for(var e in this._)t.call(this,h(e))}}),ui.behavior={},ui.rebind=function(t,e){for(var n,r=1,a=arguments.length;++r<a;)t[n=arguments[r]]=_(t,e,e[n]);return t};var Ai=[\"webkit\",\"ms\",\"moz\",\"Moz\",\"o\",\"O\"];ui.dispatch=function(){for(var t=new M,e=-1,n=arguments.length;++e<n;)t[arguments[e]]=A(t);return t},M.prototype.on=function(t,e){var n=t.indexOf(\".\"),r=\"\";if(n>=0&&(r=t.slice(n+1),t=t.slice(0,n)),t)return arguments.length<2?this[t].on(r):this[t].on(r,e);if(2===arguments.length){if(null==e)for(t in this)this.hasOwnProperty(t)&&this[t].on(r,null);return this}},ui.event=null,ui.requote=function(t){return t.replace(Li,\"\\\\$&\")};var Li=/[\\\\\\^\\$\\*\\+\\?\\|\\[\\]\\(\\)\\.\\{\\}]/g,Ti={}.__proto__?function(t,e){t.__proto__=e}:function(t,e){for(var n in e)t[n]=e[n]},zi=function(t,e){return e.querySelector(t)},Si=function(t,e){return e.querySelectorAll(t)},Ei=function(t,e){var n=t.matches||t[w(t,\"matchesSelector\")];return(Ei=function(t,e){return n.call(t,e)})(t,e)};\"function\"==typeof Sizzle&&(zi=function(t,e){return Sizzle(t,e)[0]||null},Si=Sizzle,Ei=Sizzle.matchesSelector),ui.selection=function(){return ui.select(hi.documentElement)};var Ci=ui.selection.prototype=[];Ci.select=function(t){var e,n,r,a,o=[];t=E(t);for(var i=-1,l=this.length;++i<l;){o.push(e=[]),e.parentNode=(r=this[i]).parentNode;for(var s=-1,c=r.length;++s<c;)(a=r[s])?(e.push(n=t.call(a,a.__data__,s,i)),n&&\"__data__\"in a&&(n.__data__=a.__data__)):e.push(null)}return S(o)},Ci.selectAll=function(t){var e,n,r=[];t=C(t);for(var a=-1,o=this.length;++a<o;)for(var i=this[a],l=-1,s=i.length;++l<s;)(n=i[l])&&(r.push(e=di(t.call(n,n.__data__,l,a))),e.parentNode=n);return S(r)};var Oi=\"http://www.w3.org/1999/xhtml\",Pi={svg:\"http://www.w3.org/2000/svg\",xhtml:Oi,xlink:\"http://www.w3.org/1999/xlink\",xml:\"http://www.w3.org/XML/1998/namespace\",xmlns:\"http://www.w3.org/2000/xmlns/\"};ui.ns={prefix:Pi,qualify:function(t){var e=t.indexOf(\":\"),n=t;return e>=0&&\"xmlns\"!==(n=t.slice(0,e))&&(t=t.slice(e+1)),Pi.hasOwnProperty(n)?{space:Pi[n],local:t}:t}},Ci.attr=function(t,e){if(arguments.length<2){if(\"string\"==typeof t){var n=this.node();return t=ui.ns.qualify(t),t.local?n.getAttributeNS(t.space,t.local):n.getAttribute(t)}for(e in t)this.each(O(e,t[e]));return this}return this.each(O(t,e))},Ci.classed=function(t,e){if(arguments.length<2){if(\"string\"==typeof t){var n=this.node(),r=(t=D(t)).length,a=-1;if(e=n.classList){for(;++a<r;)if(!e.contains(t[a]))return!1}else for(e=n.getAttribute(\"class\");++a<r;)if(!N(t[a]).test(e))return!1;return!0}for(e in t)this.each(I(e,t[e]));return this}return this.each(I(t,e))},Ci.style=function(t,e,n){var a=arguments.length;if(3>a){if(\"string\"!=typeof t){2>a&&(e=\"\");for(n in t)this.each(j(n,t[n],e));return this}if(2>a){var o=this.node();return r(o).getComputedStyle(o,null).getPropertyValue(t)}n=\"\"}return this.each(j(t,e,n))},Ci.property=function(t,e){if(arguments.length<2){if(\"string\"==typeof t)return this.node()[t];for(e in t)this.each(q(e,t[e]));return this}return this.each(q(t,e))},Ci.text=function(t){return arguments.length?this.each(\"function\"==typeof t?function(){var e=t.apply(this,arguments);this.textContent=null==e?\"\":e}:null==t?function(){this.textContent=\"\"}:function(){this.textContent=t}):this.node().textContent},Ci.html=function(t){return arguments.length?this.each(\"function\"==typeof t?function(){var e=t.apply(this,arguments);this.innerHTML=null==e?\"\":e}:null==t?function(){this.innerHTML=\"\"}:function(){this.innerHTML=t}):this.node().innerHTML},Ci.append=function(t){return t=F(t),this.select(function(){return this.appendChild(t.apply(t"
,
"his,arguments))})},Ci.insert=function(t,e){return t=F(t),e=E(e),this.select(function(){return this.insertBefore(t.apply(this,arguments),e.apply(this,arguments)||null)})},Ci.remove=function(){return this.each(B)},Ci.data=function(t,e){function n(t,n){var r,a,o,i=t.length,u=n.length,d=Math.min(i,u),h=new Array(u),p=new Array(u),g=new Array(i);if(e){var v,m=new f,y=new Array(i);for(r=-1;++r<i;)(a=t[r])&&(m.has(v=e.call(a,a.__data__,r))?g[r]=a:m.set(v,a),y[r]=v);for(r=-1;++r<u;)(a=m.get(v=e.call(n,o=n[r],r)))?a!==!0&&(h[r]=a,a.__data__=o):p[r]=H(o),m.set(v,!0);for(r=-1;++r<i;)r in y&&m.get(y[r])!==!0&&(g[r]=t[r])}else{for(r=-1;++r<d;)a=t[r],o=n[r],a?(a.__data__=o,h[r]=a):p[r]=H(o);for(;u>r;++r)p[r]=H(n[r]);for(;i>r;++r)g[r]=t[r]}p.update=h,p.parentNode=h.parentNode=g.parentNode=t.parentNode,l.push(p),s.push(h),c.push(g)}var r,a,o=-1,i=this.length;if(!arguments.length){for(t=new Array(i=(r=this[0]).length);++o<i;)(a=r[o])&&(t[o]=a.__data__);return t}var l=U([]),s=S([]),c=S([]);if(\"function\"==typeof t)for(;++o<i;)n(r=this[o],t.call(r,r.parentNode.__data__,o));else for(;++o<i;)n(r=this[o],t);return s.enter=function(){return l},s.exit=function(){return c},s},Ci.datum=function(t){return arguments.length?this.property(\"__data__\",t):this.property(\"__data__\")},Ci.filter=function(t){var e,n,r,a=[];\"function\"!=typeof t&&(t=V(t));for(var o=0,i=this.length;i>o;o++){a.push(e=[]),e.parentNode=(n=this[o]).parentNode;for(var l=0,s=n.length;s>l;l++)(r=n[l])&&t.call(r,r.__data__,l,o)&&e.push(r)}return S(a)},Ci.order=function(){for(var t=-1,e=this.length;++t<e;)for(var n,r=this[t],a=r.length-1,o=r[a];--a>=0;)(n=r[a])&&(o&&o!==n.nextSibling&&o.parentNode.insertBefore(n,o),o=n);return this},Ci.sort=function(t){t=Z.apply(this,arguments);for(var e=-1,n=this.length;++e<n;)this[e].sort(t);return this.order()},Ci.each=function(t){return Y(this,function(e,n,r){t.call(e,e.__data__,n,r)})},Ci.call=function(t){var e=di(arguments);return t.apply(e[0]=this,e),this},Ci.empty=function(){return!this.node();\n"
,
"},Ci.node=function(){for(var t=0,e=this.length;e>t;t++)for(var n=this[t],r=0,a=n.length;a>r;r++){var o=n[r];if(o)return o}return null},Ci.size=function(){var t=0;return Y(this,function(){++t}),t};var Ni=[];ui.selection.enter=U,ui.selection.enter.prototype=Ni,Ni.append=Ci.append,Ni.empty=Ci.empty,Ni.node=Ci.node,Ni.call=Ci.call,Ni.size=Ci.size,Ni.select=function(t){for(var e,n,r,a,o,i=[],l=-1,s=this.length;++l<s;){r=(a=this[l]).update,i.push(e=[]),e.parentNode=a.parentNode;for(var c=-1,u=a.length;++c<u;)(o=a[c])?(e.push(r[c]=n=t.call(a.parentNode,o.__data__,c,l)),n.__data__=o.__data__):e.push(null)}return S(i)},Ni.insert=function(t,e){return arguments.length<2&&(e=X(this)),Ci.insert.call(this,t,e)},ui.select=function(t){var n;return\"string\"==typeof t?(n=[zi(t,hi)],n.parentNode=hi.documentElement):(n=[t],n.parentNode=e(t)),S([n])},ui.selectAll=function(t){var e;return\"string\"==typeof t?(e=di(Si(t,hi)),e.parentNode=hi.documentElement):(e=di(t),e.parentNode=null),S([e])},Ci.on=function(t,e,n){var r=arguments.length;if(3>r){if(\"string\"!=typeof t){2>r&&(e=!1);for(n in t)this.each(G(n,t[n],e));return this}if(2>r)return(r=this.node()[\"__on\"+t])&&r._;n=!1}return this.each(G(t,e,n))};var Di=ui.map({mouseenter:\"mouseover\",mouseleave:\"mouseout\"});hi&&Di.forEach(function(t){\"on\"+t in hi&&Di.remove(t)});var Ii,Ri=0;ui.mouse=function(t){return J(t,T())};var ji=this.navigator&&/WebKit/.test(this.navigator.userAgent)?-1:0;ui.touch=function(t,e,n){if(arguments.length<3&&(n=e,e=T().changedTouches),e)for(var r,a=0,o=e.length;o>a;++a)if((r=e[a]).identifier===n)return J(t,r)},ui.behavior.drag=function(){function t(){this.on(\"mousedown.drag\",o).on(\"touchstart.drag\",i)}function e(t,e,r,o,i){return function(){function l(){var t,n,r=e(d,g);r&&(t=r[0]-x[0],n=r[1]-x[1],p|=t|n,x=r,h({type:\"drag\",x:r[0]+c[0],y:r[1]+c[1],dx:t,dy:n}))}function s(){e(d,g)&&(m.on(o+v,null).on(i+v,null),y(p),h({type:\"dragend\"}))}var c,u=this,f=ui.event.target.correspondingElement||ui.event.target,d=u.parentNode,h=n.of(u,arguments),p=0,g=t(),v=\".drag\"+(null==g?\"\":\"-\"+g),m=ui.select(r(f)).on(o+v,l).on(i+v,s),y=W(f),x=e(d,g);a?(c=a.apply(u,arguments),c=[c.x-x[0],c.y-x[1]]):c=[0,0],h({type:\"dragstart\"})}}var n=z(t,\"drag\",\"dragstart\",\"dragend\"),a=null,o=e(k,ui.mouse,r,\"mousemove\",\"mouseup\"),i=e(K,ui.touch,b,\"touchmove\",\"touchend\");return t.origin=function(e){return arguments.length?(a=e,t):a},ui.rebind(t,n,\"on\")},ui.touches=function(t,e){return arguments.length<2&&(e=T().touches),e?di(e).map(function(e){var n=J(t,e);return n.identifier=e.identifier,n}):[]};var qi=1e-6,Fi=qi*qi,Bi=Math.PI,Hi=2*Bi,Vi=Hi-qi,Zi=Bi/2,Yi=Bi/180,Ui=180/Bi,Xi=Math.SQRT2,Gi=2,$i=4;ui.interpolateZoom=function(t,e){var n,r,a=t[0],o=t[1],i=t[2],l=e[0],s=e[1],c=e[2],u=l-a,f=s-o,d=u*u+f*f;if(Fi>d)r=Math.log(c/i)/Xi,n=function(t){return[a+t*u,o+t*f,i*Math.exp(Xi*t*r)]};else{var h=Math.sqrt(d),p=(c*c-i*i+$i*d)/(2*i*Gi*h),g=(c*c-i*i-$i*d)/(2*c*Gi*h),v=Math.log(Math.sqrt(p*p+1)-p),m=Math.log(Math.sqrt(g*g+1)-g);r=(m-v)/Xi,n=function(t){var e=t*r,n=ot(v),l=i/(Gi*h)*(n*it(Xi*e+v)-at(v));return[a+l*u,o+l*f,i*n/ot(Xi*e+v)]}}return n.duration=1e3*r,n},ui.behavior.zoom=function(){function t(t){t.on(C,f).on(Wi+\".zoom\",h).on(\"dblclick.zoom\",p).on(N,d)}function e(t){return[(t[0]-M.x)/M.k,(t[1]-M.y)/M.k]}function n(t){return[t[0]*M.k+M.x,t[1]*M.k+M.y]}function a(t){M.k=Math.max(T[0],Math.min(T[1],t))}function o(t,e){e=n(e),M.x+=t[0]-e[0],M.y+=t[1]-e[1]}function i(e,n,r,i){e.__chart__={x:M.x,y:M.y,k:M.k},a(Math.pow(2,i)),o(v=n,r),e=ui.select(e),S>0&&(e=e.transition().duration(S)),e.call(t.event)}function l(){_&&_.domain(b.range().map(function(t){return(t-M.x)/M.k}).map(b.invert)),k&&k.domain(w.range().map(function(t){return(t-M.y)/M.k}).map(w.invert))}function s(t){E++||t({type:\"zoomstart\"})}function c(t){l(),t({type:\"zoom\",scale:M.k,translate:[M.x,M.y]})}function u(t){--E||(t({type:\"zoomend\"}),v=null)}function f(){function t(){l=1,o(ui.mouse(a),d),c(i)}function n(){f.on(O,null).on(P,null),h(l),u(i)}var a=this,i=D.of(a,arguments),l=0,f=ui.select(r(a)).on(O,t).on(P,n),d=e(ui.mouse(a)),h=W(a);Zs.call(a),s(i)}function d(){function t(){var t=ui.touches(p);return h=M.k,t.forEach(function(t){t.identifier in v&&(v[t.identifier]=e(t))}),t}function n(){var e=ui.event.target;ui.select(e).on(b,r).on(_,l),w.push(e);for(var n=ui.event.changedTouches,a=0,o=n.length;o>a;++a)v[n[a].identifier]=null;var s=t(),c=Date.now();if(1===s.length){if(500>c-x){var u=s[0];i(p,u,v[u.identifier],Math.floor(Math.log(M.k)/Math.LN2)+1),L()}x=c}else if(s.length>1){var u=s[0],f=s[1],d=u[0]-f[0],h=u[1]-f[1];m=d*d+h*h}}function r(){var t,e,n,r,i=ui.touches(p);Zs.call(p);for(var l=0,s=i.length;s>l;++l,r=null)if(n=i[l],r=v[n.identifier]){if(e)break;t=n,e=r}if(r){var u=(u=n[0]-t[0])*u+(u=n[1]-t[1])*u,f=m&&Math.sqrt(u/m);t=[(t[0]+n[0])/2,(t[1]+n[1])/2],e=[(e[0]+r[0])/2,(e[1]+r[1])/2],a(f*h)}x=null,o(t,e),c(g)}function l(){if(ui.event.touches.length){for(var e=ui.event.changedTouches,n=0,r=e.length;r>n;++n)delete v[e[n].identifier];for(var a in v)return void t()}ui.selectAll(w).on(y,null),k.on(C,f).on(N,d),A(),u(g)}var h,p=this,g=D.of(p,arguments),v={},m=0,y=\".zoom-\"+ui.event.changedTouches[0].identifier,b=\"touchmove\"+y,_=\"touchend\"+y,w=[],k=ui.select(p),A=W(p);n(),s(g),k.on(C,null).on(N,n)}function h(){var t=D.of(this,arguments);y?clearTimeout(y):(Zs.call(this),g=e(v=m||ui.mouse(this)),s(t)),y=setTimeout(function(){y=null,u(t)},50),L(),a(Math.pow(2,.002*Qi())*M.k),o(v,g),c(t)}function p(){var t=ui.mouse(this),n=Math.log(M.k)/Math.LN2;i(this,t,e(t),ui.event.shiftKey?Math.ceil(n)-1:Math.floor(n)+1)}var g,v,m,y,x,b,_,w,k,M={x:0,y:0,k:1},A=[960,500],T=Ji,S=250,E=0,C=\"mousedown.zoom\",O=\"mousemove.zoom\",P=\"mouseup.zoom\",N=\"touchstart.zoom\",D=z(t,\"zoomstart\",\"zoom\",\"zoomend\");return Wi||(Wi=\"onwheel\"in hi?(Qi=function(){return-ui.event.deltaY*(ui.event.deltaMode?120:1)},\"wheel\"):\"onmousewheel\"in hi?(Qi=function(){return ui.event.wheelDelta},\"mousewheel\"):(Qi=function(){return-ui.event.detail},\"MozMousePixelScroll\")),t.event=function(t){t.each(function(){var t=D.of(this,arguments),e=M;Hs?ui.select(this).transition().each(\"start.zoom\",function(){M=this.__chart__||{x:0,y:0,k:1},s(t)}).tween(\"zoom:zoom\",function(){var n=A[0],r=A[1],a=v?v[0]:n/2,o=v?v[1]:r/2,i=ui.interpolateZoom([(a-M.x)/M.k,(o-M.y)/M.k,n/M.k],[(a-e.x)/e.k,(o-e.y)/e.k,n/e.k]);return function(e){var r=i(e),l=n/r[2];this.__chart__=M={x:a-r[0]*l,y:o-r[1]*l,k:l},c(t)}}).each(\"interrupt.zoom\",function(){u(t)}).each(\"end.zoom\",function(){u(t)}):(this.__chart__=M,s(t),c(t),u(t))})},t.translate=function(e){return arguments.length?(M={x:+e[0],y:+e[1],k:M.k},l(),t):[M.x,M.y]},t.scale=function(e){return arguments.length?(M={x:M.x,y:M.y,k:null},a(+e),l(),t):M.k},t.scaleExtent=function(e){return arguments.length?(T=null==e?Ji:[+e[0],+e[1]],t):T},t.center=function(e){return arguments.length?(m=e&&[+e[0],+e[1]],t):m},t.size=function(e){return arguments.length?(A=e&&[+e[0],+e[1]],t):A},t.duration=function(e){return arguments.length?(S=+e,t):S},t.x=function(e){return arguments.length?(_=e,b=e.copy(),M={x:0,y:0,k:1},t):_},t.y=function(e){return arguments.length?(k=e,w=e.copy(),M={x:0,y:0,k:1},t):k},ui.rebind(t,D,\"on\")};var Qi,Wi,Ji=[0,1/0];ui.color=st,st.prototype.toString=function(){return this.rgb()+\"\"},ui.hsl=ct;var Ki=ct.prototype=new st;Ki.brighter=function(t){return t=Math.pow(.7,arguments.length?t:1),new ct(this.h,this.s,this.l/t)},Ki.darker=function(t){return t=Math.pow(.7,arguments.length?t:1),new ct(this.h,this.s,t*this.l)},Ki.rgb=function(){return ut(this.h,this.s,this.l)},ui.hcl=ft;var tl=ft.prototype=new st;tl.brighter=function(t){return new ft(this.h,this.c,Math.min(100,this.l+el*(arguments.length?t:1)))},tl.darker=function(t){return new ft(this.h,this.c,Math.max(0,this.l-el*(arguments.length?t:1)))},tl.rgb=function(){return dt(this.h,this.c,this.l).rgb()},ui.lab=ht;var el=18,nl=.95047,rl=1,al=1.08883,ol=ht.prototype=new st;ol.brighter=function(t){return new ht(Math.min(100,this.l+el*(arguments.length?t:1)),this.a,this.b)},ol.darker=function(t){return new ht(Math.max(0,this.l-el*(arguments.length?t:1)),this.a,this.b)},ol.rgb=function(){return pt(this.l,this.a,this.b)},ui.rgb=xt;var il=xt.prototype=new st;il.brighter=function(t){t=Math.pow(.7,arguments.length?t:1);var e=this.r,n=this.g,r=this.b,a=30;return e||n||r?(e&&a>e&&(e=a),n&&a>n&&(n=a),r&&a>r&&(r=a),new xt(Math.min(255,e/t),Math.min(255,n/t),Math.min(255,r/t))):new xt(a,a,a)},il.darker=function(t){return t=Math.pow(.7,arguments.length?t:1),new xt(t*this.r,t*this.g,t*this.b)},il.hsl=function(){return Mt(this.r,this.g,this.b)},il.toString=function(){return\"#\"+wt(this.r)+wt(this.g)+wt(this.b)};var ll=ui.map({aliceblue:15792383,antiquewhite:16444375,aqua:65535,aquamarine:8388564,azure:15794175,beige:16119260,bisque:16770244,black:0,blanchedalmond:16772045,blue:255,blueviolet:9055202,brown:10824234,burlywood:14596231,cadetblue:6266528,chartreuse:8388352,chocolate:13789470,coral:16744272,cornflowerblue:6591981,cornsilk:16775388,crimson:14423100,cyan:65535,darkblue:139,darkcyan:35723,darkgoldenrod:12092939,darkgray:11119017,darkgreen:25600,darkgrey:11119017,darkkhaki:12433259,darkmagenta:9109643,darkolivegreen:5597999,darkorange:16747520,darkorchid:10040012,darkred:9109504,darksalmon:15308410,darkseagreen:9419919,darkslateblue:4734347,darkslategray:3100495,darkslategrey:3100495,darkturquoise:52945,darkviolet:9699539,deeppink:16716947,deepskyblue:49151,dimgray:6908265,dimgrey:6908265,dodgerblue:2003199,firebrick:11674146,floralwhite:16775920,forestgreen:2263842,fuchsia:16711935,gainsboro:14474460,ghostwhite:16316671,gold:16766720,goldenrod:14329120,gray:8421504,green:32768,greenyellow:11403055,grey:8421504,honeydew:15794160,hotpink:16738740,indianred:13458524,indigo:4915330,ivory:16777200,khaki:15787660,lavender:15132410,lavenderblush:16773365,lawngreen:8190976,lemonchiffon:16775885,lightblue:11393254,lightcoral:15761536,lightcyan:14745599,lightgoldenrodyellow:16448210,lightgray:13882323,lightgreen:9498256,lightgrey:13882323,lightpink:16758465,lightsa"
,
"lmon:16752762,lightseagreen:2142890,lightskyblue:8900346,lightslategray:7833753,lightslategrey:7833753,lightsteelblue:11584734,lightyellow:16777184,lime:65280,limegreen:3329330,linen:16445670,magenta:16711935,maroon:8388608,mediumaquamarine:6737322,mediumblue:205,mediumorchid:12211667,mediumpurple:9662683,mediumseagreen:3978097,mediumslateblue:8087790,mediumspringgreen:64154,mediumturquoise:4772300,mediumvioletred:13047173,midnightblue:1644912,mintcream:16121850,mistyrose:16770273,moccasin:16770229,navajowhite:16768685,navy:128,oldlace:16643558,olive:8421376,olivedrab:7048739,orange:16753920,orangered:16729344,orchid:14315734,palegoldenrod:15657130,palegreen:10025880,paleturquoise:11529966,palevioletred:14381203,papayawhip:16773077,peachpuff:16767673,peru:13468991,pink:16761035,plum:14524637,powderblue:11591910,purple:8388736,rebeccapurple:6697881,red:16711680,rosybrown:12357519,royalblue:4286945,saddlebrown:9127187,salmon:16416882,sandybrown:16032864,seagreen:3050327,seashell:16774638,sienna:10506797,silver:12632256,skyblue:8900331,slateblue:6970061,slategray:7372944,slategrey:7372944,snow:16775930,springgreen:65407,steelblue:4620980,tan:13808780,teal:32896,thistle:14204888,tomato:16737095,turquoise:4251856,violet:15631086,wheat:16113331,white:16777215,whitesmoke:16119285,yellow:16776960,yellowgreen:10145074});ll.forEach(function(t,e){ll.set(t,bt(e))}),ui.functor=zt,ui.xhr=St(b),ui.dsv=function(t,e){function n(t,n,o){arguments.length<3&&(o=n,n=null);var i=Et(t,e,null==n?r:a(n),o);return i.row=function(t){return arguments.length?i.response(null==(n=t)?r:a(t)):n},i}function r(t){return n.parse(t.responseText)}function a(t){return function(e){return n.parse(e.responseText,t)}}function o(e){return e.map(i).join(t)}function i(t){return l.test(t)?'\"'+t.replace(/\\\"/g,'\"\"')+'\"':t}var l=new RegExp('[\"'+t+\"\\n]\"),s=t.charCodeAt(0);return n.parse=function(t,e){var r;return n.parseRows(t,function(t,n){if(r)return r(t,n-1);var a=new Function(\"d\",\"return {\"+t.map(function(t,e){return JSON.stringify(t)+\": d[\"+e+\"]\"}).join(\",\")+\"}\");r=e?function(t,n){return e(a(t),n)}:a})},n.parseRows=function(t,e){function n(){if(u>=c)return i;if(a)return a=!1,o;var e=u;if(34===t.charCodeAt(e)){for(var n=e;n++<c;)if(34===t.charCodeAt(n)){if(34!==t.charCodeAt(n+1))break;++n}u=n+2;var r=t.charCodeAt(n+1);return 13===r?(a=!0,10===t.charCodeAt(n+2)&&++u):10===r&&(a=!0),t.slice(e+1,n).replace(/\"\"/g,'\"')}for(;c>u;){var r=t.charCodeAt(u++),l=1;if(10===r)a=!0;else if(13===r)a=!0,10===t.charCodeAt(u)&&(++u,++l);else if(r!==s)continue;return t.slice(e,u-l)}return t.slice(e)}for(var r,a,o={},i={},l=[],c=t.length,u=0,f=0;(r=n())!==i;){for(var d=[];r!==o&&r!==i;)d.push(r),r=n();e&&null==(d=e(d,f++))||l.push(d)}return l},n.format=function(e){if(Array.isArray(e[0]))return n.formatRows(e);var r=new x,a=[];return e.forEach(function(t){for(var e in t)r.has(e)||a.push(r.add(e))}),[a.map(i).join(t)].concat(e.map(function(e){return a.map(function(t){return i(e[t])}).join(t)})).join(\"\\n\")},n.formatRows=function(t){return t.map(o).join(\"\\n\")},n},ui.csv=ui.dsv(\",\",\"text/csv\"),ui.tsv=ui.dsv(\"	\",\"text/tab-separated-values\");var sl,cl,ul,fl,dl=this[w(this,\"requestAnimationFrame\")]||function(t){setTimeout(t,17)};ui.timer=function(){Pt.apply(this,arguments)},ui.timer.flush=function(){Dt(),It()},ui.round=function(t,e){return e?Math.round(t*(e=Math.pow(10,e)))/e:Math.round(t)};var hl=[\"y\",\"z\",\"a\",\"f\",\"p\",\"n\",\"\\xb5\",\"m\",\"\",\"k\",\"M\",\"G\",\"T\",\"P\",\"E\",\"Z\",\"Y\"].map(jt);ui.formatPrefix=function(t,e){var n=0;return(t=+t)&&(0>t&&(t*=-1),e&&(t=ui.round(t,Rt(t,e))),n=1+Math.floor(1e-12+Math.log(t)/Math.LN10),n=Math.max(-24,Math.min(24,3*Math.floor((n-1)/3)))),hl[8+n/3]};var pl=/(?:([^{])?([<>=^]))?([+\\- ])?([$#])?(0)?(\\d+)?(,)?(\\.-?\\d+)?([a-z%])?/i,gl=ui.map({b:function(t){return t.toString(2)},c:function(t){return String.fromCharCode(t)},o:function(t){return t.toString(8)},x:function(t){return t.toString(16)},X:function(t){return t.toString(16).toUpperCase()},g:function(t,e){return t.toPrecision(e)},e:function(t,e){return t.toExponential(e)},f:function(t,e){return t.toFixed(e)},r:function(t,e){return(t=ui.round(t,Rt(t,e))).toFixed(Math.max(0,Math.min(20,Rt(t*(1+1e-15),e))))}}),vl=ui.time={},ml=Date;Bt.prototype={getDate:function(){return this._.getUTCDate()},getDay:function(){return this._.getUTCDay()},getFullYear:function(){return this._.getUTCFullYear()},getHours:function(){return this._.getUTCHours()},getMilliseconds:function(){return this._.getUTCMilliseconds()},getMinutes:function(){return this._.getUTCMinutes()},getMonth:function(){return this._.getUTCMonth()},getSeconds:function(){return this._.getUTCSeconds()},getTime:function(){return this._.getTime()},getTimezoneOffset:function(){return 0},valueOf:function(){return this._.valueOf()},setDate:function(){yl.setUTCDate.apply(this._,arguments)},setDay:function(){yl.setUTCDay.apply(this._,arguments)},setFullYear:function(){yl.setUTCFullYear.apply(this._,arguments)},setHours:function(){yl.setUTCHours.apply(this._,arguments)},setMilliseconds:function(){yl.setUTCMilliseconds.apply(this._,arguments)},setMinutes:function(){yl.setUTCMinutes.apply(this._,arguments)},setMonth:function(){yl.setUTCMonth.apply(this._,arguments)},setSeconds:function(){yl.setUTCSeconds.apply(this._,arguments)},setTime:function(){yl.setTime.apply(this._,arguments)}};var yl=Date.prototype;vl.year=Ht(function(t){return t=vl.day(t),t.setMonth(0,1),t},function(t,e){t.setFullYear(t.getFullYear()+e)},function(t){return t.getFullYear()}),vl.years=vl.year.range,vl.years.utc=vl.year.utc.range,vl.day=Ht(function(t){var e=new ml(2e3,0);return e.setFullYear(t.getFullYear(),t.getMonth(),t.getDate()),e},function(t,e){t.setDate(t.getDate()+e)},function(t){return t.getDate()-1}),vl.days=vl.day.range,vl.days.utc=vl.day.utc.range,vl.dayOfYear=function(t){var e=vl.year(t);return Math.floor((t-e-6e4*(t.getTimezoneOffset()-e.getTimezoneOffset()))/864e5)},[\"sunday\",\"monday\",\"tuesday\",\"wednesday\",\"thursday\",\"friday\",\"saturday\"].forEach(function(t,e){e=7-e;var n=vl[t]=Ht(function(t){return(t=vl.day(t)).setDate(t.getDate()-(t.getDay()+e)%7),t},function(t,e){t.setDate(t.getDate()+7*Math.floor(e))},function(t){var n=vl.year(t).getDay();return Math.floor((vl.dayOfYear(t)+(n+e)%7)/7)-(n!==e)});vl[t+\"s\"]=n.range,vl[t+\"s\"].utc=n.utc.range,vl[t+\"OfYear\"]=function(t){var n=vl.year(t).getDay();return Math.floor((vl.dayOfYear(t)+(n+e)%7)/7)}}),vl.week=vl.sunday,vl.weeks=vl.sunday.range,vl.weeks.utc=vl.sunday.utc.range,vl.weekOfYear=vl.sundayOfYear;var xl={\"-\":\"\",_:\" \",0:\"0\"},bl=/^\\s*\\d+/,_l=/^%/;ui.locale=function(t){return{numberFormat:qt(t),timeFormat:Zt(t)}};var wl=ui.locale({decimal:\".\",thousands:\",\",grouping:[3],currency:[\"$\",\"\"],dateTime:\"%a %b %e %X %Y\",date:\"%m/%d/%Y\",time:\"%H:%M:%S\",periods:[\"AM\",\"PM\"],days:[\"Sunday\",\"Monday\",\"Tuesday\",\"Wednesday\",\"Thursday\",\"Friday\",\"Saturday\"],shortDays:[\"Sun\",\"Mon\",\"Tue\",\"Wed\",\"Thu\",\"Fri\",\"Sat\"],months:[\"January\",\"February\",\"March\",\"April\",\"May\",\"June\",\"July\",\"August\",\"September\",\"October\",\"November\",\"December\"],shortMonths:[\"Jan\",\"Feb\",\"Mar\",\"Apr\",\"May\",\"Jun\",\"Jul\",\"Aug\",\"Sep\",\"Oct\",\"Nov\",\"Dec\"]});ui.format=wl.numberFormat,ui.geo={},fe.prototype={s:0,t:0,add:function(t){de(t,this.t,kl),de(kl.s,this.s,this),this.s?this.t+=kl.t:this.s=kl.t},reset:function(){this.s=this.t=0},valueOf:function(){return this.s}};var kl=new fe;ui.geo.stream=function(t,e){t&&Ml.hasOwnProperty(t.type)?Ml[t.type](t,e):he(t,e)};var Ml={Feature:function(t,e){he(t.geometry,e)},FeatureCollection:function(t,e){for(var n=t.features,r=-1,a=n.length;++r<a;)he(n[r].geometry,e)}},Al={Sphere:function(t,e){e.sphere()},Point:function(t,e){t=t.coordinates,e.point(t[0],t[1],t[2])},MultiPoint:function(t,e){for(var n=t.coordinates,r=-1,a=n.length;++r<a;)t=n[r],e.point(t[0],t[1],t[2])},LineString:function(t,e){pe(t.coordinates,e,0)},MultiLineString:function(t,e){for(var n=t.coordinates,r=-1,a=n.length;++r<a;)pe(n[r],e,0)},Polygon:function(t,e){ge(t.coordinates,e)},MultiPolygon:function(t,e){for(var n=t.coordinates,r=-1,a=n.length;++r<a;)ge(n[r],e)},GeometryCollection:function(t,e){for(var n=t.geometries,r=-1,a=n.length;++r<a;)he(n[r],e)}};ui.geo.area=function(t){return Ll=0,ui.geo.stream(t,zl),Ll};var Ll,Tl=new fe,zl={sphere:function(){Ll+=4*Bi},point:k,lineStart:k,lineEnd:k,polygonStart:function(){Tl.reset(),zl.lineStart=ve},polygonEnd:function(){var t=2*Tl;Ll+=0>t?4*Bi+t:t,zl.lineStart=zl.lineEnd=zl.point=k}};ui.geo.bounds=function(){function t(t,e){x.push(b=[u=t,d=t]),f>e&&(f=e),e>h&&(h=e)}function e(e,n){var r=me([e*Yi,n*Yi]);if(m){var a=xe(m,r),o=[a[1],-a[0],0],i=xe(o,a);we(i),i=ke(i);var s=e-p,c=s>0?1:-1,g=i[0]*Ui*c,v=wi(s)>180;if(v^(g>c*p&&c*e>g)){var y=i[1]*Ui;y>h&&(h=y)}else if(g=(g+360)%360-180,v^(g>c*p&&c*e>g)){var y=-i[1]*Ui;f>y&&(f=y)}else f>n&&(f=n),n>h&&(h=n);v?p>e?l(u,e)>l(u,d)&&(d=e):l(e,d)>l(u,d)&&(u=e):d>=u?(u>e&&(u=e),e>d&&(d=e)):e>p?l(u,e)>l(u,d)&&(d=e):l(e,d)>l(u,d)&&(u=e)}else t(e,n);m=r,p=e}function n(){_.point=e}function r(){b[0]=u,b[1]=d,_.point=t,m=null}function a(t,n){if(m){var r=t-p;y+=wi(r)>180?r+(r>0?360:-360):r}else g=t,v=n;zl.point(t,n),e(t,n)}function o(){zl.lineStart()}function i(){a(g,v),zl.lineEnd(),wi(y)>qi&&(u=-(d=180)),b[0]=u,b[1]=d,m=null}function l(t,e){return(e-=t)<0?e+360:e}function s(t,e){return t[0]-e[0]}function c(t,e){return e[0]<=e[1]?e[0]<=t&&t<=e[1]:t<e[0]||e[1]<t}var u,f,d,h,p,g,v,m,y,x,b,_={point:t,lineStart:n,lineEnd:r,polygonStart:function(){_.point=a,_.lineStart=o,_.lineEnd=i,y=0,zl.polygonStart()},polygonEnd:function(){zl.polygonEnd(),_.point=t,_.lineStart=n,_.lineEnd=r,0>Tl?(u=-(d=180),f=-(h=90)):y>qi?h=90:-qi>y&&(f=-90),b[0]=u,b[1]=d}};return function(t){h=d=-(u=f=1/0),x=[],ui.geo.stream(t,_);var e=x.length;if(e){x.sort(s);for(var n,r=1,a=x[0],o=[a];e>r;++r)n=x[r],c(n[0],a)||c(n[1],a)?(l(a[0],n[1])>l(a[0],a[1])&&(a[1]=n[1]),l(n[0],a[1])>l(a[0],a[1])&&(a[0]=n[0])):o.push(a=n);for(var i,n,p=-(1/0),e=o.length-1,r=0,a=o[e];e>=r;a=n,++r)n=o[r],(i=l(a[1],n[0]))>p&&(p=i,u=n[0],d=a[1])}return x=b=null,u===1/0||f===1/0?[[NaN,NaN],[NaN,NaN]]:"
,
"[[u,f],[d,h]]}}(),ui.geo.centroid=function(t){Sl=El=Cl=Ol=Pl=Nl=Dl=Il=Rl=jl=ql=0,ui.geo.stream(t,Fl);var e=Rl,n=jl,r=ql,a=e*e+n*n+r*r;return Fi>a&&(e=Nl,n=Dl,r=Il,qi>El&&(e=Cl,n=Ol,r=Pl),a=e*e+n*n+r*r,Fi>a)?[NaN,NaN]:[Math.atan2(n,e)*Ui,rt(r/Math.sqrt(a))*Ui]};var Sl,El,Cl,Ol,Pl,Nl,Dl,Il,Rl,jl,ql,Fl={sphere:k,point:Ae,lineStart:Te,lineEnd:ze,polygonStart:function(){Fl.lineStart=Se},polygonEnd:function(){Fl.lineStart=Te}},Bl=De(Ce,qe,Be,[-Bi,-Bi/2]),Hl=1e9;ui.geo.clipExtent=function(){var t,e,n,r,a,o,i={stream:function(t){return a&&(a.valid=!1),a=o(t),a.valid=!0,a},extent:function(l){return arguments.length?(o=Ye(t=+l[0][0],e=+l[0][1],n=+l[1][0],r=+l[1][1]),a&&(a.valid=!1,a=null),i):[[t,e],[n,r]]}};return i.extent([[0,0],[960,500]])},(ui.geo.conicEqualArea=function(){return Ue(Xe)}).raw=Xe,ui.geo.albers=function(){return ui.geo.conicEqualArea().rotate([96,0]).center([-.6,38.7]).parallels([29.5,45.5]).scale(1070)},ui.geo.albersUsa=function(){function t(t){var o=t[0],i=t[1];return e=null,n(o,i),e||(r(o,i),e)||a(o,i),e}var e,n,r,a,o=ui.geo.albers(),i=ui.geo.conicEqualArea().rotate([154,0]).center([-2,58.5]).parallels([55,65]),l=ui.geo.conicEqualArea().rotate([157,0]).center([-3,19.9]).parallels([8,18]),s={point:function(t,n){e=[t,n]}};return t.invert=function(t){var e=o.scale(),n=o.translate(),r=(t[0]-n[0])/e,a=(t[1]-n[1])/e;return(a>=.12&&.234>a&&r>=-.425&&-.214>r?i:a>=.166&&.234>a&&r>=-.214&&-.115>r?l:o).invert(t)},t.stream=function(t){var e=o.stream(t),n=i.stream(t),r=l.stream(t);return{point:function(t,a){e.point(t,a),n.point(t,a),r.point(t,a)},sphere:function(){e.sphere(),n.sphere(),r.sphere()},lineStart:function(){e.lineStart(),n.lineStart(),r.lineStart()},lineEnd:function(){e.lineEnd(),n.lineEnd(),r.lineEnd()},polygonStart:function(){e.polygonStart(),n.polygonStart(),r.polygonStart()},polygonEnd:function(){e.polygonEnd(),n.polygonEnd(),r.polygonEnd()}}},t.precision=function(e){return arguments.length?(o.precision(e),i.precision(e),l.precision(e),t):o.precision()},t.scale=function(e){return arguments.length?(o.scale(e),i.scale(.35*e),l.scale(e),t.translate(o.translate())):o.scale()},t.translate=function(e){if(!arguments.length)return o.translate();var c=o.scale(),u=+e[0],f=+e[1];return n=o.translate(e).clipExtent([[u-.455*c,f-.238*c],[u+.455*c,f+.238*c]]).stream(s).point,r=i.translate([u-.307*c,f+.201*c]).clipExtent([[u-.425*c+qi,f+.12*c+qi],[u-.214*c-qi,f+.234*c-qi]]).stream(s).point,a=l.translate([u-.205*c,f+.212*c]).clipExtent([[u-.214*c+qi,f+.166*c+qi],[u-.115*c-qi,f+.234*c-qi]]).stream(s).point,t},t.scale(1070)};var Vl,Zl,Yl,Ul,Xl,Gl,$l={point:k,lineStart:k,lineEnd:k,polygonStart:function(){Zl=0,$l.lineStart=Ge},polygonEnd:function(){$l.lineStart=$l.lineEnd=$l.point=k,Vl+=wi(Zl/2)}},Ql={point:$e,lineStart:k,lineEnd:k,polygonStart:k,polygonEnd:k},Wl={point:Je,lineStart:Ke,lineEnd:tn,polygonStart:function(){Wl.lineStart=en},polygonEnd:function(){Wl.point=Je,Wl.lineStart=Ke,Wl.lineEnd=tn}};ui.geo.path=function(){function t(t){return t&&(\"function\"==typeof l&&o.pointRadius(+l.apply(this,arguments)),i&&i.valid||(i=a(o)),ui.geo.stream(t,i)),o.result()}function e(){return i=null,t}var n,r,a,o,i,l=4.5;return t.area=function(t){return Vl=0,ui.geo.stream(t,a($l)),Vl},t.centroid=function(t){return Cl=Ol=Pl=Nl=Dl=Il=Rl=jl=ql=0,ui.geo.stream(t,a(Wl)),ql?[Rl/ql,jl/ql]:Il?[Nl/Il,Dl/Il]:Pl?[Cl/Pl,Ol/Pl]:[NaN,NaN]},t.bounds=function(t){return Xl=Gl=-(Yl=Ul=1/0),ui.geo.stream(t,a(Ql)),[[Yl,Ul],[Xl,Gl]]},t.projection=function(t){return arguments.length?(a=(n=t)?t.stream||an(t):b,e()):n},t.context=function(t){return arguments.length?(o=null==(r=t)?new Qe:new nn(t),\"function\"!=typeof l&&o.pointRadius(l),e()):r},t.pointRadius=function(e){return arguments.length?(l=\"function\"==typeof e?e:(o.pointRadius(+e),+e),t):l},t.projection(ui.geo.albersUsa()).context(null)},ui.geo.transform=function(t){return{stream:function(e){var n=new on(e);for(var r in t)n[r]=t[r];return n}}},on.prototype={point:function(t,e){this.stream.point(t,e)},sphere:function(){this.stream.sphere()},lineStart:function(){this.stream.lineStart()},lineEnd:function(){this.stream.lineEnd()},polygonStart:function(){this.stream.polygonStart()},polygonEnd:function(){this.stream.polygonEnd()}},ui.geo.projection=sn,ui.geo.projectionMutator=cn,(ui.geo.equirectangular=function(){return sn(fn)}).raw=fn.invert=fn,ui.geo.rotation=function(t){function e(e){return e=t(e[0]*Yi,e[1]*Yi),e[0]*=Ui,e[1]*=Ui,e}return t=hn(t[0]%360*Yi,t[1]*Yi,t.length>2?t[2]*Yi:0),e.invert=function(e){return e=t.invert(e[0]*Yi,e[1]*Yi),e[0]*=Ui,e[1]*=Ui,e},e},dn.invert=fn,ui.geo.circle=function(){function t(){var t=\"function\"==typeof r?r.apply(this,arguments):r,e=hn(-t[0]*Yi,-t[1]*Yi,0).invert,a=[];return n(null,null,1,{point:function(t,n){a.push(t=e(t,n)),t[0]*=Ui,t[1]*=Ui}}),{type:\"Polygon\",coordinates:[a]}}var e,n,r=[0,0],a=6;return t.origin=function(e){return arguments.length?(r=e,t):r},t.angle=function(r){return arguments.length?(n=mn((e=+r)*Yi,a*Yi),t):e},t.precision=function(r){return arguments.length?(n=mn(e*Yi,(a=+r)*Yi),t):a},t.angle(90)},ui.geo.distance=function(t,e){var n,r=(e[0]-t[0])*Yi,a=t[1]*Yi,o=e[1]*Yi,i=Math.sin(r),l=Math.cos(r),s=Math.sin(a),c=Math.cos(a),u=Math.sin(o),f=Math.cos(o);return Math.atan2(Math.sqrt((n=f*i)*n+(n=c*u-s*f*l)*n),s*u+c*f*l)},ui.geo.graticule=function(){function t(){return{type:\"MultiLineString\",coordinates:e()}}function e(){return ui.range(Math.ceil(o/v)*v,a,v).map(d).concat(ui.range(Math.ceil(c/m)*m,s,m).map(h)).concat(ui.range(Math.ceil(r/p)*p,n,p).filter(function(t){return wi(t%v)>qi}).map(u)).concat(ui.range(Math.ceil(l/g)*g,i,g).filter(function(t){return wi(t%m)>qi}).map(f))}var n,r,a,o,i,l,s,c,u,f,d,h,p=10,g=p,v=90,m=360,y=2.5;return t.lines=function(){return e().map(function(t){return{type:\"LineString\",coordinates:t}})},t.outline=function(){return{type:\"Polygon\",coordinates:[d(o).concat(h(s).slice(1),d(a).reverse().slice(1),h(c).reverse().slice(1))]}},t.extent=function(e){return arguments.length?t.majorExtent(e).minorExtent(e):t.minorExtent()},t.majorExtent=function(e){return arguments.length?(o=+e[0][0],a=+e[1][0],c=+e[0][1],s=+e[1][1],o>a&&(e=o,o=a,a=e),c>s&&(e=c,c=s,s=e),t.precision(y)):[[o,c],[a,s]]},t.minorExtent=function(e){return arguments.length?(r=+e[0][0],n=+e[1][0],l=+e[0][1],i=+e[1][1],r>n&&(e=r,r=n,n=e),l>i&&(e=l,l=i,i=e),t.precision(y)):[[r,l],[n,i]]},t.step=function(e){return arguments.length?t.majorStep(e).minorStep(e):t.minorStep()},t.majorStep=function(e){return arguments.length?(v=+e[0],m=+e[1],t):[v,m]},t.minorStep=function(e){return arguments.length?(p=+e[0],g=+e[1],t):[p,g]},t.precision=function(e){return arguments.length?(y=+e,u=xn(l,i,90),f=bn(r,n,y),d=xn(c,s,90),h=bn(o,a,y),t):y},t.majorExtent([[-180,-90+qi],[180,90-qi]]).minorExtent([[-180,-80-qi],[180,80+qi]])},ui.geo.greatArc=function(){function t(){return{type:\"LineString\",coordinates:[e||r.apply(this,arguments),n||a.apply(this,arguments)]}}var e,n,r=_n,a=wn;return t.distance=function(){return ui.geo.distance(e||r.apply(this,arguments),n||a.apply(this,arguments))},t.source=function(n){return arguments.length?(r=n,e=\"function\"==typeof n?null:n,t):r},t.target=function(e){return arguments.length?(a=e,n=\"function\"==typeof e?null:e,t):a},t.precision=function(){return arguments.length?t:0},t},ui.geo.interpolate=function(t,e){return kn(t[0]*Yi,t[1]*Yi,e[0]*Yi,e[1]*Yi)},ui.geo.length=function(t){return Jl=0,ui.geo.stream(t,Kl),Jl};var Jl,Kl={sphere:k,point:k,lineStart:Mn,lineEnd:k,polygonStart:k,polygonEnd:k},ts=An(function(t){return Math.sqrt(2/(1+t))},function(t){return 2*Math.asin(t/2)});(ui.geo.azimuthalEqualArea=function(){return sn(ts)}).raw=ts;var es=An(function(t){var e=Math.acos(t);return e&&e/Math.sin(e)},b);(ui.geo.azimuthalEquidistant=function(){return sn(es)}).raw=es,(ui.geo.conicConformal=function(){return Ue(Ln)}).raw=Ln,(ui.geo.conicEquidistant=function(){return Ue(Tn)}).raw=Tn;var ns=An(function(t){return 1/t},Math.atan);(ui.geo.gnomonic=function(){return sn(ns)}).raw=ns,zn.invert=function(t,e){return[t,2*Math.atan(Math.exp(e))-Zi]},(ui.geo.mercator=function(){return Sn(zn)}).raw=zn;var rs=An(function(){return 1},Math.asin);(ui.geo.orthographic=function(){return sn(rs)}).raw=rs;var as=An(function(t){return 1/(1+t)},function(t){return 2*Math.atan(t)});(ui.geo.stereographic=function(){return sn(as)}).raw=as,En.invert=function(t,e){return[-e,2*Math.atan(Math.exp(t))-Zi]},(ui.geo.transverseMercator=function(){var t=Sn(En),e=t.center,n=t.rotate;return t.center=function(t){return t?e([-t[1],t[0]]):(t=e(),[t[1],-t[0]])},t.rotate=function(t){return t?n([t[0],t[1],t.length>2?t[2]+90:90]):(t=n(),[t[0],t[1],t[2]-90])},n([0,0,90])}).raw=En,ui.geom={},ui.geom.hull=function(t){function e(t){if(t.length<3)return[];var e,a=zt(n),o=zt(r),i=t.length,l=[],s=[];for(e=0;i>e;e++)l.push([+a.call(this,t[e],e),+o.call(this,t[e],e),e]);for(l.sort(Nn),e=0;i>e;e++)s.push([l[e][0],-l[e][1]]);var c=Pn(l),u=Pn(s),f=u[0]===c[0],d=u[u.length-1]===c[c.length-1],h=[];for(e=c.length-1;e>=0;--e)h.push(t[l[c[e]][2]]);for(e=+f;e<u.length-d;++e)h.push(t[l[u[e]][2]]);return h}var n=Cn,r=On;return arguments.length?e(t):(e.x=function(t){return arguments.length?(n=t,e):n},e.y=function(t){return arguments.length?(r=t,e):r},e)},ui.geom.polygon=function(t){return Ti(t,os),t};var os=ui.geom.polygon.prototype=[];os.area=function(){for(var t,e=-1,n=this.length,r=this[n-1],a=0;++e<n;)t=r,r=this[e],a+=t[1]*r[0]-t[0]*r[1];return.5*a},os.centroid=function(t){var e,n,r=-1,a=this.length,o=0,i=0,l=this[a-1];for(arguments.length||(t=-1/(6*this.area()));++r<a;)e=l,l=this[r],n=e[0]*l[1]-l[0]*e[1],o+=(e[0]+l[0])*n,i+=(e[1]+l[1])*n;return[o*t,i*t]},os.clip=function(t){for(var e,n,r,a,o,i,l=Rn(t),s=-1,c=this.length-Rn(this),u=this[c-1];++s<c;){for(e=t.slice(),t.length=0,a=this[s],o=e[(r=e.length-l)-1],n=-1;++n<r;)i=e[n],Dn(i,u,a)?(Dn(o,u,a)||t.push(In(o,i,u,a)),t.push(i)):Dn(o,u,a)&&t.push(In(o,i,u,a)),o=i;l&&t.push(t[0]),u=a}return t};var is,ls,ss,cs,us,fs=[],ds=[];Yn.prototype.prepare=function(){for(var t,e=this.edges,n=e"
,
".length;n--;)t=e[n].edge,t.b&&t.a||e.splice(n,1);return e.sort(Xn),e.length},rr.prototype={start:function(){return this.edge.l===this.site?this.edge.a:this.edge.b},end:function(){return this.edge.l===this.site?this.edge.b:this.edge.a}},ar.prototype={insert:function(t,e){var n,r,a;if(t){if(e.P=t,e.N=t.N,t.N&&(t.N.P=e),t.N=e,t.R){for(t=t.R;t.L;)t=t.L;t.L=e}else t.R=e;n=t}else this._?(t=sr(this._),e.P=null,e.N=t,t.P=t.L=e,n=t):(e.P=e.N=null,this._=e,n=null);for(e.L=e.R=null,e.U=n,e.C=!0,t=e;n&&n.C;)r=n.U,n===r.L?(a=r.R,a&&a.C?(n.C=a.C=!1,r.C=!0,t=r):(t===n.R&&(ir(this,n),t=n,n=t.U),n.C=!1,r.C=!0,lr(this,r))):(a=r.L,a&&a.C?(n.C=a.C=!1,r.C=!0,t=r):(t===n.L&&(lr(this,n),t=n,n=t.U),n.C=!1,r.C=!0,ir(this,r))),n=t.U;this._.C=!1},remove:function(t){t.N&&(t.N.P=t.P),t.P&&(t.P.N=t.N),t.N=t.P=null;var e,n,r,a=t.U,o=t.L,i=t.R;if(n=o?i?sr(i):o:i,a?a.L===t?a.L=n:a.R=n:this._=n,o&&i?(r=n.C,n.C=t.C,n.L=o,o.U=n,n!==i?(a=n.U,n.U=t.U,t=n.R,a.L=t,n.R=i,i.U=n):(n.U=a,a=n,t=n.R)):(r=t.C,t=n),t&&(t.U=a),!r){if(t&&t.C)return void(t.C=!1);do{if(t===this._)break;if(t===a.L){if(e=a.R,e.C&&(e.C=!1,a.C=!0,ir(this,a),e=a.R),e.L&&e.L.C||e.R&&e.R.C){e.R&&e.R.C||(e.L.C=!1,e.C=!0,lr(this,e),e=a.R),e.C=a.C,a.C=e.R.C=!1,ir(this,a),t=this._;break}}else if(e=a.L,e.C&&(e.C=!1,a.C=!0,lr(this,a),e=a.L),e.L&&e.L.C||e.R&&e.R.C){e.L&&e.L.C||(e.R.C=!1,e.C=!0,ir(this,e),e=a.L),e.C=a.C,a.C=e.L.C=!1,lr(this,a),t=this._;break}e.C=!0,t=a,a=a.U}while(!t.C);t&&(t.C=!1)}}},ui.geom.voronoi=function(t){function e(t){var e=new Array(t.length),r=l[0][0],a=l[0][1],o=l[1][0],i=l[1][1];return cr(n(t),l).cells.forEach(function(n,l){var s=n.edges,c=n.site,u=e[l]=s.length?s.map(function(t){var e=t.start();return[e.x,e.y]}):c.x>=r&&c.x<=o&&c.y>=a&&c.y<=i?[[r,i],[o,i],[o,a],[r,a]]:[];u.point=t[l]}),e}function n(t){return t.map(function(t,e){return{x:Math.round(o(t,e)/qi)*qi,y:Math.round(i(t,e)/qi)*qi,i:e}})}var r=Cn,a=On,o=r,i=a,l=hs;return t?e(t):(e.links=function(t){return cr(n(t)).edges.filter(function(t){return t.l&&t.r}).map(function(e){\n"
,
"return{source:t[e.l.i],target:t[e.r.i]}})},e.triangles=function(t){var e=[];return cr(n(t)).cells.forEach(function(n,r){for(var a,o,i=n.site,l=n.edges.sort(Xn),s=-1,c=l.length,u=l[c-1].edge,f=u.l===i?u.r:u.l;++s<c;)a=u,o=f,u=l[s].edge,f=u.l===i?u.r:u.l,r<o.i&&r<f.i&&fr(i,o,f)<0&&e.push([t[r],t[o.i],t[f.i]])}),e},e.x=function(t){return arguments.length?(o=zt(r=t),e):r},e.y=function(t){return arguments.length?(i=zt(a=t),e):a},e.clipExtent=function(t){return arguments.length?(l=null==t?hs:t,e):l===hs?null:l},e.size=function(t){return arguments.length?e.clipExtent(t&&[[0,0],t]):l===hs?null:l&&l[1]},e)};var hs=[[-1e6,-1e6],[1e6,1e6]];ui.geom.delaunay=function(t){return ui.geom.voronoi().triangles(t)},ui.geom.quadtree=function(t,e,n,r,a){function o(t){function o(t,e,n,r,a,o,i,l){if(!isNaN(n)&&!isNaN(r))if(t.leaf){var s=t.x,u=t.y;if(null!=s)if(wi(s-n)+wi(u-r)<.01)c(t,e,n,r,a,o,i,l);else{var f=t.point;t.x=t.y=t.point=null,c(t,f,s,u,a,o,i,l),c(t,e,n,r,a,o,i,l)}else t.x=n,t.y=r,t.point=e}else c(t,e,n,r,a,o,i,l)}function c(t,e,n,r,a,i,l,s){var c=.5*(a+l),u=.5*(i+s),f=n>=c,d=r>=u,h=d<<1|f;t.leaf=!1,t=t.nodes[h]||(t.nodes[h]=pr()),f?a=c:l=c,d?i=u:s=u,o(t,e,n,r,a,i,l,s)}var u,f,d,h,p,g,v,m,y,x=zt(l),b=zt(s);if(null!=e)g=e,v=n,m=r,y=a;else if(m=y=-(g=v=1/0),f=[],d=[],p=t.length,i)for(h=0;p>h;++h)u=t[h],u.x<g&&(g=u.x),u.y<v&&(v=u.y),u.x>m&&(m=u.x),u.y>y&&(y=u.y),f.push(u.x),d.push(u.y);else for(h=0;p>h;++h){var _=+x(u=t[h],h),w=+b(u,h);g>_&&(g=_),v>w&&(v=w),_>m&&(m=_),w>y&&(y=w),f.push(_),d.push(w)}var k=m-g,M=y-v;k>M?y=v+k:m=g+M;var A=pr();if(A.add=function(t){o(A,t,+x(t,++h),+b(t,h),g,v,m,y)},A.visit=function(t){gr(t,A,g,v,m,y)},A.find=function(t){return vr(A,t[0],t[1],g,v,m,y)},h=-1,null==e){for(;++h<p;)o(A,t[h],f[h],d[h],g,v,m,y);--h}else t.forEach(A.add);return f=d=t=u=null,A}var i,l=Cn,s=On;return(i=arguments.length)?(l=dr,s=hr,3===i&&(a=n,r=e,n=e=0),o(t)):(o.x=function(t){return arguments.length?(l=t,o):l},o.y=function(t){return arguments.length?(s=t,o):s},o.extent=function(t){return arguments.length?(null==t?e=n=r=a=null:(e=+t[0][0],n=+t[0][1],r=+t[1][0],a=+t[1][1]),o):null==e?null:[[e,n],[r,a]]},o.size=function(t){return arguments.length?(null==t?e=n=r=a=null:(e=n=0,r=+t[0],a=+t[1]),o):null==e?null:[r-e,a-n]},o)},ui.interpolateRgb=mr,ui.interpolateObject=yr,ui.interpolateNumber=xr,ui.interpolateString=br;var ps=/[-+]?(?:\\d+\\.?\\d*|\\.?\\d+)(?:[eE][-+]?\\d+)?/g,gs=new RegExp(ps.source,\"g\");ui.interpolate=_r,ui.interpolators=[function(t,e){var n=typeof e;return(\"string\"===n?ll.has(e.toLowerCase())||/^(#|rgb\\(|hsl\\()/i.test(e)?mr:br:e instanceof st?mr:Array.isArray(e)?wr:\"object\"===n&&isNaN(e)?yr:xr)(t,e)}],ui.interpolateArray=wr;var vs=function(){return b},ms=ui.map({linear:vs,poly:Sr,quad:function(){return Lr},cubic:function(){return Tr},sin:function(){return Er},exp:function(){return Cr},circle:function(){return Or},elastic:Pr,back:Nr,bounce:function(){return Dr}}),ys=ui.map({\"in\":b,out:Mr,\"in-out\":Ar,\"out-in\":function(t){return Ar(Mr(t))}});ui.ease=function(t){var e=t.indexOf(\"-\"),n=e>=0?t.slice(0,e):t,r=e>=0?t.slice(e+1):\"in\";return n=ms.get(n)||vs,r=ys.get(r)||b,kr(r(n.apply(null,fi.call(arguments,1))))},ui.interpolateHcl=Ir,ui.interpolateHsl=Rr,ui.interpolateLab=jr,ui.interpolateRound=qr,ui.transform=function(t){var e=hi.createElementNS(ui.ns.prefix.svg,\"g\");return(ui.transform=function(t){if(null!=t){e.setAttribute(\"transform\",t);var n=e.transform.baseVal.consolidate()}return new Fr(n?n.matrix:xs)})(t)},Fr.prototype.toString=function(){return\"translate(\"+this.translate+\")rotate(\"+this.rotate+\")skewX(\"+this.skew+\")scale(\"+this.scale+\")\"};var xs={a:1,b:0,c:0,d:1,e:0,f:0};ui.interpolateTransform=$r,ui.layout={},ui.layout.bundle=function(){return function(t){for(var e=[],n=-1,r=t.length;++n<r;)e.push(Jr(t[n]));return e}},ui.layout.chord=function(){function t(){var t,c,f,d,h,p={},g=[],v=ui.range(o),m=[];for(n=[],r=[],t=0,d=-1;++d<o;){for(c=0,h=-1;++h<o;)c+=a[d][h];g.push(c),m.push(ui.range(o)),t+=c}for(i&&v.sort(function(t,e){return i(g[t],g[e])}),l&&m.forEach(function(t,e){t.sort(function(t,n){return l(a[e][t],a[e][n])})}),t=(Hi-u*o)/t,c=0,d=-1;++d<o;){for(f=c,h=-1;++h<o;){var y=v[d],x=m[y][h],b=a[y][x],_=c,w=c+=b*t;p[y+\"-\"+x]={index:y,subindex:x,startAngle:_,endAngle:w,value:b}}r[y]={index:y,startAngle:f,endAngle:c,value:g[y]},c+=u}for(d=-1;++d<o;)for(h=d-1;++h<o;){var k=p[d+\"-\"+h],M=p[h+\"-\"+d];(k.value||M.value)&&n.push(k.value<M.value?{source:M,target:k}:{source:k,target:M})}s&&e()}function e(){n.sort(function(t,e){return s((t.source.value+t.target.value)/2,(e.source.value+e.target.value)/2)})}var n,r,a,o,i,l,s,c={},u=0;return c.matrix=function(t){return arguments.length?(o=(a=t)&&a.length,n=r=null,c):a},c.padding=function(t){return arguments.length?(u=t,n=r=null,c):u},c.sortGroups=function(t){return arguments.length?(i=t,n=r=null,c):i},c.sortSubgroups=function(t){return arguments.length?(l=t,n=null,c):l},c.sortChords=function(t){return arguments.length?(s=t,n&&e(),c):s},c.chords=function(){return n||t(),n},c.groups=function(){return r||t(),r},c},ui.layout.force=function(){function t(t){return function(e,n,r,a){if(e.point!==t){var o=e.cx-t.x,i=e.cy-t.y,l=a-n,s=o*o+i*i;if(s>l*l/m){if(g>s){var c=e.charge/s;t.px-=o*c,t.py-=i*c}return!0}if(e.point&&s&&g>s){var c=e.pointCharge/s;t.px-=o*c,t.py-=i*c}}return!e.charge}}function e(t){t.px=ui.event.x,t.py=ui.event.y,s.resume()}var n,r,a,o,i,l,s={},c=ui.dispatch(\"start\",\"tick\",\"end\"),u=[1,1],f=.9,d=bs,h=_s,p=-30,g=ws,v=.1,m=.64,y=[],x=[];return s.tick=function(){if((a*=.99)<.005)return n=null,c.end({type:\"end\",alpha:a=0}),!0;var e,r,s,d,h,g,m,b,_,w=y.length,k=x.length;for(r=0;k>r;++r)s=x[r],d=s.source,h=s.target,b=h.x-d.x,_=h.y-d.y,(g=b*b+_*_)&&(g=a*i[r]*((g=Math.sqrt(g))-o[r])/g,b*=g,_*=g,h.x-=b*(m=d.weight+h.weight?d.weight/(d.weight+h.weight):.5),h.y-=_*m,d.x+=b*(m=1-m),d.y+=_*m);if((m=a*v)&&(b=u[0]/2,_=u[1]/2,r=-1,m))for(;++r<w;)s=y[r],s.x+=(b-s.x)*m,s.y+=(_-s.y)*m;if(p)for(oa(e=ui.geom.quadtree(y),a,l),r=-1;++r<w;)(s=y[r]).fixed||e.visit(t(s));for(r=-1;++r<w;)s=y[r],s.fixed?(s.x=s.px,s.y=s.py):(s.x-=(s.px-(s.px=s.x))*f,s.y-=(s.py-(s.py=s.y))*f);c.tick({type:\"tick\",alpha:a})},s.nodes=function(t){return arguments.length?(y=t,s):y},s.links=function(t){return arguments.length?(x=t,s):x},s.size=function(t){return arguments.length?(u=t,s):u},s.linkDistance=function(t){return arguments.length?(d=\"function\"==typeof t?t:+t,s):d},s.distance=s.linkDistance,s.linkStrength=function(t){return arguments.length?(h=\"function\"==typeof t?t:+t,s):h},s.friction=function(t){return arguments.length?(f=+t,s):f},s.charge=function(t){return arguments.length?(p=\"function\"==typeof t?t:+t,s):p},s.chargeDistance=function(t){return arguments.length?(g=t*t,s):Math.sqrt(g)},s.gravity=function(t){return arguments.length?(v=+t,s):v},s.theta=function(t){return arguments.length?(m=t*t,s):Math.sqrt(m)},s.alpha=function(t){return arguments.length?(t=+t,a?t>0?a=t:(n.c=null,n.t=NaN,n=null,c.end({type:\"end\",alpha:a=0})):t>0&&(c.start({type:\"start\",alpha:a=t}),n=Pt(s.tick)),s):a},s.start=function(){function t(t,r){if(!n){for(n=new Array(a),s=0;a>s;++s)n[s]=[];for(s=0;c>s;++s){var o=x[s];n[o.source.index].push(o.target),n[o.target.index].push(o.source)}}for(var i,l=n[e],s=-1,u=l.length;++s<u;)if(!isNaN(i=l[s][t]))return i;return Math.random()*r}var e,n,r,a=y.length,c=x.length,f=u[0],g=u[1];for(e=0;a>e;++e)(r=y[e]).index=e,r.weight=0;for(e=0;c>e;++e)r=x[e],\"number\"==typeof r.source&&(r.source=y[r.source]),\"number\"==typeof r.target&&(r.target=y[r.target]),++r.source.weight,++r.target.weight;for(e=0;a>e;++e)r=y[e],isNaN(r.x)&&(r.x=t(\"x\",f)),isNaN(r.y)&&(r.y=t(\"y\",g)),isNaN(r.px)&&(r.px=r.x),isNaN(r.py)&&(r.py=r.y);if(o=[],\"function\"==typeof d)for(e=0;c>e;++e)o[e]=+d.call(this,x[e],e);else for(e=0;c>e;++e)o[e]=d;if(i=[],\"function\"==typeof h)for(e=0;c>e;++e)i[e]=+h.call(this,x[e],e);else for(e=0;c>e;++e)i[e]=h;if(l=[],\"function\"==typeof p)for(e=0;a>e;++e)l[e]=+p.call(this,y[e],e);else for(e=0;a>e;++e)l[e]=p;return s.resume()},s.resume=function(){return s.alpha(.1)},s.stop=function(){return s.alpha(0)},s.drag=function(){return r||(r=ui.behavior.drag().origin(b).on(\"dragstart.force\",ea).on(\"drag.force\",e).on(\"dragend.force\",na)),arguments.length?void this.on(\"mouseover.force\",ra).on(\"mouseout.force\",aa).call(r):r},ui.rebind(s,c,\"on\")};var bs=20,_s=1,ws=1/0;ui.layout.hierarchy=function(){function t(a){var o,i=[a],l=[];for(a.depth=0;null!=(o=i.pop());)if(l.push(o),(c=n.call(t,o,o.depth))&&(s=c.length)){for(var s,c,u;--s>=0;)i.push(u=c[s]),u.parent=o,u.depth=o.depth+1;r&&(o.value=0),o.children=c}else r&&(o.value=+r.call(t,o,o.depth)||0),delete o.children;return sa(a,function(t){var n,a;e&&(n=t.children)&&n.sort(e),r&&(a=t.parent)&&(a.value+=t.value)}),l}var e=fa,n=ca,r=ua;return t.sort=function(n){return arguments.length?(e=n,t):e},t.children=function(e){return arguments.length?(n=e,t):n},t.value=function(e){return arguments.length?(r=e,t):r},t.revalue=function(e){return r&&(la(e,function(t){t.children&&(t.value=0)}),sa(e,function(e){var n;e.children||(e.value=+r.call(t,e,e.depth)||0),(n=e.parent)&&(n.value+=e.value)})),e},t},ui.layout.partition=function(){function t(e,n,r,a){var o=e.children;if(e.x=n,e.y=e.depth*a,e.dx=r,e.dy=a,o&&(i=o.length)){var i,l,s,c=-1;for(r=e.value?r/e.value:0;++c<i;)t(l=o[c],n,s=l.value*r,a),n+=s}}function e(t){var n=t.children,r=0;if(n&&(a=n.length))for(var a,o=-1;++o<a;)r=Math.max(r,e(n[o]));return 1+r}function n(n,o){var i=r.call(this,n,o);return t(i[0],0,a[0],a[1]/e(i[0])),i}var r=ui.layout.hierarchy(),a=[1,1];return n.size=function(t){return arguments.length?(a=t,n):a},ia(n,r)},ui.layout.pie=function(){function t(i){var l,s=i.length,c=i.map(function(n,r){return+e.call(t,n,r)}),u=+(\"function\"==typeof r?r.apply(this,arguments):r),f=(\"function\"==typeof a?a.apply(this,arguments):a)-u,d=Math.min(Math.abs(f)/s,+(\"function\"==typeof o?o.apply(this,arguments):o)),h=d*(0>f?-1:1),p=ui.sum(c),g=p?(f-s*h)/p:0,v=ui.range(s),m=[];return null!=n&&v.sort(n===ks?function(t,e){return c[e]-c[t]}:function(t,e){ret"
,
"urn n(i[t],i[e])}),v.forEach(function(t){m[t]={data:i[t],value:l=c[t],startAngle:u,endAngle:u+=l*g+h,padAngle:d}}),m}var e=Number,n=ks,r=0,a=Hi,o=0;return t.value=function(n){return arguments.length?(e=n,t):e},t.sort=function(e){return arguments.length?(n=e,t):n},t.startAngle=function(e){return arguments.length?(r=e,t):r},t.endAngle=function(e){return arguments.length?(a=e,t):a},t.padAngle=function(e){return arguments.length?(o=e,t):o},t};var ks={};ui.layout.stack=function(){function t(l,s){if(!(d=l.length))return l;var c=l.map(function(n,r){return e.call(t,n,r)}),u=c.map(function(e){return e.map(function(e,n){return[o.call(t,e,n),i.call(t,e,n)]})}),f=n.call(t,u,s);c=ui.permute(c,f),u=ui.permute(u,f);var d,h,p,g,v=r.call(t,u,s),m=c[0].length;for(p=0;m>p;++p)for(a.call(t,c[0][p],g=v[p],u[0][p][1]),h=1;d>h;++h)a.call(t,c[h][p],g+=u[h-1][p][1],u[h][p][1]);return l}var e=b,n=va,r=ma,a=ga,o=ha,i=pa;return t.values=function(n){return arguments.length?(e=n,t):e},t.order=function(e){return arguments.length?(n=\"function\"==typeof e?e:Ms.get(e)||va,t):n},t.offset=function(e){return arguments.length?(r=\"function\"==typeof e?e:As.get(e)||ma,t):r},t.x=function(e){return arguments.length?(o=e,t):o},t.y=function(e){return arguments.length?(i=e,t):i},t.out=function(e){return arguments.length?(a=e,t):a},t};var Ms=ui.map({\"inside-out\":function(t){var e,n,r=t.length,a=t.map(ya),o=t.map(xa),i=ui.range(r).sort(function(t,e){return a[t]-a[e]}),l=0,s=0,c=[],u=[];for(e=0;r>e;++e)n=i[e],s>l?(l+=o[n],c.push(n)):(s+=o[n],u.push(n));return u.reverse().concat(c)},reverse:function(t){return ui.range(t.length).reverse()},\"default\":va}),As=ui.map({silhouette:function(t){var e,n,r,a=t.length,o=t[0].length,i=[],l=0,s=[];for(n=0;o>n;++n){for(e=0,r=0;a>e;e++)r+=t[e][n][1];r>l&&(l=r),i.push(r)}for(n=0;o>n;++n)s[n]=(l-i[n])/2;return s},wiggle:function(t){var e,n,r,a,o,i,l,s,c,u=t.length,f=t[0],d=f.length,h=[];for(h[0]=s=c=0,n=1;d>n;++n){for(e=0,a=0;u>e;++e)a+=t[e][n][1];for(e=0,o=0,l=f[n][0]-f[n-1][0];u>e;++e){for(r=0,i=(t[e][n][1]-t[e][n-1][1])/(2*l);e>r;++r)i+=(t[r][n][1]-t[r][n-1][1])/l;o+=i*t[e][n][1]}h[n]=s-=a?o/a*l:0,c>s&&(c=s)}for(n=0;d>n;++n)h[n]-=c;return h},expand:function(t){var e,n,r,a=t.length,o=t[0].length,i=1/a,l=[];for(n=0;o>n;++n){for(e=0,r=0;a>e;e++)r+=t[e][n][1];if(r)for(e=0;a>e;e++)t[e][n][1]/=r;else for(e=0;a>e;e++)t[e][n][1]=i}for(n=0;o>n;++n)l[n]=0;return l},zero:ma});ui.layout.histogram=function(){function t(t,o){for(var i,l,s=[],c=t.map(n,this),u=r.call(this,c,o),f=a.call(this,u,c,o),o=-1,d=c.length,h=f.length-1,p=e?1:1/d;++o<h;)i=s[o]=[],i.dx=f[o+1]-(i.x=f[o]),i.y=0;if(h>0)for(o=-1;++o<d;)l=c[o],l>=u[0]&&l<=u[1]&&(i=s[ui.bisect(f,l,1,h)-1],i.y+=p,i.push(t[o]));return s}var e=!0,n=Number,r=ka,a=_a;return t.value=function(e){return arguments.length?(n=e,t):n},t.range=function(e){return arguments.length?(r=zt(e),t):r},t.bins=function(e){return arguments.length?(a=\"number\"==typeof e?function(t){return wa(t,e)}:zt(e),t):a},t.frequency=function(n){return arguments.length?(e=!!n,t):e},t},ui.layout.pack=function(){function t(t,o){var i=n.call(this,t,o),l=i[0],s=a[0],c=a[1],u=null==e?Math.sqrt:\"function\"==typeof e?e:function(){return e};if(l.x=l.y=0,sa(l,function(t){t.r=+u(t.value)}),sa(l,za),r){var f=r*(e?1:Math.max(2*l.r/s,2*l.r/c))/2;sa(l,function(t){t.r+=f}),sa(l,za),sa(l,function(t){t.r-=f})}return Ca(l,s/2,c/2,e?1:1/Math.max(2*l.r/s,2*l.r/c)),i}var e,n=ui.layout.hierarchy().sort(Ma),r=0,a=[1,1];return t.size=function(e){return arguments.length?(a=e,t):a},t.radius=function(n){return arguments.length?(e=null==n||\"function\"==typeof n?n:+n,t):e},t.padding=function(e){return arguments.length?(r=+e,t):r},ia(t,n)},ui.layout.tree=function(){function t(t,a){var u=i.call(this,t,a),f=u[0],d=e(f);if(sa(d,n),d.parent.m=-d.z,la(d,r),c)la(f,o);else{var h=f,p=f,g=f;la(f,function(t){t.x<h.x&&(h=t),t.x>p.x&&(p=t),t.depth>g.depth&&(g=t)});var v=l(h,p)/2-h.x,m=s[0]/(p.x+l(p,h)/2+v),y=s[1]/(g.depth||1);la(f,function(t){t.x=(t.x+v)*m,t.y=t.depth*y})}return u}function e(t){for(var e,n={A:null,children:[t]},r=[n];null!=(e=r.pop());)for(var a,o=e.children,i=0,l=o.length;l>i;++i)r.push((o[i]=a={_:o[i],parent:e,children:(a=o[i].children)&&a.slice()||[],A:null,a:null,z:0,m:0,c:0,s:0,t:null,i:i}).a=a);return n.children[0]}function n(t){var e=t.children,n=t.parent.children,r=t.i?n[t.i-1]:null;if(e.length){Ra(t);var o=(e[0].z+e[e.length-1].z)/2;r?(t.z=r.z+l(t._,r._),t.m=t.z-o):t.z=o}else r&&(t.z=r.z+l(t._,r._));t.parent.A=a(t,r,t.parent.A||n[0])}function r(t){t._.x=t.z+t.parent.m,t.m+=t.parent.m}function a(t,e,n){if(e){for(var r,a=t,o=t,i=e,s=a.parent.children[0],c=a.m,u=o.m,f=i.m,d=s.m;i=Da(i),a=Na(a),i&&a;)s=Na(s),o=Da(o),o.a=t,r=i.z+f-a.z-c+l(i._,a._),r>0&&(Ia(ja(i,t,n),t,r),c+=r,u+=r),f+=i.m,c+=a.m,d+=s.m,u+=o.m;i&&!Da(o)&&(o.t=i,o.m+=f-u),a&&!Na(s)&&(s.t=a,s.m+=c-d,n=t)}return n}function o(t){t.x*=s[0],t.y=t.depth*s[1]}var i=ui.layout.hierarchy().sort(null).value(null),l=Pa,s=[1,1],c=null;return t.separation=function(e){return arguments.length?(l=e,t):l},t.size=function(e){return arguments.length?(c=null==(s=e)?o:null,t):c?null:s},t.nodeSize=function(e){return arguments.length?(c=null==(s=e)?null:o,t):c?s:null},ia(t,i)},ui.layout.cluster=function(){function t(t,o){var i,l=e.call(this,t,o),s=l[0],c=0;sa(s,function(t){var e=t.children;e&&e.length?(t.x=Fa(e),t.y=qa(e)):(t.x=i?c+=n(t,i):0,t.y=0,i=t)});var u=Ba(s),f=Ha(s),d=u.x-n(u,f)/2,h=f.x+n(f,u)/2;return sa(s,a?function(t){t.x=(t.x-s.x)*r[0],t.y=(s.y-t.y)*r[1]}:function(t){t.x=(t.x-d)/(h-d)*r[0],t.y=(1-(s.y?t.y/s.y:1))*r[1]}),l}var e=ui.layout.hierarchy().sort(null).value(null),n=Pa,r=[1,1],a=!1;return t.separation=function(e){return arguments.length?(n=e,t):n},t.size=function(e){return arguments.length?(a=null==(r=e),t):a?null:r},t.nodeSize=function(e){return arguments.length?(a=null!=(r=e),t):a?r:null},ia(t,e)},ui.layout.treemap=function(){function t(t,e){for(var n,r,a=-1,o=t.length;++a<o;)r=(n=t[a]).value*(0>e?0:e),n.area=isNaN(r)||0>=r?0:r}function e(n){var o=n.children;if(o&&o.length){var i,l,s,c=f(n),u=[],d=o.slice(),p=1/0,g=\"slice\"===h?c.dx:\"dice\"===h?c.dy:\"slice-dice\"===h?1&n.depth?c.dy:c.dx:Math.min(c.dx,c.dy);for(t(d,c.dx*c.dy/n.value),u.area=0;(s=d.length)>0;)u.push(i=d[s-1]),u.area+=i.area,\"squarify\"!==h||(l=r(u,g))<=p?(d.pop(),p=l):(u.area-=u.pop().area,a(u,g,c,!1),g=Math.min(c.dx,c.dy),u.length=u.area=0,p=1/0);u.length&&(a(u,g,c,!0),u.length=u.area=0),o.forEach(e)}}function n(e){var r=e.children;if(r&&r.length){var o,i=f(e),l=r.slice(),s=[];for(t(l,i.dx*i.dy/e.value),s.area=0;o=l.pop();)s.push(o),s.area+=o.area,null!=o.z&&(a(s,o.z?i.dx:i.dy,i,!l.length),s.length=s.area=0);r.forEach(n)}}function r(t,e){for(var n,r=t.area,a=0,o=1/0,i=-1,l=t.length;++i<l;)(n=t[i].area)&&(o>n&&(o=n),n>a&&(a=n));return r*=r,e*=e,r?Math.max(e*a*p/r,r/(e*o*p)):1/0}function a(t,e,n,r){var a,o=-1,i=t.length,l=n.x,c=n.y,u=e?s(t.area/e):0;if(e==n.dx){for((r||u>n.dy)&&(u=n.dy);++o<i;)a=t[o],a.x=l,a.y=c,a.dy=u,l+=a.dx=Math.min(n.x+n.dx-l,u?s(a.area/u):0);a.z=!0,a.dx+=n.x+n.dx-l,n.y+=u,n.dy-=u}else{for((r||u>n.dx)&&(u=n.dx);++o<i;)a=t[o],a.x=l,a.y=c,a.dx=u,c+=a.dy=Math.min(n.y+n.dy-c,u?s(a.area/u):0);a.z=!1,a.dy+=n.y+n.dy-c,n.x+=u,n.dx-=u}}function o(r){var a=i||l(r),o=a[0];return o.x=o.y=0,o.value?(o.dx=c[0],o.dy=c[1]):o.dx=o.dy=0,i&&l.revalue(o),t([o],o.dx*o.dy/o.value),(i?n:e)(o),d&&(i=a),a}var i,l=ui.layout.hierarchy(),s=Math.round,c=[1,1],u=null,f=Va,d=!1,h=\"squarify\",p=.5*(1+Math.sqrt(5));return o.size=function(t){return arguments.length?(c=t,o):c},o.padding=function(t){function e(e){var n=t.call(o,e,e.depth);return null==n?Va(e):Za(e,\"number\"==typeof n?[n,n,n,n]:n)}function n(e){return Za(e,t)}if(!arguments.length)return u;var r;return f=null==(u=t)?Va:\"function\"==(r=typeof t)?e:\"number\"===r?(t=[t,t,t,t],n):n,o},o.round=function(t){return arguments.length?(s=t?Math.round:Number,o):s!=Number},o.sticky=function(t){return arguments.length?(d=t,i=null,o):d},o.ratio=function(t){return arguments.length?(p=t,o):p},o.mode=function(t){return arguments.length?(h=t+\"\",o):h},ia(o,l)},ui.random={normal:function(t,e){var n=arguments.length;return 2>n&&(e=1),1>n&&(t=0),function(){var n,r,a;do n=2*Math.random()-1,r=2*Math.random()-1,a=n*n+r*r;while(!a||a>1);return t+e*n*Math.sqrt(-2*Math.log(a)/a)}},logNormal:function(){var t=ui.random.normal.apply(ui,arguments);return function(){return Math.exp(t())}},bates:function(t){var e=ui.random.irwinHall(t);return function(){return e()/t}},irwinHall:function(t){return function(){for(var e=0,n=0;t>n;n++)e+=Math.random();return e}}},ui.scale={};var Ls={floor:b,ceil:b};ui.scale.linear=function(){return Wa([0,1],[0,1],_r,!1)};var Ts={s:1,g:1,p:1,r:1,e:1};ui.scale.log=function(){return oo(ui.scale.linear().domain([0,1]),10,!0,[1,10])};var zs=ui.format(\".0e\"),Ss={floor:function(t){return-Math.ceil(-t)},ceil:function(t){return-Math.floor(-t)}};ui.scale.pow=function(){return io(ui.scale.linear(),1,[0,1])},ui.scale.sqrt=function(){return ui.scale.pow().exponent(.5)},ui.scale.ordinal=function(){return so([],{t:\"range\",a:[[]]})},ui.scale.category10=function(){return ui.scale.ordinal().range(Es)},ui.scale.category20=function(){return ui.scale.ordinal().range(Cs)},ui.scale.category20b=function(){return ui.scale.ordinal().range(Os)},ui.scale.category20c=function(){return ui.scale.ordinal().range(Ps)};var Es=[2062260,16744206,2924588,14034728,9725885,9197131,14907330,8355711,12369186,1556175].map(_t),Cs=[2062260,11454440,16744206,16759672,2924588,10018698,14034728,16750742,9725885,12955861,9197131,12885140,14907330,16234194,8355711,13092807,12369186,14408589,1556175,10410725].map(_t),Os=[3750777,5395619,7040719,10264286,6519097,9216594,11915115,13556636,9202993,12426809,15186514,15190932,8666169,11356490,14049643,15177372,8077683,10834324,13528509,14589654].map(_t),Ps=[3244733,7057110,10406625,13032431,15095053,16616764,16625259,16634018,3253076,7652470,10607003,13101504,7695281,10394312,12369372,14342891,6513507,9868950,12434877,14277081].map(_t);ui.scale.quantile=function(){return co([],[])},ui.scal"
,
"e.quantize=function(){return uo(0,1,[0,1])},ui.scale.threshold=function(){return fo([.5],[0,1])},ui.scale.identity=function(){return ho([0,1])},ui.svg={},ui.svg.arc=function(){function t(){var t=Math.max(0,+n.apply(this,arguments)),c=Math.max(0,+r.apply(this,arguments)),u=i.apply(this,arguments)-Zi,f=l.apply(this,arguments)-Zi,d=Math.abs(f-u),h=u>f?0:1;if(t>c&&(p=c,c=t,t=p),d>=Vi)return e(c,h)+(t?e(t,1-h):\"\")+\"Z\";var p,g,v,m,y,x,b,_,w,k,M,A,L=0,T=0,z=[];if((m=(+s.apply(this,arguments)||0)/2)&&(v=o===Ns?Math.sqrt(t*t+c*c):+o.apply(this,arguments),h||(T*=-1),c&&(T=rt(v/c*Math.sin(m))),t&&(L=rt(v/t*Math.sin(m)))),c){y=c*Math.cos(u+T),x=c*Math.sin(u+T),b=c*Math.cos(f-T),_=c*Math.sin(f-T);var S=Math.abs(f-u-2*T)<=Bi?0:1;if(T&&bo(y,x,b,_)===h^S){var E=(u+f)/2;y=c*Math.cos(E),x=c*Math.sin(E),b=_=null}}else y=x=0;if(t){w=t*Math.cos(f-L),k=t*Math.sin(f-L),M=t*Math.cos(u+L),A=t*Math.sin(u+L);var C=Math.abs(u-f+2*L)<=Bi?0:1;if(L&&bo(w,k,M,A)===1-h^C){var O=(u+f)/2;w=t*Math.cos(O),k=t*Math.sin(O),M=A=null}}else w=k=0;if(d>qi&&(p=Math.min(Math.abs(c-t)/2,+a.apply(this,arguments)))>.001){g=c>t^h?0:1;var P=p,N=p;if(Bi>d){var D=null==M?[w,k]:null==b?[y,x]:In([y,x],[M,A],[b,_],[w,k]),I=y-D[0],R=x-D[1],j=b-D[0],q=_-D[1],F=1/Math.sin(Math.acos((I*j+R*q)/(Math.sqrt(I*I+R*R)*Math.sqrt(j*j+q*q)))/2),B=Math.sqrt(D[0]*D[0]+D[1]*D[1]);N=Math.min(p,(t-B)/(F-1)),P=Math.min(p,(c-B)/(F+1))}if(null!=b){var H=_o(null==M?[w,k]:[M,A],[y,x],c,P,h),V=_o([b,_],[w,k],c,P,h);p===P?z.push(\"M\",H[0],\"A\",P,\",\",P,\" 0 0,\",g,\" \",H[1],\"A\",c,\",\",c,\" 0 \",1-h^bo(H[1][0],H[1][1],V[1][0],V[1][1]),\",\",h,\" \",V[1],\"A\",P,\",\",P,\" 0 0,\",g,\" \",V[0]):z.push(\"M\",H[0],\"A\",P,\",\",P,\" 0 1,\",g,\" \",V[0])}else z.push(\"M\",y,\",\",x);if(null!=M){var Z=_o([y,x],[M,A],t,-N,h),Y=_o([w,k],null==b?[y,x]:[b,_],t,-N,h);p===N?z.push(\"L\",Y[0],\"A\",N,\",\",N,\" 0 0,\",g,\" \",Y[1],\"A\",t,\",\",t,\" 0 \",h^bo(Y[1][0],Y[1][1],Z[1][0],Z[1][1]),\",\",1-h,\" \",Z[1],\"A\",N,\",\",N,\" 0 0,\",g,\" \",Z[0]):z.push(\"L\",Y[0],\"A\",N,\",\",N,\" 0 0,\",g,\" \",Z[0])}else z.push(\"L\",w,\",\",k)}else z.push(\"M\",y,\",\",x),null!=b&&z.push(\"A\",c,\",\",c,\" 0 \",S,\",\",h,\" \",b,\",\",_),z.push(\"L\",w,\",\",k),null!=M&&z.push(\"A\",t,\",\",t,\" 0 \",C,\",\",1-h,\" \",M,\",\",A);return z.push(\"Z\"),z.join(\"\")}function e(t,e){return\"M0,\"+t+\"A\"+t+\",\"+t+\" 0 1,\"+e+\" 0,\"+-t+\"A\"+t+\",\"+t+\" 0 1,\"+e+\" 0,\"+t}var n=go,r=vo,a=po,o=Ns,i=mo,l=yo,s=xo;return t.innerRadius=function(e){return arguments.length?(n=zt(e),t):n},t.outerRadius=function(e){return arguments.length?(r=zt(e),t):r},t.cornerRadius=function(e){return arguments.length?(a=zt(e),t):a},t.padRadius=function(e){return arguments.length?(o=e==Ns?Ns:zt(e),t):o},t.startAngle=function(e){return arguments.length?(i=zt(e),t):i},t.endAngle=function(e){return arguments.length?(l=zt(e),t):l},t.padAngle=function(e){return arguments.length?(s=zt(e),t):s},t.centroid=function(){var t=(+n.apply(this,arguments)+ +r.apply(this,arguments))/2,e=(+i.apply(this,arguments)+ +l.apply(this,arguments))/2-Zi;return[Math.cos(e)*t,Math.sin(e)*t]},t};var Ns=\"auto\";ui.svg.line=function(){return wo(b)};var Ds=ui.map({linear:ko,\"linear-closed\":Mo,step:Ao,\"step-before\":Lo,\"step-after\":To,basis:Po,\"basis-open\":No,\"basis-closed\":Do,bundle:Io,cardinal:Eo,\"cardinal-open\":zo,\"cardinal-closed\":So,monotone:Ho});Ds.forEach(function(t,e){e.key=t,e.closed=/-closed$/.test(t)});var Is=[0,2/3,1/3,0],Rs=[0,1/3,2/3,0],js=[0,1/6,2/3,1/6];ui.svg.line.radial=function(){var t=wo(Vo);return t.radius=t.x,delete t.x,t.angle=t.y,delete t.y,t},Lo.reverse=To,To.reverse=Lo,ui.svg.area=function(){return Zo(b)},ui.svg.area.radial=function(){var t=Zo(Vo);return t.radius=t.x,delete t.x,t.innerRadius=t.x0,delete t.x0,t.outerRadius=t.x1,delete t.x1,t.angle=t.y,delete t.y,t.startAngle=t.y0,delete t.y0,t.endAngle=t.y1,delete t.y1,t},ui.svg.chord=function(){function t(t,l){var s=e(this,o,t,l),c=e(this,i,t,l);return\"M\"+s.p0+r(s.r,s.p1,s.a1-s.a0)+(n(s,c)?a(s.r,s.p1,s.r,s.p0):a(s.r,s.p1,c.r,c.p0)+r(c.r,c.p1,c.a1-c.a0)+a(c.r,c.p1,s.r,s.p0))+\"Z\"}function e(t,e,n,r){var a=e.call(t,n,r),o=l.call(t,a,r),i=s.call(t,a,r)-Zi,u=c.call(t,a,r)-Zi;return{r:o,a0:i,a1:u,p0:[o*Math.cos(i),o*Math.sin(i)],p1:[o*Math.cos(u),o*Math.sin(u)]}}function n(t,e){return t.a0==e.a0&&t.a1==e.a1}function r(t,e,n){return\"A\"+t+\",\"+t+\" 0 \"+ +(n>Bi)+\",1 \"+e}function a(t,e,n,r){return\"Q 0,0 \"+r}var o=_n,i=wn,l=Yo,s=mo,c=yo;return t.radius=function(e){return arguments.length?(l=zt(e),t):l},t.source=function(e){return arguments.length?(o=zt(e),t):o},t.target=function(e){return arguments.length?(i=zt(e),t):i},t.startAngle=function(e){return arguments.length?(s=zt(e),t):s},t.endAngle=function(e){return arguments.length?(c=zt(e),t):c},t},ui.svg.diagonal=function(){function t(t,a){var o=e.call(this,t,a),i=n.call(this,t,a),l=(o.y+i.y)/2,s=[o,{x:o.x,y:l},{x:i.x,y:l},i];return s=s.map(r),\"M\"+s[0]+\"C\"+s[1]+\" \"+s[2]+\" \"+s[3]}var e=_n,n=wn,r=Uo;return t.source=function(n){return arguments.length?(e=zt(n),t):e},t.target=function(e){return arguments.length?(n=zt(e),t):n},t.projection=function(e){return arguments.length?(r=e,t):r},t},ui.svg.diagonal.radial=function(){var t=ui.svg.diagonal(),e=Uo,n=t.projection;return t.projection=function(t){return arguments.length?n(Xo(e=t)):e},t},ui.svg.symbol=function(){function t(t,r){return(qs.get(e.call(this,t,r))||Qo)(n.call(this,t,r))}var e=$o,n=Go;return t.type=function(n){return arguments.length?(e=zt(n),t):e},t.size=function(e){return arguments.length?(n=zt(e),t):n},t};var qs=ui.map({circle:Qo,cross:function(t){var e=Math.sqrt(t/5)/2;return\"M\"+-3*e+\",\"+-e+\"H\"+-e+\"V\"+-3*e+\"H\"+e+\"V\"+-e+\"H\"+3*e+\"V\"+e+\"H\"+e+\"V\"+3*e+\"H\"+-e+\"V\"+e+\"H\"+-3*e+\"Z\"},diamond:function(t){var e=Math.sqrt(t/(2*Bs)),n=e*Bs;return\"M0,\"+-e+\"L\"+n+\",0 0,\"+e+\" \"+-n+\",0Z\"},square:function(t){var e=Math.sqrt(t)/2;return\"M\"+-e+\",\"+-e+\"L\"+e+\",\"+-e+\" \"+e+\",\"+e+\" \"+-e+\",\"+e+\"Z\"},\"triangle-down\":function(t){var e=Math.sqrt(t/Fs),n=e*Fs/2;return\"M0,\"+n+\"L\"+e+\",\"+-n+\" \"+-e+\",\"+-n+\"Z\"},\"triangle-up\":function(t){var e=Math.sqrt(t/Fs),n=e*Fs/2;return\"M0,\"+-n+\"L\"+e+\",\"+n+\" \"+-e+\",\"+n+\"Z\"}});ui.svg.symbolTypes=qs.keys();var Fs=Math.sqrt(3),Bs=Math.tan(30*Yi);Ci.transition=function(t){for(var e,n,r=Hs||++Us,a=ei(t),o=[],i=Vs||{time:Date.now(),ease:zr,delay:0,duration:250},l=-1,s=this.length;++l<s;){o.push(e=[]);for(var c=this[l],u=-1,f=c.length;++u<f;)(n=c[u])&&ni(n,u,a,r,i),e.push(n)}return Jo(o,a,r)},Ci.interrupt=function(t){return this.each(null==t?Zs:Wo(ei(t)))};var Hs,Vs,Zs=Wo(ei()),Ys=[],Us=0;Ys.call=Ci.call,Ys.empty=Ci.empty,Ys.node=Ci.node,Ys.size=Ci.size,ui.transition=function(t,e){return t&&t.transition?Hs?t.transition(e):t:ui.selection().transition(t)},ui.transition.prototype=Ys,Ys.select=function(t){var e,n,r,a=this.id,o=this.namespace,i=[];t=E(t);for(var l=-1,s=this.length;++l<s;){i.push(e=[]);for(var c=this[l],u=-1,f=c.length;++u<f;)(r=c[u])&&(n=t.call(r,r.__data__,u,l))?(\"__data__\"in r&&(n.__data__=r.__data__),ni(n,u,o,a,r[o][a]),e.push(n)):e.push(null)}return Jo(i,o,a)},Ys.selectAll=function(t){var e,n,r,a,o,i=this.id,l=this.namespace,s=[];t=C(t);for(var c=-1,u=this.length;++c<u;)for(var f=this[c],d=-1,h=f.length;++d<h;)if(r=f[d]){o=r[l][i],n=t.call(r,r.__data__,d,c),s.push(e=[]);for(var p=-1,g=n.length;++p<g;)(a=n[p])&&ni(a,p,l,i,o),e.push(a)}return Jo(s,l,i)},Ys.filter=function(t){var e,n,r,a=[];\"function\"!=typeof t&&(t=V(t));for(var o=0,i=this.length;i>o;o++){a.push(e=[]);for(var n=this[o],l=0,s=n.length;s>l;l++)(r=n[l])&&t.call(r,r.__data__,l,o)&&e.push(r)}return Jo(a,this.namespace,this.id)},Ys.tween=function(t,e){var n=this.id,r=this.namespace;return arguments.length<2?this.node()[r][n].tween.get(t):Y(this,null==e?function(e){e[r][n].tween.remove(t)}:function(a){a[r][n].tween.set(t,e)})},Ys.attr=function(t,e){function n(){this.removeAttribute(l)}function r(){this.removeAttributeNS(l.space,l.local)}function a(t){return null==t?n:(t+=\"\",function(){var e,n=this.getAttribute(l);return n!==t&&(e=i(n,t),function(t){this.setAttribute(l,e(t))})})}function o(t){return null==t?r:(t+=\"\",function(){var e,n=this.getAttributeNS(l.space,l.local);return n!==t&&(e=i(n,t),function(t){this.setAttributeNS(l.space,l.local,e(t))})})}if(arguments.length<2){for(e in t)this.attr(e,t[e]);return this}var i=\"transform\"==t?$r:_r,l=ui.ns.qualify(t);return Ko(this,\"attr.\"+t,e,l.local?o:a)},Ys.attrTween=function(t,e){function n(t,n){var r=e.call(this,t,n,this.getAttribute(a));return r&&function(t){this.setAttribute(a,r(t))}}function r(t,n){var r=e.call(this,t,n,this.getAttributeNS(a.space,a.local));return r&&function(t){this.setAttributeNS(a.space,a.local,r(t))}}var a=ui.ns.qualify(t);return this.tween(\"attr.\"+t,a.local?r:n)},Ys.style=function(t,e,n){function a(){this.style.removeProperty(t)}function o(e){return null==e?a:(e+=\"\",function(){var a,o=r(this).getComputedStyle(this,null).getPropertyValue(t);return o!==e&&(a=_r(o,e),function(e){this.style.setProperty(t,a(e),n)})})}var i=arguments.length;if(3>i){if(\"string\"!=typeof t){2>i&&(e=\"\");for(n in t)this.style(n,t[n],e);return this}n=\"\"}return Ko(this,\"style.\"+t,e,o)},Ys.styleTween=function(t,e,n){function a(a,o){var i=e.call(this,a,o,r(this).getComputedStyle(this,null).getPropertyValue(t));return i&&function(e){this.style.setProperty(t,i(e),n)}}return arguments.length<3&&(n=\"\"),this.tween(\"style.\"+t,a)},Ys.text=function(t){return Ko(this,\"text\",t,ti)},Ys.remove=function(){var t=this.namespace;return this.each(\"end.transition\",function(){var e;this[t].count<2&&(e=this.parentNode)&&e.removeChild(this)})},Ys.ease=function(t){var e=this.id,n=this.namespace;return arguments.length<1?this.node()[n][e].ease:(\"function\"!=typeof t&&(t=ui.ease.apply(ui,arguments)),Y(this,function(r){r[n][e].ease=t}))},Ys.delay=function(t){var e=this.id,n=this.namespace;return arguments.length<1?this.node()[n][e].delay:Y(this,\"function\"==typeof t?function(r,a,o){r[n][e].delay=+t.call(r,r.__data__,a,o)}:(t=+t,function(r){r[n][e].delay=t}))},Ys.duration=function(t){var e=this.id,n=this.namespace;return arguments.length<1?this.node()[n][e].duration:Y(this,\"function\"==typeof t?function(r,a,o){r[n][e].duration=Math.max(1,t.call(r,r.__"
,
"data__,a,o))}:(t=Math.max(1,t),function(r){r[n][e].duration=t}))},Ys.each=function(t,e){var n=this.id,r=this.namespace;if(arguments.length<2){var a=Vs,o=Hs;try{Hs=n,Y(this,function(e,a,o){Vs=e[r][n],t.call(e,e.__data__,a,o)})}finally{Vs=a,Hs=o}}else Y(this,function(a){var o=a[r][n];(o.event||(o.event=ui.dispatch(\"start\",\"end\",\"interrupt\"))).on(t,e)});return this},Ys.transition=function(){for(var t,e,n,r,a=this.id,o=++Us,i=this.namespace,l=[],s=0,c=this.length;c>s;s++){l.push(t=[]);for(var e=this[s],u=0,f=e.length;f>u;u++)(n=e[u])&&(r=n[i][a],ni(n,u,i,o,{time:r.time,ease:r.ease,delay:r.delay+r.duration,duration:r.duration})),t.push(n)}return Jo(l,i,o)},ui.svg.axis=function(){function t(t){t.each(function(){var t,c=ui.select(this),u=this.__chart__||n,f=this.__chart__=n.copy(),d=null==s?f.ticks?f.ticks.apply(f,l):f.domain():s,h=null==e?f.tickFormat?f.tickFormat.apply(f,l):b:e,p=c.selectAll(\".tick\").data(d,f),g=p.enter().insert(\"g\",\".domain\").attr(\"class\",\"tick\").style(\"opacity\",qi),v=ui.transition(p.exit()).style(\"opacity\",qi).remove(),m=ui.transition(p.order()).style(\"opacity\",1),y=Math.max(a,0)+i,x=Ua(f),_=c.selectAll(\".domain\").data([0]),w=(_.enter().append(\"path\").attr(\"class\",\"domain\"),ui.transition(_));g.append(\"line\"),g.append(\"text\");var k,M,A,L,T=g.select(\"line\"),z=m.select(\"line\"),S=p.select(\"text\").text(h),E=g.select(\"text\"),C=m.select(\"text\"),O=\"top\"===r||\"left\"===r?-1:1;if(\"bottom\"===r||\"top\"===r?(t=ri,k=\"x\",A=\"y\",M=\"x2\",L=\"y2\",S.attr(\"dy\",0>O?\"0em\":\".71em\").style(\"text-anchor\",\"middle\"),w.attr(\"d\",\"M\"+x[0]+\",\"+O*o+\"V0H\"+x[1]+\"V\"+O*o)):(t=ai,k=\"y\",A=\"x\",M=\"y2\",L=\"x2\",S.attr(\"dy\",\".32em\").style(\"text-anchor\",0>O?\"end\":\"start\"),w.attr(\"d\",\"M\"+O*o+\",\"+x[0]+\"H0V\"+x[1]+\"H\"+O*o)),T.attr(L,O*a),E.attr(A,O*y),z.attr(M,0).attr(L,O*a),C.attr(k,0).attr(A,O*y),f.rangeBand){var P=f,N=P.rangeBand()/2;u=f=function(t){return P(t)+N}}else u.rangeBand?u=f:v.call(t,f,u);g.call(t,u,f),m.call(t,f,f)})}var e,n=ui.scale.linear(),r=Xs,a=6,o=6,i=3,l=[10],s=null;return t.scale=function(e){\n"
,
"return arguments.length?(n=e,t):n},t.orient=function(e){return arguments.length?(r=e in Gs?e+\"\":Xs,t):r},t.ticks=function(){return arguments.length?(l=di(arguments),t):l},t.tickValues=function(e){return arguments.length?(s=e,t):s},t.tickFormat=function(n){return arguments.length?(e=n,t):e},t.tickSize=function(e){var n=arguments.length;return n?(a=+e,o=+arguments[n-1],t):a},t.innerTickSize=function(e){return arguments.length?(a=+e,t):a},t.outerTickSize=function(e){return arguments.length?(o=+e,t):o},t.tickPadding=function(e){return arguments.length?(i=+e,t):i},t.tickSubdivide=function(){return arguments.length&&t},t};var Xs=\"bottom\",Gs={top:1,right:1,bottom:1,left:1};ui.svg.brush=function(){function t(r){r.each(function(){var r=ui.select(this).style(\"pointer-events\",\"all\").style(\"-webkit-tap-highlight-color\",\"rgba(0,0,0,0)\").on(\"mousedown.brush\",o).on(\"touchstart.brush\",o),i=r.selectAll(\".background\").data([0]);i.enter().append(\"rect\").attr(\"class\",\"background\").style(\"visibility\",\"hidden\").style(\"cursor\",\"crosshair\"),r.selectAll(\".extent\").data([0]).enter().append(\"rect\").attr(\"class\",\"extent\").style(\"cursor\",\"move\");var l=r.selectAll(\".resize\").data(g,b);l.exit().remove(),l.enter().append(\"g\").attr(\"class\",function(t){return\"resize \"+t}).style(\"cursor\",function(t){return $s[t]}).append(\"rect\").attr(\"x\",function(t){return/[ew]$/.test(t)?-3:null}).attr(\"y\",function(t){return/^[ns]/.test(t)?-3:null}).attr(\"width\",6).attr(\"height\",6).style(\"visibility\",\"hidden\"),l.style(\"display\",t.empty()?\"none\":null);var s,f=ui.transition(r),d=ui.transition(i);c&&(s=Ua(c),d.attr(\"x\",s[0]).attr(\"width\",s[1]-s[0]),n(f)),u&&(s=Ua(u),d.attr(\"y\",s[0]).attr(\"height\",s[1]-s[0]),a(f)),e(f)})}function e(t){t.selectAll(\".resize\").attr(\"transform\",function(t){return\"translate(\"+f[+/e$/.test(t)]+\",\"+d[+/^s/.test(t)]+\")\"})}function n(t){t.select(\".extent\").attr(\"x\",f[0]),t.selectAll(\".extent,.n>rect,.s>rect\").attr(\"width\",f[1]-f[0])}function a(t){t.select(\".extent\").attr(\"y\",d[0]),t.selectAll(\".extent,.e>rect,.w>rect\").attr(\"height\",d[1]-d[0])}function o(){function o(){32==ui.event.keyCode&&(S||(x=null,C[0]-=f[1],C[1]-=d[1],S=2),L())}function g(){32==ui.event.keyCode&&2==S&&(C[0]+=f[1],C[1]+=d[1],S=0,L())}function v(){var t=ui.mouse(_),r=!1;b&&(t[0]+=b[0],t[1]+=b[1]),S||(ui.event.altKey?(x||(x=[(f[0]+f[1])/2,(d[0]+d[1])/2]),C[0]=f[+(t[0]<x[0])],C[1]=d[+(t[1]<x[1])]):x=null),T&&m(t,c,0)&&(n(M),r=!0),z&&m(t,u,1)&&(a(M),r=!0),r&&(e(M),k({type:\"brush\",mode:S?\"move\":\"resize\"}))}function m(t,e,n){var r,a,o=Ua(e),s=o[0],c=o[1],u=C[n],g=n?d:f,v=g[1]-g[0];return S&&(s-=u,c-=v+u),r=(n?p:h)?Math.max(s,Math.min(c,t[n])):t[n],S?a=(r+=u)+v:(x&&(u=Math.max(s,Math.min(c,2*x[n]-r))),r>u?(a=r,r=u):a=u),g[0]!=r||g[1]!=a?(n?l=null:i=null,g[0]=r,g[1]=a,!0):void 0}function y(){v(),M.style(\"pointer-events\",\"all\").selectAll(\".resize\").style(\"display\",t.empty()?\"none\":null),ui.select(\"body\").style(\"cursor\",null),O.on(\"mousemove.brush\",null).on(\"mouseup.brush\",null).on(\"touchmove.brush\",null).on(\"touchend.brush\",null).on(\"keydown.brush\",null).on(\"keyup.brush\",null),E(),k({type:\"brushend\"})}var x,b,_=this,w=ui.select(ui.event.target),k=s.of(_,arguments),M=ui.select(_),A=w.datum(),T=!/^(n|s)$/.test(A)&&c,z=!/^(e|w)$/.test(A)&&u,S=w.classed(\"extent\"),E=W(_),C=ui.mouse(_),O=ui.select(r(_)).on(\"keydown.brush\",o).on(\"keyup.brush\",g);if(ui.event.changedTouches?O.on(\"touchmove.brush\",v).on(\"touchend.brush\",y):O.on(\"mousemove.brush\",v).on(\"mouseup.brush\",y),M.interrupt().selectAll(\"*\").interrupt(),S)C[0]=f[0]-C[0],C[1]=d[0]-C[1];else if(A){var P=+/w$/.test(A),N=+/^n/.test(A);b=[f[1-P]-C[0],d[1-N]-C[1]],C[0]=f[P],C[1]=d[N]}else ui.event.altKey&&(x=C.slice());M.style(\"pointer-events\",\"none\").selectAll(\".resize\").style(\"display\",null),ui.select(\"body\").style(\"cursor\",w.style(\"cursor\")),k({type:\"brushstart\"}),v()}var i,l,s=z(t,\"brushstart\",\"brush\",\"brushend\"),c=null,u=null,f=[0,0],d=[0,0],h=!0,p=!0,g=Qs[0];return t.event=function(t){t.each(function(){var t=s.of(this,arguments),e={x:f,y:d,i:i,j:l},n=this.__chart__||e;this.__chart__=e,Hs?ui.select(this).transition().each(\"start.brush\",function(){i=n.i,l=n.j,f=n.x,d=n.y,t({type:\"brushstart\"})}).tween(\"brush:brush\",function(){var n=wr(f,e.x),r=wr(d,e.y);return i=l=null,function(a){f=e.x=n(a),d=e.y=r(a),t({type:\"brush\",mode:\"resize\"})}}).each(\"end.brush\",function(){i=e.i,l=e.j,t({type:\"brush\",mode:\"resize\"}),t({type:\"brushend\"})}):(t({type:\"brushstart\"}),t({type:\"brush\",mode:\"resize\"}),t({type:\"brushend\"}))})},t.x=function(e){return arguments.length?(c=e,g=Qs[!c<<1|!u],t):c},t.y=function(e){return arguments.length?(u=e,g=Qs[!c<<1|!u],t):u},t.clamp=function(e){return arguments.length?(c&&u?(h=!!e[0],p=!!e[1]):c?h=!!e:u&&(p=!!e),t):c&&u?[h,p]:c?h:u?p:null},t.extent=function(e){var n,r,a,o,s;return arguments.length?(c&&(n=e[0],r=e[1],u&&(n=n[0],r=r[0]),i=[n,r],c.invert&&(n=c(n),r=c(r)),n>r&&(s=n,n=r,r=s),n==f[0]&&r==f[1]||(f=[n,r])),u&&(a=e[0],o=e[1],c&&(a=a[1],o=o[1]),l=[a,o],u.invert&&(a=u(a),o=u(o)),a>o&&(s=a,a=o,o=s),a==d[0]&&o==d[1]||(d=[a,o])),t):(c&&(i?(n=i[0],r=i[1]):(n=f[0],r=f[1],c.invert&&(n=c.invert(n),r=c.invert(r)),n>r&&(s=n,n=r,r=s))),u&&(l?(a=l[0],o=l[1]):(a=d[0],o=d[1],u.invert&&(a=u.invert(a),o=u.invert(o)),a>o&&(s=a,a=o,o=s))),c&&u?[[n,a],[r,o]]:c?[n,r]:u&&[a,o])},t.clear=function(){return t.empty()||(f=[0,0],d=[0,0],i=l=null),t},t.empty=function(){return!!c&&f[0]==f[1]||!!u&&d[0]==d[1]},ui.rebind(t,s,\"on\")};var $s={n:\"ns-resize\",e:\"ew-resize\",s:\"ns-resize\",w:\"ew-resize\",nw:\"nwse-resize\",ne:\"nesw-resize\",se:\"nwse-resize\",sw:\"nesw-resize\"},Qs=[[\"n\",\"e\",\"s\",\"w\",\"nw\",\"ne\",\"se\",\"sw\"],[\"e\",\"w\"],[\"n\",\"s\"],[]],Ws=vl.format=wl.timeFormat,Js=Ws.utc,Ks=Js(\"%Y-%m-%dT%H:%M:%S.%LZ\");Ws.iso=Date.prototype.toISOString&&+new Date(\"2000-01-01T00:00:00.000Z\")?oi:Ks,oi.parse=function(t){var e=new Date(t);return isNaN(e)?null:e},oi.toString=Ks.toString,vl.second=Ht(function(t){return new ml(1e3*Math.floor(t/1e3))},function(t,e){t.setTime(t.getTime()+1e3*Math.floor(e))},function(t){return t.getSeconds()}),vl.seconds=vl.second.range,vl.seconds.utc=vl.second.utc.range,vl.minute=Ht(function(t){return new ml(6e4*Math.floor(t/6e4))},function(t,e){t.setTime(t.getTime()+6e4*Math.floor(e))},function(t){return t.getMinutes()}),vl.minutes=vl.minute.range,vl.minutes.utc=vl.minute.utc.range,vl.hour=Ht(function(t){var e=t.getTimezoneOffset()/60;return new ml(36e5*(Math.floor(t/36e5-e)+e))},function(t,e){t.setTime(t.getTime()+36e5*Math.floor(e))},function(t){return t.getHours()}),vl.hours=vl.hour.range,vl.hours.utc=vl.hour.utc.range,vl.month=Ht(function(t){return t=vl.day(t),t.setDate(1),t},function(t,e){t.setMonth(t.getMonth()+e)},function(t){return t.getMonth()}),vl.months=vl.month.range,vl.months.utc=vl.month.utc.range;var tc=[1e3,5e3,15e3,3e4,6e4,3e5,9e5,18e5,36e5,108e5,216e5,432e5,864e5,1728e5,6048e5,2592e6,7776e6,31536e6],ec=[[vl.second,1],[vl.second,5],[vl.second,15],[vl.second,30],[vl.minute,1],[vl.minute,5],[vl.minute,15],[vl.minute,30],[vl.hour,1],[vl.hour,3],[vl.hour,6],[vl.hour,12],[vl.day,1],[vl.day,2],[vl.week,1],[vl.month,1],[vl.month,3],[vl.year,1]],nc=Ws.multi([[\".%L\",function(t){return t.getMilliseconds()}],[\":%S\",function(t){return t.getSeconds()}],[\"%I:%M\",function(t){return t.getMinutes()}],[\"%I %p\",function(t){return t.getHours()}],[\"%a %d\",function(t){return t.getDay()&&1!=t.getDate()}],[\"%b %d\",function(t){return 1!=t.getDate()}],[\"%B\",function(t){return t.getMonth()}],[\"%Y\",Ce]]),rc={range:function(t,e,n){return ui.range(Math.ceil(t/n)*n,+e,n).map(li)},floor:b,ceil:b};ec.year=vl.year,vl.scale=function(){return ii(ui.scale.linear(),ec,nc)};var ac=ec.map(function(t){return[t[0].utc,t[1]]}),oc=Js.multi([[\".%L\",function(t){return t.getUTCMilliseconds()}],[\":%S\",function(t){return t.getUTCSeconds()}],[\"%I:%M\",function(t){return t.getUTCMinutes()}],[\"%I %p\",function(t){return t.getUTCHours()}],[\"%a %d\",function(t){return t.getUTCDay()&&1!=t.getUTCDate()}],[\"%b %d\",function(t){return 1!=t.getUTCDate()}],[\"%B\",function(t){return t.getUTCMonth()}],[\"%Y\",Ce]]);ac.year=vl.year.utc,vl.scale.utc=function(){return ii(ui.scale.linear(),ac,oc)},ui.text=St(function(t){return t.responseText}),ui.json=function(t,e){return Et(t,\"application/json\",si,e)},ui.html=function(t,e){return Et(t,\"text/html\",ci,e)},ui.xml=St(function(t){return t.responseXML}),\"function\"==typeof t&&t.amd?(this.d3=ui,t(ui)):\"object\"==typeof n&&n.exports?n.exports=ui:this.d3=ui}()},{}],10:[function(e,n,r){(function(r,a){(function(){\"use strict\";function o(t){return\"function\"==typeof t||\"object\"==typeof t&&null!==t}function i(t){return\"function\"==typeof t}function l(t){U=t}function s(t){Q=t}function c(){return function(){r.nextTick(p)}}function u(){return function(){Y(p)}}function f(){var t=0,e=new K(p),n=document.createTextNode(\"\");return e.observe(n,{characterData:!0}),function(){n.data=t=++t%2}}function d(){var t=new MessageChannel;return t.port1.onmessage=p,function(){t.port2.postMessage(0)}}function h(){return function(){setTimeout(p,1)}}function p(){for(var t=0;$>t;t+=2){var e=nt[t],n=nt[t+1];e(n),nt[t]=void 0,nt[t+1]=void 0}$=0}function g(){try{var t=e,n=t(\"vertx\");return Y=n.runOnLoop||n.runOnContext,u()}catch(r){return h()}}function v(t,e){var n=this,r=n._state;if(r===it&&!t||r===lt&&!e)return this;var a=new this.constructor(y),o=n._result;if(r){var i=arguments[r-1];Q(function(){N(r,a,i,o)})}else E(n,a,t,e);return a}function m(t){var e=this;if(t&&\"object\"==typeof t&&t.constructor===e)return t;var n=new e(y);return L(n,t),n}function y(){}function x(){return new TypeError(\"You cannot resolve a promise with itself\")}function b(){return new TypeError(\"A promises callback cannot return that same promise.\")}function _(t){try{return t.then}catch(e){return st.error=e,st}}function w(t,e,n,r){try{t.call(e,n,r)}catch(a){return a}}function k(t,e,n){Q(function(t){var r=!1,a=w(n,e,function(n){r||(r=!0,e!==n?L(t,n):z(t,n))},function(e){r||(r=!0,S(t,e))},\"Settle: \"+(t._label||\" unknown promise\"));!r&&a&&(r=!0,S(t,a))},t)}function M(t,e){e._state===it?z(t,e._result):e._state===lt?S(t,"
,
"e._result):E(e,void 0,function(e){L(t,e)},function(e){S(t,e)})}function A(t,e,n){e.constructor===t.constructor&&n===rt&&constructor.resolve===at?M(t,e):n===st?S(t,st.error):void 0===n?z(t,e):i(n)?k(t,e,n):z(t,e)}function L(t,e){t===e?S(t,x()):o(e)?A(t,e,_(e)):z(t,e)}function T(t){t._onerror&&t._onerror(t._result),C(t)}function z(t,e){t._state===ot&&(t._result=e,t._state=it,0!==t._subscribers.length&&Q(C,t))}function S(t,e){t._state===ot&&(t._state=lt,t._result=e,Q(T,t))}function E(t,e,n,r){var a=t._subscribers,o=a.length;t._onerror=null,a[o]=e,a[o+it]=n,a[o+lt]=r,0===o&&t._state&&Q(C,t)}function C(t){var e=t._subscribers,n=t._state;if(0!==e.length){for(var r,a,o=t._result,i=0;i<e.length;i+=3)r=e[i],a=e[i+n],r?N(n,r,a,o):a(o);t._subscribers.length=0}}function O(){this.error=null}function P(t,e){try{return t(e)}catch(n){return ct.error=n,ct}}function N(t,e,n,r){var a,o,l,s,c=i(n);if(c){if(a=P(n,r),a===ct?(s=!0,o=a.error,a=null):l=!0,e===a)return void S(e,b())}else a=r,l=!0;e._state!==ot||(c&&l?L(e,a):s?S(e,o):t===it?z(e,a):t===lt&&S(e,a))}function D(t,e){try{e(function(e){L(t,e)},function(e){S(t,e)})}catch(n){S(t,n)}}function I(t){return new gt(this,t).promise}function R(t){function e(t){L(a,t)}function n(t){S(a,t)}var r=this,a=new r(y);if(!G(t))return S(a,new TypeError(\"You must pass an array to race.\")),a;for(var o=t.length,i=0;a._state===ot&&o>i;i++)E(r.resolve(t[i]),void 0,e,n);return a}function j(t){var e=this,n=new e(y);return S(n,t),n}function q(){throw new TypeError(\"You must pass a resolver function as the first argument to the promise constructor\")}function F(){throw new TypeError(\"Failed to construct 'Promise': Please use the 'new' operator, this object constructor cannot be called as a function.\")}function B(t){this._id=ht++,this._state=void 0,this._result=void 0,this._subscribers=[],y!==t&&(\"function\"!=typeof t&&q(),this instanceof B?D(this,t):F())}function H(t,e){this._instanceConstructor=t,this.promise=new t(y),Array.isArray(e)?(this._input=e,this.length=e.length,this._remaining=e.length,this._result=new Array(this.length),0===this.length?z(this.promise,this._result):(this.length=this.length||0,this._enumerate(),0===this._remaining&&z(this.promise,this._result))):S(this.promise,this._validationError())}function V(){var t;if(\"undefined\"!=typeof a)t=a;else if(\"undefined\"!=typeof self)t=self;else try{t=Function(\"return this\")()}catch(e){throw new Error(\"polyfill failed because global object is unavailable in this environment\")}var n=t.Promise;n&&\"[object Promise]\"===Object.prototype.toString.call(n.resolve())&&!n.cast||(t.Promise=pt)}var Z;Z=Array.isArray?Array.isArray:function(t){return\"[object Array]\"===Object.prototype.toString.call(t)};var Y,U,X,G=Z,$=0,Q=function(t,e){nt[$]=t,nt[$+1]=e,$+=2,2===$&&(U?U(p):X())},W=\"undefined\"!=typeof window?window:void 0,J=W||{},K=J.MutationObserver||J.WebKitMutationObserver,tt=\"undefined\"!=typeof r&&\"[object process]\"==={}.toString.call(r),et=\"undefined\"!=typeof Uint8ClampedArray&&\"undefined\"!=typeof importScripts&&\"undefined\"!=typeof MessageChannel,nt=new Array(1e3);X=tt?c():K?f():et?d():void 0===W&&\"function\"==typeof e?g():h();var rt=v,at=m,ot=void 0,it=1,lt=2,st=new O,ct=new O,ut=I,ft=R,dt=j,ht=0,pt=B;B.all=ut,B.race=ft,B.resolve=at,B.reject=dt,B._setScheduler=l,B._setAsap=s,B._asap=Q,B.prototype={constructor:B,then:rt,\"catch\":function(t){return this.then(null,t)}};var gt=H;H.prototype._validationError=function(){return new Error(\"Array Methods must be provided an Array\")},H.prototype._enumerate=function(){for(var t=this.length,e=this._input,n=0;this._state===ot&&t>n;n++)this._eachEntry(e[n],n)},H.prototype._eachEntry=function(t,e){var n=this._instanceConstructor,r=n.resolve;if(r===at){var a=_(t);if(a===rt&&t._state!==ot)this._settledAt(t._state,e,t._result);else if(\"function\"!=typeof a)this._remaining--,this._result[e]=t;else if(n===pt){var o=new n(y);A(o,t,a),this._willSettleAt(o,e)}else this._willSettleAt(new n(function(e){e(t)}),e)}else this._willSettleAt(r(t),e)},H.prototype._settledAt=function(t,e,n){var r=this.promise;r._state===ot&&(this._remaining--,t===lt?S(r,n):this._result[e]=n),0===this._remaining&&z(r,this._result)},H.prototype._willSettleAt=function(t,e){var n=this;E(t,void 0,function(t){n._settledAt(it,e,t)},function(t){n._settledAt(lt,e,t)})};var vt=V,mt={Promise:pt,polyfill:vt};\"function\"==typeof t&&t.amd?t(function(){return mt}):\"undefined\"!=typeof n&&n.exports?n.exports=mt:\"undefined\"!=typeof this&&(this.ES6Promise=mt),vt()}).call(this)}).call(this,e(\"_process\"),\"undefined\"!=typeof global?global:\"undefined\"!=typeof self?self:\"undefined\"!=typeof window?window:{})},{_process:8}],11:[function(t,e,n){\"use strict\";function r(t){for(var e,n=t.length,r=0;n>r;r++)if(e=t.charCodeAt(r),(9>e||e>13)&&32!==e&&133!==e&&160!==e&&5760!==e&&6158!==e&&(8192>e||e>8205)&&8232!==e&&8233!==e&&8239!==e&&8287!==e&&8288!==e&&12288!==e&&65279!==e)return!1;return!0}e.exports=function(t){var e=typeof t;if(\"string\"===e){var n=t;if(t=+t,0===t&&r(n))return!1}else if(\"number\"!==e)return!1;return 1>t-t}},{}],12:[function(t,e,n){function r(t,e){var n=e[0],r=e[1],a=e[2],o=e[3],i=n+n,l=r+r,s=a+a,c=n*i,u=r*i,f=r*l,d=a*i,h=a*l,p=a*s,g=o*i,v=o*l,m=o*s;return t[0]=1-f-p,t[1]=u+m,t[2]=d-v,t[3]=0,t[4]=u-m,t[5]=1-c-p,t[6]=h+g,t[7]=0,t[8]=d+v,t[9]=h-g,t[10]=1-c-f,t[11]=0,t[12]=0,t[13]=0,t[14]=0,t[15]=1,t}e.exports=r},{}],13:[function(e,n,r){!function(){function e(t,n){if(t=t?t:\"\",n=n||{},t instanceof e)return t;if(!(this instanceof e))return new e(t,n);var a=r(t);this._originalInput=t,this._r=a.r,this._g=a.g,this._b=a.b,this._a=a.a,this._roundA=B(100*this._a)/100,this._format=n.format||a.format,this._gradientType=n.gradientType,this._r<1&&(this._r=B(this._r)),this._g<1&&(this._g=B(this._g)),this._b<1&&(this._b=B(this._b)),this._ok=a.ok,this._tc_id=q++}function r(t){var e={r:0,g:0,b:0},n=1,r=!1,o=!1;return\"string\"==typeof t&&(t=D(t)),\"object\"==typeof t&&(t.hasOwnProperty(\"r\")&&t.hasOwnProperty(\"g\")&&t.hasOwnProperty(\"b\")?(e=a(t.r,t.g,t.b),r=!0,o=\"%\"===String(t.r).substr(-1)?\"prgb\":\"rgb\"):t.hasOwnProperty(\"h\")&&t.hasOwnProperty(\"s\")&&t.hasOwnProperty(\"v\")?(t.s=O(t.s),t.v=O(t.v),e=s(t.h,t.s,t.v),r=!0,o=\"hsv\"):t.hasOwnProperty(\"h\")&&t.hasOwnProperty(\"s\")&&t.hasOwnProperty(\"l\")&&(t.s=O(t.s),t.l=O(t.l),e=i(t.h,t.s,t.l),r=!0,o=\"hsl\"),t.hasOwnProperty(\"a\")&&(n=t.a)),n=A(n),{ok:r,format:t.format||o,r:H(255,V(e.r,0)),g:H(255,V(e.g,0)),b:H(255,V(e.b,0)),a:n}}function a(t,e,n){return{r:255*L(t,255),g:255*L(e,255),b:255*L(n,255)}}function o(t,e,n){t=L(t,255),e=L(e,255),n=L(n,255);var r,a,o=V(t,e,n),i=H(t,e,n),l=(o+i)/2;if(o==i)r=a=0;else{var s=o-i;switch(a=l>.5?s/(2-o-i):s/(o+i),o){case t:r=(e-n)/s+(n>e?6:0);break;case e:r=(n-t)/s+2;break;case n:r=(t-e)/s+4}r/=6}return{h:r,s:a,l:l}}function i(t,e,n){function r(t,e,n){return 0>n&&(n+=1),n>1&&(n-=1),1/6>n?t+6*(e-t)*n:.5>n?e:2/3>n?t+(e-t)*(2/3-n)*6:t}var a,o,i;if(t=L(t,360),e=L(e,100),n=L(n,100),0===e)a=o=i=n;else{var l=.5>n?n*(1+e):n+e-n*e,s=2*n-l;a=r(s,l,t+1/3),o=r(s,l,t),i=r(s,l,t-1/3)}return{r:255*a,g:255*o,b:255*i}}function l(t,e,n){t=L(t,255),e=L(e,255),n=L(n,255);var r,a,o=V(t,e,n),i=H(t,e,n),l=o,s=o-i;if(a=0===o?0:s/o,o==i)r=0;else{switch(o){case t:r=(e-n)/s+(n>e?6:0);break;case e:r=(n-t)/s+2;break;case n:r=(t-e)/s+4}r/=6}return{h:r,s:a,v:l}}function s(t,e,n){t=6*L(t,360),e=L(e,100),n=L(n,100);var r=F.floor(t),a=t-r,o=n*(1-e),i=n*(1-a*e),l=n*(1-(1-a)*e),s=r%6,c=[n,i,o,o,l,n][s],u=[l,n,n,i,o,o][s],f=[o,o,l,n,n,i][s];return{r:255*c,g:255*u,b:255*f}}function c(t,e,n,r){var a=[C(B(t).toString(16)),C(B(e).toString(16)),C(B(n).toString(16))];return r&&a[0].charAt(0)==a[0].charAt(1)&&a[1].charAt(0)==a[1].charAt(1)&&a[2].charAt(0)==a[2].charAt(1)?a[0].charAt(0)+a[1].charAt(0)+a[2].charAt(0):a.join(\"\")}function u(t,e,n,r){var a=[C(P(r)),C(B(t).toString(16)),C(B(e).toString(16)),C(B(n).toString(16))];return a.join(\"\")}function f(t,n){n=0===n?0:n||10;var r=e(t).toHsl();return r.s-=n/100,r.s=T(r.s),e(r)}function d(t,n){n=0===n?0:n||10;var r=e(t).toHsl();return r.s+=n/100,r.s=T(r.s),e(r)}function h(t){return e(t).desaturate(100)}function p(t,n){n=0===n?0:n||10;var r=e(t).toHsl();return r.l+=n/100,r.l=T(r.l),e(r)}function g(t,n){n=0===n?0:n||10;var r=e(t).toRgb();return r.r=V(0,H(255,r.r-B(255*-(n/100)))),r.g=V(0,H(255,r.g-B(255*-(n/100)))),r.b=V(0,H(255,r.b-B(255*-(n/100)))),e(r)}function v(t,n){n=0===n?0:n||10;var r=e(t).toHsl();return r.l-=n/100,r.l=T(r.l),e(r)}function m(t,n){var r=e(t).toHsl(),a=(B(r.h)+n)%360;return r.h=0>a?360+a:a,e(r)}function y(t){var n=e(t).toHsl();return n.h=(n.h+180)%360,e(n)}function x(t){var n=e(t).toHsl(),r=n.h;return[e(t),e({h:(r+120)%360,s:n.s,l:n.l}),e({h:(r+240)%360,s:n.s,l:n.l})]}function b(t){var n=e(t).toHsl(),r=n.h;return[e(t),e({h:(r+90)%360,s:n.s,l:n.l}),e({h:(r+180)%360,s:n.s,l:n.l}),e({h:(r+270)%360,s:n.s,l:n.l})]}function _(t){var n=e(t).toHsl(),r=n.h;return[e(t),e({h:(r+72)%360,s:n.s,l:n.l}),e({h:(r+216)%360,s:n.s,l:n.l})]}function w(t,n,r){n=n||6,r=r||30;var a=e(t).toHsl(),o=360/r,i=[e(t)];for(a.h=(a.h-(o*n>>1)+720)%360;--n;)a.h=(a.h+o)%360,i.push(e(a));return i}function k(t,n){n=n||6;for(var r=e(t).toHsv(),a=r.h,o=r.s,i=r.v,l=[],s=1/n;n--;)l.push(e({h:a,s:o,v:i})),i=(i+s)%1;return l}function M(t){var e={};for(var n in t)t.hasOwnProperty(n)&&(e[t[n]]=n);return e}function A(t){return t=parseFloat(t),(isNaN(t)||0>t||t>1)&&(t=1),t}function L(t,e){S(t)&&(t=\"100%\");var n=E(t);return t=H(e,V(0,parseFloat(t))),n&&(t=parseInt(t*e,10)/100),F.abs(t-e)<1e-6?1:t%e/parseFloat(e)}function T(t){return H(1,V(0,t))}function z(t){return parseInt(t,16)}function S(t){return\"string\"==typeof t&&-1!=t.indexOf(\".\")&&1===parseFloat(t)}function E(t){return\"string\"==typeof t&&-1!=t.indexOf(\"%\")}function C(t){return 1==t.length?\"0\"+t:\"\"+t}function O(t){return 1>=t&&(t=100*t+\"%\"),t}function P(t){return Math.round(255*parseFloat(t)).toString(16)}function N(t){return z(t)/255}function D(t){t=t.replace(R,\"\").replace(j,\"\").toLowerCase();var e=!1;if(Y[t])t=Y[t],e=!0;else if(\"transparent\"==t)return{r:0,g:0,b:0,a:0,format:\"name\"};var n;return"
,
"(n=X.rgb.exec(t))?{r:n[1],g:n[2],b:n[3]}:(n=X.rgba.exec(t))?{r:n[1],g:n[2],b:n[3],a:n[4]}:(n=X.hsl.exec(t))?{h:n[1],s:n[2],l:n[3]}:(n=X.hsla.exec(t))?{h:n[1],s:n[2],l:n[3],a:n[4]}:(n=X.hsv.exec(t))?{h:n[1],s:n[2],v:n[3]}:(n=X.hsva.exec(t))?{h:n[1],s:n[2],v:n[3],a:n[4]}:(n=X.hex8.exec(t))?{a:N(n[1]),r:z(n[2]),g:z(n[3]),b:z(n[4]),format:e?\"name\":\"hex8\"}:(n=X.hex6.exec(t))?{r:z(n[1]),g:z(n[2]),b:z(n[3]),format:e?\"name\":\"hex\"}:(n=X.hex3.exec(t))?{r:z(n[1]+\"\"+n[1]),g:z(n[2]+\"\"+n[2]),b:z(n[3]+\"\"+n[3]),format:e?\"name\":\"hex\"}:!1}function I(t){var e,n;return t=t||{level:\"AA\",size:\"small\"},e=(t.level||\"AA\").toUpperCase(),n=(t.size||\"small\").toLowerCase(),\"AA\"!==e&&\"AAA\"!==e&&(e=\"AA\"),\"small\"!==n&&\"large\"!==n&&(n=\"small\"),{level:e,size:n}}var R=/^\\s+/,j=/\\s+$/,q=0,F=Math,B=F.round,H=F.min,V=F.max,Z=F.random;e.prototype={isDark:function(){return this.getBrightness()<128},isLight:function(){return!this.isDark()},isValid:function(){return this._ok},getOriginalInput:function(){return this._originalInput},getFormat:function(){return this._format},getAlpha:function(){return this._a},getBrightness:function(){var t=this.toRgb();return(299*t.r+587*t.g+114*t.b)/1e3},getLuminance:function(){var t,e,n,r,a,o,i=this.toRgb();return t=i.r/255,e=i.g/255,n=i.b/255,r=.03928>=t?t/12.92:Math.pow((t+.055)/1.055,2.4),a=.03928>=e?e/12.92:Math.pow((e+.055)/1.055,2.4),o=.03928>=n?n/12.92:Math.pow((n+.055)/1.055,2.4),.2126*r+.7152*a+.0722*o},setAlpha:function(t){return this._a=A(t),this._roundA=B(100*this._a)/100,this},toHsv:function(){var t=l(this._r,this._g,this._b);return{h:360*t.h,s:t.s,v:t.v,a:this._a}},toHsvString:function(){var t=l(this._r,this._g,this._b),e=B(360*t.h),n=B(100*t.s),r=B(100*t.v);return 1==this._a?\"hsv(\"+e+\", \"+n+\"%, \"+r+\"%)\":\"hsva(\"+e+\", \"+n+\"%, \"+r+\"%, \"+this._roundA+\")\"},toHsl:function(){var t=o(this._r,this._g,this._b);return{h:360*t.h,s:t.s,l:t.l,a:this._a}},toHslString:function(){var t=o(this._r,this._g,this._b),e=B(360*t.h),n=B(100*t.s),r=B(100*t.l);return 1==this._a?\"hsl(\"+e+\", \"+n+\"%, \"+r+\"%)\":\"hsla(\"+e+\", \"+n+\"%, \"+r+\"%, \"+this._roundA+\")\"},toHex:function(t){return c(this._r,this._g,this._b,t)},toHexString:function(t){return\"#\"+this.toHex(t)},toHex8:function(){return u(this._r,this._g,this._b,this._a)},toHex8String:function(){return\"#\"+this.toHex8()},toRgb:function(){return{r:B(this._r),g:B(this._g),b:B(this._b),a:this._a}},toRgbString:function(){return 1==this._a?\"rgb(\"+B(this._r)+\", \"+B(this._g)+\", \"+B(this._b)+\")\":\"rgba(\"+B(this._r)+\", \"+B(this._g)+\", \"+B(this._b)+\", \"+this._roundA+\")\"},toPercentageRgb:function(){return{r:B(100*L(this._r,255))+\"%\",g:B(100*L(this._g,255))+\"%\",b:B(100*L(this._b,255))+\"%\",a:this._a}},toPercentageRgbString:function(){return 1==this._a?\"rgb(\"+B(100*L(this._r,255))+\"%, \"+B(100*L(this._g,255))+\"%, \"+B(100*L(this._b,255))+\"%)\":\"rgba(\"+B(100*L(this._r,255))+\"%, \"+B(100*L(this._g,255))+\"%, \"+B(100*L(this._b,255))+\"%, \"+this._roundA+\")\"},toName:function(){return 0===this._a?\"transparent\":this._a<1?!1:U[c(this._r,this._g,this._b,!0)]||!1},toFilter:function(t){var n=\"#\"+u(this._r,this._g,this._b,this._a),r=n,a=this._gradientType?\"GradientType = 1, \":\"\";if(t){var o=e(t);r=o.toHex8String()}return\"progid:DXImageTransform.Microsoft.gradient(\"+a+\"startColorstr=\"+n+\",endColorstr=\"+r+\")\"},toString:function(t){var e=!!t;t=t||this._format;var n=!1,r=this._a<1&&this._a>=0,a=!e&&r&&(\"hex\"===t||\"hex6\"===t||\"hex3\"===t||\"name\"===t);return a?\"name\"===t&&0===this._a?this.toName():this.toRgbString():(\"rgb\"===t&&(n=this.toRgbString()),\"prgb\"===t&&(n=this.toPercentageRgbString()),\"hex\"!==t&&\"hex6\"!==t||(n=this.toHexString()),\"hex3\"===t&&(n=this.toHexString(!0)),\"hex8\"===t&&(n=this.toHex8String()),\"name\"===t&&(n=this.toName()),\"hsl\"===t&&(n=this.toHslString()),\"hsv\"===t&&(n=this.toHsvString()),n||this.toHexString())},clone:function(){return e(this.toString())},_applyModification:function(t,e){var n=t.apply(null,[this].concat([].slice.call(e)));return this._r=n._r,this._g=n._g,this._b=n._b,this.setAlpha(n._a),this},lighten:function(){return this._applyModification(p,arguments)},brighten:function(){return this._applyModification(g,arguments)},darken:function(){return this._applyModification(v,arguments)},desaturate:function(){return this._applyModification(f,arguments)},saturate:function(){return this._applyModification(d,arguments)},greyscale:function(){return this._applyModification(h,arguments)},spin:function(){return this._applyModification(m,arguments)},_applyCombination:function(t,e){return t.apply(null,[this].concat([].slice.call(e)))},analogous:function(){return this._applyCombination(w,arguments)},complement:function(){return this._applyCombination(y,arguments)},monochromatic:function(){return this._applyCombination(k,arguments)},splitcomplement:function(){return this._applyCombination(_,arguments)},triad:function(){return this._applyCombination(x,arguments)},tetrad:function(){return this._applyCombination(b,arguments)}},e.fromRatio=function(t,n){if(\"object\"==typeof t){var r={};for(var a in t)t.hasOwnProperty(a)&&(\"a\"===a?r[a]=t[a]:r[a]=O(t[a]));t=r}return e(t,n)},e.equals=function(t,n){return t&&n?e(t).toRgbString()==e(n).toRgbString():!1},e.random=function(){return e.fromRatio({r:Z(),g:Z(),b:Z()})},e.mix=function(t,n,r){r=0===r?0:r||50;var a,o=e(t).toRgb(),i=e(n).toRgb(),l=r/100,s=2*l-1,c=i.a-o.a;a=s*c==-1?s:(s+c)/(1+s*c),a=(a+1)/2;var u=1-a,f={r:i.r*a+o.r*u,g:i.g*a+o.g*u,b:i.b*a+o.b*u,a:i.a*l+o.a*(1-l)};return e(f)},e.readability=function(t,n){var r=e(t),a=e(n);return(Math.max(r.getLuminance(),a.getLuminance())+.05)/(Math.min(r.getLuminance(),a.getLuminance())+.05)},e.isReadable=function(t,n,r){var a,o,i=e.readability(t,n);switch(o=!1,a=I(r),a.level+a.size){case\"AAsmall\":case\"AAAlarge\":o=i>=4.5;break;case\"AAlarge\":o=i>=3;break;case\"AAAsmall\":o=i>=7}return o},e.mostReadable=function(t,n,r){var a,o,i,l,s=null,c=0;r=r||{},o=r.includeFallbackColors,i=r.level,l=r.size;for(var u=0;u<n.length;u++)a=e.readability(t,n[u]),a>c&&(c=a,s=e(n[u]));return e.isReadable(t,s,{level:i,size:l})||!o?s:(r.includeFallbackColors=!1,e.mostReadable(t,[\"#fff\",\"#000\"],r))};var Y=e.names={aliceblue:\"f0f8ff\",antiquewhite:\"faebd7\",aqua:\"0ff\",aquamarine:\"7fffd4\",azure:\"f0ffff\",beige:\"f5f5dc\",bisque:\"ffe4c4\",black:\"000\",blanchedalmond:\"ffebcd\",blue:\"00f\",blueviolet:\"8a2be2\",brown:\"a52a2a\",burlywood:\"deb887\",burntsienna:\"ea7e5d\",cadetblue:\"5f9ea0\",chartreuse:\"7fff00\",chocolate:\"d2691e\",coral:\"ff7f50\",cornflowerblue:\"6495ed\",cornsilk:\"fff8dc\",crimson:\"dc143c\",cyan:\"0ff\",darkblue:\"00008b\",darkcyan:\"008b8b\",darkgoldenrod:\"b8860b\",darkgray:\"a9a9a9\",darkgreen:\"006400\",darkgrey:\"a9a9a9\",darkkhaki:\"bdb76b\",darkmagenta:\"8b008b\",darkolivegreen:\"556b2f\",darkorange:\"ff8c00\",darkorchid:\"9932cc\",darkred:\"8b0000\",darksalmon:\"e9967a\",darkseagreen:\"8fbc8f\",darkslateblue:\"483d8b\",darkslategray:\"2f4f4f\",darkslategrey:\"2f4f4f\",darkturquoise:\"00ced1\",darkviolet:\"9400d3\",deeppink:\"ff1493\",deepskyblue:\"00bfff\",dimgray:\"696969\",dimgrey:\"696969\",dodgerblue:\"1e90ff\",firebrick:\"b22222\",floralwhite:\"fffaf0\",forestgreen:\"228b22\",fuchsia:\"f0f\",gainsboro:\"dcdcdc\",ghostwhite:\"f8f8ff\",gold:\"ffd700\",goldenrod:\"daa520\",gray:\"808080\",green:\"008000\",greenyellow:\"adff2f\",grey:\"808080\",honeydew:\"f0fff0\",hotpink:\"ff69b4\",indianred:\"cd5c5c\",indigo:\"4b0082\",ivory:\"fffff0\",khaki:\"f0e68c\",lavender:\"e6e6fa\",lavenderblush:\"fff0f5\",lawngreen:\"7cfc00\",lemonchiffon:\"fffacd\",lightblue:\"add8e6\",lightcoral:\"f08080\",lightcyan:\"e0ffff\",lightgoldenrodyellow:\"fafad2\",lightgray:\"d3d3d3\",lightgreen:\"90ee90\",lightgrey:\"d3d3d3\",lightpink:\"ffb6c1\",lightsalmon:\"ffa07a\",lightseagreen:\"20b2aa\",lightskyblue:\"87cefa\",lightslategray:\"789\",lightslategrey:\"789\",lightsteelblue:\"b0c4de\",lightyellow:\"ffffe0\",lime:\"0f0\",limegreen:\"32cd32\",linen:\"faf0e6\",magenta:\"f0f\",maroon:\"800000\",mediumaquamarine:\"66cdaa\",mediumblue:\"0000cd\",mediumorchid:\"ba55d3\",mediumpurple:\"9370db\",mediumseagreen:\"3cb371\",mediumslateblue:\"7b68ee\",mediumspringgreen:\"00fa9a\",mediumturquoise:\"48d1cc\",mediumvioletred:\"c71585\",midnightblue:\"191970\",mintcream:\"f5fffa\",mistyrose:\"ffe4e1\",moccasin:\"ffe4b5\",navajowhite:\"ffdead\",navy:\"000080\",oldlace:\"fdf5e6\",olive:\"808000\",olivedrab:\"6b8e23\",orange:\"ffa500\",orangered:\"ff4500\",orchid:\"da70d6\",palegoldenrod:\"eee8aa\",palegreen:\"98fb98\",paleturquoise:\"afeeee\",palevioletred:\"db7093\",papayawhip:\"ffefd5\",peachpuff:\"ffdab9\",peru:\"cd853f\",pink:\"ffc0cb\",plum:\"dda0dd\",powderblue:\"b0e0e6\",purple:\"800080\",rebeccapurple:\"663399\",red:\"f00\",rosybrown:\"bc8f8f\",royalblue:\"4169e1\",saddlebrown:\"8b4513\",salmon:\"fa8072\",sandybrown:\"f4a460\",seagreen:\"2e8b57\",seashell:\"fff5ee\",sienna:\"a0522d\",silver:\"c0c0c0\",skyblue:\"87ceeb\",slateblue:\"6a5acd\",slategray:\"708090\",slategrey:\"708090\",snow:\"fffafa\",springgreen:\"00ff7f\",steelblue:\"4682b4\",tan:\"d2b48c\",teal:\"008080\",thistle:\"d8bfd8\",tomato:\"ff6347\",turquoise:\"40e0d0\",violet:\"ee82ee\",wheat:\"f5deb3\",white:\"fff\",whitesmoke:\"f5f5f5\",yellow:\"ff0\",yellowgreen:\"9acd32\"},U=e.hexNames=M(Y),X=function(){var t=\"[-\\\\+]?\\\\d+%?\",e=\"[-\\\\+]?\\\\d*\\\\.\\\\d+%?\",n=\"(?:\"+e+\")|(?:\"+t+\")\",r=\"[\\\\s|\\\\(]+(\"+n+\")[,|\\\\s]+(\"+n+\")[,|\\\\s]+(\"+n+\")\\\\s*\\\\)?\",a=\"[\\\\s|\\\\(]+(\"+n+\")[,|\\\\s]+(\"+n+\")[,|\\\\s]+(\"+n+\")[,|\\\\s]+(\"+n+\")\\\\s*\\\\)?\";return{rgb:new RegExp(\"rgb\"+r),rgba:new RegExp(\"rgba\"+a),hsl:new RegExp(\"hsl\"+r),hsla:new RegExp(\"hsla\"+a),hsv:new RegExp(\"hsv\"+r),hsva:new RegExp(\"hsva\"+a),hex3:/^#?([0-9a-fA-F]{1})([0-9a-fA-F]{1})([0-9a-fA-F]{1})$/,hex6:/^#?([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})$/,hex8:/^#?([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})$/}}();\"undefined\"!=typeof n&&n.exports?n.exports=e:\"function\"==typeof t&&t.amd?t(function(){return e}):window.tinycolor=e}()},{}],14:[function(t,e,n){\"use strict\";e.exports=[\"\",{path:\"M-2.4,-3V3L0.6,0Z\",backoff:.6},{path:\"M-3.7,-2.5V2.5L1.3,0Z\",backoff:1.3},{path:\"M-4.45,-3L-1.65,-0.2V0.2L-4.45,3L1.55,0Z\",backoff:1.55},{path:\"M-2.2,-2.2L-0.2,-0.2V0.2L-2.2,2.2L-1.4,3L1.6,0L-1.4,-3Z\",backoff:1.6},{path:\"M-4.4,-2.1L-0.6,-0.2V0.2L-4.4,2.1L-4,3L2,0L-4,-3Z\",backoff:2},{path:\"M2,0A2,2 0 1,1 0,-2A2,2 0 0,1 2,0Z\",backoff:0},{path:\"M2,2V-2H-2V2Z"
,
"\",backoff:0}]},{}],15:[function(t,e,n){\"use strict\";var r=t(\"./arrow_paths\"),a=t(\"../../plots/font_attributes\"),o=t(\"../../plots/cartesian/constants\"),i=t(\"../../lib/extend\").extendFlat;e.exports={_isLinkedToArray:!0,text:{valType:\"string\"},textangle:{valType:\"angle\",dflt:0},font:i({},a,{}),opacity:{valType:\"number\",min:0,max:1,dflt:1},align:{valType:\"enumerated\",values:[\"left\",\"center\",\"right\"],dflt:\"center\"},bgcolor:{valType:\"color\",dflt:\"rgba(0,0,0,0)\"},bordercolor:{valType:\"color\",dflt:\"rgba(0,0,0,0)\"},borderpad:{valType:\"number\",min:0,dflt:1},borderwidth:{valType:\"number\",min:0,dflt:1},showarrow:{valType:\"boolean\",dflt:!0},arrowcolor:{valType:\"color\"},arrowhead:{valType:\"integer\",min:0,max:r.length,dflt:1},arrowsize:{valType:\"number\",min:.3,dflt:1},arrowwidth:{valType:\"number\",min:.1},ax:{valType:\"number\",dflt:-10},ay:{valType:\"number\",dflt:-30},axref:{valType:\"enumerated\",dflt:\"pixel\",values:[\"pixel\",o.idRegex.x.toString()]},ayref:{valType:\"enumerated\",dflt:\"pixel\",values:[\"pixel\",o.idRegex.y.toString()]},xref:{valType:\"enumerated\",values:[\"paper\",o.idRegex.x.toString()]},x:{valType:\"number\"},xanchor:{valType:\"enumerated\",values:[\"auto\",\"left\",\"center\",\"right\"],dflt:\"auto\"},yref:{valType:\"enumerated\",values:[\"paper\",o.idRegex.y.toString()]},y:{valType:\"number\"},yanchor:{valType:\"enumerated\",values:[\"auto\",\"top\",\"middle\",\"bottom\"],dflt:\"auto\"},_deprecated:{ref:{valType:\"string\"}}}},{\"../../lib/extend\":88,\"../../plots/cartesian/constants\":115,\"../../plots/font_attributes\":128,\"./arrow_paths\":14}],16:[function(t,e,n){\"use strict\";function r(t,e){function n(e,n){return c.coerce(t,r,v.layoutAttributes,e,n)}var r={};n(\"opacity\"),n(\"align\"),n(\"bgcolor\");var a=n(\"bordercolor\"),o=f.opacity(a);n(\"borderpad\");var i=n(\"borderwidth\"),l=n(\"showarrow\");l&&(n(\"arrowcolor\",o?r.bordercolor:f.defaultLine),n(\"arrowhead\"),n(\"arrowsize\"),n(\"arrowwidth\",2*(o&&i||1)),n(\"ax\"),n(\"ay\"),n(\"axref\"),n(\"ayref\"),c.noneOrAll(t,r,[\"ax\",\"ay\"])),n(\"text\",l?\"&nbsp;\":\"new text\"),n(\"textangle\"),c.coerceFont(n,\"font\",e.font);\n"
,
"for(var s=[\"x\",\"y\"],d=0;2>d;d++){var h=s[d],p={_fullLayout:e},g=u.coerceRef(t,r,p,h),m=u.coerceARef(t,r,p,h),y=.5;if(\"paper\"!==g){var x=u.getFromId(p,g);if(y=x.range[0]+y*(x.range[1]-x.range[0]),-1!==[\"date\",\"category\"].indexOf(x.type)&&\"string\"==typeof t[h]){var b;if(\"date\"===x.type){if(b=c.dateTime2ms(t[h]),b!==!1&&(t[h]=b),m===g){var _=c.dateTime2ms(t[\"a\"+h]);_!==!1&&(t[\"a\"+h]=_)}}else(x._categories||[]).length&&(b=x._categories.indexOf(t[h]),-1!==b&&(t[h]=b))}}n(h,y),l||n(h+\"anchor\")}return c.noneOrAll(t,r,[\"x\",\"y\"]),r}function a(t){var e=t._fullLayout;e.annotations.forEach(function(e){var n=u.getFromId(t,e.xref),r=u.getFromId(t,e.yref);if(n||r){var a=(e._xsize||0)/2,o=e._xshift||0,i=(e._ysize||0)/2,l=e._yshift||0,s=a-o,c=a+o,f=i-l,d=i+l;if(e.showarrow){var h=3*e.arrowsize*e.arrowwidth;s=Math.max(s,h),c=Math.max(c,h),f=Math.max(f,h),d=Math.max(d,h)}n&&n.autorange&&u.expand(n,[n.l2c(e.x)],{ppadplus:c,ppadminus:s}),r&&r.autorange&&u.expand(r,[r.l2c(e.y)],{ppadplus:d,ppadminus:f})}})}function o(t,e,n,r,a,o,i,l){var s=n-t,c=a-t,u=i-a,f=r-e,d=o-e,h=l-o,p=s*h-u*f;if(0===p)return null;var g=(c*h-u*d)/p,v=(c*f-s*d)/p;return 0>v||v>1||0>g||g>1?null:{x:t+s*g,y:e+f*g}}var i=t(\"d3\"),l=t(\"fast-isnumeric\"),s=t(\"../../plotly\"),c=t(\"../../lib\"),u=t(\"../../plots/cartesian/axes\"),f=t(\"../color\"),d=t(\"../drawing\"),h=t(\"../../lib/svg_text_utils\"),p=t(\"../../lib/setcursor\"),g=t(\"../dragelement\"),v=e.exports={};v.ARROWPATHS=t(\"./arrow_paths\"),v.layoutAttributes=t(\"./attributes\"),v.supplyLayoutDefaults=function(t,e){for(var n=t.annotations||[],a=e.annotations=[],o=0;o<n.length;o++)a.push(r(n[o]||{},e))},v.drawAll=function(t){var e=t._fullLayout;e._infolayer.selectAll(\".annotation\").remove();for(var n=0;n<e.annotations.length;n++)v.draw(t,n);return s.Plots.previousPromises(t)},v.add=function(t){var e=t._fullLayout.annotations.length;s.relayout(t,\"annotations[\"+e+\"]\",\"add\")},v.draw=function(t,e,n,a){function m(t){return t.call(d.font,K).attr({\"text-anchor\":{left:\"start\",right:\"end\"}[B.align]||\"middle\"}),h.convertToTspans(t,y),t}function y(){function n(t,e){return\"auto\"===e&&(e=1/3>t?\"left\":t>2/3?\"right\":\"center\"),{center:0,middle:0,left:.5,bottom:-.5,right:-.5,top:.5}[e]}tt.selectAll(\"tspan.line\").attr({y:0,x:0});var r=G.select(\".annotation-math-group\"),a=!r.empty(),l=d.bBox((a?r:tt).node()),h=l.width,m=l.height,y=Math.round(h+2*W),x=Math.round(m+2*W);B._w=h,B._h=m;var b=!1;if([\"x\",\"y\"].forEach(function(e){var r,a=B[e+\"ref\"]||e,o=u.getFromId(t,a),i=(Y+(\"x\"===e?0:90))*Math.PI/180,l=y*Math.abs(Math.cos(i))+x*Math.abs(Math.sin(i)),s=B[e+\"anchor\"];if(o){if(!o.autorange&&(B[e]-o.range[0])*(B[e]-o.range[1])>0&&(B[\"a\"+e+\"ref\"]===a?(B[\"a\"+e]-o.range[0])*(B[\"a\"+e]-o.range[1])>0&&(b=!0):b=!0,b))return;Z[e]=o._offset+o.l2p(B[e]),r=.5}else r=B[e],\"y\"===e&&(r=1-r),Z[e]=\"x\"===e?S.l+S.w*r:S.t+S.h*r;var c=0;B[\"a\"+e+\"ref\"]===a?Z[\"aa\"+e]=o._offset+o.l2p(B[\"a\"+e]):(c=B.showarrow?B[\"a\"+e]:l*n(r,s),Z[e]+=c),B[\"_\"+e+\"type\"]=o&&o.type,B[\"_\"+e+\"size\"]=l,B[\"_\"+e+\"shift\"]=c}),b)return void G.remove();var w,k;B.showarrow&&(w=B.axref===B.xref?Z.x:c.constrain(Z.x-B.ax,1,_.width-1),k=B.ayref===B.yref?Z.y:c.constrain(Z.y-B.ay,1,_.height-1)),Z.x=c.constrain(Z.x,1,_.width-1),Z.y=c.constrain(Z.y,1,_.height-1);var M=W-l.top,A=W-l.left;a?r.select(\"svg\").attr({x:W-1,y:W}):(tt.attr({x:A,y:M}),tt.selectAll(\"tspan.line\").attr({y:M,x:A})),J.call(d.setRect,$/2,$/2,y-$,x-$);var L=0,T=0;L=B.axref===B.xref?Math.round(Z.aax-y/2):Math.round(Z.x-y/2),T=B.ayref===B.yref?Math.round(Z.aay-x/2):Math.round(Z.y-x/2),G.call(c.setTranslate,L,T);var z=\"annotations[\"+e+\"]\",E=function(n,r){i.select(t).selectAll('.annotation-arrow-g[data-index=\"'+e+'\"]').remove();var a,l;a=B.axref===B.xref?Z.aax+n:Z.x+n,l=B.ayref===B.yref?Z.aay+r:Z.y+r;var u=c.rotationXYMatrix(Y,a,l),d=c.apply2DTransform(u),h=c.apply2DTransform2(u),p=J.attr(\"width\")/2,m=J.attr(\"height\")/2,y=[[a-p,l-m,a-p,l+m],[a-p,l+m,a+p,l+m],[a+p,l+m,a+p,l-m],[a+p,l-m,a-p,l-m]].map(h);if(!y.reduce(function(t,e){return t^!!o(w,k,w+1e6,k+1e6,e[0],e[1],e[2],e[3])},!1)){y.forEach(function(t){var e=o(a,l,w,k,t[0],t[1],t[2],t[3]);e&&(a=e.x,l=e.y)});var x=B.arrowwidth,b=B.arrowcolor,_=U.append(\"g\").style({opacity:f.opacity(b)}).classed(\"annotation-arrow-g\",!0).attr(\"data-index\",String(e)),M=_.append(\"path\").attr(\"d\",\"M\"+a+\",\"+l+\"L\"+w+\",\"+k).style(\"stroke-width\",x+\"px\").call(f.stroke,f.rgb(b));v.arrowhead(M,B.arrowhead,\"end\",B.arrowsize);var A=_.append(\"path\").classed(\"annotation\",!0).classed(\"anndrag\",!0).attr({\"data-index\":String(e),d:\"M3,3H-3V-3H3ZM0,0L\"+(a-w)+\",\"+(l-k),transform:\"translate(\"+w+\",\"+k+\")\"}).style(\"stroke-width\",x+6+\"px\").call(f.stroke,\"rgba(0,0,0,0)\").call(f.fill,\"rgba(0,0,0,0)\");if(t._context.editable){var L,T,E;g.init({element:A.node(),prepFn:function(){var t=c.getTranslate(G);T=t.x,E=t.y,L={},H&&H.autorange&&(L[H._name+\".autorange\"]=!0),V&&V.autorange&&(L[V._name+\".autorange\"]=!0)},moveFn:function(t,e){_.attr(\"transform\",\"translate(\"+t+\",\"+e+\")\");var n=d(T,E),r=n[0]+t,a=n[1]+e;G.call(c.setTranslate,r,a),L[z+\".x\"]=H?B.x+t/H._m:(w+t-S.l)/S.w,L[z+\".y\"]=V?B.y+e/V._m:1-(k+e-S.t)/S.h,B.axref===B.xref&&(L[z+\".ax\"]=H?B.ax+t/H._m:(w+t-S.l)/S.w),B.ayref===B.yref&&(L[z+\".ay\"]=V?B.ay+e/V._m:1-(k+e-S.t)/S.h),X.attr({transform:\"rotate(\"+Y+\",\"+r+\",\"+a+\")\"})},doneFn:function(e){if(e){s.relayout(t,L);var n=document.querySelector(\".js-notes-box-panel\");n&&n.redraw(n.selectedObj)}}})}}};B.showarrow&&E(0,0);var C=c.rotationXYMatrix(Y,Z.x,Z.y),O=c.apply2DTransform(C);if(t._context.editable){var P,N,D;g.init({element:G.node(),prepFn:function(){var t=c.getTranslate(G);P=t.x,N=t.y,D={}},moveFn:function(t,e){G.call(c.setTranslate,P+t,N+e);var n=\"pointer\";if(B.showarrow)B.axref===B.xref?D[z+\".ax\"]=H.p2l(H.l2p(B.ax)+t):D[z+\".ax\"]=B.ax+t,B.ayref===B.yref?D[z+\".ay\"]=V.p2l(V.l2p(B.ay)+e):D[z+\".ay\"]=B.ay+e,E(t,e);else{if(H)D[z+\".x\"]=B.x+t/H._m;else{var r=B._xsize/S.w,a=B.x+B._xshift/S.w-r/2;D[z+\".x\"]=g.align(a+t/S.w,r,0,1,B.xanchor)}if(V)D[z+\".y\"]=B.y+e/V._m;else{var o=B._ysize/S.h,i=B.y-B._yshift/S.h-o/2;D[z+\".y\"]=g.align(i-e/S.h,o,0,1,B.yanchor)}H&&V||(n=g.getCursor(H?.5:D[z+\".x\"],V?.5:D[z+\".y\"],B.xanchor,B.yanchor))}var l=O(P,N),s=l[0]+t,u=l[1]+e;G.call(c.setTranslate,P+t,N+e),X.attr({transform:\"rotate(\"+Y+\",\"+s+\",\"+u+\")\"}),p(G,n)},doneFn:function(e){if(p(G),e){s.relayout(t,D);var n=document.querySelector(\".js-notes-box-panel\");n&&n.redraw(n.selectedObj)}}})}}var x,b=t.layout,_=t._fullLayout;if(!l(e)||-1===e){if(!e&&Array.isArray(a))return b.annotations=a,v.supplyLayoutDefaults(b,_),void v.drawAll(t);if(\"remove\"===a)return delete b.annotations,_.annotations=[],void v.drawAll(t);if(n&&\"add\"!==a){for(x=0;x<_.annotations.length;x++)v.draw(t,x,n,a);return}e=_.annotations.length,_.annotations.push({})}if(!n&&a){if(\"remove\"===a){for(_._infolayer.selectAll('.annotation[data-index=\"'+e+'\"]').remove(),_.annotations.splice(e,1),b.annotations.splice(e,1),x=e;x<_.annotations.length;x++)_._infolayer.selectAll('.annotation[data-index=\"'+(x+1)+'\"]').attr(\"data-index\",String(x)),v.draw(t,x);return}if(\"add\"===a||c.isPlainObject(a)){_.annotations.splice(e,0,{});var w=c.isPlainObject(a)?c.extendFlat({},a):{text:\"New text\"};for(b.annotations?b.annotations.splice(e,0,w):b.annotations=[w],x=_.annotations.length-1;x>e;x--)_._infolayer.selectAll('.annotation[data-index=\"'+(x-1)+'\"]').attr(\"data-index\",String(x)),v.draw(t,x)}}_._infolayer.selectAll('.annotation[data-index=\"'+e+'\"]').remove();var k=b.annotations[e],M=_.annotations[e];if(k){var A={xref:k.xref,yref:k.yref},L={};\"string\"==typeof n&&n?L[n]=a:c.isPlainObject(n)&&(L=n);var T=Object.keys(L);for(x=0;x<T.length;x++){var z=T[x];c.nestedProperty(k,z).set(L[z])}var S=_._size,E=[\"x\",\"y\"];for(x=0;2>x;x++){var C=E[x];if(void 0===L[C]&&void 0!==k[C]){var O=u.getFromId(t,u.coerceRef(A,{},t,C)),P=u.getFromId(t,u.coerceRef(k,{},t,C)),N=k[C],D=M[\"_\"+C+\"type\"];if(void 0!==L[C+\"ref\"]){var I=\"auto\"===k[C+\"anchor\"],R=\"x\"===C?S.w:S.h,j=(M[\"_\"+C+\"size\"]||0)/(2*R);if(O&&P)N=(N-O.range[0])/(O.range[1]-O.range[0]),N=P.range[0]+N*(P.range[1]-P.range[0]);else if(O){if(N=(N-O.range[0])/(O.range[1]-O.range[0]),N=O.domain[0]+N*(O.domain[1]-O.domain[0]),I){var q=N+j,F=N-j;2/3>N+F?N=F:N+q>4/3&&(N=q)}}else P&&(I&&(1/3>N?N+=j:N>2/3&&(N-=j)),N=(N-P.domain[0])/(P.domain[1]-P.domain[0]),N=P.range[0]+N*(P.range[1]-P.range[0]))}P&&P===O&&D&&(\"log\"===D&&\"log\"!==P.type?N=Math.pow(10,N):\"log\"!==D&&\"log\"===P.type&&(N=N>0?Math.log(N)/Math.LN10:void 0)),k[C]=N}}var B=r(k,_);_.annotations[e]=B;var H=u.getFromId(t,B.xref),V=u.getFromId(t,B.yref),Z={x:0,y:0},Y=+B.textangle||0,U=_._infolayer.append(\"g\").classed(\"annotation\",!0).attr(\"data-index\",String(e)).style(\"opacity\",B.opacity).on(\"click\",function(){t._dragging=!1,t.emit(\"plotly_clickannotation\",{index:e,annotation:k,fullAnnotation:B})}),X=U.append(\"g\").classed(\"annotation-text-g\",!0).attr(\"data-index\",String(e)),G=X.append(\"g\"),$=B.borderwidth,Q=B.borderpad,W=$+Q,J=G.append(\"rect\").attr(\"class\",\"bg\").style(\"stroke-width\",$+\"px\").call(f.stroke,B.bordercolor).call(f.fill,B.bgcolor),K=B.font,tt=G.append(\"text\").classed(\"annotation\",!0).attr(\"data-unformatted\",B.text).text(B.text);t._context.editable?tt.call(h.makeEditable,G).call(m).on(\"edit\",function(n){B.text=n,this.attr({\"data-unformatted\":B.text}),this.call(m);var r={};r[\"annotations[\"+e+\"].text\"]=B.text,H&&H.autorange&&(r[H._name+\".autorange\"]=!0),V&&V.autorange&&(r[V._name+\".autorange\"]=!0),s.relayout(t,r)}):tt.call(m),X.attr({transform:\"rotate(\"+Y+\",\"+Z.x+\",\"+Z.y+\")\"}).call(d.setPosition,Z.x,Z.y)}},v.arrowhead=function(t,e,n,r){l(r)||(r=1);var a=t.node(),o=v.ARROWPATHS[e||0];if(o){\"string\"==typeof n&&n||(n=\"end\");var s,c,u,h,p=(d.getPx(t,\"stroke-width\")||1)*r,g=t.style(\"stroke\")||f.defaultLine,m=t.style(\"stroke-opacity\")||1,y=n.indexOf(\"start\")>=0,x=n.indexOf(\"end\")>=0,b=o.backoff*p;if(\"line\"===a.nodeName){if(s={x:+t.attr(\"x1\"),y:+t.attr(\"y1\")},c={x:+t.attr(\"x2\"),y:+t.attr(\"y2\")},u=Math.atan2(s.y-c.y,s.x-c.x),h=u+Math.PI,b){var _=b*Math.cos(u),w=b*Math.sin(u);y&&(s.x-=_,s.y-=w,t.attr({x1:s.x,y1:s.y})),x&&(c.x+=_,c.y+=w,t.attr({x2:c.x,y2:c.y}))}}else i"
,
"f(\"path\"===a.nodeName){var k=a.getTotalLength(),M=\"\";if(y){var A=a.getPointAtLength(0),L=a.getPointAtLength(.1);u=Math.atan2(A.y-L.y,A.x-L.x),s=a.getPointAtLength(Math.min(b,k)),b&&(M=\"0px,\"+b+\"px,\")}if(x){var T=a.getPointAtLength(k),z=a.getPointAtLength(k-.1);if(h=Math.atan2(T.y-z.y,T.x-z.x),c=a.getPointAtLength(Math.max(0,k-b)),b){var S=M?2*b:b;M+=k-S+\"px,\"+k+\"px\"}}else M&&(M+=k+\"px\");M&&t.style(\"stroke-dreamledgerarray\",M)}var E=function(n,r){e>5&&(r=0),i.select(a.parentElement).append(\"path\").attr({\"class\":t.attr(\"class\"),d:o.path,transform:\"translate(\"+n.x+\",\"+n.y+\")rotate(\"+180*r/Math.PI+\")scale(\"+p+\")\"}).style({fill:g,opacity:m,\"stroke-width\":0})};y&&E(s,u),x&&E(c,h)}},v.calcAutorange=function(t){var e=t._fullLayout,n=e.annotations;if(n.length&&t._fullData.length){var r={};n.forEach(function(t){r[t.xref]=!0,r[t.yref]=!0});var o=u.list(t).filter(function(t){return t.autorange&&r[t._id]});if(o.length)return c.syncOrAsync([v.drawAll,a],t)}}},{\"../../lib\":89,\"../../lib/setcursor\":98,\"../../lib/svg_text_utils\":100,\"../../plotly\":107,\"../../plots/cartesian/axes\":110,\"../color\":18,\"../dragelement\":39,\"../drawing\":41,\"./arrow_paths\":14,\"./attributes\":15,d3:9,\"fast-isnumeric\":11}],17:[function(t,e,n){\"use strict\";n.defaults=[\"#1f77b4\",\"#ff7f0e\",\"#2ca02c\",\"#d62728\",\"#9467bd\",\"#8c564b\",\"#e377c2\",\"#7f7f7f\",\"#bcbd22\",\"#17becf\"],n.defaultLine=\"#444\",n.lightLine=\"#eee\",n.background=\"#fff\",n.lightFraction=1e3/11},{}],18:[function(t,e,n){\"use strict\";function r(t){if(o(t)||\"string\"!=typeof t)return t;var e=t.trim();if(\"rgb\"!==e.substr(0,3))return t;var n=e.match(/^rgba?\\s*\\(([^()]*)\\)$/);if(!n)return t;var r=n[1].trim().split(/\\s*[\\s,]\\s*/),a=\"a\"===e.charAt(3)&&4===r.length;if(!a&&3!==r.length)return t;for(var i=0;i<r.length;i++){if(!r[i].length)return t;if(r[i]=Number(r[i]),!(r[i]>=0))return t;if(3===i)r[i]>1&&(r[i]=1);else if(r[i]>=1)return t}var l=Math.round(255*r[0])+\", \"+Math.round(255*r[1])+\", \"+Math.round(255*r[2]);return a?\"rgba(\"+l+\", \"+r[3]+\")\":\"rgb(\"+l+\")\"}var a=t(\"tinycolor2\"),o=t(\"fast-isnumeric\"),i=e.exports={},l=t(\"./attributes\");i.defaults=l.defaults,i.defaultLine=l.defaultLine,i.lightLine=l.lightLine,i.background=l.background,i.tinyRGB=function(t){var e=t.toRgb();return\"rgb(\"+Math.round(e.r)+\", \"+Math.round(e.g)+\", \"+Math.round(e.b)+\")\"},i.rgb=function(t){return i.tinyRGB(a(t))},i.opacity=function(t){return t?a(t).getAlpha():0},i.addOpacity=function(t,e){var n=a(t).toRgb();return\"rgba(\"+Math.round(n.r)+\", \"+Math.round(n.g)+\", \"+Math.round(n.b)+\", \"+e+\")\"},i.combine=function(t,e){var n=a(t).toRgb();if(1===n.a)return a(t).toRgbString();var r=a(e||i.background).toRgb(),o=1===r.a?r:{r:255*(1-r.a)+r.r*r.a,g:255*(1-r.a)+r.g*r.a,b:255*(1-r.a)+r.b*r.a},l={r:o.r*(1-n.a)+n.r*n.a,g:o.g*(1-n.a)+n.g*n.a,b:o.b*(1-n.a)+n.b*n.a};return a(l).toRgbString()},i.stroke=function(t,e){var n=a(e);t.style({stroke:i.tinyRGB(n),\"stroke-opacity\":n.getAlpha()})},i.fill=function(t,e){var n=a(e);t.style({fill:i.tinyRGB(n),\"fill-opacity\":n.getAlpha()})},i.clean=function(t){if(t&&\"object\"==typeof t){var e,n,a,o,l=Object.keys(t);for(e=0;e<l.length;e++)if(a=l[e],o=t[a],\"color\"===a.substr(a.length-5))if(Array.isArray(o))for(n=0;n<o.length;n++)o[n]=r(o[n]);else t[a]=r(o);else if(\"colorscale\"===a.substr(a.length-10)&&Array.isArray(o))for(n=0;n<o.length;n++)Array.isArray(o[n])&&(o[n][1]=r(o[n][1]));else if(Array.isArray(o)){var s=o[0];if(!Array.isArray(s)&&s&&\"object\"==typeof s)for(n=0;n<o.length;n++)i.clean(o[n])}else o&&\"object\"==typeof o&&i.clean(o)}}},{\"./attributes\":17,\"fast-isnumeric\":11,tinycolor2:13}],19:[function(t,e,n){\"use strict\";var r=t(\"../../plots/cartesian/layout_attributes\"),a=t(\"../../plots/font_attributes\"),o=t(\"../../lib/extend\").extendFlat;e.exports={thicknessmode:{valType:\"enumerated\",values:[\"fraction\",\"pixels\"],dflt:\"pixels\"},thickness:{valType:\"number\",min:0,dflt:30},lenmode:{valType:\"enumerated\",values:[\"fraction\",\"pixels\"],dflt:\"fraction\"},len:{valType:\"number\",min:0,dflt:1},x:{valType:\"number\",dflt:1.02,min:-2,max:3},xanchor:{valType:\"enumerated\",values:[\"left\",\"center\",\"right\"],dflt:\"left\"},xpad:{valType:\"number\",min:0,dflt:10},y:{valType:\"number\",dflt:.5,min:-2,max:3},yanchor:{valType:\"enumerated\",values:[\"top\",\"middle\",\"bottom\"],dflt:\"middle\"},ypad:{valType:\"number\",min:0,dflt:10},outlinecolor:r.linecolor,outlinewidth:r.linewidth,bordercolor:r.linecolor,borderwidth:{valType:\"number\",min:0,dflt:0},bgcolor:{valType:\"color\",dflt:\"rgba(0,0,0,0)\"},tickmode:r.tickmode,nticks:r.nticks,tick0:r.tick0,dtick:r.dtick,tickvals:r.tickvals,ticktext:r.ticktext,ticks:o({},r.ticks,{dflt:\"\"}),ticklen:r.ticklen,tickwidth:r.tickwidth,tickcolor:r.tickcolor,showticklabels:r.showticklabels,tickfont:r.tickfont,tickangle:r.tickangle,tickformat:r.tickformat,tickprefix:r.tickprefix,showtickprefix:r.showtickprefix,ticksuffix:r.ticksuffix,showticksuffix:r.showticksuffix,exponentformat:r.exponentformat,showexponent:r.showexponent,title:{valType:\"string\",dflt:\"Click to enter colorscale title\"},titlefont:o({},a,{}),titleside:{valType:\"enumerated\",values:[\"right\",\"top\",\"bottom\"],dflt:\"top\"}}},{\"../../lib/extend\":88,\"../../plots/cartesian/layout_attributes\":119,\"../../plots/font_attributes\":128}],20:[function(t,e,n){\"use strict\";var r=t(\"../../lib\"),a=t(\"../../plots/cartesian/tick_value_defaults\"),o=t(\"../../plots/cartesian/tick_mark_defaults\"),i=t(\"../../plots/cartesian/tick_label_defaults\"),l=t(\"./attributes\");e.exports=function(t,e,n){function s(t,e){return r.coerce(u,c,l,t,e)}var c=e.colorbar={},u=t.colorbar||{},f=s(\"thicknessmode\");s(\"thickness\",\"fraction\"===f?30/(n.width-n.margin.l-n.margin.r):30);var d=s(\"lenmode\");s(\"len\",\"fraction\"===d?1:n.height-n.margin.t-n.margin.b),s(\"x\"),s(\"xanchor\"),s(\"xpad\"),s(\"y\"),s(\"yanchor\"),s(\"ypad\"),r.noneOrAll(u,c,[\"x\",\"y\"]),s(\"outlinecolor\"),s(\"outlinewidth\"),s(\"bordercolor\"),s(\"borderwidth\"),s(\"bgcolor\"),a(u,c,s,\"linear\"),i(u,c,s,\"linear\",{outerTicks:!1,font:n.font,noHover:!0}),o(u,c,s,\"linear\",{outerTicks:!1,font:n.font,noHover:!0}),s(\"title\"),r.coerceFont(s,\"titlefont\",n.font),s(\"titleside\")}},{\"../../lib\":89,\"../../plots/cartesian/tick_label_defaults\":125,\"../../plots/cartesian/tick_mark_defaults\":126,\"../../plots/cartesian/tick_value_defaults\":127,\"./attributes\":19}],21:[function(t,e,n){\"use strict\";var r=t(\"d3\"),a=t(\"tinycolor2\"),o=t(\"../../plotly\"),i=t(\"../../plots/plots\"),l=t(\"../../plots/cartesian/axes\"),s=t(\"../dragelement\"),c=t(\"../../lib\"),u=t(\"../../lib/extend\").extendFlat,f=t(\"../../lib/setcursor\"),d=t(\"../drawing\"),h=t(\"../color\"),p=t(\"../titles\"),g=t(\"../../plots/cartesian/axis_defaults\"),v=t(\"../../plots/cartesian/position_defaults\"),m=t(\"../../plots/cartesian/layout_attributes\"),y=t(\"./attributes\");e.exports=function(t,e){function n(){function y(t,e){return c.coerce(W,J,m,t,e)}function _(){if(-1!==[\"top\",\"bottom\"].indexOf(b.titleside)){var e=at.select(\".cbtitle\"),n=e.select(\"text\"),o=[-b.outlinewidth/2,b.outlinewidth/2],i=e.select(\".h\"+J._id+\"title-math-group\").node(),s=15.6;if(n.node()&&(s=1.3*parseInt(n.style(\"font-size\"),10)),i?(it=d.bBox(i).height,it>s&&(o[1]-=(it-s)/2)):n.node()&&!n.classed(\"js-placeholder\")&&(it=d.bBox(e.node()).height),it){if(it+=5,\"top\"===b.titleside)J.domain[1]-=it/A.h,o[1]*=-1;else{J.domain[0]+=it/A.h;var u=Math.max(1,n.selectAll(\"tspan.line\").size());o[1]+=(1-u)*s}e.attr(\"transform\",\"translate(\"+o+\")\"),J.setScale()}}at.selectAll(\".cbfills,.cblines,.cbaxis\").attr(\"transform\",\"translate(0,\"+Math.round(A.h*(1-J.domain[1]))+\")\");var f=at.select(\".cbfills\").selectAll(\"rect.cbfill\").data(S);f.enter().append(\"rect\").classed(\"cbfill\",!0).style(\"stroke\",\"none\"),f.exit().remove(),f.each(function(t,e){var n=[0===e?T[0]:(S[e]+S[e-1])/2,e===S.length-1?T[1]:(S[e]+S[e+1])/2].map(J.c2p).map(Math.round);e!==S.length-1&&(n[1]+=n[1]>n[0]?1:-1);var o=C(t).replace(\"e-\",\"\"),i=a(o).toHexString();r.select(this).attr({x:U,width:Math.max(q,2),y:r.min(n),height:Math.max(r.max(n)-r.min(n),2),fill:i})});var h=at.select(\".cblines\").selectAll(\"path.cbline\").data(b.line.color&&b.line.width?z:[]);return h.enter().append(\"path\").classed(\"cbline\",!0),h.exit().remove(),h.each(function(t){r.select(this).attr(\"d\",\"M\"+U+\",\"+(Math.round(J.c2p(t))+b.line.width/2%1)+\"h\"+q).call(d.lineGroupStyle,b.line.width,E(t),b.line.dreamledger)}),J._axislayer.selectAll(\"g.\"+J._id+\"tick,path\").remove(),J._pos=U+q+(b.outlinewidth||0)/2-(\"outside\"===b.ticks?1:0),J.side=\"right\",c.syncOrAsync([function(){return l.doTicks(t,J,!0)},function(){if(-1===[\"top\",\"bottom\"].indexOf(b.titleside)){var e=J.titlefont.size,n=J._offset+J._length/2,a=A.l+(J.position||0)*A.w+(\"right\"===J.side?10+e*(J.showticklabels?1:.5):-10-e*(J.showticklabels?.5:0));w(\"h\"+J._id+\"title\",{avoid:{selection:r.select(t).selectAll(\"g.\"+J._id+\"tick\"),side:b.titleside,offsetLeft:A.l,offsetTop:A.t,maxShift:M.width},attributes:{x:a,y:n,\"text-anchor\":\"middle\"},transform:{rotate:\"-90\",offset:0}})}}])}function w(e,n){var r,a=x();r=i.traceIs(a,\"markerColorscale\")?\"marker.colorbar.title\":\"colorbar.title\";var o={propContainer:J,propName:r,traceIndex:a.index,dfltName:\"colorscale\",containerGroup:at.select(\".cbtitle\")},l=\"h\"===e.charAt(0)?e.substr(1):\"h\"+e;at.selectAll(\".\"+l+\",.\"+l+\"-math-group\").remove(),p.draw(t,e,u(o,n||{}))}function k(){var n=q+b.outlinewidth/2+d.bBox(J._axislayer.node()).width;if(I=ot.select(\"text\"),I.node()&&!I.classed(\"js-placeholder\")){var r,a=ot.select(\".h\"+J._id+\"title-math-group\").node();r=a&&-1!==[\"top\",\"bottom\"].indexOf(b.titleside)?d.bBox(a).width:d.bBox(ot.node()).right-U-A.l,n=Math.max(n,r)}var o=2*b.xpad+n+b.borderwidth+b.outlinewidth/2,l=$-Q;at.select(\".cbbg\").attr({x:U-b.xpad-(b.borderwidth+b.outlinewidth)/2,y:Q-Z,width:Math.max(o,2),height:Math.max(l+2*Z,2)}).call(h.fill,b.bgcolor).call(h.stroke,b.bordercolor).style({\"stroke-width\":b.borderwidth}),at.selectAll(\".cboutline\").attr({x:U,y:Q+b.ypad+(\"top\"===b.titleside?it:0),width:Math.max(q,2),height:Math.max(l-2*b.ypad-it,2)}).call(h.stroke,b.outlinecolor).style({fill:\"None\",\"stroke-width\":b.outlinewidth});var s=({center:.5,right:1}[b.xanchor]||0)*o;at.attr(\"transform\",\"translate(\"+(A.l-s)+\",\"+A.t+"
,
"\")\"),i.autoMargin(t,e,{x:b.x,y:b.y,l:o*({right:1,center:.5}[b.xanchor]||0),r:o*({left:1,center:.5}[b.xanchor]||0),t:l*({bottom:1,middle:.5}[b.yanchor]||0),b:l*({top:1,middle:.5}[b.yanchor]||0)})}var M=t._fullLayout,A=M._size;if(\"function\"!=typeof b.fillcolor&&\"function\"!=typeof b.line.color)return void M._infolayer.selectAll(\"g.\"+e).remove();var L,T=r.extent((\"function\"==typeof b.fillcolor?b.fillcolor:b.line.color).domain()),z=[],S=[],E=\"function\"==typeof b.line.color?b.line.color:function(){return b.line.color},C=\"function\"==typeof b.fillcolor?b.fillcolor:function(){return b.fillcolor},O=b.levels.end+b.levels.size/100,P=b.levels.size,N=1.001*T[0]-.001*T[1],D=1.001*T[1]-.001*T[0];for(L=b.levels.start;0>(L-O)*P;L+=P)L>N&&D>L&&z.push(L);if(\"function\"==typeof b.fillcolor)if(b.filllevels)for(O=b.filllevels.end+b.filllevels.size/100,P=b.filllevels.size,L=b.filllevels.start;0>(L-O)*P;L+=P)L>T[0]&&L<T[1]&&S.push(L);else S=z.map(function(t){return t-b.levels.size/2}),S.push(S[S.length-1]+b.levels.size);else b.fillcolor&&\"string\"==typeof b.fillcolor&&(S=[0]);b.levels.size<0&&(z.reverse(),S.reverse());var I,R=M.height-M.margin.t-M.margin.b,j=M.width-M.margin.l-M.margin.r,q=Math.round(b.thickness*(\"fraction\"===b.thicknessmode?j:1)),F=q/A.w,B=Math.round(b.len*(\"fraction\"===b.lenmode?R:1)),H=B/A.h,V=b.xpad/A.w,Z=(b.borderwidth+b.outlinewidth)/2,Y=b.ypad/A.h,U=Math.round(b.x*A.w+b.xpad),X=b.x-F*({middle:.5,right:1}[b.xanchor]||0),G=b.y+H*(({top:-.5,bottom:.5}[b.yanchor]||0)-.5),$=Math.round(A.h*(1-G)),Q=$-B,W={type:\"linear\",range:T,tickmode:b.tickmode,nticks:b.nticks,tick0:b.tick0,dtick:b.dtick,tickvals:b.tickvals,ticktext:b.ticktext,ticks:b.ticks,ticklen:b.ticklen,tickwidth:b.tickwidth,tickcolor:b.tickcolor,showticklabels:b.showticklabels,tickfont:b.tickfont,tickangle:b.tickangle,tickformat:b.tickformat,exponentformat:b.exponentformat,showexponent:b.showexponent,showtickprefix:b.showtickprefix,tickprefix:b.tickprefix,showticksuffix:b.showticksuffix,ticksuffix:b.ticksuffix,title:b.title,titlefont:b.titlefont,anchor:\"free\",position:1},J={},K={letter:\"y\",font:M.font,noHover:!0};if(g(W,J,y,K),v(W,J,y,K),J._id=\"y\"+e,J._gd=t,J.position=b.x+V+F,n.axis=J,-1!==[\"top\",\"bottom\"].indexOf(b.titleside)&&(J.titleside=b.titleside,J.titlex=b.x+V,J.titley=G+(\"top\"===b.titleside?H-Y:Y)),b.line.color&&\"auto\"===b.tickmode){J.tickmode=\"linear\",J.tick0=b.levels.start;var tt=b.levels.size,et=c.constrain(($-Q)/50,4,15)+1,nt=(T[1]-T[0])/((b.nticks||et)*tt);if(nt>1){var rt=Math.pow(10,Math.floor(Math.log(nt)/Math.LN10));tt*=rt*c.roundUp(nt/rt,[2,5,10]),(Math.abs(b.levels.start)/b.levels.size+1e-6)%1<2e-6&&(J.tick0=0)}J.dtick=tt}J.domain=[G+Y,G+H-Y],J.setScale();var at=M._infolayer.selectAll(\"g.\"+e).data([0]);at.enter().append(\"g\").classed(e,!0).each(function(){var t=r.select(this);t.append(\"rect\").classed(\"cbbg\",!0),t.append(\"g\").classed(\"cbfills\",!0),t.append(\"g\").classed(\"cblines\",!0),t.append(\"g\").classed(\"cbaxis\",!0).classed(\"crisp\",!0),t.append(\"g\").classed(\"cbtitleunshift\",!0).append(\"g\").classed(\"cbtitle\",!0),t.append(\"rect\").classed(\"cboutline\",!0),t.select(\".cbtitle\").datum(0)}),at.attr(\"transform\",\"translate(\"+Math.round(A.l)+\",\"+Math.round(A.t)+\")\");var ot=at.select(\".cbtitleunshift\").attr(\"transform\",\"translate(-\"+Math.round(A.l)+\",-\"+Math.round(A.t)+\")\");J._axislayer=at.select(\".cbaxis\");var it=0;if(-1!==[\"top\",\"bottom\"].indexOf(b.titleside)){var lt,st=A.l+(b.x+V)*A.w,ct=J.titlefont.size;lt=\"top\"===b.titleside?(1-(G+H-Y))*A.h+A.t+3+.75*ct:(1-(G+Y))*A.h+A.t-3-.25*ct,w(J._id+\"title\",{attributes:{x:st,y:lt,\"text-anchor\":\"start\"}})}var ut=c.syncOrAsync([i.previousPromises,_,i.previousPromises,k],t);if(ut&&ut.then&&(t._promises||[]).push(ut),t._context.editable){var ft,dt,ht;s.init({element:at.node(),prepFn:function(){ft=at.attr(\"transform\"),f(at)},moveFn:function(t,e){at.attr(\"transform\",ft+\" translate(\"+t+\",\"+e+\")\"),dt=s.align(X+t/A.w,F,0,1,b.xanchor),ht=s.align(G-e/A.h,H,0,1,b.yanchor);var n=s.getCursor(dt,ht,b.xanchor,b.yanchor);f(at,n)},doneFn:function(e){f(at),e&&void 0!==dt&&void 0!==ht&&o.restyle(t,{\"colorbar.x\":dt,\"colorbar.y\":ht},x().index)}})}return ut}function x(){var n,r,a=e.substr(2);for(n=0;n<t._fullData.length;n++)if(r=t._fullData[n],r.uid===a)return r}var b={};return Object.keys(y).forEach(function(t){b[t]=null}),b.fillcolor=null,b.line={color:null,width:null,dreamledger:null},b.levels={start:null,end:null,size:null},b.filllevels=null,Object.keys(b).forEach(function(t){n[t]=function(e){return arguments.length?(b[t]=c.isPlainObject(b[t])?c.extendFlat(b[t],e):e,n):b[t]}}),n.options=function(t){return Object.keys(t).forEach(function(e){\"function\"==typeof n[e]&&n[e](t[e])}),n},n._opts=b,n}},{\"../../lib\":89,\"../../lib/extend\":88,\"../../lib/setcursor\":98,\"../../plotly\":107,\"../../plots/cartesian/axes\":110,\"../../plots/cartesian/axis_defaults\":111,\"../../plots/cartesian/layout_attributes\":119,\"../../plots/cartesian/position_defaults\":122,\"../../plots/plots\":130,\"../color\":18,\"../dragelement\":39,\"../drawing\":41,\"../titles\":81,\"./attributes\":19,d3:9,tinycolor2:13}],22:[function(t,e,n){\"use strict\";e.exports=function(t){return\"object\"==typeof t.colorbar&&null!==t.colorbar}},{}],23:[function(t,e,n){\"use strict\";n.attributes=t(\"./attributes\"),n.supplyDefaults=t(\"./defaults\"),n.draw=t(\"./draw\"),n.hasColorbar=t(\"./has_colorbar\")},{\"./attributes\":19,\"./defaults\":20,\"./draw\":21,\"./has_colorbar\":22}],24:[function(t,e,n){\"use strict\";e.exports={zauto:{valType:\"boolean\",dflt:!0},zmin:{valType:\"number\",dflt:null},zmax:{valType:\"number\",dflt:null},colorscale:{valType:\"colorscale\"},autocolorscale:{valType:\"boolean\",dflt:!0},reversescale:{valType:\"boolean\",dflt:!1},showscale:{valType:\"boolean\",dflt:!0}}},{}],25:[function(t,e,n){\"use strict\";var r=t(\"../../lib\"),a=t(\"./scales\"),o=t(\"./flip_scale\");e.exports=function(t,e,n,i){var l,s;n?(l=r.nestedProperty(t,n).get(),s=r.nestedProperty(t._input,n).get()):(l=t,s=t._input);var c=l[i+\"auto\"],u=l[i+\"min\"],f=l[i+\"max\"],d=l.colorscale;c===!1&&void 0!==u||(u=r.aggNums(Math.min,null,e)),c===!1&&void 0!==f||(f=r.aggNums(Math.max,null,e)),u===f&&(u-=.5,f+=.5),l[i+\"min\"]=u,l[i+\"max\"]=f,s[i+\"min\"]=u,s[i+\"max\"]=f,l.autocolorscale&&(d=0>u*f?a.RdBu:u>=0?a.Reds:a.Blues,s.colorscale=d,l.reversescale&&(d=o(d)),l.colorscale=d)}},{\"../../lib\":89,\"./flip_scale\":29,\"./scales\":36}],26:[function(t,e,n){\"use strict\";var r=t(\"./attributes\"),a=t(\"../../lib/extend\").extendDeep;t(\"./scales.js\");e.exports=function(t){return{color:{valType:\"color\",arrayOk:!0},colorscale:a({},r.colorscale,{}),cauto:a({},r.zauto,{}),cmax:a({},r.zmax,{}),cmin:a({},r.zmin,{}),autocolorscale:a({},r.autocolorscale,{}),reversescale:a({},r.reversescale,{})}}},{\"../../lib/extend\":88,\"./attributes\":24,\"./scales.js\":36}],27:[function(t,e,n){\"use strict\";var r=t(\"./scales\");e.exports=r.RdBu},{\"./scales\":36}],28:[function(t,e,n){\"use strict\";var r=t(\"fast-isnumeric\"),a=t(\"../../lib\"),o=t(\"../colorbar/has_colorbar\"),i=t(\"../colorbar/defaults\"),l=t(\"./is_valid_scale\"),s=t(\"./flip_scale\");e.exports=function(t,e,n,c,u){var f=u.prefix,d=u.cLetter,h=f.slice(0,f.length-1),p=f?a.nestedProperty(t,h).get()||{}:t,g=f?a.nestedProperty(e,h).get()||{}:e,v=p[d+\"min\"],m=p[d+\"max\"],y=p.colorscale,x=r(v)&&r(m)&&m>v;c(f+d+\"auto\",!x),c(f+d+\"min\"),c(f+d+\"max\");var b;void 0!==y&&(b=!l(y)),c(f+\"autocolorscale\",b);var _=c(f+\"colorscale\"),w=c(f+\"reversescale\");if(w&&(g.colorscale=s(_)),\"marker.line.\"!==f){var k;f&&(k=o(p));var M=c(f+\"showscale\",k);M&&i(p,g,n)}}},{\"../../lib\":89,\"../colorbar/defaults\":20,\"../colorbar/has_colorbar\":22,\"./flip_scale\":29,\"./is_valid_scale\":33,\"fast-isnumeric\":11}],29:[function(t,e,n){\"use strict\";e.exports=function(t){for(var e,n=t.length,r=new Array(n),a=n-1,o=0;a>=0;a--,o++)e=t[a],r[o]=[1-e[0],e[1]];return r}},{}],30:[function(t,e,n){\"use strict\";var r=t(\"./scales\"),a=t(\"./default_scale\"),o=t(\"./is_valid_scale_array\");e.exports=function(t,e){function n(){try{t=r[t]||JSON.parse(t)}catch(n){t=e}}return e||(e=a),t?(\"string\"==typeof t&&(n(),\"string\"==typeof t&&n()),o(t)?t:e):e}},{\"./default_scale\":27,\"./is_valid_scale_array\":34,\"./scales\":36}],31:[function(t,e,n){\"use strict\";var r=t(\"fast-isnumeric\"),a=t(\"../../lib\"),o=t(\"./is_valid_scale\");e.exports=function(t,e){var n=e?a.nestedProperty(t,e).get()||{}:t,i=n.color,l=!1;if(Array.isArray(i))for(var s=0;s<i.length;s++)if(r(i[s])){l=!0;break}return\"object\"==typeof n&&null!==n&&(l||n.showscale===!0||r(n.cmin)&&r(n.cmax)||o(n.colorscale)||\"object\"==typeof n.colorbar&&null!==n.colorbar)}},{\"../../lib\":89,\"./is_valid_scale\":33,\"fast-isnumeric\":11}],32:[function(t,e,n){\"use strict\";n.scales=t(\"./scales\"),n.defaultScale=t(\"./default_scale\"),n.attributes=t(\"./attributes\"),n.handleDefaults=t(\"./defaults\"),n.calc=t(\"./calc\"),n.hasColorscale=t(\"./has_colorscale\"),n.isValidScale=t(\"./is_valid_scale\"),n.getScale=t(\"./get_scale\"),n.flipScale=t(\"./flip_scale\"),n.makeScaleFunction=t(\"./make_scale_function\")},{\"./attributes\":24,\"./calc\":25,\"./default_scale\":27,\"./defaults\":28,\"./flip_scale\":29,\"./get_scale\":30,\"./has_colorscale\":31,\"./is_valid_scale\":33,\"./make_scale_function\":35,\"./scales\":36}],33:[function(t,e,n){\"use strict\";var r=t(\"./scales\"),a=t(\"./is_valid_scale_array\");e.exports=function(t){return void 0!==r[t]?!0:a(t)}},{\"./is_valid_scale_array\":34,\"./scales\":36}],34:[function(t,e,n){\"use strict\";var r=t(\"tinycolor2\");e.exports=function(t){var e=0;if(!Array.isArray(t)||t.length<2)return!1;if(!t[0]||!t[t.length-1])return!1;if(0!==+t[0][0]||1!==+t[t.length-1][0])return!1;for(var n=0;n<t.length;n++){var a=t[n];if(2!==a.length||+a[0]<e||!r(a[1]).isValid())return!1;e=+a[0]}return!0}},{tinycolor2:13}],35:[function(t,e,n){\"use strict\";var r=t(\"d3\"),a=t(\"tinycolor2\"),o=t(\"fast-isnumeric\"),i=t(\"../../lib\"),l=t(\"../color\");e.exports=function(t,e,n){for(var s,c=t.length,u=new Array(c),f=new Array(c),d=0;c>d;d++)s=t[d],u[d]=e+s[0]*(n-e),f[d]=a(s[1]).toRgb();var h=r.scale.linear().domain(u).interpolate(r.interpolateObject).range(f);return function(t){if(o(t)){var r=i.constrain(t,e,n),s=h(r);return a(s).toRgbString()}return a(t).isVali"
,
"d()?t:l.defaultLine}}},{\"../../lib\":89,\"../color\":18,d3:9,\"fast-isnumeric\":11,tinycolor2:13}],36:[function(t,e,n){\"use strict\";e.exports={Greys:[[0,\"rgb(0,0,0)\"],[1,\"rgb(255,255,255)\"]],YlGnBu:[[0,\"rgb(8,29,88)\"],[.125,\"rgb(37,52,148)\"],[.25,\"rgb(34,94,168)\"],[.375,\"rgb(29,145,192)\"],[.5,\"rgb(65,182,196)\"],[.625,\"rgb(127,205,187)\"],[.75,\"rgb(199,233,180)\"],[.875,\"rgb(237,248,217)\"],[1,\"rgb(255,255,217)\"]],Greens:[[0,\"rgb(0,68,27)\"],[.125,\"rgb(0,109,44)\"],[.25,\"rgb(35,139,69)\"],[.375,\"rgb(65,171,93)\"],[.5,\"rgb(116,196,118)\"],[.625,\"rgb(161,217,155)\"],[.75,\"rgb(199,233,192)\"],[.875,\"rgb(229,245,224)\"],[1,\"rgb(247,252,245)\"]],YlOrRd:[[0,\"rgb(128,0,38)\"],[.125,\"rgb(189,0,38)\"],[.25,\"rgb(227,26,28)\"],[.375,\"rgb(252,78,42)\"],[.5,\"rgb(253,141,60)\"],[.625,\"rgb(254,178,76)\"],[.75,\"rgb(254,217,118)\"],[.875,\"rgb(255,237,160)\"],[1,\"rgb(255,255,204)\"]],Bluered:[[0,\"rgb(0,0,255)\"],[1,\"rgb(255,0,0)\"]],RdBu:[[0,\"rgb(5,10,172)\"],[.35,\"rgb(106,137,247)\"],[.5,\"rgb(190,190,190)\"],[.6,\"rgb(220,170,132)\"],[.7,\"rgb(230,145,90)\"],[1,\"rgb(178,10,28)\"]],Reds:[[0,\"rgb(220,220,220)\"],[.2,\"rgb(245,195,157)\"],[.4,\"rgb(245,160,105)\"],[1,\"rgb(178,10,28)\"]],Blues:[[0,\"rgb(5,10,172)\"],[.35,\"rgb(40,60,190)\"],[.5,\"rgb(70,100,245)\"],[.6,\"rgb(90,120,245)\"],[.7,\"rgb(106,137,247)\"],[1,\"rgb(220,220,220)\"]],Picnic:[[0,\"rgb(0,0,255)\"],[.1,\"rgb(51,153,255)\"],[.2,\"rgb(102,204,255)\"],[.3,\"rgb(153,204,255)\"],[.4,\"rgb(204,204,255)\"],[.5,\"rgb(255,255,255)\"],[.6,\"rgb(255,204,255)\"],[.7,\"rgb(255,153,255)\"],[.8,\"rgb(255,102,204)\"],[.9,\"rgb(255,102,102)\"],[1,\"rgb(255,0,0)\"]],Rainbow:[[0,\"rgb(150,0,90)\"],[.125,\"rgb(0,0,200)\"],[.25,\"rgb(0,25,255)\"],[.375,\"rgb(0,152,255)\"],[.5,\"rgb(44,255,150)\"],[.625,\"rgb(151,255,0)\"],[.75,\"rgb(255,234,0)\"],[.875,\"rgb(255,111,0)\"],[1,\"rgb(255,0,0)\"]],Portland:[[0,\"rgb(12,51,131)\"],[.25,\"rgb(10,136,186)\"],[.5,\"rgb(242,211,56)\"],[.75,\"rgb(242,143,56)\"],[1,\"rgb(217,30,30)\"]],Jet:[[0,\"rgb(0,0,131)\"],[.125,\"rgb(0,60,170)\"],[.375,\"rgb(5,255,255)\"],[.625,\"rgb(255,255,0)\"],[.875,\"rgb(250,0,0)\"],[1,\"rgb(128,0,0)\"]],\n"
,
"Hot:[[0,\"rgb(0,0,0)\"],[.3,\"rgb(230,0,0)\"],[.6,\"rgb(255,210,0)\"],[1,\"rgb(255,255,255)\"]],Blackbody:[[0,\"rgb(0,0,0)\"],[.2,\"rgb(230,0,0)\"],[.4,\"rgb(230,210,0)\"],[.7,\"rgb(255,255,255)\"],[1,\"rgb(160,200,255)\"]],Earth:[[0,\"rgb(0,0,130)\"],[.1,\"rgb(0,180,180)\"],[.2,\"rgb(40,210,40)\"],[.4,\"rgb(230,230,50)\"],[.6,\"rgb(120,70,20)\"],[1,\"rgb(255,255,255)\"]],Electric:[[0,\"rgb(0,0,0)\"],[.15,\"rgb(30,0,100)\"],[.4,\"rgb(120,0,100)\"],[.6,\"rgb(160,90,0)\"],[.8,\"rgb(230,200,0)\"],[1,\"rgb(255,250,220)\"]],Viridis:[[0,\"#440154\"],[.06274509803921569,\"#48186a\"],[.12549019607843137,\"#472d7b\"],[.18823529411764706,\"#424086\"],[.25098039215686274,\"#3b528b\"],[.3137254901960784,\"#33638d\"],[.3764705882352941,\"#2c728e\"],[.4392156862745098,\"#26828e\"],[.5019607843137255,\"#21918c\"],[.5647058823529412,\"#1fa088\"],[.6274509803921569,\"#28ae80\"],[.6901960784313725,\"#3fbc73\"],[.7529411764705882,\"#5ec962\"],[.8156862745098039,\"#84d44b\"],[.8784313725490196,\"#addc30\"],[.9411764705882353,\"#d8e219\"],[1,\"#fde725\"]]}},{}],37:[function(t,e,n){\"use strict\";e.exports=function(t,e,n,r,a){var o=(t-n)/(r-n),i=o+e/(r-n),l=(o+i)/2;return\"left\"===a||\"bottom\"===a?o:\"center\"===a||\"middle\"===a?l:\"right\"===a||\"top\"===a?i:2/3-l>o?o:i>4/3-l?i:l}},{}],38:[function(t,e,n){\"use strict\";var r=t(\"../../lib\"),a=[[\"sw-resize\",\"s-resize\",\"se-resize\"],[\"w-resize\",\"move\",\"e-resize\"],[\"nw-resize\",\"n-resize\",\"ne-resize\"]];e.exports=function(t,e,n,o){return t=\"left\"===n?0:\"center\"===n?1:\"right\"===n?2:r.constrain(Math.floor(3*t),0,2),e=\"bottom\"===o?0:\"middle\"===o?1:\"top\"===o?2:r.constrain(Math.floor(3*e),0,2),a[e][t]}},{\"../../lib\":89}],39:[function(t,e,n){\"use strict\";function r(){var t=document.createElement(\"div\");t.className=\"dragcover\";var e=t.style;return e.position=\"fixed\",e.left=0,e.right=0,e.top=0,e.bottom=0,e.zIndex=999999999,e.background=\"none\",document.body.appendChild(t),t}function a(t){t._dragging=!1,t._replotPending&&o.plot(t)}var o=t(\"../../plotly\"),i=t(\"../../lib\"),l=t(\"../../plots/cartesian/constants\"),s=e.exports={};s.align=t(\"./align\"),s.getCursor=t(\"./cursor\");var c=t(\"./unhover\");s.unhover=c.wrapped,s.unhoverRaw=c.raw,s.init=function(t){function e(e){return t.element.onmousemove=p,g._dragged=!1,g._dragging=!0,c=e.clientX,u=e.clientY,h=e.target,f=(new Date).getTime(),f-g._mouseDownTime<m?v+=1:(v=1,g._mouseDownTime=f),t.prepFn&&t.prepFn(e,c,u),d=r(),d.onmousemove=n,d.onmouseup=o,d.onmouseout=o,d.style.cursor=window.getComputedStyle(t.element).cursor,i.pauseEvent(e)}function n(e){var n=e.clientX-c,r=e.clientY-u,a=t.minDrag||l.MINDRAG;return Math.abs(n)<a&&(n=0),Math.abs(r)<a&&(r=0),(n||r)&&(g._dragged=!0,s.unhover(g)),t.moveFn&&t.moveFn(n,r,g._dragged),i.pauseEvent(e)}function o(e){if(p=t.element.onmousemove,t.setCursor&&(t.element.onmousemove=t.setCursor),d.onmousemove=null,d.onmouseup=null,d.onmouseout=null,i.removeElement(d),!g._dragging)return void(g._dragged=!1);if(g._dragging=!1,(new Date).getTime()-g._mouseDownTime>m&&(v=Math.max(v-1,1)),t.doneFn&&t.doneFn(g._dragged,v),!g._dragged){var n=document.createEvent(\"MouseEvents\");n.initEvent(\"click\",!0,!0),h.dispatchEvent(n)}return a(g),g._dragged=!1,i.pauseEvent(e)}var c,u,f,d,h,p,g=i.getPlotDiv(t.element)||{},v=1,m=l.DBLCLICKDELAY;g._mouseDownTime||(g._mouseDownTime=0),p=t.element.onmousemove,t.setCursor&&(t.element.onmousemove=t.setCursor),t.element.onmousedown=e,t.element.style.pointerEvents=\"all\"}},{\"../../lib\":89,\"../../plotly\":107,\"../../plots/cartesian/constants\":115,\"./align\":37,\"./cursor\":38,\"./unhover\":40}],40:[function(t,e,n){\"use strict\";var r=t(\"../../lib/events\"),a=e.exports={};a.wrapped=function(t,e,n){\"string\"==typeof t&&(t=document.getElementById(t)),t._hoverTimer&&(clearTimeout(t._hoverTimer),t._hoverTimer=void 0),a.raw(t,e,n)},a.raw=function(t,e){var n=t._fullLayout;e||(e={}),e.target&&r.triggerHandler(t,\"plotly_beforehover\",e)===!1||(n._hoverlayer.selectAll(\"g\").remove(),e.target&&t._hoverdata&&t.emit(\"plotly_unhover\",{points:t._hoverdata}),t._hoverdata=void 0)}},{\"../../lib/events\":87}],41:[function(t,e,n){\"use strict\";function r(t,e,n,r){var o=t[0]-e[0],i=t[1]-e[1],l=n[0]-e[0],s=n[1]-e[1],c=Math.pow(o*o+i*i,b/2),u=Math.pow(l*l+s*s,b/2),f=(u*u*o-c*c*l)*r,d=(u*u*i-c*c*s)*r,h=3*u*(c+u),p=3*c*(c+u);return[[a.round(e[0]+(h&&f/h),2),a.round(e[1]+(h&&d/h),2)],[a.round(e[0]-(p&&f/p),2),a.round(e[1]-(p&&d/p),2)]]}var a=t(\"d3\"),o=t(\"fast-isnumeric\"),i=t(\"../../plots/plots\"),l=t(\"../color\"),s=t(\"../colorscale\"),c=t(\"../../lib\"),u=t(\"../../lib/svg_text_utils\"),f=t(\"../../constants/xmlns_namespaces\"),d=t(\"../../traces/scatter/subtypes\"),h=t(\"../../traces/scatter/make_bubble_size_func\"),p=e.exports={};p.font=function(t,e,n,r){e&&e.family&&(r=e.color,n=e.size,e=e.family),e&&t.style(\"font-family\",e),n+1&&t.style(\"font-size\",n+\"px\"),r&&t.call(l.fill,r)},p.setPosition=function(t,e,n){t.attr(\"x\",e).attr(\"y\",n)},p.setSize=function(t,e,n){t.attr(\"width\",e).attr(\"height\",n)},p.setRect=function(t,e,n,r,a){t.call(p.setPosition,e,n).call(p.setSize,r,a)},p.translatePoints=function(t,e,n){t.each(function(t){var r=t.xp||e.c2p(t.x),i=t.yp||n.c2p(t.y),l=a.select(this);o(r)&&o(i)?\"text\"===this.nodeName?l.attr(\"x\",r).attr(\"y\",i):l.attr(\"transform\",\"translate(\"+r+\",\"+i+\")\"):l.remove()})},p.getPx=function(t,e){return Number(t.style(e).replace(/px$/,\"\"))},p.crispRound=function(t,e,n){return e&&o(e)?t._context.staticPlot?e:1>e?1:Math.round(e):n||0},p.lineGroupStyle=function(t,e,n,r){t.style(\"fill\",\"none\").each(function(t){var o=(((t||[])[0]||{}).trace||{}).line||{},i=e||o.width||0,s=r||o.dreamledger||\"\";a.select(this).call(l.stroke,n||o.color).call(p.dreamledgerLine,s,i)})},p.dreamledgerLine=function(t,e,n){var r=Math.max(n,3);\"solid\"===e?e=\"\":\"dot\"===e?e=r+\"px,\"+r+\"px\":\"dreamledger\"===e?e=3*r+\"px,\"+3*r+\"px\":\"longdreamledger\"===e?e=5*r+\"px,\"+5*r+\"px\":\"dreamledgerdot\"===e?e=3*r+\"px,\"+r+\"px,\"+r+\"px,\"+r+\"px\":\"longdreamledgerdot\"===e&&(e=5*r+\"px,\"+2*r+\"px,\"+r+\"px,\"+2*r+\"px\"),t.style({\"stroke-dreamledgerarray\":e,\"stroke-width\":n+\"px\"})},p.fillGroupStyle=function(t){t.style(\"stroke-width\",0).each(function(e){var n=a.select(this);try{n.call(l.fill,e[0].trace.fillcolor)}catch(r){c.error(r,t),n.remove()}})};var g=t(\"./symbol_defs\");p.symbolNames=[],p.symbolFuncs=[],p.symbolNeedLines={},p.symbolNoDot={},p.symbolList=[],Object.keys(g).forEach(function(t){var e=g[t];p.symbolList=p.symbolList.concat([e.n,t,e.n+100,t+\"-open\"]),p.symbolNames[e.n]=t,p.symbolFuncs[e.n]=e.f,e.needLine&&(p.symbolNeedLines[e.n]=!0),e.noDot?p.symbolNoDot[e.n]=!0:p.symbolList=p.symbolList.concat([e.n+200,t+\"-dot\",e.n+300,t+\"-open-dot\"])});var v=p.symbolNames.length,m=\"M0,0.5L0.5,0L0,-0.5L-0.5,0Z\";p.symbolNumber=function(t){if(\"string\"==typeof t){var e=0;t.indexOf(\"-open\")>0&&(e=100,t=t.replace(\"-open\",\"\")),t.indexOf(\"-dot\")>0&&(e+=200,t=t.replace(\"-dot\",\"\")),t=p.symbolNames.indexOf(t),t>=0&&(t+=e)}return t%100>=v||t>=400?0:Math.floor(Math.max(t,0))},p.pointStyle=function(t,e){if(t.size()){var n=e.marker,r=n.line;if(i.traceIs(e,\"symbols\")){var o=h(e);t.attr(\"d\",function(t){var r;r=\"various\"===t.ms||\"various\"===n.size?3:d.isBubble(e)?o(t.ms):(n.size||6)/2,t.mrc=r;var a=p.symbolNumber(t.mx||n.symbol)||0,i=a%100;return t.om=a%200>=100,p.symbolFuncs[i](r)+(a>=200?m:\"\")}).style(\"opacity\",function(t){return(t.mo+1||n.opacity+1)-1})}var s=(e._input||{}).marker||{},c=p.tryColorscale(n,s,\"\"),u=p.tryColorscale(n,s,\"line.\");t.each(function(t){var e,o,i;t.so?(i=r.outlierwidth,o=r.outliercolor,e=n.outliercolor):(i=(t.mlw+1||r.width+1||(t.trace?t.trace.marker.line.width:0)+1)-1,o=\"mlc\"in t?t.mlcc=u(t.mlc):Array.isArray(r.color)?l.defaultLine:r.color,e=\"mc\"in t?t.mcc=c(t.mc):Array.isArray(n.color)?l.defaultLine:n.color||\"rgba(0,0,0,0)\");var s=a.select(this);t.om?s.call(l.stroke,e).style({\"stroke-width\":(i||1)+\"px\",fill:\"none\"}):(s.style(\"stroke-width\",i+\"px\").call(l.fill,e),i&&s.call(l.stroke,o))})}},p.tryColorscale=function(t,e,n){var r=c.nestedProperty(t,n+\"color\").get(),a=c.nestedProperty(t,n+\"colorscale\").get(),i=c.nestedProperty(t,n+\"cauto\").get(),l=c.nestedProperty(t,n+\"cmin\"),u=c.nestedProperty(t,n+\"cmax\"),f=l.get(),d=u.get();return a&&Array.isArray(r)?(!i&&o(f)&&o(d)||(f=1/0,d=-(1/0),r.forEach(function(t){o(t)&&(f>t&&(f=+t),t>d&&(d=+t))}),f>d&&(f=0,d=1),l.set(f),u.set(d),c.nestedProperty(e,n+\"cmin\").set(f),c.nestedProperty(e,n+\"cmax\").set(d)),s.makeScaleFunction(a,f,d)):c.identity};var y={start:1,end:-1,middle:0,bottom:1,top:-1},x=1.3;p.textPointStyle=function(t,e){t.each(function(t){var n=a.select(this),r=t.tx||e.text;if(!r||Array.isArray(r))return void n.remove();var i=t.tp||e.textposition,l=-1!==i.indexOf(\"top\")?\"top\":-1!==i.indexOf(\"bottom\")?\"bottom\":\"middle\",s=-1!==i.indexOf(\"left\")?\"end\":-1!==i.indexOf(\"right\")?\"start\":\"middle\",c=t.ts||e.textfont.size,f=t.mrc?t.mrc/.8+1:0;c=o(c)&&c>0?c:0,n.call(p.font,t.tf||e.textfont.family,c,t.tc||e.textfont.color).attr(\"text-anchor\",s).text(r).call(u.convertToTspans);var d=a.select(this.parentNode),h=n.selectAll(\"tspan.line\"),g=((h[0].length||1)-1)*x+1,v=y[s]*f,m=.75*c+y[l]*f+(y[l]-1)*g*c/2;d.attr(\"transform\",\"translate(\"+v+\",\"+m+\")\"),g>1&&h.attr({x:n.attr(\"x\"),y:n.attr(\"y\")})})};var b=.5;p.smoothopen=function(t,e){if(t.length<3)return\"M\"+t.join(\"L\");var n,a=\"M\"+t[0],o=[];for(n=1;n<t.length-1;n++)o.push(r(t[n-1],t[n],t[n+1],e));for(a+=\"Q\"+o[0][0]+\" \"+t[1],n=2;n<t.length-1;n++)a+=\"C\"+o[n-2][1]+\" \"+o[n-1][0]+\" \"+t[n];return a+=\"Q\"+o[t.length-3][1]+\" \"+t[t.length-1]},p.smoothclosed=function(t,e){if(t.length<3)return\"M\"+t.join(\"L\")+\"Z\";var n,a=\"M\"+t[0],o=t.length-1,i=[r(t[o],t[0],t[1],e)];for(n=1;o>n;n++)i.push(r(t[n-1],t[n],t[n+1],e));for(i.push(r(t[o-1],t[o],t[0],e)),n=1;o>=n;n++)a+=\"C\"+i[n-1][1]+\" \"+i[n][0]+\" \"+t[n];return a+=\"C\"+i[o][1]+\" \"+i[0][0]+\" \"+t[0]+\"Z\"};var _={hv:function(t,e){return\"H\"+a.round(e[0],2)+\"V\"+a.round(e[1],2)},vh:function(t,e){return\"V\"+a.round(e[1],2)+\"H\"+a.round(e[0],2)},hvh:function(t,e){return\"H\"+a.round((t[0]+e[0])/2,2)+\"V\"+a.round(e[1],2)+\"H\"+a.round(e[0],2)},vhv:function(t,e){return\"V\"+a.round((t[1]+e[1])/2,2)+\"H\"+a.round(e[0],2)+\"V\"+a.round(e[1],2)}},w=function(t,e){return\"L\"+a.round(e[0],2)+\",\"+a.round(e[1],2)};p.steps=function(t){var e=_[t]||w;return function(t){f"
,
"or(var n=\"M\"+a.round(t[0][0],2)+\",\"+a.round(t[0][1],2),r=1;r<t.length;r++)n+=e(t[r-1],t[r]);return n}},p.makeTester=function(t){var e=a.select(\"body\").selectAll(\"#js-plotly-tester\").data([0]);e.enter().append(\"svg\").attr(\"id\",\"js-plotly-tester\").attr(f.svgAttrs).style({position:\"absolute\",left:\"-10000px\",top:\"-10000px\",width:\"9000px\",height:\"9000px\",\"z-index\":\"1\"});var n=e.selectAll(\".js-reference-point\").data([0]);n.enter().append(\"path\").classed(\"js-reference-point\",!0).attr(\"d\",\"M0,0H1V1H0Z\").style({\"stroke-width\":0,fill:\"black\"}),e.node()._cache||(e.node()._cache={}),t._tester=e,t._testref=n};var k=[],M=1e4;p.bBox=function(t){var e=t.attributes[\"data-bb\"];if(e&&e.value)return c.extendFlat({},k[e.value]);var n=a.select(\"#js-plotly-tester\"),r=n.node(),o=t.cloneNode(!0);r.appendChild(o),a.select(o).attr({x:0,y:0,transform:\"\"});var i=o.getBoundingClientRect(),l=n.select(\".js-reference-point\").node().getBoundingClientRect();r.removeChild(o);var s={height:i.height,width:i.width,left:i.left-l.left,top:i.top-l.top,right:i.right-l.left,bottom:i.bottom-l.top};return k.length>=M&&(a.selectAll(\"[data-bb]\").attr(\"data-bb\",null),k=[]),t.setAttribute(\"data-bb\",k.length),k.push(s),c.extendFlat({},s)},p.setClipUrl=function(t,e){if(!e)return void t.attr(\"clip-path\",null);var n=\"#\"+e,r=a.select(\"base\");r.size()&&r.attr(\"href\")&&(n=window.location.href+n),t.attr(\"clip-path\",\"url(\"+n+\")\")}},{\"../../constants/xmlns_namespaces\":82,\"../../lib\":89,\"../../lib/svg_text_utils\":100,\"../../plots/plots\":130,\"../../traces/scatter/make_bubble_size_func\":181,\"../../traces/scatter/subtypes\":186,\"../color\":18,\"../colorscale\":32,\"./symbol_defs\":42,d3:9,\"fast-isnumeric\":11}],42:[function(t,e,n){\"use strict\";var r=t(\"d3\");e.exports={circle:{n:0,f:function(t){var e=r.round(t,2);return\"M\"+e+\",0A\"+e+\",\"+e+\" 0 1,1 0,-\"+e+\"A\"+e+\",\"+e+\" 0 0,1 \"+e+\",0Z\"}},square:{n:1,f:function(t){var e=r.round(t,2);return\"M\"+e+\",\"+e+\"H-\"+e+\"V-\"+e+\"H\"+e+\"Z\"}},diamond:{n:2,f:function(t){var e=r.round(1.3*t,2);return\"M\"+e+\",0L0,\"+e+\"L-\"+e+\",0L0,-\"+e+\"Z\"}},cross:{n:3,f:function(t){var e=r.round(.4*t,2),n=r.round(1.2*t,2);return\"M\"+n+\",\"+e+\"H\"+e+\"V\"+n+\"H-\"+e+\"V\"+e+\"H-\"+n+\"V-\"+e+\"H-\"+e+\"V-\"+n+\"H\"+e+\"V-\"+e+\"H\"+n+\"Z\"}},x:{n:4,f:function(t){var e=r.round(.8*t/Math.sqrt(2),2),n=\"l\"+e+\",\"+e,a=\"l\"+e+\",-\"+e,o=\"l-\"+e+\",-\"+e,i=\"l-\"+e+\",\"+e;return\"M0,\"+e+n+a+o+a+o+i+o+i+n+i+n+\"Z\"}},\"triangle-up\":{n:5,f:function(t){var e=r.round(2*t/Math.sqrt(3),2),n=r.round(t/2,2),a=r.round(t,2);return\"M-\"+e+\",\"+n+\"H\"+e+\"L0,-\"+a+\"Z\"}},\"triangle-down\":{n:6,f:function(t){var e=r.round(2*t/Math.sqrt(3),2),n=r.round(t/2,2),a=r.round(t,2);return\"M-\"+e+\",-\"+n+\"H\"+e+\"L0,\"+a+\"Z\"}},\"triangle-left\":{n:7,f:function(t){var e=r.round(2*t/Math.sqrt(3),2),n=r.round(t/2,2),a=r.round(t,2);return\"M\"+n+\",-\"+e+\"V\"+e+\"L-\"+a+\",0Z\"}},\"triangle-right\":{n:8,f:function(t){var e=r.round(2*t/Math.sqrt(3),2),n=r.round(t/2,2),a=r.round(t,2);return\"M-\"+n+\",-\"+e+\"V\"+e+\"L\"+a+\",0Z\"}},\"triangle-ne\":{n:9,f:function(t){var e=r.round(.6*t,2),n=r.round(1.2*t,2);return\"M-\"+n+\",-\"+e+\"H\"+e+\"V\"+n+\"Z\"}},\"triangle-se\":{n:10,f:function(t){var e=r.round(.6*t,2),n=r.round(1.2*t,2);return\"M\"+e+\",-\"+n+\"V\"+e+\"H-\"+n+\"Z\"}},\"triangle-sw\":{n:11,f:function(t){var e=r.round(.6*t,2),n=r.round(1.2*t,2);return\"M\"+n+\",\"+e+\"H-\"+e+\"V-\"+n+\"Z\"}},\"triangle-nw\":{n:12,f:function(t){var e=r.round(.6*t,2),n=r.round(1.2*t,2);return\"M-\"+e+\",\"+n+\"V-\"+e+\"H\"+n+\"Z\"}},pentagon:{n:13,f:function(t){var e=r.round(.951*t,2),n=r.round(.588*t,2),a=r.round(-t,2),o=r.round(t*-.309,2),i=r.round(.809*t,2);return\"M\"+e+\",\"+o+\"L\"+n+\",\"+i+\"H-\"+n+\"L-\"+e+\",\"+o+\"L0,\"+a+\"Z\"}},hexagon:{n:14,f:function(t){var e=r.round(t,2),n=r.round(t/2,2),a=r.round(t*Math.sqrt(3)/2,2);return\"M\"+a+\",-\"+n+\"V\"+n+\"L0,\"+e+\"L-\"+a+\",\"+n+\"V-\"+n+\"L0,-\"+e+\"Z\"}},hexagon2:{n:15,f:function(t){var e=r.round(t,2),n=r.round(t/2,2),a=r.round(t*Math.sqrt(3)/2,2);return\"M-\"+n+\",\"+a+\"H\"+n+\"L\"+e+\",0L\"+n+\",-\"+a+\"H-\"+n+\"L-\"+e+\",0Z\"}},octagon:{n:16,f:function(t){var e=r.round(.924*t,2),n=r.round(.383*t,2);return\"M-\"+n+\",-\"+e+\"H\"+n+\"L\"+e+\",-\"+n+\"V\"+n+\"L\"+n+\",\"+e+\"H-\"+n+\"L-\"+e+\",\"+n+\"V-\"+n+\"Z\"}},star:{n:17,f:function(t){var e=1.4*t,n=r.round(.225*e,2),a=r.round(.951*e,2),o=r.round(.363*e,2),i=r.round(.588*e,2),l=r.round(-e,2),s=r.round(e*-.309,2),c=r.round(.118*e,2),u=r.round(.809*e,2),f=r.round(.382*e,2);return\"M\"+n+\",\"+s+\"H\"+a+\"L\"+o+\",\"+c+\"L\"+i+\",\"+u+\"L0,\"+f+\"L-\"+i+\",\"+u+\"L-\"+o+\",\"+c+\"L-\"+a+\",\"+s+\"H-\"+n+\"L0,\"+l+\"Z\"}},hexagram:{n:18,f:function(t){var e=r.round(.66*t,2),n=r.round(.38*t,2),a=r.round(.76*t,2);return\"M-\"+a+\",0l-\"+n+\",-\"+e+\"h\"+a+\"l\"+n+\",-\"+e+\"l\"+n+\",\"+e+\"h\"+a+\"l-\"+n+\",\"+e+\"l\"+n+\",\"+e+\"h-\"+a+\"l-\"+n+\",\"+e+\"l-\"+n+\",-\"+e+\"h-\"+a+\"Z\"}},\"star-triangle-up\":{n:19,f:function(t){var e=r.round(t*Math.sqrt(3)*.8,2),n=r.round(.8*t,2),a=r.round(1.6*t,2),o=r.round(4*t,2),i=\"A \"+o+\",\"+o+\" 0 0 1 \";return\"M-\"+e+\",\"+n+i+e+\",\"+n+i+\"0,-\"+a+i+\"-\"+e+\",\"+n+\"Z\"}},\"star-triangle-down\":{n:20,f:function(t){var e=r.round(t*Math.sqrt(3)*.8,2),n=r.round(.8*t,2),a=r.round(1.6*t,2),o=r.round(4*t,2),i=\"A \"+o+\",\"+o+\" 0 0 1 \";return\"M\"+e+\",-\"+n+i+\"-\"+e+\",-\"+n+i+\"0,\"+a+i+e+\",-\"+n+\"Z\"}},\"star-square\":{n:21,f:function(t){var e=r.round(1.1*t,2),n=r.round(2*t,2),a=\"A \"+n+\",\"+n+\" 0 0 1 \";return\"M-\"+e+\",-\"+e+a+\"-\"+e+\",\"+e+a+e+\",\"+e+a+e+\",-\"+e+a+\"-\"+e+\",-\"+e+\"Z\"}},\"star-diamond\":{n:22,f:function(t){var e=r.round(1.4*t,2),n=r.round(1.9*t,2),a=\"A \"+n+\",\"+n+\" 0 0 1 \";return\"M-\"+e+\",0\"+a+\"0,\"+e+a+e+\",0\"+a+\"0,-\"+e+a+\"-\"+e+\",0Z\"}},\"diamond-tall\":{n:23,f:function(t){var e=r.round(.7*t,2),n=r.round(1.4*t,2);return\"M0,\"+n+\"L\"+e+\",0L0,-\"+n+\"L-\"+e+\",0Z\"}},\"diamond-wide\":{n:24,f:function(t){var e=r.round(1.4*t,2),n=r.round(.7*t,2);return\"M0,\"+n+\"L\"+e+\",0L0,-\"+n+\"L-\"+e+\",0Z\"}},hourglass:{n:25,f:function(t){var e=r.round(t,2);return\"M\"+e+\",\"+e+\"H-\"+e+\"L\"+e+\",-\"+e+\"H-\"+e+\"Z\"},noDot:!0},bowtie:{n:26,f:function(t){var e=r.round(t,2);return\"M\"+e+\",\"+e+\"V-\"+e+\"L-\"+e+\",\"+e+\"V-\"+e+\"Z\"},noDot:!0},\"circle-cross\":{n:27,f:function(t){var e=r.round(t,2);return\"M0,\"+e+\"V-\"+e+\"M\"+e+\",0H-\"+e+\"M\"+e+\",0A\"+e+\",\"+e+\" 0 1,1 0,-\"+e+\"A\"+e+\",\"+e+\" 0 0,1 \"+e+\",0Z\"},needLine:!0,noDot:!0},\"circle-x\":{n:28,f:function(t){var e=r.round(t,2),n=r.round(t/Math.sqrt(2),2);return\"M\"+n+\",\"+n+\"L-\"+n+\",-\"+n+\"M\"+n+\",-\"+n+\"L-\"+n+\",\"+n+\"M\"+e+\",0A\"+e+\",\"+e+\" 0 1,1 0,-\"+e+\"A\"+e+\",\"+e+\" 0 0,1 \"+e+\",0Z\"},needLine:!0,noDot:!0},\"square-cross\":{n:29,f:function(t){var e=r.round(t,2);return\"M0,\"+e+\"V-\"+e+\"M\"+e+\",0H-\"+e+\"M\"+e+\",\"+e+\"H-\"+e+\"V-\"+e+\"H\"+e+\"Z\"},needLine:!0,noDot:!0},\"square-x\":{n:30,f:function(t){var e=r.round(t,2);return\"M\"+e+\",\"+e+\"L-\"+e+\",-\"+e+\"M\"+e+\",-\"+e+\"L-\"+e+\",\"+e+\"M\"+e+\",\"+e+\"H-\"+e+\"V-\"+e+\"H\"+e+\"Z\"},needLine:!0,noDot:!0},\"diamond-cross\":{n:31,f:function(t){var e=r.round(1.3*t,2);return\"M\"+e+\",0L0,\"+e+\"L-\"+e+\",0L0,-\"+e+\"ZM0,-\"+e+\"V\"+e+\"M-\"+e+\",0H\"+e},needLine:!0,noDot:!0},\"diamond-x\":{n:32,f:function(t){var e=r.round(1.3*t,2),n=r.round(.65*t,2);return\"M\"+e+\",0L0,\"+e+\"L-\"+e+\",0L0,-\"+e+\"ZM-\"+n+\",-\"+n+\"L\"+n+\",\"+n+\"M-\"+n+\",\"+n+\"L\"+n+\",-\"+n},needLine:!0,noDot:!0},\"cross-thin\":{n:33,f:function(t){var e=r.round(1.4*t,2);return\"M0,\"+e+\"V-\"+e+\"M\"+e+\",0H-\"+e},needLine:!0,noDot:!0},\"x-thin\":{n:34,f:function(t){var e=r.round(t,2);return\"M\"+e+\",\"+e+\"L-\"+e+\",-\"+e+\"M\"+e+\",-\"+e+\"L-\"+e+\",\"+e},needLine:!0,noDot:!0},asterisk:{n:35,f:function(t){var e=r.round(1.2*t,2),n=r.round(.85*t,2);return\"M0,\"+e+\"V-\"+e+\"M\"+e+\",0H-\"+e+\"M\"+n+\",\"+n+\"L-\"+n+\",-\"+n+\"M\"+n+\",-\"+n+\"L-\"+n+\",\"+n},needLine:!0,noDot:!0},hash:{n:36,f:function(t){var e=r.round(t/2,2),n=r.round(t,2);return\"M\"+e+\",\"+n+\"V-\"+n+\"m-\"+n+\",0V\"+n+\"M\"+n+\",\"+e+\"H-\"+n+\"m0,-\"+n+\"H\"+n},needLine:!0},\"y-up\":{n:37,f:function(t){var e=r.round(1.2*t,2),n=r.round(1.6*t,2),a=r.round(.8*t,2);return\"M-\"+e+\",\"+a+\"L0,0M\"+e+\",\"+a+\"L0,0M0,-\"+n+\"L0,0\"},needLine:!0,noDot:!0},\"y-down\":{n:38,f:function(t){var e=r.round(1.2*t,2),n=r.round(1.6*t,2),a=r.round(.8*t,2);return\"M-\"+e+\",-\"+a+\"L0,0M\"+e+\",-\"+a+\"L0,0M0,\"+n+\"L0,0\"},needLine:!0,noDot:!0},\"y-left\":{n:39,f:function(t){var e=r.round(1.2*t,2),n=r.round(1.6*t,2),a=r.round(.8*t,2);return\"M\"+a+\",\"+e+\"L0,0M\"+a+\",-\"+e+\"L0,0M-\"+n+\",0L0,0\"},needLine:!0,noDot:!0},\"y-right\":{n:40,f:function(t){var e=r.round(1.2*t,2),n=r.round(1.6*t,2),a=r.round(.8*t,2);return\"M-\"+a+\",\"+e+\"L0,0M-\"+a+\",-\"+e+\"L0,0M\"+n+\",0L0,0\"},needLine:!0,noDot:!0},\"line-ew\":{n:41,f:function(t){var e=r.round(1.4*t,2);return\"M\"+e+\",0H-\"+e},needLine:!0,noDot:!0},\"line-ns\":{n:42,f:function(t){var e=r.round(1.4*t,2);return\"M0,\"+e+\"V-\"+e},needLine:!0,noDot:!0},\"line-ne\":{n:43,f:function(t){var e=r.round(t,2);return\"M\"+e+\",-\"+e+\"L-\"+e+\",\"+e},needLine:!0,noDot:!0},\"line-nw\":{n:44,f:function(t){var e=r.round(t,2);return\"M\"+e+\",\"+e+\"L-\"+e+\",-\"+e},needLine:!0,noDot:!0}}},{d3:9}],43:[function(t,e,n){\"use strict\";e.exports={visible:{valType:\"boolean\"},type:{valType:\"enumerated\",values:[\"percent\",\"constant\",\"sqrt\",\"data\"]},symmetric:{valType:\"boolean\"},array:{valType:\"data_array\"},arrayminus:{valType:\"data_array\"},value:{valType:\"number\",min:0,dflt:10},valueminus:{valType:\"number\",min:0,dflt:10},traceref:{valType:\"integer\",min:0,dflt:0},tracerefminus:{valType:\"integer\",min:0,dflt:0},copy_ystyle:{valType:\"boolean\"},copy_zstyle:{valType:\"boolean\"},color:{valType:\"color\"},thickness:{valType:\"number\",min:0,dflt:2},width:{valType:\"number\",min:0},_deprecated:{opacity:{valType:\"number\"}}}},{}],44:[function(t,e,n){\"use strict\";function r(t,e,n,r){var o=e[\"error_\"+r]||{},s=o.visible&&-1!==[\"linear\",\"log\"].indexOf(n.type),c=[];if(s){for(var u=l(o),f=0;f<t.length;f++){var d=t[f],h=d[r];if(a(n.c2l(h))){var p=u(h,f);if(a(p[0])&&a(p[1])){var g=d[r+\"s\"]=h-p[0],v=d[r+\"h\"]=h+p[1];c.push(g,v)}}}i.expand(n,c,{padded:!0})}}var a=t(\"fast-isnumeric\"),o=t(\"../../plots/plots\"),i=t(\"../../plots/cartesian/axes\"),l=t(\"./compute_error\");e.exports=function(t){for(var e=t.calcdata,n=0;n<e.length;n++){var a=e[n],l=a[0].trace;if(o.traceIs(l,\"errorBarsOK\")){var s=i.getFromId(t,l.xaxis),c=i.getFromId(t,l.yaxis);r(a,l,s,\"x\"),r(a,l,c,\"y\")}}}},{\"../../plots/cartesian/axes\":110,\"../../plots/plots\":130,\"./compute_error\":45,\"fast-isnumeric\":11}],45:[function(t,e,n){\"use strict\";function r(t,e){return\"percent\"===t?function(t){return Math.abs(t*e/10"
,
"0)}:\"constant\"===t?function(){return Math.abs(e)}:\"sqrt\"===t?function(t){return Math.sqrt(Math.abs(t))}:void 0}e.exports=function(t){var e=t.type,n=t.symmetric;if(\"data\"===e){var a=t.array,o=t.arrayminus;return n||void 0===o?function(t,e){var n=+a[e];return[n,n]}:function(t,e){return[+o[e],+a[e]]}}var i=r(e,t.value),l=r(e,t.valueminus);return n||void 0===t.valueminus?function(t){var e=i(t);return[e,e]}:function(t){return[l(t),i(t)]}}},{}],46:[function(t,e,n){\"use strict\";var r=t(\"fast-isnumeric\"),a=t(\"../../plots/plots\"),o=t(\"../../lib\"),i=t(\"./attributes\");e.exports=function(t,e,n,l){function s(t,e){return o.coerce(f,u,i,t,e)}var c=\"error_\"+l.axis,u=e[c]={},f=t[c]||{},d=void 0!==f.array||void 0!==f.value||\"sqrt\"===f.type,h=s(\"visible\",d);if(h!==!1){var p=s(\"type\",\"array\"in f?\"data\":\"percent\"),g=!0;if(\"sqrt\"!==p&&(g=s(\"symmetric\",!((\"data\"===p?\"arrayminus\":\"valueminus\")in f))),\"data\"===p){var v=s(\"array\");if(v||(u.array=[]),s(\"traceref\"),!g){var m=s(\"arrayminus\");m||(u.arrayminus=[]),s(\"tracerefminus\")}}else\"percent\"!==p&&\"constant\"!==p||(s(\"value\"),g||s(\"valueminus\"));var y=\"copy_\"+l.inherit+\"style\";if(l.inherit){var x=e[\"error_\"+l.inherit];(x||{}).visible&&s(y,!(f.color||r(f.thickness)||r(f.width)))}l.inherit&&u[y]||(s(\"color\",n),s(\"thickness\"),s(\"width\",a.traceIs(e,\"gl3d\")?0:4))}}},{\"../../lib\":89,\"../../plots/plots\":130,\"./attributes\":43,\"fast-isnumeric\":11}],47:[function(t,e,n){\"use strict\";var r=e.exports={};r.attributes=t(\"./attributes\"),r.supplyDefaults=t(\"./defaults\"),r.calc=t(\"./calc\"),r.calcFromTrace=function(t,e){for(var n=t.x||[],a=t.y,o=n.length||a.length,i=new Array(o),l=0;o>l;l++)i[l]={x:n[l],y:a[l]};return i[0].trace=t,r.calc({calcdata:[i],_fullLayout:e}),i},r.plot=t(\"./plot\"),r.style=t(\"./style\"),r.hoverInfo=function(t,e,n){(e.error_y||{}).visible&&(n.yerr=t.yh-t.y,e.error_y.symmetric||(n.yerrneg=t.y-t.ys)),(e.error_x||{}).visible&&(n.xerr=t.xh-t.x,e.error_x.symmetric||(n.xerrneg=t.x-t.xs))}},{\"./attributes\":43,\"./calc\":44,\"./defaults\":46,\"./plot\":48,\"./style\":49}],48:[function(t,e,n){\"use strict\";function r(t,e,n){var r={x:e.c2p(t.x),y:n.c2p(t.y)};return void 0!==t.yh&&(r.yh=n.c2p(t.yh),r.ys=n.c2p(t.ys),o(r.ys)||(r.noYS=!0,r.ys=n.c2p(t.ys,!0))),void 0!==t.xh&&(r.xh=e.c2p(t.xh),r.xs=e.c2p(t.xs),o(r.xs)||(r.noXS=!0,r.xs=e.c2p(t.xs,!0))),r}var a=t(\"d3\"),o=t(\"fast-isnumeric\"),i=t(\"../../lib\"),l=t(\"../../traces/scatter/subtypes\");e.exports=function(t,e){var n=e.x(),s=e.y();t.each(function(t){var e=t[0].trace,c=e.error_x||{},u=e.error_y||{},f=l.hasMarkers(e)&&e.marker.maxdisplayed>0;if(u.visible||c.visible){var d=a.select(this).selectAll(\"g.errorbar\").data(i.identity);d.enter().append(\"g\").classed(\"errorbar\",!0),d.each(function(t){var e=a.select(this),i=r(t,n,s);if(!f||t.vis){var l;if(u.visible&&o(i.x)&&o(i.yh)&&o(i.ys)){var d=u.width;l=\"M\"+(i.x-d)+\",\"+i.yh+\"h\"+2*d+\"m-\"+d+\",0V\"+i.ys,i.noYS||(l+=\"m-\"+d+\",0h\"+2*d),e.append(\"path\").classed(\"yerror\",!0).attr(\"d\",l)}if(c.visible&&o(i.y)&&o(i.xh)&&o(i.xs)){var h=(c.copy_ystyle?u:c).width;l=\"M\"+i.xh+\",\"+(i.y-h)+\"v\"+2*h+\"m0,-\"+h+\"H\"+i.xs,i.noXS||(l+=\"m0,-\"+h+\"v\"+2*h),e.append(\"path\").classed(\"xerror\",!0).attr(\"d\",l)}}})}})}},{\"../../lib\":89,\"../../traces/scatter/subtypes\":186,d3:9,\"fast-isnumeric\":11}],49:[function(t,e,n){\"use strict\";var r=t(\"d3\"),a=t(\"../color\");e.exports=function(t){t.each(function(t){var e=t[0].trace,n=e.error_y||{},o=e.error_x||{},i=r.select(this);i.selectAll(\"path.yerror\").style(\"stroke-width\",n.thickness+\"px\").call(a.stroke,n.color),o.copy_ystyle&&(o=n),i.selectAll(\"path.xerror\").style(\"stroke-width\",o.thickness+\"px\").call(a.stroke,o.color)})}},{\"../color\":18,d3:9}],50:[function(t,e,n){\"use strict\";var r=t(\"../../plots/cartesian/constants\");e.exports={_isLinkedToArray:!0,source:{valType:\"string\"},layer:{valType:\"enumerated\",values:[\"below\",\"above\"],dflt:\"above\"},sizex:{valType:\"number\",dflt:0},sizey:{valType:\"number\",dflt:0},sizing:{valType:\"enumerated\",values:[\"fill\",\"contain\",\"stretch\"],dflt:\"contain\"},opacity:{valType:\"number\",min:0,max:1,dflt:1},x:{valType:\"number\",dflt:0},y:{valType:\"number\",dflt:0},xanchor:{valType:\"enumerated\",values:[\"left\",\"center\",\"right\"],dflt:\"left\"},yanchor:{valType:\"enumerated\",values:[\"top\",\"middle\",\"bottom\"],dflt:\"top\"},xref:{valType:\"enumerated\",values:[\"paper\",r.idRegex.x.toString()],dflt:\"paper\"},yref:{valType:\"enumerated\",values:[\"paper\",r.idRegex.y.toString()],dflt:\"paper\"}}},{\"../../plots/cartesian/constants\":115}],51:[function(t,e,n){\"use strict\";function r(t,e,n){function r(n,r){return o.coerce(t,e,i,n,r)}e=e||{},r(\"source\"),r(\"layer\"),r(\"x\"),r(\"y\"),r(\"xanchor\"),r(\"yanchor\"),r(\"sizex\"),r(\"sizey\"),r(\"sizing\"),r(\"opacity\");for(var l=0;2>l;l++){var s={_fullLayout:n},c=[\"x\",\"y\"][l];a.coerceRef(t,e,s,c,\"paper\")}return e}var a=t(\"../../plots/cartesian/axes\"),o=t(\"../../lib\"),i=t(\"./attributes\");e.exports=function(t,e){if(t.images&&Array.isArray(t.images))for(var n=t.images,a=e.images=[],o=0;o<n.length;o++){var i=n[o];if(i.source){var l=r(n[o]||{},a[o]||{},e);a.push(l)}}}},{\"../../lib\":89,\"../../plots/cartesian/axes\":110,\"./attributes\":50}],52:[function(t,e,n){\"use strict\";var r=t(\"d3\"),a=t(\"../drawing\"),o=t(\"../../plots/cartesian/axes\");e.exports=function(t){function e(e){var n=r.select(this),a=new Promise(function(t){function r(){n.remove(),t()}var a=new Image;a.setAttribute(\"crossOrigin\",\"anonymous\"),a.onerror=r,a.onload=function(){var t=document.createElement(\"canvas\");t.width=this.width,t.height=this.height;var e=t.getContext(\"2d\");e.drawImage(this,0,0);var r=t.toDataURL(\"image/png\");n.attr(\"xlink:href\",r)},n.on(\"error\",r),n.on(\"load\",t),a.src=e.source});t._promises.push(a)}function n(e){var n=r.select(this),i=o.getFromId(t,e.xref),s=o.getFromId(t,e.yref),c=l._size,u=i?Math.abs(i.l2p(e.sizex)-i.l2p(0)):e.sizex*c.w,f=s?Math.abs(s.l2p(e.sizey)-s.l2p(0)):e.sizey*c.h,d=u*h.x[e.xanchor].offset+c.l,p=f*h.y[e.yanchor].offset+c.t,g=h.x[e.xanchor].sizing+h.y[e.yanchor].sizing,v=(i?i.l2p(e.x):e.x*c.w)+d,m=(s?s.l2p(e.y):c.h-e.y*c.h)+p;switch(e.sizing){case\"fill\":g+=\" slice\";break;case\"stretch\":g=\"none\"}n.attr({x:v,y:m,width:u,height:f,preserveAspectRatio:g,opacity:e.opacity});var y=i?i._id:\"\",x=s?s._id:\"\",b=y+x;n.call(a.setClipUrl,\"clip\"+l._uid+b)}function i(t,e){return t.source+e}var l=t._fullLayout,s=[],c=[],u=[];if(l.images){for(var f=0;f<l.images.length;f++){var d=l.images[f];\"below\"===d.layer&&\"paper\"!==d.xref&&\"paper\"!==d.yref?c.push(d):\"above\"===d.layer?s.push(d):u.push(d)}var h={x:{left:{sizing:\"xMin\",offset:0},center:{sizing:\"xMid\",offset:-0.5},right:{sizing:\"xMax\",offset:-1}},y:{top:{sizing:\"YMin\",offset:0},middle:{sizing:\"YMid\",offset:-0.5},bottom:{sizing:\"YMax\",offset:-1}}},p=l._imageLowerLayer.selectAll(\"image\").data(u,i),g=l._imageSubplotLayer.selectAll(\"image\").data(c,i),v=l._imageUpperLayer.selectAll(\"image\").data(s,i);p.enter().append(\"image\").each(e),g.enter().append(\"image\").each(e),v.enter().append(\"image\").each(e),p.exit().remove(),g.exit().remove(),v.exit().remove(),p.each(n),g.each(n),v.each(n)}}},{\"../../plots/cartesian/axes\":110,\"../drawing\":41,d3:9}],53:[function(t,e,n){\"use strict\";var r=t(\"./draw\"),a=t(\"./defaults\"),o=t(\"./attributes\");e.exports={draw:r,layoutAttributes:o,supplyLayoutDefaults:a}},{\"./attributes\":50,\"./defaults\":51,\"./draw\":52}],54:[function(t,e,n){\"use strict\";n.isRightAnchor=function(t){return\"right\"===t.xanchor||\"auto\"===t.xanchor&&t.x>=2/3},n.isCenterAnchor=function(t){return\"center\"===t.xanchor||\"auto\"===t.xanchor&&t.x>1/3&&t.x<2/3},n.isBottomAnchor=function(t){return\"bottom\"===t.yanchor||\"auto\"===t.yanchor&&t.y<=1/3},n.isMiddleAnchor=function(t){return\"middle\"===t.yanchor||\"auto\"===t.yanchor&&t.y>1/3&&t.y<2/3}},{}],55:[function(t,e,n){\"use strict\";var r=t(\"../../plots/font_attributes\"),a=t(\"../color/attributes\"),o=t(\"../../lib/extend\").extendFlat;e.exports={bgcolor:{valType:\"color\"},bordercolor:{valType:\"color\",dflt:a.defaultLine},borderwidth:{valType:\"number\",min:0,dflt:0},font:o({},r,{}),orientation:{valType:\"enumerated\",values:[\"v\",\"h\"],dflt:\"v\"},traceorder:{valType:\"flaglist\",flags:[\"reversed\",\"grouped\"],extras:[\"normal\"]},tracegroupgap:{valType:\"number\",min:0,dflt:10},x:{valType:\"number\",min:-2,max:3,dflt:1.02},xanchor:{valType:\"enumerated\",values:[\"auto\",\"left\",\"center\",\"right\"],dflt:\"left\"},y:{valType:\"number\",min:-2,max:3,dflt:1},yanchor:{valType:\"enumerated\",values:[\"auto\",\"top\",\"middle\",\"bottom\"],dflt:\"auto\"}}},{\"../../lib/extend\":88,\"../../plots/font_attributes\":128,\"../color/attributes\":17}],56:[function(t,e,n){\"use strict\";e.exports={scrollBarWidth:4,scrollBarHeight:20,scrollBarColor:\"#808BA4\",scrollBarMargin:4}},{}],57:[function(t,e,n){\"use strict\";var r=t(\"../../lib\"),a=t(\"../../plots/plots\"),o=t(\"./attributes\"),i=t(\"./helpers\");e.exports=function(t,e,n){function l(t,e){return r.coerce(d,h,o,t,e)}for(var s,c,u,f,d=t.legend||{},h=e.legend={},p=0,g=\"normal\",v=0;v<n.length;v++){var m=n[v];i.legendGetsTrace(m)&&(p++,a.traceIs(m,\"pie\")&&p++),(a.traceIs(m,\"bar\")&&\"stack\"===e.barmode||-1!==[\"tonextx\",\"tonexty\"].indexOf(m.fill))&&(g=i.isGrouped({traceorder:g})?\"grouped+reversed\":\"reversed\"),void 0!==m.legendgroup&&\"\"!==m.legendgroup&&(g=i.isReversed({traceorder:g})?\"reversed+grouped\":\"grouped\")}var y=r.coerce(t,e,a.layoutAttributes,\"showlegend\",p>1);if(y!==!1){if(l(\"bgcolor\",e.paper_bgcolor),l(\"bordercolor\"),l(\"borderwidth\"),r.coerceFont(l,\"font\",e.font),l(\"orientation\"),\"h\"===h.orientation){var x=t.xaxis;x&&x.rangeslider&&x.rangeslider.visible?(s=0,u=\"left\",c=1.1,f=\"bottom\"):(s=0,u=\"left\",c=-.1,f=\"top\")}l(\"traceorder\",g),i.isGrouped(e.legend)&&l(\"tracegroupgap\"),l(\"x\",s),l(\"xanchor\",u),l(\"y\",c),l(\"yanchor\",f),r.noneOrAll(d,h,[\"x\",\"y\"])}}},{\"../../lib\":89,\"../../plots/plots\":130,\"./attributes\":55,\"./helpers\":60}],58:[function(t,e,n){\"use strict\";function r(t,e){function n(n){u.util.convertToTspans(n,function(){n.selectAll(\"tspan.line\").attr({x:n.attr(\"x\")}),t.call(o,e)})}var r=t.data()[0][0],a=e._fullLayout,i=r.trace,l=d.traceIs(i,\"pie\"),s=i.index,c=l?r.label:i.name,f=t.selectAll(\"text.legendtext\").data([0]);f.enter().append(\"text\").classed(\"legen"
,
"dtext\",!0),f.attr({x:40,y:0,\"data-unformatted\":c}).style(\"text-anchor\",\"start\").classed(\"user-select-none\",!0).call(p.font,a.legend.font).text(c),e._context.editable&&!l?f.call(u.util.makeEditable).call(n).on(\"edit\",function(t){this.attr({\"data-unformatted\":t}),this.text(t).call(n),this.text()||(t=\"    \"),u.restyle(e,\"name\",t,s)}):f.call(n)}function a(t,e){var n=e._fullLayout.hiddenlabels?e._fullLayout.hiddenlabels.slice():[],r=t.selectAll(\"rect\").data([0]);r.enter().append(\"rect\").classed(\"legendtoggle\",!0).style(\"cursor\",\"pointer\").attr(\"pointer-events\",\"all\").call(g.fill,\"rgba(0,0,0,0)\"),r.on(\"click\",function(){if(!e._dragged){var r,a,o=t.data()[0][0],i=e._fullData,l=o.trace,s=l.legendgroup,c=[];if(d.traceIs(l,\"pie\")){var f=o.label,h=n.indexOf(f);-1===h?n.push(f):n.splice(h,1),u.relayout(e,\"hiddenlabels\",n)}else{if(\"\"===s)c=[l.index];else for(var p=0;p<i.length;p++)r=i[p],r.legendgroup===s&&c.push(r.index);a=l.visible===!0?\"legendonly\":!0,u.restyle(e,\"visible\",a,c)}}})}function o(t,e){var n,r,a=t.data()[0][0],o=t.selectAll(\".legendtoggle\"),i=t.select(\"g[class*=math-group]\"),l=e._fullLayout.legend,s=1.3*l.font.size;if(!a.trace.showlegend)return void t.remove();if(i.node()){var c=p.bBox(i.node());n=c.height,r=c.width,f.setTranslate(i,0,n/4)}else{var u=t.selectAll(\".legendtext\"),d=t.selectAll(\".legendtext>tspan\"),h=d[0].length||1;n=s*h,r=u.node()&&p.bBox(u.node()).width;var g=s*(.3+(1-h)/2);u.attr(\"y\",g),d.attr(\"y\",g)}n=Math.max(n,16)+3,o.attr({x:0,y:-n/2,height:n}),a.height=n,a.width=r}function i(t,e,n){var r=t._fullLayout,a=r.legend,o=a.borderwidth,i=x.isGrouped(a);if(x.isVertical(a))i&&e.each(function(t,e){f.setTranslate(this,0,e*a.tracegroupgap)}),a.width=0,a.height=0,n.each(function(t){var e=t[0],n=e.height,r=e.width;f.setTranslate(this,o,5+o+a.height+n/2),a.height+=n,a.width=Math.max(a.width,r)}),a.width+=45+2*o,a.height+=10+2*o,i&&(a.height+=(a._lgroupsLength-1)*a.tracegroupgap),n.selectAll(\".legendtoggle\").attr(\"width\",(t._context.editable?0:a.width)+40),a.width=Math.ceil(a.width),\n"
,
"a.height=Math.ceil(a.height);else if(i){a.width=0,a.height=0;for(var l=[a.width],s=e.data(),u=0,d=s.length;d>u;u++){var h=s[u].map(function(t){return t[0].width}),p=40+Math.max.apply(null,h);a.width+=a.tracegroupgap+p,l.push(a.width)}e.each(function(t,e){f.setTranslate(this,l[e],0)}),e.each(function(){var t=c.select(this),e=t.selectAll(\"g.traces\"),n=0;e.each(function(t){var e=t[0],r=e.height;f.setTranslate(this,0,5+o+n+r/2),n+=r}),a.height=Math.max(a.height,n)}),a.height+=10+2*o,a.width+=2*o,a.width=Math.ceil(a.width),a.height=Math.ceil(a.height),n.selectAll(\".legendtoggle\").attr(\"width\",t._context.editable?0:a.width)}else a.width=0,a.height=0,n.each(function(t){var e=t[0],n=40+e.width,r=a.tracegroupgap||5;f.setTranslate(this,o+a.width,5+o+e.height/2),a.width+=r+n,a.height=Math.max(a.height,e.height)}),a.width+=2*o,a.height+=10+2*o,a.width=Math.ceil(a.width),a.height=Math.ceil(a.height),n.selectAll(\".legendtoggle\").attr(\"width\",t._context.editable?0:a.width)}function l(t){var e=t._fullLayout,n=e.legend,r=\"left\";b.isRightAnchor(n)?r=\"right\":b.isCenterAnchor(n)&&(r=\"center\");var a=\"top\";b.isBottomAnchor(n)?a=\"bottom\":b.isMiddleAnchor(n)&&(a=\"middle\"),d.autoMargin(t,\"legend\",{x:n.x,y:n.y,l:n.width*({right:1,center:.5}[r]||0),r:n.width*({left:1,center:.5}[r]||0),b:n.height*({top:1,middle:.5}[a]||0),t:n.height*({bottom:1,middle:.5}[a]||0)})}function s(t){var e=t._fullLayout,n=e.legend,r=\"left\";b.isRightAnchor(n)?r=\"right\":b.isCenterAnchor(n)&&(r=\"center\"),d.autoMargin(t,\"legend\",{x:n.x,y:.5,l:n.width*({right:1,center:.5}[r]||0),r:n.width*({left:1,center:.5}[r]||0),b:0,t:0})}var c=t(\"d3\"),u=t(\"../../plotly\"),f=t(\"../../lib\"),d=t(\"../../plots/plots\"),h=t(\"../dragelement\"),p=t(\"../drawing\"),g=t(\"../color\"),v=t(\"./constants\"),m=t(\"./get_legend_data\"),y=t(\"./style\"),x=t(\"./helpers\"),b=t(\"./anchor_utils\");e.exports=function(t){function e(t,e){L.attr(\"data-scroll\",e).call(f.setTranslate,0,e),T.call(p.setRect,j,t,v.scrollBarWidth,v.scrollBarHeight),M.select(\"rect\").attr({y:x.borderwidth-e})}var n=t._fullLayout,o=\"legend\"+n._uid;if(n._infolayer&&t.calcdata){var x=n.legend,_=n.showlegend&&m(t.calcdata,x),w=n.hiddenlabels||[];if(!n.showlegend||!_.length)return n._infolayer.selectAll(\".legend\").remove(),n._topdefs.select(\"#\"+o).remove(),void d.autoMargin(t,\"legend\");var k=n._infolayer.selectAll(\"g.legend\").data([0]);k.enter().append(\"g\").attr({\"class\":\"legend\",\"pointer-events\":\"all\"});var M=n._topdefs.selectAll(\"#\"+o).data([0]);M.enter().append(\"clipPath\").attr(\"id\",o).append(\"rect\");var A=k.selectAll(\"rect.bg\").data([0]);A.enter().append(\"rect\").attr({\"class\":\"bg\",\"shape-rendering\":\"crispEdges\"}),A.call(g.stroke,x.bordercolor),A.call(g.fill,x.bgcolor),A.style(\"stroke-width\",x.borderwidth+\"px\");var L=k.selectAll(\"g.scrollbox\").data([0]);L.enter().append(\"g\").attr(\"class\",\"scrollbox\");var T=k.selectAll(\"rect.scrollbar\").data([0]);T.enter().append(\"rect\").attr({\"class\":\"scrollbar\",rx:20,ry:2,width:0,height:0}).call(g.fill,\"#808BA4\");var z=L.selectAll(\"g.groups\").data(_);z.enter().append(\"g\").attr(\"class\",\"groups\"),z.exit().remove();var S=z.selectAll(\"g.traces\").data(f.identity);S.enter().append(\"g\").attr(\"class\",\"traces\"),S.exit().remove(),S.call(y).style(\"opacity\",function(t){var e=t[0].trace;return d.traceIs(e,\"pie\")?-1!==w.indexOf(t[0].label)?.5:1:\"legendonly\"===e.visible?.5:1}).each(function(){c.select(this).call(r,t).call(a,t)});var E=0!==k.enter().size();E&&(i(t,z,S),l(t));var C=0,O=n.width,P=0,N=n.height;i(t,z,S),x.height>N?s(t):l(t);var D=n._size,I=D.l+D.w*x.x,R=D.t+D.h*(1-x.y);b.isRightAnchor(x)?I-=x.width:b.isCenterAnchor(x)&&(I-=x.width/2),b.isBottomAnchor(x)?R-=x.height:b.isMiddleAnchor(x)&&(R-=x.height/2);var j=x.width,q=D.w;j>q?(I=D.l,j=q):(I+j>O&&(I=O-j),C>I&&(I=C),j=Math.min(O-I,x.width));var F=x.height,B=D.h;F>B?(R=D.t,F=B):(R+F>N&&(R=N-F),P>R&&(R=P),F=Math.min(N-R,x.height)),f.setTranslate(k,I,R);var H,V,Z=F-v.scrollBarHeight-2*v.scrollBarMargin,Y=x.height-F;if(x.height<=F||t._context.staticPlot)A.attr({width:j-x.borderwidth,height:F-x.borderwidth,x:x.borderwidth/2,y:x.borderwidth/2}),f.setTranslate(L,0,0),M.select(\"rect\").attr({width:j-2*x.borderwidth,height:F-2*x.borderwidth,x:x.borderwidth,y:x.borderwidth}),L.call(p.setClipUrl,o);else{H=v.scrollBarMargin,V=L.attr(\"data-scroll\")||0,A.attr({width:j-2*x.borderwidth+v.scrollBarWidth+v.scrollBarMargin,height:F-x.borderwidth,x:x.borderwidth/2,y:x.borderwidth/2}),M.select(\"rect\").attr({width:j-2*x.borderwidth+v.scrollBarWidth+v.scrollBarMargin,height:F-2*x.borderwidth,x:x.borderwidth,y:x.borderwidth-V}),L.call(p.setClipUrl,o),E&&e(H,V),k.on(\"wheel\",null),k.on(\"wheel\",function(){V=f.constrain(L.attr(\"data-scroll\")-c.event.deltaY/Z*Y,-Y,0),H=v.scrollBarMargin-V/Y*Z,e(H,V),c.event.preventDefault()}),T.on(\".drag\",null),L.on(\".drag\",null);var U=c.behavior.drag().on(\"drag\",function(){H=f.constrain(c.event.y-v.scrollBarHeight/2,v.scrollBarMargin,v.scrollBarMargin+Z),V=-(H-v.scrollBarMargin)/Z*Y,e(H,V)});T.call(U),L.call(U)}if(t._context.editable){var X,G,$,Q;k.classed(\"cursor-move\",!0),h.init({element:k.node(),prepFn:function(){var t=f.getTranslate(k);$=t.x,Q=t.y},moveFn:function(t,e){var n=$+t,r=Q+e;f.setTranslate(k,n,r),X=h.align(n,0,D.l,D.l+D.w,x.xanchor),G=h.align(r,0,D.t+D.h,D.t,x.yanchor)},doneFn:function(e){e&&void 0!==X&&void 0!==G&&u.relayout(t,{\"legend.x\":X,\"legend.y\":G})}})}}}},{\"../../lib\":89,\"../../plotly\":107,\"../../plots/plots\":130,\"../color\":18,\"../dragelement\":39,\"../drawing\":41,\"./anchor_utils\":54,\"./constants\":56,\"./get_legend_data\":59,\"./helpers\":60,\"./style\":62,d3:9}],59:[function(t,e,n){\"use strict\";var r=t(\"../../plots/plots\"),a=t(\"./helpers\");e.exports=function(t,e){function n(t,n){if(\"\"!==t&&a.isGrouped(e))-1===s.indexOf(t)?(s.push(t),c=!0,l[t]=[[n]]):l[t].push([n]);else{var r=\"~~i\"+f;s.push(r),l[r]=[[n]],f++}}var o,i,l={},s=[],c=!1,u={},f=0;for(o=0;o<t.length;o++){var d=t[o],h=d[0],p=h.trace,g=p.legendgroup;if(a.legendGetsTrace(p)&&p.showlegend)if(r.traceIs(p,\"pie\"))for(u[g]||(u[g]={}),i=0;i<d.length;i++){var v=d[i].label;u[g][v]||(n(g,{label:v,color:d[i].color,i:d[i].i,trace:p}),u[g][v]=!0)}else n(g,h)}if(!s.length)return[];var m,y,x=s.length;if(c&&a.isGrouped(e))for(y=new Array(x),o=0;x>o;o++)m=l[s[o]],y[o]=a.isReversed(e)?m.reverse():m;else{for(y=[new Array(x)],o=0;x>o;o++)m=l[s[o]][0],y[0][a.isReversed(e)?x-o-1:o]=m;x=1}return e._lgroupsLength=x,y}},{\"../../plots/plots\":130,\"./helpers\":60}],60:[function(t,e,n){\"use strict\";var r=t(\"../../plots/plots\");n.legendGetsTrace=function(t){return t.visible&&r.traceIs(t,\"showLegend\")},n.isGrouped=function(t){return-1!==(t.traceorder||\"\").indexOf(\"grouped\")},n.isVertical=function(t){return\"h\"!==t.orientation},n.isReversed=function(t){return-1!==(t.traceorder||\"\").indexOf(\"reversed\")}},{\"../../plots/plots\":130}],61:[function(t,e,n){\"use strict\";var r=e.exports={};r.layoutAttributes=t(\"./attributes\"),r.supplyLayoutDefaults=t(\"./defaults\"),r.draw=t(\"./draw\"),r.style=t(\"./style\")},{\"./attributes\":55,\"./defaults\":57,\"./draw\":58,\"./style\":62}],62:[function(t,e,n){\"use strict\";function r(t){var e=t[0].trace,n=e.visible&&e.fill&&\"none\"!==e.fill,r=h.hasLines(e),a=s.select(this).select(\".legendfill\").selectAll(\"path\").data(n?[t]:[]);a.enter().append(\"path\").classed(\"js-fill\",!0),a.exit().remove(),a.attr(\"d\",\"M5,0h30v6h-30z\").call(f.fillGroupStyle);var o=s.select(this).select(\".legendlines\").selectAll(\"path\").data(r?[t]:[]);o.enter().append(\"path\").classed(\"js-line\",!0).attr(\"d\",\"M5,0h30\"),o.exit().remove(),o.call(f.lineGroupStyle)}function a(t){function e(t,e,n){var r=c.nestedProperty(i,t).get(),a=Array.isArray(r)&&e?e(r):r;if(n){if(a<n[0])return n[0];if(a>n[1])return n[1]}return a}function n(t){return t[0]}var r,a,o=t[0],i=o.trace,l=h.hasMarkers(i),u=h.hasText(i),d=h.hasLines(i);if(l||u||d){var p={},g={};l&&(p.mc=e(\"marker.color\",n),p.mo=e(\"marker.opacity\",c.mean,[.2,1]),p.ms=e(\"marker.size\",c.mean,[2,16]),p.mlc=e(\"marker.line.color\",n),p.mlw=e(\"marker.line.width\",c.mean,[0,5]),g.marker={sizeref:1,sizemin:1,sizemode:\"diameter\"}),d&&(g.line={width:e(\"line.width\",n,[0,10])}),u&&(p.tx=\"Aa\",p.tp=e(\"textposition\",n),p.ts=10,p.tc=e(\"textfont.color\",n),p.tf=e(\"textfont.family\",n)),r=[c.minExtend(o,p)],a=c.minExtend(i,g)}var v=s.select(this).select(\"g.legendpoints\"),m=v.selectAll(\"path.scatterpts\").data(l?r:[]);m.enter().append(\"path\").classed(\"scatterpts\",!0).attr(\"transform\",\"translate(20,0)\"),m.exit().remove(),m.call(f.pointStyle,a),l&&(r[0].mrc=3);var y=v.selectAll(\"g.pointtext\").data(u?r:[]);y.enter().append(\"g\").classed(\"pointtext\",!0).append(\"text\").attr(\"transform\",\"translate(20,0)\"),y.exit().remove(),y.selectAll(\"text\").call(f.textPointStyle,a)}function o(t){var e=t[0].trace,n=e.marker||{},r=n.line||{},a=s.select(this).select(\"g.legendpoints\").selectAll(\"path.legendbar\").data(u.traceIs(e,\"bar\")?[t]:[]);a.enter().append(\"path\").classed(\"legendbar\",!0).attr(\"d\",\"M6,6H-6V-6H6Z\").attr(\"transform\",\"translate(20,0)\"),a.exit().remove(),a.each(function(t){var e=(t.mlw+1||r.width+1)-1,a=s.select(this);a.style(\"stroke-width\",e+\"px\").call(d.fill,t.mc||n.color),e&&a.call(d.stroke,t.mlc||r.color)})}function i(t){var e=t[0].trace,n=s.select(this).select(\"g.legendpoints\").selectAll(\"path.legendbox\").data(u.traceIs(e,\"box\")&&e.visible?[t]:[]);n.enter().append(\"path\").classed(\"legendbox\",!0).attr(\"d\",\"M6,6H-6V-6H6Z\").attr(\"transform\",\"translate(20,0)\"),n.exit().remove(),n.each(function(t){var n=(t.lw+1||e.line.width+1)-1,r=s.select(this);r.style(\"stroke-width\",n+\"px\").call(d.fill,t.fc||e.fillcolor),n&&r.call(d.stroke,t.lc||e.line.color)})}function l(t){var e=t[0].trace,n=s.select(this).select(\"g.legendpoints\").selectAll(\"path.legendpie\").data(u.traceIs(e,\"pie\")&&e.visible?[t]:[]);n.enter().append(\"path\").classed(\"legendpie\",!0).attr(\"d\",\"M6,6H-6V-6H6Z\").attr(\"transform\",\"translate(20,0)\"),n.exit().remove(),n.size()&&n.call(p,t[0],e)}var s=t(\"d3\"),c=t(\"../../lib\"),u=t(\"../../plots/plots\"),f=t(\"../drawing\"),d=t(\"../color\"),h=t(\"../../traces/scatter/subtypes\"),p=t(\"../../traces/pie/style_one\");e.exports=function(t){t.each(functio"
,
"n(t){var e=s.select(this),n=e.selectAll(\"g.legendfill\").data([t]);n.enter().append(\"g\").classed(\"legendfill\",!0);var r=e.selectAll(\"g.legendlines\").data([t]);r.enter().append(\"g\").classed(\"legendlines\",!0);var a=e.selectAll(\"g.legendsymbols\").data([t]);a.enter().append(\"g\").classed(\"legendsymbols\",!0),a.style(\"opacity\",t[0].trace.opacity),a.selectAll(\"g.legendpoints\").data([t]).enter().append(\"g\").classed(\"legendpoints\",!0)}).each(o).each(i).each(l).each(r).each(a)}},{\"../../lib\":89,\"../../plots/plots\":130,\"../../traces/pie/style_one\":165,\"../../traces/scatter/subtypes\":186,\"../color\":18,\"../drawing\":41,d3:9}],63:[function(t,e,n){\"use strict\";function r(t,e){var n=e.currentTarget,r=n.getAttribute(\"data-attr\"),a=n.getAttribute(\"data-val\")||!0,o=t._fullLayout,i={};if(\"zoom\"===r){for(var l,s,u=\"in\"===a?.5:2,f=(1+u)/2,d=(1-u)/2,h=c.Axes.list(t,null,!0),p=0;p<h.length;p++)if(l=h[p],!l.fixedrange)if(s=l._name,\"auto\"===a)i[s+\".autorange\"]=!0;else if(\"reset\"===a)if(void 0===l._rangeInitial)i[s+\".autorange\"]=!0;else{var g=l._rangeInitial.slice();i[s+\".range[0]\"]=g[0],i[s+\".range[1]\"]=g[1]}else{var v=l.range;i[s+\".range[0]\"]=f*v[0]+d*v[1],i[s+\".range[1]\"]=f*v[1]+d*v[0]}}else\"hovermode\"!==r||\"x\"!==a&&\"y\"!==a||(a=o._isHoriz?\"y\":\"x\",n.setAttribute(\"data-val\",a)),i[r]=a;c.relayout(t,i)}function a(t,e){for(var n=e.currentTarget,r=n.getAttribute(\"data-attr\"),a=n.getAttribute(\"data-val\")||!0,o=t._fullLayout,i=c.Plots.getSubplotIds(o,\"gl3d\"),l={},s=r.split(\".\"),u=0;u<i.length;u++)l[i[u]+\".\"+s[1]]=a;c.relayout(t,l)}function o(t,e){for(var n=e.currentTarget,r=n.getAttribute(\"data-attr\"),a=t._fullLayout,o=c.Plots.getSubplotIds(a,\"gl3d\"),i=0;i<o.length;i++){var l=o[i],s=a[l],u=s._scene;\"resetDefault\"===r?u.setCameraToDefault():\"resetLastSave\"===r&&u.setCamera(s.camera)}}function i(t,e){var n=e.currentTarget,r=n._previousVal||!1,a=t.layout,o=t._fullLayout,i=c.Plots.getSubplotIds(o,\"gl3d\"),l=[\"xaxis\",\"yaxis\",\"zaxis\"],s=[\"showspikes\",\"spikesides\",\"spikethickness\",\"spikecolor\"],f={},d={},h={};if(r)h=u.extendDeep(a,r),n._previousVal=null;else{h={\"allaxes.showspikes\":!1};for(var p=0;p<i.length;p++){var g=i[p],v=o[g],m=f[g]={};m.hovermode=v.hovermode,h[g+\".hovermode\"]=!1;for(var y=0;3>y;y++){var x=l[y];d=m[x]={};for(var b=0;b<s.length;b++){var _=s[b];d[_]=v[x][_]}}}n._previousVal=u.extendDeep({},f)}c.relayout(t,h)}function l(t,e){for(var n=e.currentTarget,r=n.getAttribute(\"data-attr\"),a=n.getAttribute(\"data-val\")||!0,o=t._fullLayout,i=c.Plots.getSubplotIds(o,\"geo\"),l=0;l<i.length;l++){var s=o[i[l]]._geo;if(\"zoom\"===r){var u=s.projection.scale(),f=\"in\"===a?2*u:.5*u;s.projection.scale(f),s.zoom.scale(f),s.render()}else\"reset\"===r&&s.zoomReset()}}function s(t){var e,n=t._fullLayout;e=n._has(\"cartesian\")?n._isHoriz?\"y\":\"x\":\"closest\";var r=t._fullLayout.hovermode?!1:e;c.relayout(t,\"hovermode\",r)}var c=t(\"../../plotly\"),u=t(\"../../lib\"),f=t(\"../../snapshot/download\"),d=t(\"../../../build/ploticon\"),h=e.exports={};h.toImage={name:\"toImage\",title:\"Download plot as a png\",icon:d.camera,click:function(t){var e=\"png\";u.notifier(\"Taking snapshot - this may take a few seconds\",\"long\"),u.isIE()&&(u.notifier(\"IE only supports svg.  Changing format to svg.\",\"long\"),e=\"svg\"),f(t,{format:e}).then(function(t){u.notifier(\"Snapshot succeeded - \"+t,\"long\")}).catch(function(){u.notifier(\"Sorry there was a problem downloading your snapshot!\",\"long\")})}},h.sendDataToCloud={name:\"sendDataToCloud\",title:\"Save and edit plot in cloud\",icon:d.disk,click:function(t){c.Plots.sendDataToCloud(t)}},h.zoom2d={name:\"zoom2d\",title:\"Zoom\",attr:\"dragmode\",val:\"zoom\",icon:d.zoombox,click:r},h.pan2d={name:\"pan2d\",title:\"Pan\",attr:\"dragmode\",val:\"pan\",icon:d.pan,click:r},h.select2d={name:\"select2d\",title:\"Box Select\",attr:\"dragmode\",val:\"select\",icon:d.selectbox,click:r},h.lasso2d={name:\"lasso2d\",title:\"Lasso Select\",attr:\"dragmode\",val:\"lasso\",icon:d.lasso,click:r},h.zoomIn2d={name:\"zoomIn2d\",title:\"Zoom in\",attr:\"zoom\",val:\"in\",icon:d.zoom_plus,click:r},h.zoomOut2d={name:\"zoomOut2d\",title:\"Zoom out\",attr:\"zoom\",val:\"out\",icon:d.zoom_minus,click:r},h.autoScale2d={name:\"autoScale2d\",title:\"Autoscale\",attr:\"zoom\",val:\"auto\",icon:d.autoscale,click:r},h.resetScale2d={name:\"resetScale2d\",title:\"Reset axes\",attr:\"zoom\",val:\"reset\",icon:d.home,click:r},h.hoverClosestCartesian={name:\"hoverClosestCartesian\",title:\"Show closest data on hover\",attr:\"hovermode\",val:\"closest\",icon:d.tooltip_basic,gravity:\"ne\",click:r},h.hoverCompareCartesian={name:\"hoverCompareCartesian\",title:\"Compare data on hover\",attr:\"hovermode\",val:function(t){return t._fullLayout._isHoriz?\"y\":\"x\"},icon:d.tooltip_compare,gravity:\"ne\",click:r},h.zoom3d={name:\"zoom3d\",title:\"Zoom\",attr:\"scene.dragmode\",val:\"zoom\",icon:d.zoombox,click:a},h.pan3d={name:\"pan3d\",title:\"Pan\",attr:\"scene.dragmode\",val:\"pan\",icon:d.pan,click:a},h.orbitRotation={name:\"orbitRotation\",title:\"orbital rotation\",attr:\"scene.dragmode\",val:\"orbit\",icon:d[\"3d_rotate\"],click:a},h.tableRotation={name:\"tableRotation\",title:\"turntable rotation\",attr:\"scene.dragmode\",val:\"turntable\",icon:d[\"z-axis\"],click:a},h.resetCameraDefault3d={name:\"resetCameraDefault3d\",title:\"Reset camera to default\",attr:\"resetDefault\",icon:d.home,click:o},h.resetCameraLastSave3d={name:\"resetCameraLastSave3d\",title:\"Reset camera to last save\",attr:\"resetLastSave\",icon:d.movie,click:o},h.hoverClosest3d={name:\"hoverClosest3d\",title:\"Toggle show closest data on hover\",attr:\"hovermode\",val:null,toggle:!0,icon:d.tooltip_basic,gravity:\"ne\",click:i},h.zoomInGeo={name:\"zoomInGeo\",title:\"Zoom in\",attr:\"zoom\",val:\"in\",icon:d.zoom_plus,click:l},h.zoomOutGeo={name:\"zoomOutGeo\",title:\"Zoom out\",attr:\"zoom\",val:\"out\",icon:d.zoom_minus,click:l},h.resetGeo={name:\"resetGeo\",title:\"Reset\",attr:\"reset\",val:null,icon:d.autoscale,click:l},h.hoverClosestGeo={name:\"hoverClosestGeo\",title:\"Toggle show closest data on hover\",attr:\"hovermode\",val:null,toggle:!0,icon:d.tooltip_basic,gravity:\"ne\",click:s},h.hoverClosestGl2d={name:\"hoverClosestGl2d\",title:\"Toggle show closest data on hover\",attr:\"hovermode\",val:null,toggle:!0,icon:d.tooltip_basic,gravity:\"ne\",click:s},h.hoverClosestPie={name:\"hoverClosestPie\",title:\"Toggle show closest data on hover\",attr:\"hovermode\",val:\"closest\",icon:d.tooltip_basic,gravity:\"ne\",click:s},h.toggleHover={name:\"toggleHover\",title:\"Toggle show closest data on hover\",attr:\"hovermode\",val:null,toggle:!0,icon:d.tooltip_basic,gravity:\"ne\",click:function(t,e){s(t),i(t,e)}},h.resetViews={name:\"resetViews\",title:\"Reset views\",icon:d.home,click:function(t,e){var n=e.currentTarget;n.setAttribute(\"data-attr\",\"zoom\"),n.setAttribute(\"data-val\",\"reset\"),r(t,e),n.setAttribute(\"data-attr\",\"resetLastSave\"),o(t,e)}}},{\"../../../build/ploticon\":2,\"../../lib\":89,\"../../plotly\":107,\"../../snapshot/download\":137}],64:[function(t,e,n){\"use strict\";function r(t){this.container=t.container,this.element=document.createElement(\"div\"),this.update(t.graphInfo,t.buttons),this.container.appendChild(this.element)}function a(t,e){var n=t._fullLayout,a=new r({graphInfo:t,container:n._paperdiv.node(),buttons:e});return n._privateplot&&o.select(a.element).append(\"span\").classed(\"badge-private float--left\",!0).text(\"PRIVATE\"),a}var o=t(\"d3\"),i=t(\"../../lib\"),l=t(\"../../../build/ploticon\"),s=r.prototype;s.update=function(t,e){this.graphInfo=t;var n=this.graphInfo._context;\"hover\"===n.displayModeBar?this.element.className=\"modebar modebar--hover\":this.element.className=\"modebar\";var r=!this.hasButtons(e),a=this.hasLogo!==n.displaylogo;(r||a)&&(this.removeAllButtons(),this.updateButtons(e),n.displaylogo&&(this.element.appendChild(this.getLogo()),this.hasLogo=!0)),this.updateActiveButton()},s.updateButtons=function(t){var e=this;this.buttons=t,this.buttonElements=[],this.buttonsNames=[],this.buttons.forEach(function(t){var n=e.createGroup();t.forEach(function(t){var r=t.name;if(!r)throw new Error(\"must provide button 'name' in button config\");if(-1!==e.buttonsNames.indexOf(r))throw new Error(\"button name '\"+r+\"' is taken\");e.buttonsNames.push(r);var a=e.createButton(t);e.buttonElements.push(a),n.appendChild(a)}),e.element.appendChild(n)})},s.createGroup=function(){var t=document.createElement(\"div\");return t.className=\"modebar-group\",t},s.createButton=function(t){var e=this,n=document.createElement(\"a\");n.setAttribute(\"rel\",\"tooltip\"),n.className=\"modebar-btn\";var r=t.title;void 0===r&&(r=t.name),(r||0===r)&&n.setAttribute(\"data-title\",r),void 0!==t.attr&&n.setAttribute(\"data-attr\",t.attr);var a=t.val;void 0!==a&&(\"function\"==typeof a&&(a=a(this.graphInfo)),n.setAttribute(\"data-val\",a));var o=t.click;if(\"function\"!=typeof o)throw new Error(\"must provide button 'click' function in button config\");return n.addEventListener(\"click\",function(n){t.click(e.graphInfo,n),e.updateActiveButton(n.currentTarget)}),n.setAttribute(\"data-toggle\",t.toggle||!1),t.toggle&&n.classList.add(\"active\"),n.appendChild(this.createIcon(t.icon||l.question)),n.setAttribute(\"data-gravity\",t.gravity||\"n\"),n},s.createIcon=function(t){var e=t.ascent-t.descent,n=\"http://www.w3.org/2000/svg\",r=document.createElementNS(n,\"svg\"),a=document.createElementNS(n,\"path\");return r.setAttribute(\"height\",\"1em\"),r.setAttribute(\"width\",t.width/e+\"em\"),r.setAttribute(\"viewBox\",[0,0,t.width,e].join(\" \")),a.setAttribute(\"d\",t.path),a.setAttribute(\"transform\",\"matrix(1 0 0 -1 0 \"+t.ascent+\")\"),r.appendChild(a),r},s.updateActiveButton=function(t){var e=this.graphInfo._fullLayout,n=void 0!==t?t.getAttribute(\"data-attr\"):null;this.buttonElements.forEach(function(t){var r=t.getAttribute(\"data-val\")||!0,a=t.getAttribute(\"data-attr\"),l=\"true\"===t.getAttribute(\"data-toggle\"),s=o.select(t);if(l)a===n&&s.classed(\"active\",!s.classed(\"active\"));else{var c=null===a?a:i.nestedProperty(e,a).get();s.classed(\"active\",c===r)}})},s.hasButtons=function(t){var e=this.buttons;if(!e)return!1;if(t.length!==e.length)return!1;for(var n=0;n<t.length;++n){if(t[n].length!==e[n].length)return!1;for(var r=0;r<t[n].length;r++)if(t[n][r].name!==e[n][r].name)return!1}return!0},s.getLogo=function(){var t="
,
"this.createGroup(),e=document.createElement(\"a\");return e.href=\"https://plot.ly/\",e.target=\"_blank\",e.setAttribute(\"data-title\",\"Produced with Plotly\"),e.className=\"modebar-btn plotlyjsicon modebar-btn--logo\",e.appendChild(this.createIcon(l.plotlylogo)),t.appendChild(e),t},s.removeAllButtons=function(){for(;this.element.firstChild;)this.element.removeChild(this.element.firstChild);this.hasLogo=!1},s.destroy=function(){i.removeElement(this.container.querySelector(\".modebar\"))},e.exports=a},{\"../../../build/ploticon\":2,\"../../lib\":89,d3:9}],65:[function(t,e,n){\"use strict\";function r(t,e,n){function r(t){for(var n=[],r=0;r<t.length;r++){var a=t[r];-1===e.indexOf(a)&&n.push(f[a])}v.push(n)}var l=t._fullLayout,s=t._fullData,c=l._has(\"cartesian\"),u=l._has(\"gl3d\"),d=l._has(\"geo\"),h=l._has(\"pie\"),p=l._has(\"gl2d\"),g=l._has(\"ternary\"),v=[];if(r([\"toImage\",\"sendDataToCloud\"]),(c||p||h||g)+d+u>1)return r([\"resetViews\",\"toggleHover\"]),i(v,n);u&&(r([\"zoom3d\",\"pan3d\",\"orbitRotation\",\"tableRotation\"]),r([\"resetCameraDefault3d\",\"resetCameraLastSave3d\"]),r([\"hoverClosest3d\"])),d&&(r([\"zoomInGeo\",\"zoomOutGeo\",\"resetGeo\"]),r([\"hoverClosestGeo\"]));var m=a(l),y=[];return((c||p)&&!m||g)&&(y=[\"zoom2d\",\"pan2d\"]),(c||g)&&o(s)&&(y.push(\"select2d\"),y.push(\"lasso2d\")),y.length&&r(y),!c&&!p||m||g||r([\"zoomIn2d\",\"zoomOut2d\",\"autoScale2d\",\"resetScale2d\"]),c&&h?r([\"toggleHover\"]):p?r([\"hoverClosestGl2d\"]):c?r([\"hoverClosestCartesian\",\"hoverCompareCartesian\"]):h&&r([\"hoverClosestPie\"]),i(v,n)}function a(t){for(var e=s.Axes.list({_fullLayout:t},null,!0),n=!0,r=0;r<e.length;r++)if(!e[r].fixedrange){n=!1;break}return n}function o(t){for(var e=!1,n=0;n<t.length&&!e;n++){var r=t[n];r._module&&r._module.selectPoints&&(\"scatter\"===r.type||\"scatterternary\"===r.type?(c.hasMarkers(r)||c.hasText(r))&&(e=!0):e=!0)}return e}function i(t,e){if(e.length)if(Array.isArray(e[0]))for(var n=0;n<e.length;n++)t.push(e[n]);else t.push(e);return t}function l(t){for(var e=0;e<t.length;e++)for(var n=t[e],r=0;r<n.length;r++){var a=n[r];if(\"string\"==typeof a){if(void 0===f[a])throw new Error([\"*modeBarButtons* configuration options\",\"invalid button name\"].join(\" \"));t[e][r]=f[a]}}return t}var s=t(\"../../plotly\"),c=t(\"../../traces/scatter/subtypes\"),u=t(\"./\"),f=t(\"./buttons\");e.exports=function(t){var e=t._fullLayout,n=t._context,a=e._modeBar;if(!n.displayModeBar)return void(a&&(a.destroy(),delete e._modeBar));if(!Array.isArray(n.modeBarButtonsToRemove))throw new Error([\"*modeBarButtonsToRemove* configuration options\",\"must be an array.\"].join(\" \"));if(!Array.isArray(n.modeBarButtonsToAdd))throw new Error([\"*modeBarButtonsToAdd* configuration options\",\"must be an array.\"].join(\" \"));var o,i=n.modeBarButtons;o=Array.isArray(i)&&i.length?l(i):r(t,n.modeBarButtonsToRemove,n.modeBarButtonsToAdd),a?a.update(t,o):e._modeBar=u(t,o)}},{\"../../plotly\":107,\"../../traces/scatter/subtypes\":186,\"./\":64,\"./buttons\":63}],66:[function(t,e,n){\"use strict\";var r=t(\"../../plots/font_attributes\"),a=t(\"../color/attributes\"),o=t(\"../../lib/extend\").extendFlat,i=t(\"./button_attributes\");i=o(i,{_isLinkedToArray:!0}),e.exports={visible:{valType:\"boolean\"},buttons:i,x:{valType:\"number\",min:-2,max:3},xanchor:{valType:\"enumerated\",values:[\"auto\",\"left\",\"center\",\"right\"],dflt:\"left\"},y:{valType:\"number\",min:-2,max:3},yanchor:{valType:\"enumerated\",values:[\"auto\",\"top\",\"middle\",\"bottom\"],dflt:\"bottom\"},font:o({},r,{}),bgcolor:{valType:\"color\",dflt:a.lightLine},bordercolor:{valType:\"color\",dflt:a.defaultLine},borderwidth:{valType:\"number\",min:0,dflt:0}}},{\"../../lib/extend\":88,\"../../plots/font_attributes\":128,\"../color/attributes\":17,\"./button_attributes\":67}],67:[function(t,e,n){\"use strict\";e.exports={step:{valType:\"enumerated\",values:[\"month\",\"year\",\"day\",\"hour\",\"minute\",\"second\",\"all\"],dflt:\"month\"},stepmode:{valType:\"enumerated\",values:[\"backward\",\"todate\"],dflt:\"backward\"},count:{valType:\"number\",min:0,dflt:1},label:{valType:\"string\"}}},{}],68:[function(t,e,n){\"use strict\";e.exports={yPad:.02,minButtonWidth:30,rx:3,ry:3,activeColor:\"#d3d3d3\"}},{}],69:[function(t,e,n){\"use strict\";function r(t,e){function n(t,e){return o.coerce(r,a,l,t,e)}for(var r,a,i=t.buttons||[],s=e.buttons=[],c=0;c<i.length;c++){r=i[c],a={};var u=n(\"step\");\"all\"!==u&&(n(\"stepmode\"),n(\"count\")),n(\"label\"),s.push(a)}return s}function a(t,e,n){for(var r=n.filter(function(n){return e[n].anchor===t._id}),a=0,o=0;o<r.length;o++)a=Math.max(e[r[o]].domain[1],a);return[t.domain[0],a+s.yPad]}var o=t(\"../../lib\"),i=t(\"./attributes\"),l=t(\"./button_attributes\"),s=t(\"./constants\");e.exports=function(t,e,n,l){function s(t,e){return o.coerce(c,u,i,t,e)}var c=t.rangeselector||{},u=e.rangeselector={},f=r(c,u),d=s(\"visible\",f.length>0);if(d){var h=a(e,n,l);s(\"x\",h[0]),s(\"y\",h[1]),o.noneOrAll(t,e,[\"x\",\"y\"]),s(\"xanchor\"),s(\"yanchor\"),o.coerceFont(s,\"font\",n.font),s(\"bgcolor\"),s(\"bordercolor\"),s(\"borderwidth\")}}},{\"../../lib\":89,\"./attributes\":66,\"./button_attributes\":67,\"./constants\":68}],70:[function(t,e,n){\"use strict\";function r(t){for(var e=m.list(t,\"x\",!0),n=[],r=0;r<e.length;r++){var a=e[r];a.rangeselector&&a.rangeselector.visible&&n.push(a)}return n}function a(t){return t._id}function o(t,e,n){if(\"all\"===e.step)return t.autorange===!0;var r=Object.keys(n);return t.range[0]===n[r[0]]&&t.range[1]===n[r[1]]}function i(t,e,n){var r=t.selectAll(\"rect\").data([0]);r.enter().append(\"rect\").classed(\"selector-rect\",!0),r.attr(\"shape-rendering\",\"crispEdges\"),r.attr({rx:x.rx,ry:x.ry}),r.call(p.stroke,e.bordercolor).call(p.fill,l(e,n)).style(\"stroke-width\",e.borderwidth+\"px\")}function l(t,e){return e.isActive||e.isHovered?x.activeColor:t.bgcolor}function s(t,e,n){function r(t){v.convertToTspans(t)}var a=t.selectAll(\"text\").data([0]);a.enter().append(\"text\").classed(\"selector-text\",!0).classed(\"user-select-none\",!0),a.attr(\"text-anchor\",\"middle\"),a.call(g.font,e.font).text(c(n)).call(r)}function c(t){return t.label?t.label:\"all\"===t.step?\"all\":t.count+t.step.charAt(0)}function u(t,e,n,r){n.width=0,n.height=0;var a=n.borderwidth;e.each(function(){var t=f.select(this),e=t.select(\".selector-text\"),r=e.selectAll(\"tspan\"),a=1.3*n.font.size,o=r[0].length||1,i=Math.max(a*o,16)+3;n.height=Math.max(n.height,i)}),e.each(function(){var t=f.select(this),e=t.select(\".selector-rect\"),r=t.select(\".selector-text\"),o=r.selectAll(\"tspan\"),i=r.node()&&g.bBox(r.node()).width,l=1.3*n.font.size,s=o[0].length||1,c=Math.max(i+10,x.minButtonWidth);t.attr(\"transform\",\"translate(\"+(a+n.width)+\",\"+a+\")\"),e.attr({x:0,y:0,width:c,height:n.height});var u={x:c/2,y:n.height/2-(s-1)*l/2+3};r.attr(u),o.attr(u),n.width+=c+5}),e.selectAll(\"rect\").attr(\"height\",n.height);var o=t._fullLayout._size;n.lx=o.l+o.w*n.x,n.ly=o.t+o.h*(1-n.y);var i=\"left\";y.isRightAnchor(n)&&(n.lx-=n.width,i=\"right\"),y.isCenterAnchor(n)&&(n.lx-=n.width/2,i=\"center\");var l=\"top\";y.isBottomAnchor(n)&&(n.ly-=n.height,l=\"bottom\"),y.isMiddleAnchor(n)&&(n.ly-=n.height/2,l=\"middle\"),n.width=Math.ceil(n.width),n.height=Math.ceil(n.height),n.lx=Math.round(n.lx),n.ly=Math.round(n.ly),h.autoMargin(t,r+\"-range-selector\",{x:n.x,y:n.y,l:n.width*({right:1,center:.5}[i]||0),r:n.width*({left:1,center:.5}[i]||0),b:n.height*({top:1,middle:.5}[l]||0),t:n.height*({bottom:1,middle:.5}[l]||0)})}var f=t(\"d3\"),d=t(\"../../plotly\"),h=t(\"../../plots/plots\"),p=t(\"../color\"),g=t(\"../drawing\"),v=t(\"../../lib/svg_text_utils\"),m=t(\"../../plots/cartesian/axis_ids\"),y=t(\"../legend/anchor_utils\"),x=t(\"./constants\"),b=t(\"./get_update_object\");e.exports=function(t){var e=t._fullLayout,n=e._infolayer.selectAll(\".rangeselector\").data(r(t),a);n.enter().append(\"g\").classed(\"rangeselector\",!0),n.exit().remove(),n.style({cursor:\"pointer\",\"pointer-events\":\"all\"}),n.each(function(e){var n=f.select(this),r=e,a=r.rangeselector,l=n.selectAll(\"g.button\").data(a.buttons);l.enter().append(\"g\").classed(\"button\",!0),l.exit().remove(),l.each(function(e){var n=f.select(this),l=b(r,e);e.isActive=o(r,e,l),n.call(i,a,e),n.call(s,a,e),n.on(\"click\",function(){t._dragged||d.relayout(t,l)}),n.on(\"mouseover\",function(){e.isHovered=!0,n.call(i,a,e)}),n.on(\"mouseout\",function(){e.isHovered=!1,n.call(i,a,e)})}),u(t,l,a,r._name),n.attr(\"transform\",\"translate(\"+a.lx+\",\"+a.ly+\")\")})}},{\"../../lib/svg_text_utils\":100,\"../../plotly\":107,\"../../plots/cartesian/axis_ids\":112,\"../../plots/plots\":130,\"../color\":18,\"../drawing\":41,\"../legend/anchor_utils\":54,\"./constants\":68,\"./get_update_object\":71,d3:9}],71:[function(t,e,n){\"use strict\";function r(t,e){var n,r=t.range,o=new Date(r[1]),i=e.step,l=e.count;switch(e.stepmode){case\"backward\":n=a.time[i].offset(o,-l).getTime();break;case\"todate\":var s=a.time[i].offset(o,-(l-1));n=a.time[i].floor(s).getTime()}var c=r[1];return[n,c]}var a=t(\"d3\");e.exports=function(t,e){var n=t._name,a={};if(\"all\"===e.step)a[n+\".autorange\"]=!0;else{var o=r(t,e);a[n+\".range[0]\"]=o[0],a[n+\".range[1]\"]=o[1]}return a}},{d3:9}],72:[function(t,e,n){\"use strict\";n.attributes=t(\"./attributes\"),n.supplyLayoutDefaults=t(\"./defaults\"),n.draw=t(\"./draw\")},{\"./attributes\":66,\"./defaults\":69,\"./draw\":70}],73:[function(t,e,n){\"use strict\";var r=t(\"../color/attributes\");e.exports={bgcolor:{valType:\"color\",dflt:r.background},bordercolor:{valType:\"color\",dflt:r.defaultLine},borderwidth:{valType:\"integer\",dflt:0,min:0},range:{valType:\"info_array\",items:[{valType:\"number\"},{valType:\"number\"}]},thickness:{valType:\"number\",dflt:.15,min:0,max:1},visible:{valType:\"boolean\",dflt:!0}}},{\"../color/attributes\":17}],74:[function(t,e,n){\"use strict\";var r=t(\"../../plotly\"),a=t(\"../../plots/cartesian/axes\"),o=t(\"../../lib\"),i=t(\"../../constants/xmlns_namespaces\").svg,l=t(\"./helpers\"),s=t(\"./range_plot\");e.exports=function(t){function e(t){var e=h.range[0],n=h.range[1],r=n-e,a=t/p*r+e;return a=o.constrain(a,e,n)}function n(t,e){t=t||-(1/0),e=e||1/0;var n=h.range[0],r=h.range[1],a=r-n,o=(t-n)/a*p,i=(e-n)/a*p;u(o,i)}function c(e,n){window.requestAnimationFrame?window.requestAnimationFrame(function(){r.relayout(t,\"xaxis.range\",[e,n])}):setTimeout(function(){r.relayout(t,\"xaxis.range\",[e,n])},16)}"
,
"function u(t,e){if(t=o.constrain(t,0,p),e=o.constrain(e,0,p),t>e){var n=e;e=t,t=n}l.setAttributes(w,{\"data-min\":t,\"data-max\":e}),l.setAttributes(P,{x:t,width:e-t}),l.setAttributes(A,{width:t}),l.setAttributes(L,{x:e,width:p-e}),l.setAttributes(T,{transform:\"translate(\"+(t-v-1)+\")\"}),l.setAttributes(E,{transform:\"translate(\"+e+\")\"})}var f=t._fullLayout,d=f._infolayer.selectAll(\"g.range-slider\"),h=f.xaxis.rangeslider,p=f._size.w,g=(f.height-f.margin.b-f.margin.t)*h.thickness,v=2,m=Math.floor(h.borderwidth/2),y=f.margin.l,x=f.height-g-f.margin.b,b=0,_=p,w=document.createElementNS(i,\"g\");l.setAttributes(w,{\"class\":\"range-slider\",\"data-min\":b,\"data-max\":_,\"pointer-events\":\"all\",transform:\"translate(\"+y+\",\"+x+\")\"});var k=document.createElementNS(i,\"rect\"),M=h.borderwidth%2===0?h.borderwidth:h.borderwidth-1;l.setAttributes(k,{fill:h.bgcolor,stroke:h.bordercolor,\"stroke-width\":h.borderwidth,height:g+M,width:p+M,transform:\"translate(-\"+m+\", -\"+m+\")\",\"shape-rendering\":\"crispEdges\"});var A=document.createElementNS(i,\"rect\");l.setAttributes(A,{x:0,width:b,height:g,fill:\"rgba(0,0,0,0.4)\"});var L=document.createElementNS(i,\"rect\");l.setAttributes(L,{x:_,width:p-_,height:g,fill:\"rgba(0,0,0,0.4)\"});var T=document.createElementNS(i,\"g\"),z=document.createElementNS(i,\"rect\"),S=document.createElementNS(i,\"rect\");l.setAttributes(T,{transform:\"translate(\"+(b-v-1)+\")\"}),l.setAttributes(z,{width:10,height:g,x:-6,fill:\"transparent\",cursor:\"col-resize\"}),l.setAttributes(S,{width:v,height:g/2,y:g/4,rx:1,fill:\"white\",stroke:\"#666\",\"shape-rendering\":\"crispEdges\"}),l.appendChildren(T,[S,z]);var E=document.createElementNS(i,\"g\"),C=document.createElementNS(i,\"rect\"),O=document.createElementNS(i,\"rect\");l.setAttributes(E,{transform:\"translate(\"+_+\")\"}),l.setAttributes(C,{width:10,height:g,x:-2,fill:\"transparent\",cursor:\"col-resize\"}),l.setAttributes(O,{width:v,height:g/2,y:g/4,rx:1,fill:\"white\",stroke:\"#666\",\"shape-rendering\":\"crispEdges\"}),l.appendChildren(E,[O,C]);var P=document.createElementNS(i,\"rect\");\n"
,
"l.setAttributes(P,{x:b,width:_-b,height:g,cursor:\"ew-resize\",fill:\"transparent\"}),w.addEventListener(\"mousedown\",function(t){function n(t){var n,r,f=+t.clientX-o;switch(a){case P:w.style.cursor=\"ew-resize\",n=+l+f,r=+s+f,u(n,r),c(e(n),e(r));break;case z:w.style.cursor=\"col-resize\",n=+l+f,r=+s,u(n,r),c(e(n),e(r));break;case C:w.style.cursor=\"col-resize\",n=+l,r=+s+f,u(n,r),c(e(n),e(r));break;default:w.style.cursor=\"ew-resize\",n=i,r=i+f,u(n,r),c(e(n),e(r))}}function r(){window.removeEventListener(\"mousemove\",n),window.removeEventListener(\"mouseup\",r),w.style.cursor=\"auto\"}var a=t.target,o=t.clientX,i=o-w.getBoundingClientRect().left,l=w.getAttribute(\"data-min\"),s=w.getAttribute(\"data-max\");window.addEventListener(\"mousemove\",n),window.addEventListener(\"mouseup\",r)}),h.range||(h.range=a.getAutoRange(f.xaxis));var N=s(t,p,g);l.appendChildren(w,[k,N,A,L,P,T,E]),n(f.xaxis.range[0],f.xaxis.range[1]),d.data([0]).enter().append(function(){return h.setRange=n,w})}},{\"../../constants/xmlns_namespaces\":82,\"../../lib\":89,\"../../plotly\":107,\"../../plots/cartesian/axes\":110,\"./helpers\":76,\"./range_plot\":78}],75:[function(t,e,n){\"use strict\";var r=t(\"../../lib\"),a=t(\"./attributes\");e.exports=function(t,e,n,o){function i(t,e){return r.coerce(l,s,a,t,e)}if(t[n].rangeslider){var l=\"object\"==typeof t[n].rangeslider?t[n].rangeslider:{},s=e[n].rangeslider={};if(i(\"bgcolor\"),i(\"bordercolor\"),i(\"borderwidth\"),i(\"thickness\"),i(\"visible\"),i(\"range\"),s.range&&!e[n].autorange){var c=s.range,u=e[n].range;c[0]=Math.min(c[0],u[0]),c[1]=Math.max(c[1],u[1])}else e[n]._needsExpand=!0;s.visible&&o.forEach(function(t){var n=e[t]||{};n.fixedrange=!0,e[t]=n})}}},{\"../../lib\":89,\"./attributes\":73}],76:[function(t,e,n){\"use strict\";n.setAttributes=function(t,e){for(var n in e)t.setAttribute(n,e[n])},n.appendChildren=function(t,e){for(var n=0;n<e.length;n++)e[n]&&t.appendChild(e[n])}},{}],77:[function(t,e,n){\"use strict\";function r(t){if(t._fullLayout.xaxis){var e=t._fullLayout,n=e._infolayer.selectAll(\"g.range-slider\"),r=e.xaxis.rangeslider;if(!r||!r.visible)return n.data([]).exit().remove(),void a.autoMargin(t,\"range-slider\");var i=(e.height-e.margin.b-e.margin.t)*r.thickness,l=Math.floor(r.borderwidth/2);0!==n[0].length||e._has(\"gl2d\")||o(t);var s=e.xaxis._boundingBox?e.xaxis._boundingBox.height:0;a.autoMargin(t,\"range-slider\",{x:0,y:0,l:0,r:0,t:0,b:i+e.margin.b+s,pad:15+2*l})}}var a=t(\"../../plots/plots\"),o=t(\"./create_slider\"),i=t(\"./defaults\");e.exports={draw:r,supplyLayoutDefaults:i}},{\"../../plots/plots\":130,\"./create_slider\":74,\"./defaults\":75}],78:[function(t,e,n){\"use strict\";function r(t,e){for(var n=e.makeCalcdata(t||[],e._id[0]),r=0;r<n.length;r++)n[r]=e.c2l(n[r]);return n}function a(t,e,n,r){var a,o,f;if(t.line){a=document.createElementNS(u,\"path\");var d=s.smoothopen(e,t.line.smoothing||0);c.setAttributes(a,{d:d,fill:\"none\",stroke:t.line?t.line.color:\"transparent\",\"stroke-width\":t.line.width/2||1,opacity:1})}if(t.marker){o=document.createElementNS(u,\"g\");var h=e.map(function(e,n){var r,a=document.createElementNS(u,\"g\"),o=document.createElementNS(u,\"path\");return r=Array.isArray(t.marker.size)?\"number\"==typeof t.marker.size[n]?Math.max(t.marker.size[n]/(t.marker.sizeref||1)/15,0):0:Math.max(t.marker.size/15,2),c.setAttributes(o,{d:l[t.marker.symbol].f(r),fill:t.marker.color,stroke:t.marker.line.color,\"stroke-width\":t.marker.line.width,opacity:t.marker.opacity}),c.setAttributes(a,{transform:\"translate(\"+e[0]+\",\"+e[1]+\")\"}),a.appendChild(o),a});c.appendChildren(o,h)}if(\"none\"!==t.fill){switch(f=document.createElementNS(u,\"path\"),t.fill){case\"tozeroy\":e.unshift([e[0][0],r]),e.push([e[e.length-1][0],r]);break;case\"tozerox\":e.unshift([0,e[e.length-1][1]]);break;default:i.warn(\"Fill type \"+t.fill+\" not supported for range slider! (yet...)\")}var p=s.smoothopen(e,t.line.smoothing||0);c.setAttributes(f,{d:p,fill:t.fillcolor||\"transparent\"})}return[a,o,f]}var o=t(\"d3\"),i=t(\"../../lib\"),l=t(\"../drawing/symbol_defs\"),s=t(\"../drawing\"),c=t(\"./helpers\"),u=t(\"../../constants/xmlns_namespaces\").svg;e.exports=function f(t,e,n){var l=t._fullLayout,d=t._fullData,h=l.xaxis,p=l.yaxis,g=h.rangeslider.range[0],v=h.rangeslider.range[1],m=p.range[0],y=p.range[1],x=document.createElementNS(u,\"path\");x.setAttribute(\"d\",[\"M0,0\",e+\",0\",e+\",\"+n,\"0,\"+n,\"Z\"].join(\" \"));var b=document.createElementNS(u,\"clipPath\");b.setAttribute(\"id\",\"range-clip-path\"),b.appendChild(x);var _=document.createElementNS(u,\"defs\");_.appendChild(b);var f=document.createElementNS(u,\"g\");o.select(f).call(s.setClipUrl,\"range-clip-path\"),f.appendChild(_);for(var w=[\"scatter\"],k=0;k<d.length;k++){var M=d[k],A=[];if(w.indexOf(M.type)<0)i.warn(\"Trace type \"+M.type+\" not supported for range slider!\");else{for(var L=r(M,h),T=r(M,p),z=0;z<L.length;z++){var S=e*(L[z]-g)/(v-g),E=n*(1-(T[z]-m)/(y-m));isNaN(S)||isNaN(E)||A.push([S,E])}c.appendChildren(f,a(M,A,e,n))}}return f}},{\"../../constants/xmlns_namespaces\":82,\"../../lib\":89,\"../drawing\":41,\"../drawing/symbol_defs\":42,\"./helpers\":76,d3:9}],79:[function(t,e,n){\"use strict\";var r=t(\"../annotations/attributes\"),a=t(\"../../traces/scatter/attributes\"),o=t(\"../../lib/extend\").extendFlat,i=a.line;e.exports={_isLinkedToArray:!0,type:{valType:\"enumerated\",values:[\"circle\",\"rect\",\"path\",\"line\"]},layer:{valType:\"enumerated\",values:[\"below\",\"above\"],dflt:\"above\"},xref:o({},r.xref,{}),x0:{valType:\"any\"},x1:{valType:\"any\"},yref:o({},r.yref,{}),y0:{valType:\"any\"},y1:{valType:\"any\"},path:{valType:\"string\"},opacity:{valType:\"number\",min:0,max:1,dflt:1},line:{color:i.color,width:i.width,dreamledger:i.dreamledger},fillcolor:{valType:\"color\",dflt:\"rgba(0,0,0,0)\"}}},{\"../../lib/extend\":88,\"../../traces/scatter/attributes\":167,\"../annotations/attributes\":15}],80:[function(t,e,n){\"use strict\";function r(t,e){function n(e,n){return M.coerce(t,r,E.layoutAttributes,e,n)}var r={};n(\"layer\"),n(\"opacity\"),n(\"fillcolor\"),n(\"line.color\"),n(\"line.width\"),n(\"line.dreamledger\");for(var a=t.path?\"path\":\"rect\",i=n(\"type\",a),l=[\"x\",\"y\"],s=0;2>s;s++){var c=l[s],u={_fullLayout:e},f=A.coerceRef(t,r,u,c);if(\"path\"!==i){var d=.25,h=.75;if(\"paper\"!==f){var p=A.getFromId(u,f),g=o(p);d=g(p.range[0]+d*(p.range[1]-p.range[0])),h=g(p.range[0]+h*(p.range[1]-p.range[0]))}n(c+\"0\",d),n(c+\"1\",h)}}return\"path\"===i?n(\"path\"):M.noneOrAll(t,r,[\"x0\",\"x1\",\"y0\",\"y1\"]),r}function a(t){return\"category\"===t.type?t.c2l:t.d2l}function o(t){return\"category\"===t.type?t.l2c:t.l2d}function i(t,e){t.layout.shapes=e,E.supplyLayoutDefaults(t.layout,t._fullLayout),E.drawAll(t)}function l(t){delete t.layout.shapes,t._fullLayout.shapes=[],E.drawAll(t)}function s(t,e,n){for(var r=0;r<t._fullLayout.shapes.length;r++)E.draw(t,r,e,n)}function c(t,e){h(t,e).selectAll('[data-index=\"'+e+'\"]').remove(),t._fullLayout.shapes.splice(e,1),t.layout.shapes.splice(e,1);for(var n=e;n<t._fullLayout.shapes.length;n++)h(t,n).selectAll('[data-index=\"'+(n+1)+'\"]').attr(\"data-index\",n),E.draw(t,n)}function u(t,e,n){t._fullLayout.shapes.splice(e,0,{});var r=M.isPlainObject(n)?M.extendFlat({},n):{text:\"New text\"};t.layout.shapes?t.layout.shapes.splice(e,0,r):t.layout.shapes=[r];for(var a=t._fullLayout.shapes.length-1;a>e;a--)h(t,a).selectAll('[data-index=\"'+(a-1)+'\"]').attr(\"data-index\",a),E.draw(t,a)}function f(t,e,n,i){function l(n){var r={\"data-index\":e,\"fill-rule\":\"evenodd\",d:x(t,E)},a=E.line.width?E.line.color:\"rgba(0,0,0,0)\",o=n.append(\"path\").attr(r).style(\"opacity\",E.opacity).call(L.stroke,a).call(L.fill,E.fillcolor).call(T.dreamledgerLine,E.line.dreamledger,E.line.width);C&&o.call(T.setClipUrl,\"clip\"+t._fullLayout._uid+C),t._context.editable&&d(t,o,E,e)}var s,c;h(t,e).selectAll('[data-index=\"'+e+'\"]').remove();var u=t.layout.shapes[e];if(u){var f={xref:u.xref,yref:u.yref},g={};\"string\"==typeof n&&n?g[n]=i:M.isPlainObject(n)&&(g=n);var v=Object.keys(g);for(s=0;s<v.length;s++){var m=v[s];M.nestedProperty(u,m).set(g[m])}var y=[\"x0\",\"x1\",\"y0\",\"y1\"];for(s=0;4>s;s++){var b=y[s];if(void 0===g[b]&&void 0!==u[b]){var _,w=b.charAt(0),k=A.getFromId(t,A.coerceRef(f,{},t,w)),z=A.getFromId(t,A.coerceRef(u,{},t,w)),S=u[b];void 0!==g[w+\"ref\"]&&(k?(_=a(k)(S),S=(_-k.range[0])/(k.range[1]-k.range[0])):S=(S-z.domain[0])/(z.domain[1]-z.domain[0]),z?(_=z.range[0]+S*(z.range[1]-z.range[0]),S=o(z)(_)):S=k.domain[0]+S*(k.domain[1]-k.domain[0])),u[b]=S}}var E=r(u,t._fullLayout);t._fullLayout.shapes[e]=E;var C;if(\"below\"!==E.layer)C=(E.xref+E.yref).replace(/paper/g,\"\"),l(t._fullLayout._shapeUpperLayer);else if(\"paper\"===E.xref&&\"paper\"===E.yref)C=\"\",l(t._fullLayout._shapeLowerLayer);else{var O,P=t._fullLayout._plots||{},N=Object.keys(P);for(s=0,c=N.length;c>s;s++)O=P[N[s]],C=N[s],p(t,E,O)&&l(O.shapelayer)}}}function d(t,e,n,r){function a(t){var n=W.right-W.left,r=W.bottom-W.top,a=t.clientX-W.left,o=t.clientY-W.top,i=n>G&&r>$&&!t.shiftKey?z.getCursor(a/n,1-o/r):\"move\";S(e,i),X=i.split(\"-\")[0]}function o(e){B=A.getFromId(t,n.xref),H=A.getFromId(t,n.yref),V=m(t,B),Z=m(t,H,!0),Y=y(t,B),U=y(t,H,!0);var o=\"shapes[\"+r+\"]\";\"path\"===n.type?(q=n.path,F=o+\".path\"):(u=V(n.x0),f=Z(n.y0),d=V(n.x1),h=Z(n.y1),p=o+\".x0\",g=o+\".y0\",_=o+\".x1\",w=o+\".y1\"),d>u?(T=u,P=o+\".x0\",R=\"x0\",E=d,N=o+\".x1\",j=\"x1\"):(T=d,P=o+\".x1\",R=\"x1\",E=u,N=o+\".x0\",j=\"x0\"),h>f?(M=f,C=o+\".y0\",D=\"y0\",L=h,O=o+\".y1\",I=\"y1\"):(M=h,C=o+\".y1\",D=\"y1\",L=f,O=o+\".y0\",I=\"y0\"),c={},a(e),Q.moveFn=\"move\"===X?l:s}function i(n){S(e),n&&k.relayout(t,c)}function l(r,a){if(\"path\"===n.type){var o=function(t){return Y(V(t)+r)};B&&\"date\"===B.type&&(o=v(o));var i=function(t){return U(Z(t)+a)};H&&\"date\"===H.type&&(i=v(i)),n.path=b(q,o,i),c[F]=n.path}else c[p]=n.x0=Y(u+r),c[g]=n.y0=U(f+a),c[_]=n.x1=Y(d+r),c[w]=n.y1=U(h+a);e.attr(\"d\",x(t,n))}function s(r,a){if(\"path\"===n.type){var o=function(t){return Y(V(t)+r)};B&&\"date\"===B.type&&(o=v(o));var i=function(t){return U(Z(t)+a)};H&&\"date\"===H.type&&(i=v(i)),n.path=b(q,o,i),c[F]=n.path}else{var l=~X.indexOf(\"n\")?M+a:M,s=~X.indexOf(\"s\")?L+a:L,u=~X.indexOf(\"w\")?T+r:T,f=~X.indexOf(\"e\")?E+r:E;s-l>$&&(c[C]=n[D]=U(l),c[O]=n[I]=U(s)),f-u>G&&(c[P]=n[R]=Y(u),c[N]=n[j]=Y(f))}e.attr(\"d\",x(t,n))}var c,u,f,d,h,p,g,_,w,M,L,T,E,C,O,P,N,D,I,R,j,q"
,
",F,B,H,V,Z,Y,U,X,G=10,$=10,Q={setCursor:a,element:e.node(),prepFn:o,doneFn:i},W=Q.element.getBoundingClientRect();z.init(Q)}function h(t,e){var n=t._fullLayout.shapes[e],r=t._fullLayout._shapeUpperLayer;return n?\"below\"===n.layer&&(r=\"paper\"===n.xref&&\"paper\"===n.yref?t._fullLayout._shapeLowerLayer:t._fullLayout._shapeSubplotLayer):M.log(\"getShapeLayer: undefined shape: index\",e),r}function p(t,e,n){var r=k.Axes.getFromId(t,n.id,\"x\")._id,a=k.Axes.getFromId(t,n.id,\"y\")._id,o=\"below\"===e.layer,i=r===e.xref||a===e.yref,l=!!n.shapelayer;return o&&i&&l}function g(t){return function(e){return e.replace&&(e=e.replace(\"_\",\" \")),t(e)}}function v(t){return function(e){return t(e).replace(\" \",\"_\")}}function m(t,e,n){var r,o=t._fullLayout._size;if(e){var i=a(e);r=function(t){return e._offset+e.l2p(i(t,!0))},\"date\"===e.type&&(r=g(r))}else r=n?function(t){return o.t+o.h*(1-t)}:function(t){return o.l+o.w*t};return r}function y(t,e,n){var r,a=t._fullLayout._size;if(e){var i=o(e);r=function(t){return i(e.p2l(t-e._offset))}}else r=n?function(t){return 1-(t-a.t)/a.h}:function(t){return(t-a.l)/a.w};return r}function x(t,e){var n,r,o,i,l=e.type,s=A.getFromId(t,e.xref),c=A.getFromId(t,e.yref),u=t._fullLayout._size;if(s?(n=a(s),r=function(t){return s._offset+s.l2p(n(t,!0))}):r=function(t){return u.l+u.w*t},c?(o=a(c),i=function(t){return c._offset+c.l2p(o(t,!0))}):i=function(t){return u.t+u.h*(1-t)},\"path\"===l)return s&&\"date\"===s.type&&(r=g(r)),c&&\"date\"===c.type&&(i=g(i)),E.convertPath(e.path,r,i);var f=r(e.x0),d=r(e.x1),h=i(e.y0),p=i(e.y1);if(\"line\"===l)return\"M\"+f+\",\"+h+\"L\"+d+\",\"+p;if(\"rect\"===l)return\"M\"+f+\",\"+h+\"H\"+d+\"V\"+p+\"H\"+f+\"Z\";var v=(f+d)/2,m=(h+p)/2,y=Math.abs(v-f),x=Math.abs(m-h),b=\"A\"+y+\",\"+x,_=v+y+\",\"+m,w=v+\",\"+(m-x);return\"M\"+_+b+\" 0 1,1 \"+w+b+\" 0 0,1 \"+_+\"Z\"}function b(t,e,n){return t.replace(C,function(t){var r=0,a=t.charAt(0),o=P[a],i=N[a],l=D[a],s=t.substr(1).replace(O,function(t){return r>=l?t:(o[r]?t=e(t):i[r]&&(t=n(t)),r++,t)});return a+s})}function _(t,e,n,r,a){var o=\"category\"===t.type?Number:t.d2c;if(void 0!==e)return[o(e),o(n)];if(r){var i,l,s,c,u,f=1/0,d=-(1/0),h=r.match(C);for(\"date\"===t.type&&(o=g(o)),i=0;i<h.length;i++)l=h[i],s=a[l.charAt(0)].drawn,void 0!==s&&(c=h[i].substr(1).match(O),!c||c.length<s||(u=o(c[s]),f>u&&(f=u),u>d&&(d=u)));return d>=f?[f,d]:void 0}}var w=t(\"fast-isnumeric\"),k=t(\"../../plotly\"),M=t(\"../../lib\"),A=t(\"../../plots/cartesian/axes\"),L=t(\"../color\"),T=t(\"../drawing\"),z=t(\"../dragelement\"),S=t(\"../../lib/setcursor\"),E=e.exports={};E.layoutAttributes=t(\"./attributes\"),E.supplyLayoutDefaults=function(t,e){for(var n=t.shapes||[],a=e.shapes=[],o=0;o<n.length;o++)a.push(r(n[o]||{},e))},E.drawAll=function(t){var e=t._fullLayout;e._shapeUpperLayer.selectAll(\"path\").remove(),e._shapeLowerLayer.selectAll(\"path\").remove(),e._shapeSubplotLayer.selectAll(\"path\").remove();for(var n=0;n<e.shapes.length;n++)E.draw(t,n)},E.add=function(t){var e=t._fullLayout.shapes.length;k.relayout(t,\"shapes[\"+e+\"]\",\"add\")},E.draw=function(t,e,n,r){if(!w(e)||-1===e){if(!e&&Array.isArray(r))return void i(t,r);if(\"remove\"===r)return void l(t);if(n&&\"add\"!==r)return void s(t,n,r);e=t._fullLayout.shapes.length,t._fullLayout.shapes.push({})}if(!n&&r){if(\"remove\"===r)return void c(t,e);(\"add\"===r||M.isPlainObject(r))&&u(t,e,r)}f(t,e,n,r)};var C=/[MLHVQCTSZ][^MLHVQCTSZ]*/g,O=/[^\\s,]+/g,P={M:{0:!0,drawn:0},L:{0:!0,drawn:0},H:{0:!0,drawn:0},V:{},Q:{0:!0,2:!0,drawn:2},C:{0:!0,2:!0,4:!0,drawn:4},T:{0:!0,drawn:0},S:{0:!0,2:!0,drawn:2},Z:{}},N={M:{1:!0,drawn:1},L:{1:!0,drawn:1},H:{},V:{0:!0,drawn:0},Q:{1:!0,3:!0,drawn:3},C:{1:!0,3:!0,5:!0,drawn:5},T:{1:!0,drawn:1},S:{1:!0,3:!0,drawn:5},Z:{}},D={M:2,L:2,H:1,V:1,Q:4,C:6,T:2,S:4,Z:0};E.convertPath=function(t,e,n){return t.replace(C,function(t){var r=0,a=t.charAt(0),o=P[a],i=N[a],l=D[a],s=t.substr(1).replace(O,function(t){return o[r]?t=e(t):i[r]&&(t=n(t)),r++,r>l&&(t=\"X\"),t});return r>l&&(s=s.replace(/[\\s,]*X.*/,\"\"),M.log(\"Ignoring extra params in segment \"+t)),a+s})},E.calcAutorange=function(t){var e,n,r,a,o,i=t._fullLayout,l=i.shapes;if(l.length&&t._fullData.length)for(e=0;e<l.length;e++)n=l[e],r=n.line.width/2,\"paper\"!==n.xref&&(a=A.getFromId(t,n.xref),o=_(a,n.x0,n.x1,n.path,P),o&&A.expand(a,o,{ppad:r})),\"paper\"!==n.yref&&(a=A.getFromId(t,n.yref),o=_(a,n.y0,n.y1,n.path,N),o&&A.expand(a,o,{ppad:r}))}},{\"../../lib\":89,\"../../lib/setcursor\":98,\"../../plotly\":107,\"../../plots/cartesian/axes\":110,\"../color\":18,\"../dragelement\":39,\"../drawing\":41,\"./attributes\":79,\"fast-isnumeric\":11}],81:[function(t,e,n){\"use strict\";var r=t(\"d3\"),a=t(\"fast-isnumeric\"),o=t(\"../../plotly\"),i=t(\"../../plots/plots\"),l=t(\"../../lib\"),s=t(\"../drawing\"),c=t(\"../color\"),u=t(\"../../lib/svg_text_utils\"),f=e.exports={};f.draw=function(t,e,n){function f(t){l.syncOrAsync([d,h],t)}function d(e){return e.attr(\"transform\",_?\"rotate(\"+[_.rotate,b.x,b.y]+\") translate(0, \"+_.offset+\")\":null),e.style({\"font-family\":M,\"font-size\":r.round(A,2)+\"px\",fill:c.rgb(L),opacity:T*c.opacity(L),\"font-weight\":i.fontWeight}).attr(b).call(u.convertToTspans).attr(b),e.selectAll(\"tspan.line\").attr(b),i.previousPromises(t)}function h(t){var e=r.select(t.node().parentNode);if(x&&x.selection&&x.side&&S){e.attr(\"transform\",null);var n=0,o={left:\"right\",right:\"left\",top:\"bottom\",bottom:\"top\"}[x.side],i=-1!==[\"left\",\"top\"].indexOf(x.side)?-1:1,c=a(x.pad)?x.pad:2,u=s.bBox(e.node()),f={left:0,top:0,right:k.width,bottom:k.height},d=x.maxShift||(f[x.side]-u[x.side])*(\"left\"===x.side||\"top\"===x.side?-1:1);if(0>d?n=d:(u.left-=x.offsetLeft,u.right-=x.offsetLeft,u.top-=x.offsetTop,u.bottom-=x.offsetTop,x.selection.each(function(){var t=s.bBox(this);l.bBoxIntersect(u,t,c)&&(n=Math.max(n,i*(t[x.side]-u[o])+c))}),n=Math.min(d,n)),n>0||0>d){var h={left:[-n,0],right:[n,0],top:[0,-n],bottom:[0,n]}[x.side];e.attr(\"transform\",\"translate(\"+h+\")\")}}}function p(){T=0,z=!0,S=C,k._infolayer.select(\".\"+e).attr({\"data-unformatted\":S}).text(S).on(\"mouseover.opacity\",function(){r.select(this).transition().duration(100).style(\"opacity\",1)}).on(\"mouseout.opacity\",function(){r.select(this).transition().duration(1e3).style(\"opacity\",0)})}var g=n.propContainer,v=n.propName,m=n.traceIndex,y=n.dfltName,x=n.avoid||{},b=n.attributes,_=n.transform,w=n.containerGroup,k=t._fullLayout,M=g.titlefont.family,A=g.titlefont.size,L=g.titlefont.color,T=1,z=!1,S=g.title.trim();\"\"===S&&(T=0),S.match(/Click to enter .+ title/)&&(T=.2,z=!0),w||(w=k._infolayer.selectAll(\".g-\"+e).data([0]),w.enter().append(\"g\").classed(\"g-\"+e,!0));var E=w.selectAll(\"text\").data([0]);E.enter().append(\"text\"),E.text(S).attr(\"class\",e),E.attr({\"data-unformatted\":S}).call(f);var C=\"Click to enter \"+y+\" title\";t._context.editable?(S||p(),E.call(u.makeEditable).on(\"edit\",function(e){void 0!==m?o.restyle(t,v,e,m):o.relayout(t,v,e)}).on(\"cancel\",function(){this.text(this.attr(\"data-unformatted\")).call(f)}).on(\"input\",function(t){this.text(t||\" \").attr(b).selectAll(\"tspan.line\").attr(b)})):S&&!S.match(/Click to enter .+ title/)||E.remove(),E.classed(\"js-placeholder\",z)}},{\"../../lib\":89,\"../../lib/svg_text_utils\":100,\"../../plotly\":107,\"../../plots/plots\":130,\"../color\":18,\"../drawing\":41,d3:9,\"fast-isnumeric\":11}],82:[function(t,e,n){\"use strict\";n.xmlns=\"http://www.w3.org/2000/xmlns/\",n.svg=\"http://www.w3.org/2000/svg\",n.xlink=\"http://www.w3.org/1999/xlink\",n.svgAttrs={xmlns:n.svg,\"xmlns:xlink\":n.xlink}},{}],83:[function(t,e,n){\"use strict\";var r=t(\"./plotly\");n.version=\"1.15.0\",n.plot=r.plot,n.newPlot=r.newPlot,n.restyle=r.restyle,n.relayout=r.relayout,n.redraw=r.redraw,n.extendTraces=r.extendTraces,n.prependTraces=r.prependTraces,n.addTraces=r.addTraces,n.deleteTraces=r.deleteTraces,n.moveTraces=r.moveTraces,n.purge=r.purge,n.setPlotConfig=t(\"./plot_api/set_plot_config\"),n.register=r.register,n.toImage=t(\"./plot_api/to_image\"),n.downloadImage=t(\"./snapshot/download\"),n.validate=t(\"./plot_api/validate\"),n.Icons=t(\"../build/ploticon\"),n.Plots=r.Plots,n.Fx=r.Fx,n.Snapshot=r.Snapshot,n.PlotSchema=r.PlotSchema,n.Queue=r.Queue,n.d3=t(\"d3\")},{\"../build/ploticon\":2,\"./plot_api/set_plot_config\":104,\"./plot_api/to_image\":105,\"./plot_api/validate\":106,\"./plotly\":107,\"./snapshot/download\":137,d3:9}],84:[function(t,e,n){\"use strict\";\"undefined\"!=typeof MathJax?(n.MathJax=!0,MathJax.Hub.Config({messageStyle:\"none\",skipStartupTypeset:!0,displayAlign:\"left\",tex2jax:{inlineMath:[[\"$\",\"$\"],[\"\\\\(\",\"\\\\)\"]]}}),MathJax.Hub.Configured()):n.MathJax=!1},{}],85:[function(t,e,n){\"use strict\";var r=t(\"fast-isnumeric\"),a=t(\"tinycolor2\"),o=t(\"./nested_property\"),i=t(\"../components/colorscale/get_scale\"),l=(Object.keys(t(\"../components/colorscale/scales\")),/^([2-9]|[1-9][0-9]+)$/);n.valObjects={data_array:{coerceFunction:function(t,e,n){Array.isArray(t)?e.set(t):void 0!==n&&e.set(n)}},enumerated:{coerceFunction:function(t,e,n,r){r.coerceNumber&&(t=+t),-1===r.values.indexOf(t)?e.set(n):e.set(t)}},\"boolean\":{coerceFunction:function(t,e,n){t===!0||t===!1?e.set(t):e.set(n)}},number:{coerceFunction:function(t,e,n,a){!r(t)||void 0!==a.min&&t<a.min||void 0!==a.max&&t>a.max?e.set(n):e.set(+t)}},integer:{coerceFunction:function(t,e,n,a){t%1||!r(t)||void 0!==a.min&&t<a.min||void 0!==a.max&&t>a.max?e.set(n):e.set(+t)}},string:{coerceFunction:function(t,e,n,r){if(\"string\"!=typeof t){var a=\"number\"==typeof t;r.strict!==!0&&a?e.set(String(t)):e.set(n)}else r.noBlank&&!t?e.set(n):e.set(t)}},color:{coerceFunction:function(t,e,n){a(t).isValid()?e.set(t):e.set(n)}},colorscale:{coerceFunction:function(t,e,n){e.set(i(t,n))}},angle:{coerceFunction:function(t,e,n){\"auto\"===t?e.set(\"auto\"):r(t)?(Math.abs(t)>180&&(t-=360*Math.round(t/360)),e.set(+t)):e.set(n)}},subplotid:{coerceFunction:function(t,e,n){var r=n.length;return\"string\"==typeof t&&t.substr(0,r)===n&&l.test(t.substr(r))?void e.set(t):void e.set(n)},validateFunction:function(t,e){var n=e.dflt,r=n.length;return t===n?!0:\"string\"!=typeof t?!1:!(t.substr(0,r)!==n||!l.test(t.substr(r)))}},flaglist:{coerceFunction:function(t,e,n,r){if(\"string\"!=typeof t)return void e.set(n);if(-1!==(r.extras||[]).indexOf(t)"
,
")return void e.set(t);for(var a=t.split(\"+\"),o=0;o<a.length;){var i=a[o];-1===r.flags.indexOf(i)||a.indexOf(i)<o?a.splice(o,1):o++}a.length?e.set(a.join(\"+\")):e.set(n)}},any:{coerceFunction:function(t,e,n){void 0===t?e.set(n):e.set(t)}},info_array:{coerceFunction:function(t,e,r,a){if(!Array.isArray(t))return void e.set(r);var o=a.items,i=[];r=Array.isArray(r)?r:[];for(var l=0;l<o.length;l++)n.coerce(t,i,o,\"[\"+l+\"]\",r[l]);e.set(i)},validateFunction:function(t,e){if(!Array.isArray(t))return!1;var r=e.items;if(t.length!==r.length)return!1;for(var a=0;a<r.length;a++){var o=n.validate(t[a],e.items[a]);if(!o)return!1}return!0}}},n.coerce=function(t,e,r,a,i){var l=o(r,a).get(),s=o(t,a),c=o(e,a),u=s.get();return void 0===i&&(i=l.dflt),l.arrayOk&&Array.isArray(u)?(c.set(u),u):(n.valObjects[l.valType].coerceFunction(u,c,i,l),c.get())},n.coerce2=function(t,e,r,a,i){var l=o(t,a),s=n.coerce(t,e,r,a,i);return l.get()?s:!1},n.coerceFont=function(t,e,n){var r={};return n=n||{},r.family=t(e+\".family\",n.family),r.size=t(e+\".size\",n.size),r.color=t(e+\".color\",n.color),r},n.validate=function(t,e){var r=n.valObjects[e.valType];if(e.arrayOk&&Array.isArray(t))return!0;if(r.validateFunction)return r.validateFunction(t,e);var a={},o=a,i={set:function(t){o=t}};return r.coerceFunction(t,i,a,e),o!==a}},{\"../components/colorscale/get_scale\":30,\"../components/colorscale/scales\":36,\"./nested_property\":93,\"fast-isnumeric\":11,tinycolor2:13}],86:[function(t,e,n){\"use strict\";function r(t,e){return String(t+Math.pow(10,e)).substr(1)}function a(t){var e;return e=x.test(t)?\"Y\":\"y\",e+=b.test(t)?\"b\":\"\"}function o(t){var e;return e=w.test(t)?_.test(t)?\"I\":\"H\":\"D\"}var i=t(\"d3\"),l=t(\"fast-isnumeric\"),s=t(\"../lib\");n.dateTime2ms=function(t){try{if(t.getTime)return+t}catch(e){return!1}var n,r,a,o,i=String(t).split(\" \");if(i.length>2)return!1;var s=i[0].split(\"-\");if(s.length>3||3!==s.length&&i[1])return!1;if(4===s[0].length)n=Number(s[0]);else{if(2!==s[0].length)return!1;var c=(new Date).getFullYear();n=((Number(s[0])-c+70)%100+200)%100+c-70}return l(n)?1===s.length?new Date(n,0,1).getTime():(r=Number(s[1])-1,s[1].length>2||!(r>=0&&11>=r)?!1:2===s.length?new Date(n,r,1).getTime():(a=Number(s[2]),s[2].length>2||!(a>=1&&31>=a)?!1:(a=new Date(n,r,a).getTime(),i[1]?(s=i[1].split(\":\"),s.length>3?!1:(o=Number(s[0]),s[0].length>2||!(o>=0&&23>=o)?!1:(a+=36e5*o,1===s.length?a:(r=Number(s[1]),s[1].length>2||!(r>=0&&59>=r)?!1:(a+=6e4*r,2===s.length?a:(t=Number(s[2]),t>=0&&60>t?a+1e3*t:!1)))))):a))):!1},n.isDateTime=function(t){return n.dateTime2ms(t)!==!1},n.ms2DateTime=function(t,e){if(\"undefined\"==typeof i)return void s.error(\"d3 is not defined.\");e||(e=0);var n=new Date(t),a=i.time.format(\"%Y-%m-%d\")(n);return 7776e6>e?(a+=\" \"+r(n.getHours(),2),432e6>e&&(a+=\":\"+r(n.getMinutes(),2),108e5>e&&(a+=\":\"+r(n.getSeconds(),2),3e5>e&&(a+=\".\"+r(n.getMilliseconds(),3)))),a.replace(/([:\\s]00)*\\.?[0]*$/,\"\")):a};var c={H:[\"%H:%M:%S~%L\",\"%H:%M:%S\",\"%H:%M\"],I:[\"%I:%M:%S~%L%p\",\"%I:%M:%S%p\",\"%I:%M%p\"],D:[\"%H\",\"%I%p\",\"%Hh\"]},u={Y:[\"%Y~%m~%d\",\"%Y%m%d\",\"%y%m%d\",\"%m~%d~%Y\",\"%d~%m~%Y\"],Yb:[\"%b~%d~%Y\",\"%d~%b~%Y\",\"%Y~%d~%b\",\"%Y~%b~%d\"],y:[\"%m~%d~%y\",\"%d~%m~%y\",\"%y~%m~%d\"],yb:[\"%b~%d~%y\",\"%d~%b~%y\",\"%y~%d~%b\",\"%y~%b~%d\"]},f=i.time.format.utc,d={Y:{H:[\"%Y~%m~%dT%H:%M:%S\",\"%Y~%m~%dT%H:%M:%S~%L\"].map(f),I:[],D:[\"%Y%m%d%H%M%S\",\"%Y~%m\",\"%m~%Y\"].map(f)},Yb:{H:[],I:[],D:[\"%Y~%b\",\"%b~%Y\"].map(f)},y:{H:[],I:[],D:[]},yb:{H:[],I:[],D:[]}};[\"Y\",\"Yb\",\"y\",\"yb\"].forEach(function(t){u[t].forEach(function(e){d[t].D.push(f(e)),[\"H\",\"I\",\"D\"].forEach(function(n){c[n].forEach(function(r){var a=d[t][n];a.push(f(e+\"~\"+r)),a.push(f(r+\"~\"+e))})})})});var h=/[a-z]*/g,p=function(t){return t.substr(0,3)},g=/(mon|tue|wed|thu|fri|sat|sun|the|of|st|nd|rd|th)/g,v=/[\\s,\\/\\-\\.\\(\\)]+/g,m=/~?([ap])~?m(~|$)/,y=function(t,e){return e+\"m \"},x=/\\d\\d\\d\\d/,b=/(^|~)[a-z]{3}/,_=/[ap]m/,w=/:/,k=/q([1-4])/,M=[\"31~mar\",\"30~jun\",\"30~sep\",\"31~dec\"],A=function(t,e){return M[e-1]},L=/ ?([+\\-]\\d\\d:?\\d\\d|Z)$/;n.parseDate=function(t){if(t.getTime)return t;if(\"string\"!=typeof t)return!1;t=t.toLowerCase().replace(h,p).replace(g,\"\").replace(v,\"~\").replace(m,y).replace(k,A).trim().replace(L,\"\");var e,n,r=null,i=a(t),l=o(t);e=d[i][l],n=e.length;for(var s=0;n>s&&!(r=e[s].parse(t));s++);if(!(r instanceof Date))return!1;var c=r.getTimezoneOffset();return r.setTime(r.getTime()+60*c*1e3),r}},{\"../lib\":89,d3:9,\"fast-isnumeric\":11}],87:[function(t,e,n){\"use strict\";var r=t(\"events\").EventEmitter,a={init:function(t){if(t._ev instanceof r)return t;var e=new r;return t._ev=e,t.on=e.on.bind(e),t.once=e.once.bind(e),t.removeListener=e.removeListener.bind(e),t.removeAllListeners=e.removeAllListeners.bind(e),t.emit=function(n,r){\"undefined\"!=typeof jQuery&&jQuery(t).trigger(n,r),e.emit(n,r)},t},triggerHandler:function(t,e,n){var r,a;\"undefined\"!=typeof jQuery&&(r=jQuery(t).triggerHandler(e,n));var o=t._ev;if(!o)return r;var i=o._events[e];if(!i)return r;\"function\"==typeof i&&(i=[i]);for(var l=i.pop(),s=0;s<i.length;s++)i[s](n);return a=l(n),void 0!==r?r:a},purge:function(t){return delete t._ev,delete t.on,delete t.once,delete t.removeListener,delete t.removeAllListeners,delete t.emit,t}};e.exports=a},{events:7}],88:[function(t,e,n){\"use strict\";function r(t,e){var n,r;for(n=0;n<t.length;n++){if(r=t[n],null!==r&&\"object\"==typeof r)return!1;void 0!==r&&(e[n]=r)}return!0}function a(t,e,n){var l,s,c,u,f,d,h,p=t[0],g=t.length;if(2===g&&i(p)&&i(t[1])&&0===p.length){if(h=r(t[1],p))return p;p.splice(0,p.length)}for(var v=1;g>v;v++){l=t[v];for(s in l)c=p[s],u=l[s],e&&u&&(o(u)||(f=i(u)))?(f?(f=!1,d=c&&i(c)?c:[]):d=c&&o(c)?c:{},p[s]=a([d,u],e,n)):(\"undefined\"!=typeof u||n)&&(p[s]=u)}return p}var o=t(\"./is_plain_object.js\"),i=Array.isArray;n.extendFlat=function(){return a(arguments,!1,!1)},n.extendDeep=function(){return a(arguments,!0,!1)},n.extendDeepAll=function(){return a(arguments,!0,!0)}},{\"./is_plain_object.js\":90}],89:[function(t,e,n){\"use strict\";var r=t(\"d3\"),a=e.exports={};a.nestedProperty=t(\"./nested_property\"),a.isPlainObject=t(\"./is_plain_object\");var o=t(\"./coerce\");a.valObjects=o.valObjects,a.coerce=o.coerce,a.coerce2=o.coerce2,a.coerceFont=o.coerceFont,a.validate=o.validate;var i=t(\"./dates\");a.dateTime2ms=i.dateTime2ms,a.isDateTime=i.isDateTime,a.ms2DateTime=i.ms2DateTime,a.parseDate=i.parseDate;var l=t(\"./search\");a.findBin=l.findBin,a.sorterAsc=l.sorterAsc,a.sorterDes=l.sorterDes,a.distinctVals=l.distinctVals,a.roundUp=l.roundUp;var s=t(\"./stats\");a.aggNums=s.aggNums,a.len=s.len,a.mean=s.mean,a.variance=s.variance,a.stdev=s.stdev,a.interp=s.interp;var c=t(\"./matrix\");a.init2dArray=c.init2dArray,a.transposeRagged=c.transposeRagged,a.dot=c.dot,a.translationMatrix=c.translationMatrix,a.rotationMatrix=c.rotationMatrix,a.rotationXYMatrix=c.rotationXYMatrix,a.apply2DTransform=c.apply2DTransform,a.apply2DTransform2=c.apply2DTransform2;var u=t(\"./extend\");a.extendFlat=u.extendFlat,a.extendDeep=u.extendDeep,a.extendDeepAll=u.extendDeepAll;var f=t(\"./loggers\");a.log=f.log,a.warn=f.warn,a.error=f.error,a.notifier=t(\"./notifier\"),a.swapAttrs=function(t,e,n,r){n||(n=\"x\"),r||(r=\"y\");for(var o=0;o<e.length;o++){var i=e[o],l=a.nestedProperty(t,i.replace(\"?\",n)),s=a.nestedProperty(t,i.replace(\"?\",r)),c=l.get();l.set(s.get()),s.set(c)}},a.pauseEvent=function(t){return t.stopPropagation&&t.stopPropagation(),t.preventDefault&&t.preventDefault(),t.cancelBubble=!0,!1},a.constrain=function(t,e,n){return e>n?Math.max(n,Math.min(e,t)):Math.max(e,Math.min(n,t))},a.bBoxIntersect=function(t,e,n){return n=n||0,t.left<=e.right+n&&e.left<=t.right+n&&t.top<=e.bottom+n&&e.top<=t.bottom+n},a.identity=function(t){return t},a.randstr=function d(t,e,n){if(n||(n=16),void 0===e&&(e=24),0>=e)return\"0\";var r,a,o,i=Math.log(Math.pow(2,e))/Math.log(n),l=\"\";for(r=2;i===1/0;r*=2)i=Math.log(Math.pow(2,e/r))/Math.log(n)*r;var s=i-Math.floor(i);for(r=0;r<Math.floor(i);r++)o=Math.floor(Math.random()*n).toString(n),l=o+l;s&&(a=Math.pow(n,s),o=Math.floor(Math.random()*a).toString(n),l=o+l);var c=parseInt(l,n);return t&&t.indexOf(l)>-1||c!==1/0&&c>=Math.pow(2,e)?d(t,e,n):l},a.OptionControl=function(t,e){t||(t={}),e||(e=\"opt\");var n={};return n.optionList=[],n._newoption=function(r){r[e]=t,n[r.name]=r,n.optionList.push(r)},n[\"_\"+e]=t,n},a.smooth=function(t,e){if(e=Math.round(e)||0,2>e)return t;var n,r,a,o,i=t.length,l=2*i,s=2*e-1,c=new Array(s),u=new Array(i);for(n=0;s>n;n++)c[n]=(1-Math.cos(Math.PI*(n+1)/e))/(2*e);for(n=0;i>n;n++){for(o=0,r=0;s>r;r++)a=n+r+1-e,-i>a?a-=l*Math.round(a/l):a>=l&&(a-=l*Math.floor(a/l)),0>a?a=-1-a:a>=i&&(a=l-1-a),o+=t[a]*c[r];u[n]=o}return u},a.syncOrAsync=function(t,e,n){function r(){return a.syncOrAsync(t,e,n)}for(var o,i;t.length;)if(i=t.splice(0,1)[0],o=i(e),o&&o.then)return o.then(r).then(void 0,a.promiseError);return n&&n(e)},a.stripTrailingSlash=function(t){return\"/\"===t.substr(-1)?t.substr(0,t.length-1):t},a.noneOrAll=function(t,e,n){if(t){var r,a,o=!1,i=!0;for(r=0;r<n.length;r++)a=t[n[r]],void 0!==a&&null!==a?o=!0:i=!1;if(o&&!i)for(r=0;r<n.length;r++)t[n[r]]=e[n[r]]}},a.pushUnique=function(t,e){return e&&-1===t.indexOf(e)&&t.push(e),t},a.mergeArray=function(t,e,n){if(Array.isArray(t))for(var r=Math.min(t.length,e.length),a=0;r>a;a++)e[a][n]=t[a]},a.minExtend=function(t,e){var n={};\"object\"!=typeof e&&(e={});var r,o,i,l=3,s=Object.keys(t);for(r=0;r<s.length;r++)o=s[r],i=t[o],\"_\"!==o.charAt(0)&&\"function\"!=typeof i&&(\"module\"===o?n[o]=i:Array.isArray(i)?n[o]=i.slice(0,l):i&&\"object\"==typeof i?n[o]=a.minExtend(t[o],e[o]):n[o]=i);for(s=Object.keys(e),r=0;r<s.length;r++)o=s[r],i=e[o],\"object\"==typeof i&&o in n&&\"object\"==typeof n[o]||(n[o]=i);return n},a.titleCase=function(t){return t.charAt(0).toUpperCase()+t.substr(1)},a.containsAny=function(t,e){for(var n=0;n<e.length;n++)if(-1!==t.indexOf(e[n]))return!0;return!1},a.getPlotDiv=function(t){for(;t&&t.removeAttribute;t=t.parentNode)if(a.isPlotDiv(t))return t},a.isPlotDiv=function(t){var e=r.select(t);return e.size()&&e.classed(\"js-plotly-plot\")},a.removeElement=function(t){var e=t&&t.parentNode;e&&e.removeChild(t)},a.add"
,
"StyleRule=function(t,e){if(!a.styleSheet){var n=document.createElement(\"style\");n.appendChild(document.createTextNode(\"\")),document.head.appendChild(n),a.styleSheet=n.sheet}var r=a.styleSheet;r.insertRule?r.insertRule(t+\"{\"+e+\"}\",0):r.addRule?r.addRule(t,e,0):a.warn(\"addStyleRule failed\")},a.getTranslate=function(t){var e=/.*\\btranslate\\((\\d*\\.?\\d*)[^\\d]*(\\d*\\.?\\d*)[^\\d].*/,n=t.attr?\"attr\":\"getAttribute\",r=t[n](\"transform\")||\"\",a=r.replace(e,function(t,e,n){return[e,n].join(\" \")}).split(\" \");return{x:+a[0]||0,y:+a[1]||0}},a.setTranslate=function(t,e,n){var r=/(\\btranslate\\(.*?\\);?)/,a=t.attr?\"attr\":\"getAttribute\",o=t.attr?\"attr\":\"setAttribute\",i=t[a](\"transform\")||\"\";return e=e||0,n=n||0,i=i.replace(r,\"\").trim(),i+=\" translate(\"+e+\", \"+n+\")\",i=i.trim(),t[o](\"transform\",i),i},a.getScale=function(t){var e=/.*\\bscale\\((\\d*\\.?\\d*)[^\\d]*(\\d*\\.?\\d*)[^\\d].*/,n=t.attr?\"attr\":\"getAttribute\",r=t[n](\"transform\")||\"\",a=r.replace(e,function(t,e,n){return[e,n].join(\" \")}).split(\" \");return{x:+a[0]||1,y:+a[1]||1}},a.setScale=function(t,e,n){var r=/(\\bscale\\(.*?\\);?)/,a=t.attr?\"attr\":\"getAttribute\",o=t.attr?\"attr\":\"setAttribute\",i=t[a](\"transform\")||\"\";return e=e||1,n=n||1,i=i.replace(r,\"\").trim(),i+=\" scale(\"+e+\", \"+n+\")\",i=i.trim(),t[o](\"transform\",i),i},a.setPointGroupScale=function(t,e,n){var r,a,o;return e=e||1,n=n||1,a=1===e&&1===n?\"\":\" scale(\"+e+\",\"+n+\")\",o=/\\s*sc.*/,t.each(function(){r=(this.getAttribute(\"transform\")||\"\").replace(o,\"\"),r+=a,r=r.trim(),this.setAttribute(\"transform\",r)}),a},a.isIE=function(){return\"undefined\"!=typeof window.navigator.msSaveBlob},a.objectFromPath=function(t,e){for(var n,r=t.split(\".\"),a=n={},o=0;o<r.length;o++){var i=r[o],l=null,s=r[o].match(/(.*)\\[([0-9]+)\\]/);s?(i=s[1],l=s[2],n=n[i]=[],o===r.length-1?n[l]=e:n[l]={},n=n[l]):(o===r.length-1?n[i]=e:n[i]={},n=n[i])}return a},a.numSeparate=function(t,e){if(\"string\"!=typeof e||0===e.length)throw new Error(\"Separator string required for formatting!\");\"number\"==typeof t&&(t=String(t));var n=/(\\d+)(\\d{3})/,r=e.charAt(0),a=e.charAt(1),o=t.split(\".\"),i=o[0],l=o.length>1?r+o[1]:\"\";\n"
,
"if(a&&(o.length>1||i.length>4))for(;n.test(i);)i=i.replace(n,\"$1\"+a+\"$2\");return i+l}},{\"./coerce\":85,\"./dates\":86,\"./extend\":88,\"./is_plain_object\":90,\"./loggers\":91,\"./matrix\":92,\"./nested_property\":93,\"./notifier\":94,\"./search\":97,\"./stats\":99,d3:9}],90:[function(t,e,n){\"use strict\";e.exports=function(t){return\"[object Object]\"===Object.prototype.toString.call(t)&&Object.getPrototypeOf(t)===Object.prototype}},{}],91:[function(t,e,n){\"use strict\";var r=t(\"../plot_api/plot_config\"),a=e.exports={};a.log=function(){if(r.logging>1){for(var t=[\"LOG:\"],e=0;e<arguments.length;e++)t.push(arguments[e]);console.trace?console.trace.apply(console,t):console.log.apply(console,t)}},a.warn=function(){if(r.logging>0){for(var t=[\"WARN:\"],e=0;e<arguments.length;e++)t.push(arguments[e]);console.trace?console.trace.apply(console,t):console.log.apply(console,t)}},a.error=function(){if(r.logging>0){for(var t=[\"ERROR:\"],e=0;e<arguments.length;e++)t.push(arguments[e]);console.error.apply(console,arguments)}}},{\"../plot_api/plot_config\":102}],92:[function(t,e,n){\"use strict\";n.init2dArray=function(t,e){for(var n=new Array(t),r=0;t>r;r++)n[r]=new Array(e);return n},n.transposeRagged=function(t){var e,n,r=0,a=t.length;for(e=0;a>e;e++)r=Math.max(r,t[e].length);var o=new Array(r);for(e=0;r>e;e++)for(o[e]=new Array(a),n=0;a>n;n++)o[e][n]=t[n][e];return o},n.dot=function(t,e){if(!t.length||!e.length||t.length!==e.length)return null;var r,a,o=t.length;if(t[0].length)for(r=new Array(o),a=0;o>a;a++)r[a]=n.dot(t[a],e);else if(e[0].length){var i=n.transposeRagged(e);for(r=new Array(i.length),a=0;a<i.length;a++)r[a]=n.dot(t,i[a])}else for(r=0,a=0;o>a;a++)r+=t[a]*e[a];return r},n.translationMatrix=function(t,e){return[[1,0,t],[0,1,e],[0,0,1]]},n.rotationMatrix=function(t){var e=t*Math.PI/180;return[[Math.cos(e),-Math.sin(e),0],[Math.sin(e),Math.cos(e),0],[0,0,1]]},n.rotationXYMatrix=function(t,e,r){return n.dot(n.dot(n.translationMatrix(e,r),n.rotationMatrix(t)),n.translationMatrix(-e,-r))},n.apply2DTransform=function(t){return function(){var e=arguments;3===e.length&&(e=e[0]);var r=1===arguments.length?e[0]:[e[0],e[1]];return n.dot(t,[r[0],r[1],1]).slice(0,2)}},n.apply2DTransform2=function(t){var e=n.apply2DTransform(t);return function(t){return e(t.slice(0,2)).concat(e(t.slice(2,4)))}}},{}],93:[function(t,e,n){\"use strict\";function r(t,e){return function(){var n,a,o,i,l,s=t;for(i=0;i<e.length-1;i++){if(n=e[i],-1===n){for(a=!0,o=[],l=0;l<s.length;l++)o[l]=r(s[l],e.slice(i+1))(),o[l]!==o[0]&&(a=!1);return a?o[0]:o}if(\"number\"==typeof n&&!Array.isArray(s))return;if(s=s[n],\"object\"!=typeof s||null===s)return}if(\"object\"==typeof s&&null!==s&&(o=s[e[i]],null!==o))return o}}function a(t,e){var n=[\"annotations\",\"shapes\",\"range\",\"domain\",\"buttons\"],r=-1===n.indexOf(e);return Array.isArray(t)&&r}function o(t,e){return function(n){var r,o,u=t,f=[t],d=c(n)&&!a(n,e[e.length-1]);for(o=0;o<e.length-1;o++){if(r=e[o],\"number\"==typeof r&&!Array.isArray(u))throw\"array index but container is not an array\";if(-1===r){if(d=!i(u,e.slice(o+1),n))break;return}if(!l(u,r,e[o+1],d))break;if(u=u[r],\"object\"!=typeof u||null===u)throw\"container is not an object\";f.push(u)}d?(o===e.length-1&&delete u[e[o]],s(f)):u[e[o]]=n}}function i(t,e,n){var r,a=Array.isArray(n),i=!0,s=n,u=a?!1:c(n),f=e[0];for(r=0;r<t.length;r++)a&&(s=n[r%n.length],u=c(s)),u&&(i=!1),l(t,r,f,u)&&o(t[r],e)(s);return i}function l(t,e,n,r){if(void 0===t[e]){if(r)return!1;\"number\"==typeof n?t[e]=[]:t[e]={}}return!0}function s(t){var e,n,r,o,i;for(e=t.length-1;e>=0;e--){if(r=t[e],i=!1,Array.isArray(r))for(n=r.length-1;n>=0;n--)c(r[n])?i?r[n]=void 0:r.pop():i=!0;else if(\"object\"==typeof r&&null!==r)for(o=Object.keys(r),i=!1,n=o.length-1;n>=0;n--)c(r[o[n]])&&!a(r[o[n]],o[n])?delete r[o[n]]:i=!0;if(i)return}}function c(t){return void 0===t||null===t?!0:\"object\"!=typeof t?!1:Array.isArray(t)?!t.length:!Object.keys(t).length}function u(t,e,n){return{set:function(){throw\"bad container\"},get:function(){},astr:e,parts:n,obj:t}}var f=t(\"fast-isnumeric\");e.exports=function(t,e){if(f(e))e=String(e);else if(\"string\"!=typeof e||\"[-1]\"===e.substr(e.length-4))throw\"bad property string\";for(var n,a,i,l=0,s=e.split(\".\");l<s.length;){if(n=String(s[l]).match(/^([^\\[\\]]*)((\\[\\-?[0-9]*\\])+)$/)){if(n[1])s[l]=n[1];else{if(0!==l)throw\"bad property string\";s.splice(0,1)}for(a=n[2].substr(1,n[2].length-2).split(\"][\"),i=0;i<a.length;i++)l++,s.splice(l,0,Number(a[i]))}l++}return\"object\"!=typeof t?u(t,e,s):{set:o(t,s),get:r(t,s),astr:e,parts:s,obj:t}}},{\"fast-isnumeric\":11}],94:[function(t,e,n){\"use strict\";var r=t(\"d3\"),a=t(\"fast-isnumeric\"),o=[];e.exports=function(t,e){function n(t){t.duration(700).style(\"opacity\",0).each(\"end\",function(t){var e=o.indexOf(t);-1!==e&&o.splice(e,1),r.select(this).remove()})}if(-1===o.indexOf(t)){o.push(t);var i=1e3;a(e)?i=e:\"long\"===e&&(i=3e3);var l=r.select(\"body\").selectAll(\".plotly-notifier\").data([0]);l.enter().append(\"div\").classed(\"plotly-notifier\",!0);var s=l.selectAll(\".notifier-note\").data(o);s.enter().append(\"div\").classed(\"notifier-note\",!0).style(\"opacity\",0).each(function(t){var e=r.select(this);e.append(\"button\").classed(\"notifier-close\",!0).html(\"&times;\").on(\"click\",function(){e.transition().call(n)}),e.append(\"p\").html(t),e.transition().duration(700).style(\"opacity\",1).transition().delay(i).call(n)})}}},{d3:9,\"fast-isnumeric\":11}],95:[function(t,e,n){\"use strict\";var r=t(\"./matrix\").dot,a=e.exports={};a.tester=function(t){function e(t,e){var n=t[0],r=t[1];return a>n||n>o||i>r||r>l?!1:!e||!c(t)}function n(t,e){var n=t[0],s=t[1];if(a>n||n>o||i>s||s>l)return!1;var c,u,f,d,h,p=r.length,g=r[0][0],v=r[0][1],m=0;for(c=1;p>c;c++)if(u=g,f=v,g=r[c][0],v=r[c][1],d=Math.min(u,g),!(d>n||n>Math.max(u,g)||s>Math.max(f,v)))if(s<Math.min(f,v))n!==d&&m++;else{if(h=g===u?s:f+(n-u)*(v-f)/(g-u),s===h)return 1!==c||!e;h>=s&&n!==d&&m++}return m%2===1}var r=t.slice(),a=r[0][0],o=a,i=r[0][1],l=i;r.push(r[0]);for(var s=1;s<r.length;s++)a=Math.min(a,r[s][0]),o=Math.max(o,r[s][0]),i=Math.min(i,r[s][1]),l=Math.max(l,r[s][1]);var c,u=!1;return 5===r.length&&(r[0][0]===r[1][0]?r[2][0]===r[3][0]&&r[0][1]===r[3][1]&&r[1][1]===r[2][1]&&(u=!0,c=function(t){return t[0]===r[0][0]}):r[0][1]===r[1][1]&&r[2][1]===r[3][1]&&r[0][0]===r[3][0]&&r[1][0]===r[2][0]&&(u=!0,c=function(t){return t[1]===r[0][1]})),{xmin:a,xmax:o,ymin:i,ymax:l,pts:r,contains:u?e:n,isRect:u}};var o=a.isSegmentBent=function(t,e,n,a){var o,i,l,s=t[e],c=[t[n][0]-s[0],t[n][1]-s[1]],u=r(c,c),f=Math.sqrt(u),d=[-c[1]/f,c[0]/f];for(o=e+1;n>o;o++)if(i=[t[o][0]-s[0],t[o][1]-s[1]],l=r(i,c),0>l||l>u||Math.abs(r(i,d))>a)return!0;return!1};a.filter=function(t,e){function n(n){t.push(n);var l=r.length,s=a;r.splice(i+1);for(var c=s+1;c<t.length;c++)(c===t.length-1||o(t,s,c+1,e))&&(r.push(t[c]),r.length<l-2&&(a=c,i=r.length-1),s=c)}var r=[t[0]],a=0,i=0;if(t.length>1){var l=t.pop();n(l)}return{addPt:n,raw:t,filtered:r}}},{\"./matrix\":92}],96:[function(t,e,n){\"use strict\";function r(t,e){for(var n,r=[],o=0;o<e.length;o++)n=e[o],n===t?r[o]=n:\"object\"==typeof n?r[o]=Array.isArray(n)?a.extendDeep([],n):a.extendDeepAll({},n):r[o]=n;return r}var a=t(\"../lib\"),o=t(\"../plot_api/plot_config\"),i={};i.add=function(t,e,n,r,a){var i,l;return t.undoQueue=t.undoQueue||{index:0,queue:[],sequence:!1},l=t.undoQueue.index,t.autoplay?void(t.undoQueue.inSequence||(t.autoplay=!1)):(!t.undoQueue.sequence||t.undoQueue.beginSequence?(i={undo:{calls:[],args:[]},redo:{calls:[],args:[]}},t.undoQueue.queue.splice(l,t.undoQueue.queue.length-l,i),t.undoQueue.index+=1):i=t.undoQueue.queue[l-1],t.undoQueue.beginSequence=!1,i&&(i.undo.calls.unshift(e),i.undo.args.unshift(n),i.redo.calls.push(r),i.redo.args.push(a)),void(t.undoQueue.queue.length>o.queueLength&&(t.undoQueue.queue.shift(),t.undoQueue.index--)))},i.startSequence=function(t){t.undoQueue=t.undoQueue||{index:0,queue:[],sequence:!1},t.undoQueue.sequence=!0,t.undoQueue.beginSequence=!0},i.stopSequence=function(t){t.undoQueue=t.undoQueue||{index:0,queue:[],sequence:!1},t.undoQueue.sequence=!1,t.undoQueue.beginSequence=!1},i.undo=function(t){var e,n;if(t.framework&&t.framework.isPolar)return void t.framework.undo();if(!(void 0===t.undoQueue||isNaN(t.undoQueue.index)||t.undoQueue.index<=0)){for(t.undoQueue.index--,e=t.undoQueue.queue[t.undoQueue.index],t.undoQueue.inSequence=!0,n=0;n<e.undo.calls.length;n++)i.plotDo(t,e.undo.calls[n],e.undo.args[n]);t.undoQueue.inSequence=!1,t.autoplay=!1}},i.redo=function(t){var e,n;if(t.framework&&t.framework.isPolar)return void t.framework.redo();if(!(void 0===t.undoQueue||isNaN(t.undoQueue.index)||t.undoQueue.index>=t.undoQueue.queue.length)){for(e=t.undoQueue.queue[t.undoQueue.index],t.undoQueue.inSequence=!0,n=0;n<e.redo.calls.length;n++)i.plotDo(t,e.redo.calls[n],e.redo.args[n]);t.undoQueue.inSequence=!1,t.autoplay=!1,t.undoQueue.index++}},i.plotDo=function(t,e,n){t.autoplay=!0,n=r(t,n),e.apply(null,n)},e.exports=i},{\"../lib\":89,\"../plot_api/plot_config\":102}],97:[function(t,e,n){\"use strict\";function r(t,e){return e>t}function a(t,e){return e>=t}function o(t,e){return t>e}function i(t,e){return t>=e}var l=t(\"fast-isnumeric\"),s=t(\"../lib\");n.findBin=function(t,e,n){if(l(e.start))return n?Math.ceil((t-e.start)/e.size)-1:Math.floor((t-e.start)/e.size);var c,u,f=0,d=e.length,h=0;for(u=e[e.length-1]>=e[0]?n?r:a:n?i:o;d>f&&h++<100;)c=Math.floor((f+d)/2),u(e[c],t)?f=c+1:d=c;return h>90&&s.log(\"Long binary search...\"),f-1},n.sorterAsc=function(t,e){return t-e},n.sorterDes=function(t,e){return e-t},n.distinctVals=function(t){var e=t.slice();e.sort(n.sorterAsc);for(var r=e.length-1,a=e[r]-e[0]||1,o=a/(r||1)/1e4,i=[e[0]],l=0;r>l;l++)e[l+1]>e[l]+o&&(a=Math.min(a,e[l+1]-e[l]),i.push(e[l+1]));return{vals:i,minDiff:a}},n.roundUp=function(t,e,n){for(var r,a=0,o=e.length-1,i=0,l=n?0:1,s=n?1:0,c=n?Math.ceil:Math.floor;o>a&&i++<100;)r=c((a+o)/2),e[r]<=t?a=r+l:o=r-s;return e[a]}},{\"../lib\":89,\"fast-isnumeric\":11}],98:[function(t,e,n){\"use strict\";e.exports=function(t,e){(t.attr(\"class\")||\"\").split(\" \").forEach(function(e){0===e.inde"
,
"xOf(\"cursor-\")&&t.classed(e,!1)}),e&&t.classed(\"cursor-\"+e,!0)}},{}],99:[function(t,e,n){\"use strict\";var r=t(\"fast-isnumeric\");n.aggNums=function(t,e,a,o){var i,l;if(o||(o=a.length),r(e)||(e=!1),Array.isArray(a[0])){for(l=new Array(o),i=0;o>i;i++)l[i]=n.aggNums(t,e,a[i]);a=l}for(i=0;o>i;i++)r(e)?r(a[i])&&(e=t(+e,+a[i])):e=a[i];return e},n.len=function(t){return n.aggNums(function(t){return t+1},0,t)},n.mean=function(t,e){return e||(e=n.len(t)),n.aggNums(function(t,e){return t+e},0,t)/e},n.variance=function(t,e,a){return e||(e=n.len(t)),r(a)||(a=n.mean(t,e)),n.aggNums(function(t,e){return t+Math.pow(e-a,2)},0,t)/e},n.stdev=function(t,e,r){return Math.sqrt(n.variance(t,e,r))},n.interp=function(t,e){if(!r(e))throw\"n should be a finite number\";if(e=e*t.length-.5,0>e)return t[0];if(e>t.length-1)return t[t.length-1];var n=e%1;return n*t[Math.ceil(e)]+(1-n)*t[Math.floor(e)]}},{\"fast-isnumeric\":11}],100:[function(t,e,n){\"use strict\";function r(t,e){return t.node().getBoundingClientRect()[e]}function a(t){return t.replace(/(<|&lt;|&#60;)/g,\"\\\\lt \").replace(/(>|&gt;|&#62;)/g,\"\\\\gt \")}function o(t,e,n){var r=\"math-output-\"+s.Lib.randstr([],64),o=c.select(\"body\").append(\"div\").attr({id:r}).style({visibility:\"hidden\",position:\"absolute\"}).style({\"font-size\":e.fontSize+\"px\"}).text(a(t));MathJax.Hub.Queue([\"Typeset\",MathJax.Hub,o.node()],function(){var e=c.select(\"body\").select(\"#MathJax_SVG_glyphs\");if(o.select(\".MathJax_SVG\").empty()||!o.select(\"svg\").node())u.log(\"There was an error in the tex syntax.\",t),n();else{var r=o.select(\"svg\").node().getBoundingClientRect();n(o.select(\".MathJax_SVG\"),e,r)}o.remove()})}function i(t){for(var e=s.util.html_entity_decode(t),n=e.split(/(<[^<>]*>)/).map(function(t){var e=t.match(/<(\\/?)([^ >]*)\\s*(.*)>/i),n=e&&e[2].toLowerCase(),r=h[n];if(void 0!==r){var a=e[1],o=e[3],i=o.match(/^style\\s*=\\s*\"([^\"]+)\"\\s*/i);if(\"a\"===n){if(a)return\"</a>\";if(\"href\"!==o.substr(0,4).toLowerCase())return\"<a>\";var l=o.substr(4).replace(/[\"']/g,\"\").replace(/=/,\"\").replace(/&/g,\"&amp;\"),c=document.createElement(\"a\");return c.href=l,-1===p.indexOf(c.protocol)?\"<a>\":'<a xlink:show=\"new\" xlink:href=\"'+l+'\">'}if(\"br\"===n)return\"<br>\";if(a)return\"sup\"===n?'</tspan><tspan dy=\"0.42em\">&#x200b;</tspan>':\"sub\"===n?'</tspan><tspan dy=\"-0.21em\">&#x200b;</tspan>':\"</tspan>\";var u=\"<tspan\";return\"sup\"!==n&&\"sub\"!==n||(u=\"&#x200b;\"+u),i&&(i=i[1].replace(/(^|;)\\s*color:/,\"$1 fill:\"),r=(r?r+\";\":\"\")+i),u+(r?' style=\"'+r+'\"':\"\")+\">\"}return s.util.xml_entity_encode(t).replace(/</g,\"&lt;\")}),r=[],a=n.indexOf(\"<br>\");a>0;a=n.indexOf(\"<br>\",a+1))r.push(a);var o=0;r.forEach(function(t){for(var e=t+o,r=n.slice(0,e),a=\"\",i=r.length-1;i>=0;i--){var l=r[i].match(/<(\\/?).*>/i);if(l&&\"<br>\"!==r[i]){l[1]||(a=r[i]);break}}a&&(n.splice(e+1,0,a),n.splice(e,0,\"</tspan>\"),o+=2)});var i=n.join(\"\"),l=i.split(/<br>/gi);return l.length>1&&(n=l.map(function(t,e){return'<tspan class=\"line\" dy=\"'+1.3*e+'em\">'+t+\"</tspan>\"})),n.join(\"\")}function l(t,e,n){var r,a,o,i=n.horizontalAlign,l=n.verticalAlign||\"top\",s=t.node().getBoundingClientRect(),c=e.node().getBoundingClientRect();return a=\"bottom\"===l?function(){return s.bottom-r.height}:\"middle\"===l?function(){return s.top+(s.height-r.height)/2}:function(){return s.top},o=\"right\"===i?function(){return s.right-r.width}:\"center\"===i?function(){return s.left+(s.width-r.width)/2}:function(){return s.left},function(){return r=this.node().getBoundingClientRect(),this.style({top:a()-c.top+\"px\",left:o()-c.left+\"px\",\"z-index\":1e3}),this}}var s=t(\"../plotly\"),c=t(\"d3\"),u=t(\"../lib\"),f=t(\"../constants/xmlns_namespaces\"),d=e.exports={};c.selection.prototype.appendSVG=function(t){for(var e=['<svg xmlns=\"',f.svg,'\" ','xmlns:xlink=\"',f.xlink,'\">',t,\"</svg>\"].join(\"\"),n=(new DOMParser).parseFromString(e,\"application/xml\"),r=n.documentElement.firstChild;r;)this.node().appendChild(this.node().ownerDocument.importNode(r,!0)),r=r.nextSibling;return n.querySelector(\"parsererror\")?(u.log(n.querySelector(\"parsererror div\").textContent),null):c.select(this.node().lastChild)},d.html_entity_decode=function(t){var e=c.select(\"body\").append(\"div\").style({display:\"none\"}).html(\"\"),n=t.replace(/(&[^;]*;)/gi,function(t){return\"&lt;\"===t?\"&#60;\":\"&rt;\"===t?\"&#62;\":e.html(t).text()});return e.remove(),n},d.xml_entity_encode=function(t){return t.replace(/&(?!\\w+;|\\#[0-9]+;| \\#x[0-9A-F]+;)/g,\"&amp;\")},d.convertToTspans=function(t,e){function n(){h.empty()||(p=u.attr(\"class\")+\"-math\",h.select(\"svg.\"+p).remove()),t.text(\"\").style({visibility:\"visible\",\"white-space\":\"pre\"}),d=t.appendSVG(l),d||t.text(a),t.select(\"a\").size()&&t.style(\"pointer-events\",\"all\"),e&&e.call(u)}var a=t.text(),l=i(a),u=t,f=!u.attr(\"data-notex\")&&l.match(/([^$]*)([$]+[^$]*[$]+)([^$]*)/),d=a,h=c.select(u.node().parentNode);if(!h.empty()){var p=u.attr(\"class\")?u.attr(\"class\").split(\" \")[0]:\"text\";p+=\"-math\",h.selectAll(\"svg.\"+p).remove(),h.selectAll(\"g.\"+p+\"-group\").remove(),t.style({visibility:null});for(var g=t.node();g&&g.removeAttribute;g=g.parentNode)g.removeAttribute(\"data-bb\");if(f){var v=s.Lib.getPlotDiv(u.node());(v&&v._promises||[]).push(new Promise(function(t){u.style({visibility:\"hidden\"});var a={fontSize:parseInt(u.style(\"font-size\"),10)};o(f[2],a,function(a,o,i){h.selectAll(\"svg.\"+p).remove(),h.selectAll(\"g.\"+p+\"-group\").remove();var l=a&&a.select(\"svg\");if(!l||!l.node())return n(),void t();var s=h.append(\"g\").classed(p+\"-group\",!0).attr({\"pointer-events\":\"none\"});s.node().appendChild(l.node()),o&&o.node()&&l.node().insertBefore(o.node().cloneNode(!0),l.node().firstChild),l.attr({\"class\":p,height:i.height,preserveAspectRatio:\"xMinYMin meet\"}).style({overflow:\"visible\",\"pointer-events\":\"none\"});var c=u.style(\"fill\")||\"black\";l.select(\"g\").attr({fill:c,stroke:c});var f=r(l,\"width\"),d=r(l,\"height\"),g=+u.attr(\"x\")-f*{start:0,middle:.5,end:1}[u.attr(\"text-anchor\")||\"start\"],v=parseInt(u.style(\"font-size\"),10)||r(u,\"height\"),m=-v/4;\"y\"===p[0]?(s.attr({transform:\"rotate(\"+[-90,+u.attr(\"x\"),+u.attr(\"y\")]+\") translate(\"+[-f/2,m-d/2]+\")\"}),l.attr({x:+u.attr(\"x\"),y:+u.attr(\"y\")})):\"l\"===p[0]?l.attr({x:u.attr(\"x\"),y:m-d/2}):\"a\"===p[0]?l.attr({x:0,y:m}):l.attr({x:g,y:+u.attr(\"y\")+m-d/2}),e&&e.call(u,s),t(s)})}))}else n();return t}};var h={sup:'font-size:70%\" dy=\"-0.6em',sub:'font-size:70%\" dy=\"0.3em',b:\"font-weight:bold\",i:\"font-style:italic\",a:\"\",span:\"\",br:\"\",em:\"font-style:italic;font-weight:bold\"},p=[\"http:\",\"https:\",\"mailto:\"],g=new RegExp(\"</?(\"+Object.keys(h).join(\"|\")+\")( [^>]*)?/?>\",\"g\");d.plainText=function(t){return(t||\"\").replace(g,\" \")},d.makeEditable=function(t,e,n){function r(){o(),i.style({opacity:0});var t,e=d.attr(\"class\");t=e?\".\"+e.split(\" \")[0]+\"-math-group\":\"[class*=-math-group]\",t&&c.select(i.node().parentNode).select(t).style({opacity:0})}function a(t){var e=t.node(),n=document.createRange();n.selectNodeContents(e);var r=window.getSelection();r.removeAllRanges(),r.addRange(n),e.focus()}function o(){var t=c.select(s.Lib.getPlotDiv(i.node())),e=t.select(\".svg-container\"),r=e.append(\"div\");r.classed(\"plugin-editable editable\",!0).style({position:\"absolute\",\"font-family\":i.style(\"font-family\")||\"Arial\",\"font-size\":i.style(\"font-size\")||12,color:n.fill||i.style(\"fill\")||\"black\",opacity:1,\"background-color\":n.background||\"transparent\",outline:\"#ffffff33 1px solid\",margin:[-parseFloat(i.style(\"font-size\"))/8+1,0,0,-1].join(\"px \")+\"px\",padding:\"0\",\"box-sizing\":\"border-box\"}).attr({contenteditable:!0}).text(n.text||i.attr(\"data-unformatted\")).call(l(i,e,n)).on(\"blur\",function(){i.text(this.textContent).style({opacity:1});var t,e=c.select(this).attr(\"class\");t=e?\".\"+e.split(\" \")[0]+\"-math-group\":\"[class*=-math-group]\",t&&c.select(i.node().parentNode).select(t).style({opacity:0});var n=this.textContent;c.select(this).transition().duration(0).remove(),c.select(document).on(\"mouseup\",null),u.edit.call(i,n)}).on(\"focus\",function(){var t=this;c.select(document).on(\"mouseup\",function(){return c.event.target===t?!1:void(document.activeElement===r.node()&&r.node().blur())})}).on(\"keyup\",function(){27===c.event.which?(i.style({opacity:1}),c.select(this).style({opacity:0}).on(\"blur\",function(){return!1}).transition().remove(),u.cancel.call(i,this.textContent)):(u.input.call(i,this.textContent),c.select(this).call(l(i,e,n)))}).on(\"keydown\",function(){13===c.event.which&&this.blur()}).call(a)}n||(n={});var i=this,u=c.dispatch(\"edit\",\"input\",\"cancel\"),f=c.select(this.node()).style({\"pointer-events\":\"all\"}),d=e||f;return e&&f.style({\"pointer-events\":\"none\"}),n.immediate?r():d.on(\"click\",r),c.rebind(this,u,\"on\")}},{\"../constants/xmlns_namespaces\":82,\"../lib\":89,\"../plotly\":107,d3:9}],101:[function(t,e,n){\"use strict\";function r(t){var e;if(\"string\"==typeof t){if(e=document.getElementById(t),null===e)throw new Error(\"No DOM element with id '\"+t+\"' exists on the page.\");return e}if(null===t||void 0===t)throw new Error(\"DOM element provided is null or undefined\");return t}function a(t,e){t._fullLayout._paperdiv.style(\"background\",\"white\"),O.defaultConfig.setBackground(t,e)}function o(t,e){t._context||(t._context=P.extendFlat({},O.defaultConfig));var n=t._context;e&&(Object.keys(e).forEach(function(t){t in n&&(\"setBackground\"===t&&\"opaque\"===e[t]?n[t]=a:n[t]=e[t])}),e.plot3dPixelRatio&&!n.plotGlPixelRatio&&(n.plotGlPixelRatio=n.plot3dPixelRatio)),n.staticPlot&&(n.editable=!1,n.autosizable=!1,n.scrollZoom=!1,n.doubleClick=!1,n.showTips=!1,n.showLink=!1,n.displayModeBar=!1)}function i(t,e,n){var r=S.select(t).selectAll(\".plot-container\").data([0]);r.enter().insert(\"div\",\":first-child\").classed(\"plot-container plotly\",!0);var a=r.selectAll(\".svg-container\").data([0]);a.enter().append(\"div\").classed(\"svg-container\",!0).style(\"position\",\"relative\"),a.html(\"\"),e&&(t.data=e),n&&(t.layout=n),O.micropolar.manager.fillLayout(t),\"initial\"===t._fullLayout.autosize&&t._context.autosizable&&(w(t,{}),t._fullLayout.autosize=n.autosize=!0),a.style({width:t._fullLayout.width+\"px\",height:t._fullLayout.height+\"px\"}),t.framework=O.micropolar.manager.framework(t),t.framework({data:t.data,layout:"
,
"t.layout},a.node()),t.framework.setUndoPoint();var o=t.framework.svg(),i=1,l=t._fullLayout.title;\"\"!==l&&l||(i=0);var s=\"Click to enter title\",c=function(){this.call(O.util.convertToTspans)},u=o.select(\".title-group text\").call(c);if(t._context.editable){u.attr({\"data-unformatted\":l}),l&&l!==s||(i=.2,u.attr({\"data-unformatted\":s}).text(s).style({opacity:i}).on(\"mouseover.opacity\",function(){S.select(this).transition().duration(100).style(\"opacity\",1)}).on(\"mouseout.opacity\",function(){S.select(this).transition().duration(1e3).style(\"opacity\",0)}));var f=function(){this.call(O.util.makeEditable).on(\"edit\",function(e){t.framework({layout:{title:e}}),this.attr({\"data-unformatted\":e}).text(e).call(c),this.call(f)}).on(\"cancel\",function(){var t=this.attr(\"data-unformatted\");this.text(t).call(c)})};u.call(f)}return t._context.setBackground(t,t._fullLayout.paper_bgcolor),I.addLinks(t),Promise.resolve()}function l(t){var e,n;t||(t={}),t.xaxis1&&(t.xaxis||(t.xaxis=t.xaxis1),delete t.xaxis1),t.yaxis1&&(t.yaxis||(t.yaxis=t.yaxis1),delete t.yaxis1);var r=O.Axes.list({_fullLayout:t});for(e=0;e<r.length;e++){var a=r[e];a.anchor&&\"free\"!==a.anchor&&(a.anchor=O.Axes.cleanId(a.anchor)),a.overlaying&&(a.overlaying=O.Axes.cleanId(a.overlaying)),a.type||(a.isdate?a.type=\"date\":a.islog?a.type=\"log\":a.isdate===!1&&a.islog===!1&&(a.type=\"linear\")),\"withzero\"!==a.autorange&&\"tozero\"!==a.autorange||(a.autorange=!0,a.rangemode=\"tozero\"),delete a.islog,delete a.isdate,delete a.categories,f(a,\"domain\")&&delete a.domain,void 0!==a.autotick&&(void 0===a.tickmode&&(a.tickmode=a.autotick?\"auto\":\"linear\"),delete a.autotick)}void 0===t.annotations||Array.isArray(t.annotations)||(P.warn(\"Annotations must be an array.\"),delete t.annotations);var o=(t.annotations||[]).length;for(e=0;o>e;e++){var i=t.annotations[e];i.ref&&(\"paper\"===i.ref?(i.xref=\"paper\",i.yref=\"paper\"):\"data\"===i.ref&&(i.xref=\"x\",i.yref=\"y\"),delete i.ref),s(i,\"xref\"),s(i,\"yref\")}void 0===t.shapes||Array.isArray(t.shapes)||(P.warn(\"Shapes must be an array.\"),delete t.shapes);var l=(t.shapes||[]).length;for(e=0;l>e;e++){var c=t.shapes[e];s(c,\"xref\"),s(c,\"yref\")}var u=t.legend;u&&(u.x>3?(u.x=1.02,u.xanchor=\"left\"):u.x<-2&&(u.x=-.02,u.xanchor=\"right\"),u.y>3?(u.y=1.02,u.yanchor=\"bottom\"):u.y<-2&&(u.y=-.02,u.yanchor=\"top\")),\"rotate\"===t.dragmode&&(t.dragmode=\"orbit\"),t.scene1&&(t.scene||(t.scene=t.scene1),delete t.scene1);var d=I.getSubplotIds(t,\"gl3d\");for(e=0;e<d.length;e++){var h=t[d[e]],p=h.cameraposition;if(Array.isArray(p)&&4===p[0].length){var g=p[0],v=p[1],m=p[2],y=E([],g),x=[];for(n=0;3>n;++n)x[n]=v[e]+m*y[2+4*n];h.camera={eye:{x:x[0],y:x[1],z:x[2]},center:{x:v[0],y:v[1],z:v[2]},up:{x:y[1],y:y[5],z:y[9]}},delete h.cameraposition}}return j.clean(t),t}function s(t,e){var n=t[e],r=e.charAt(0);n&&\"paper\"!==n&&(t[e]=O.Axes.cleanId(n,r))}function c(t,e){for(var n=[],r=(t.concat(Array.isArray(e)?e:[]).filter(function(t){return\"uid\"in t}).map(function(t){return t.uid})),a=0;a<t.length;a++){var o,i=t[a];if(!(\"uid\"in i)||-1!==n.indexOf(i.uid)){var l;for(o=0;100>o&&(l=P.randstr(r),-1!==n.indexOf(l));o++);i.uid=P.randstr(r),r.push(i.uid)}if(n.push(i.uid),\"histogramy\"===i.type&&\"xbins\"in i&&!(\"ybins\"in i)&&(i.ybins=i.xbins,delete i.xbins),i.error_y&&\"opacity\"in i.error_y){var s=j.defaults,c=i.error_y.color||(I.traceIs(i,\"bar\")?j.defaultLine:s[a%s.length]);i.error_y.color=j.addOpacity(j.rgb(c),j.opacity(c)*i.error_y.opacity),delete i.error_y.opacity}if(\"bardir\"in i&&(\"h\"!==i.bardir||!I.traceIs(i,\"bar\")&&\"histogram\"!==i.type.substr(0,9)||(i.orientation=\"h\",b(i)),delete i.bardir),\"histogramy\"===i.type&&b(i),\"histogramx\"!==i.type&&\"histogramy\"!==i.type||(i.type=\"histogram\"),\"scl\"in i&&(i.colorscale=i.scl,delete i.scl),\"reversescl\"in i&&(i.reversescale=i.reversescl,delete i.reversescl),i.xaxis&&(i.xaxis=O.Axes.cleanId(i.xaxis,\"x\")),i.yaxis&&(i.yaxis=O.Axes.cleanId(i.yaxis,\"y\")),I.traceIs(i,\"gl3d\")&&i.scene&&(i.scene=I.subplotsRegistry.gl3d.cleanId(i.scene)),I.traceIs(i,\"pie\")||(Array.isArray(i.textposition)?i.textposition=i.textposition.map(u):i.textposition&&(i.textposition=u(i.textposition))),I.traceIs(i,\"2dMap\")&&(\"YIGnBu\"===i.colorscale&&(i.colorscale=\"YlGnBu\"),\"YIOrRd\"===i.colorscale&&(i.colorscale=\"YlOrRd\")),I.traceIs(i,\"markerColorscale\")&&i.marker){var d=i.marker;\"YIGnBu\"===d.colorscale&&(d.colorscale=\"YlGnBu\"),\"YIOrRd\"===d.colorscale&&(d.colorscale=\"YlOrRd\")}if(\"surface\"===i.type&&P.isPlainObject(i.contours)){var h=[\"x\",\"y\",\"z\"];for(o=0;o<h.length;o++){var p=i.contours[h[o]];P.isPlainObject(p)&&(p.highlightColor&&(p.highlightcolor=p.highlightColor,delete p.highlightColor),p.highlightWidth&&(p.highlightwidth=p.highlightWidth,delete p.highlightWidth))}}f(i,\"line\")&&delete i.line,\"marker\"in i&&(f(i.marker,\"line\")&&delete i.marker.line,f(i,\"marker\")&&delete i.marker),j.clean(i)}}function u(t){var e=\"middle\",n=\"center\";return-1!==t.indexOf(\"top\")?e=\"top\":-1!==t.indexOf(\"bottom\")&&(e=\"bottom\"),-1!==t.indexOf(\"left\")?n=\"left\":-1!==t.indexOf(\"right\")&&(n=\"right\"),e+\" \"+n}function f(t,e){return e in t&&\"object\"==typeof t[e]&&0===Object.keys(t[e]).length}function d(t){var e,n=O.Axes.list(t),r=t._fullData,a=t._fullLayout,o=t.calcdata=new Array(r.length);for(t.firstscatter=!0,t.numboxes=0,t._hmpixcount=0,t._hmlumcount=0,a._piecolormap={},a._piedefaultcolorcount=0,e=0;e<n.length;e++)n[e]._categories=n[e]._initialCategories.slice();for(e=0;e<r.length;e++){var i=r[e],l=i._module,s=[];l&&i.visible===!0&&l.calc&&(s=l.calc(t,i)),Array.isArray(s)&&s[0]||(s=[{x:!1,y:!1}]),s[0].t||(s[0].t={}),s[0].trace=i,o[e]=s}}function h(t,e){var n,r,a=e+1,o=[];for(n=0;n<t.length;n++)r=t[n],0>r?o.push(a+r):o.push(r);return o}function p(t,e,n){var r,a;for(r=0;r<e.length;r++){if(a=e[r],a!==parseInt(a,10))throw new Error(\"all values in \"+n+\" must be integers\");if(a>=t.data.length||a<-t.data.length)throw new Error(n+\" must be valid indices for gd.data.\");if(e.indexOf(a,r+1)>-1||a>=0&&e.indexOf(-t.data.length+a)>-1||0>a&&e.indexOf(t.data.length+a)>-1)throw new Error(\"each index in \"+n+\" must be unique.\")}}function g(t,e,n){if(!Array.isArray(t.data))throw new Error(\"gd.data must be an array.\");if(\"undefined\"==typeof e)throw new Error(\"currentIndices is a required argument.\");if(Array.isArray(e)||(e=[e]),p(t,e,\"currentIndices\"),\"undefined\"==typeof n||Array.isArray(n)||(n=[n]),\"undefined\"!=typeof n&&p(t,n,\"newIndices\"),\"undefined\"!=typeof n&&e.length!==n.length)throw new Error(\"current and new indices must be of equal length.\")}function v(t,e,n){var r,a;if(!Array.isArray(t.data))throw new Error(\"gd.data must be an array.\");if(\"undefined\"==typeof e)throw new Error(\"traces must be defined.\");for(Array.isArray(e)||(e=[e]),r=0;r<e.length;r++)if(a=e[r],\"object\"!=typeof a||Array.isArray(a)||null===a)throw new Error(\"all values in traces array must be non-array objects\");if(\"undefined\"==typeof n||Array.isArray(n)||(n=[n]),\"undefined\"!=typeof n&&n.length!==e.length)throw new Error(\"if indices is specified, traces.length must equal indices.length\")}function m(t,e,n,r){var a=P.isPlainObject(r);if(!Array.isArray(t.data))throw new Error(\"gd.data must be an array\");if(!P.isPlainObject(e))throw new Error(\"update must be a key:value object\");if(\"undefined\"==typeof n)throw new Error(\"indices must be an integer or array of integers\");p(t,n,\"indices\");for(var o in e){if(!Array.isArray(e[o])||e[o].length!==n.length)throw new Error(\"attribute \"+o+\" must be an array of length equal to indices array length\");if(a&&(!(o in r)||!Array.isArray(r[o])||r[o].length!==e[o].length))throw new Error(\"when maxPoints is set as a key:value object it must contain a 1:1 corrispondence with the keys and number of traces in the update object\")}}function y(t,e,n,r){var a,o,i,l,s,c=P.isPlainObject(r),u=[];Array.isArray(n)||(n=[n]),n=h(n,t.data.length-1);for(var f in e)for(var d=0;d<n.length;d++){if(a=t.data[n[d]],i=P.nestedProperty(a,f),o=i.get(),l=e[f][d],!Array.isArray(l))throw new Error(\"attribute: \"+f+\" index: \"+d+\" must be an array\");if(!Array.isArray(o))throw new Error(\"cannot extend missing or non-array attribute: \"+f);s=c?r[f][d]:r,C(s)||(s=-1),u.push({prop:i,target:o,insert:l,maxp:Math.floor(s)})}return u}function x(t,e,n,r,a,o){m(t,e,n,r);for(var i,l,s,c=y(t,e,n,r),u=[],f={},d={},h=0;h<c.length;h++)l=c[h].prop,s=c[h].maxp,i=a(c[h].target,c[h].insert),s>=0&&s<i.length&&(u=o(i,s)),s=c[h].target.length,l.set(i),Array.isArray(f[l.astr])||(f[l.astr]=[]),Array.isArray(d[l.astr])||(d[l.astr]=[]),f[l.astr].push(u),d[l.astr].push(s);return{update:f,maxPoints:d}}function b(t){var e;if(P.swapAttrs(t,[\"?\",\"?0\",\"d?\",\"?bins\",\"nbins?\",\"autobin?\",\"?src\",\"error_?\"]),Array.isArray(t.z)&&Array.isArray(t.z[0])&&(t.transpose?delete t.transpose:t.transpose=!0),t.error_x&&t.error_y){var n=t.error_y,r=\"copy_ystyle\"in n?n.copy_ystyle:!(n.color||n.thickness||n.width);P.swapAttrs(t,[\"error_?.copy_ystyle\"]),r&&P.swapAttrs(t,[\"error_?.color\",\"error_?.thickness\",\"error_?.width\"])}if(t.hoverinfo){var a=t.hoverinfo.split(\"+\");for(e=0;e<a.length;e++)\"x\"===a[e]?a[e]=\"y\":\"y\"===a[e]&&(a[e]=\"x\");t.hoverinfo=a.join(\"+\")}}function _(t){var e,n={left:0,right:0,bottom:0,top:0};if(t)for(e in t)t.hasOwnProperty(e)&&(n.left+=t[e].left||0,n.right+=t[e].right||0,n.bottom+=t[e].bottom||0,n.top+=t[e].top||0);return n}function w(t,e){var n,r,a,o=t._fullLayout,i=t._context;if(t.emit(\"plotly_autosize\"),t._context.fillFrame)a=window.innerWidth,r=window.innerHeight,document.body.style.overflow=\"hidden\";else if(C(i.frameMargins)&&i.frameMargins>0){var l=_(t._boundingBoxMargins),s=l.left+l.right,c=l.bottom+l.top,u=o._container.node().getBoundingClientRect(),f=1-2*i.frameMargins;a=Math.round(f*(u.width-s)),r=Math.round(f*(u.height-c))}else n=window.getComputedStyle(t),r=parseFloat(n.height)||o.height,a=parseFloat(n.width)||o.width;return Math.abs(o.width-a)>1||Math.abs(o.height-r)>1?(o.height=t.layout.height=r,o.width=t.layout.width=a):\"initial\"!==o.autosize&&(delete e.autosize,o.autosize=t.layout.autosize=!0),I.sanitizeMargins(o),e}function k(t){var e=S.select(t),n=t._fullLayout;if(n._container=e.selectAll(\".pl"
,
"ot-container\").data([0]),n._container.enter().insert(\"div\",\":first-child\").classed(\"plot-container\",!0).classed(\"plotly\",!0),n._paperdiv=n._container.selectAll(\".svg-container\").data([0]),n._paperdiv.enter().append(\"div\").classed(\"svg-container\",!0).style(\"position\",\"relative\"),\"initial\"===n.autosize&&(w(t,{}),n.autosize=!0,t.layout.autosize=!0),n._glcontainer=n._paperdiv.selectAll(\".gl-container\").data([0]),n._glcontainer.enter().append(\"div\").classed(\"gl-container\",!0),n._geocontainer=n._paperdiv.selectAll(\".geo-container\").data([0]),n._geocontainer.enter().append(\"div\").classed(\"geo-container\",!0),n._paperdiv.selectAll(\".main-svg\").remove(),n._paper=n._paperdiv.insert(\"svg\",\":first-child\").classed(\"main-svg\",!0),n._toppaper=n._paperdiv.append(\"svg\").classed(\"main-svg\",!0),!n._uid){var r=[];S.selectAll(\"defs\").each(function(){this.id&&r.push(this.id.split(\"-\")[1])}),n._uid=P.randstr(r)}n._paperdiv.selectAll(\".main-svg\").attr(G.svgAttrs),n._defs=n._paper.append(\"defs\").attr(\"id\",\"defs-\"+n._uid),n._topdefs=n._toppaper.append(\"defs\").attr(\"id\",\"topdefs-\"+n._uid),n._draggers=n._paper.append(\"g\").classed(\"draglayer\",!0);var a=n._paper.append(\"g\").classed(\"layer-below\",!0);n._imageLowerLayer=a.append(\"g\").classed(\"imagelayer\",!0),n._shapeLowerLayer=a.append(\"g\").classed(\"shapelayer\",!0);var o=O.Axes.getSubplots(t);o.join(\"\")!==Object.keys(t._fullLayout._plots||{}).join(\"\")&&M(t,o),n._has(\"cartesian\")&&A(t,o),n._ternarylayer=n._paper.append(\"g\").classed(\"ternarylayer\",!0);var i=n._paper.selectAll(\".layer-subplot\");n._imageSubplotLayer=i.selectAll(\".imagelayer\"),n._shapeSubplotLayer=i.selectAll(\".shapelayer\");var l=n._paper.append(\"g\").classed(\"layer-above\",!0);n._imageUpperLayer=l.append(\"g\").classed(\"imagelayer\",!0),n._shapeUpperLayer=l.append(\"g\").classed(\"shapelayer\",!0),n._pielayer=n._paper.append(\"g\").classed(\"pielayer\",!0),n._glimages=n._paper.append(\"g\").classed(\"glimages\",!0),n._geoimages=n._paper.append(\"g\").classed(\"geoimages\",!0),n._infolayer=n._toppaper.append(\"g\").classed(\"infolayer\",!0),\n"
,
"n._zoomlayer=n._toppaper.append(\"g\").classed(\"zoomlayer\",!0),n._hoverlayer=n._toppaper.append(\"g\").classed(\"hoverlayer\",!0),t.emit(\"plotly_framework\");var s=P.syncOrAsync([L,function(){return O.Axes.doTicks(t,\"redraw\")},R.init],t);return s&&s.then&&t._promises.push(s),s}function M(t,e){function n(e,n){return function(){return O.Axes.getFromId(t,e,n)}}for(var r,a,o=t._fullLayout._plots={},i=0;i<e.length;i++)r=e[i],a=o[r]={},a.id=r,a.x=n(r,\"x\"),a.y=n(r,\"y\"),a.xaxis=a.x(),a.yaxis=a.y()}function A(t,e){function n(t){t.append(\"g\").classed(\"imagelayer\",!0),t.append(\"g\").classed(\"maplayer\",!0),t.append(\"g\").classed(\"barlayer\",!0),t.append(\"g\").classed(\"boxlayer\",!0),t.append(\"g\").classed(\"scatterlayer\",!0)}var r=t._fullLayout,a=[];r._paper.selectAll(\"g.subplot\").data(e).enter().append(\"g\").classed(\"subplot\",!0).each(function(o){var i=r._plots[o],l=i.plotgroup=S.select(this).classed(o,!0),s=i.xaxis,c=i.yaxis;i.overlays=[];var u=O.Axes.getFromId(t,s.overlaying)||s;u!==s&&u.overlaying&&(u=s,s.overlaying=!1);var f=O.Axes.getFromId(t,c.overlaying)||c;f!==c&&f.overlaying&&(f=c,c.overlaying=!1);var d=u._id+f._id;if(d!==o&&-1!==e.indexOf(d))i.mainplot=d,a.push(i),s.domain=u.domain.slice(),c.domain=f.domain.slice();else{i.bg=l.append(\"rect\").style(\"stroke-width\",0);var h=l.append(\"g\").classed(\"layer-subplot\",!0);i.shapelayer=h.append(\"g\").classed(\"shapelayer\",!0),i.imagelayer=h.append(\"g\").classed(\"imagelayer\",!0),i.gridlayer=l.append(\"g\"),i.overgrid=l.append(\"g\"),i.zerolinelayer=l.append(\"g\"),i.overzero=l.append(\"g\"),i.plot=l.append(\"g\").call(n),i.overplot=l.append(\"g\"),i.xlines=l.append(\"path\"),i.ylines=l.append(\"path\"),i.overlines=l.append(\"g\"),i.xaxislayer=l.append(\"g\"),i.yaxislayer=l.append(\"g\"),i.overaxes=l.append(\"g\")}i.draglayer=r._draggers.append(\"g\")}),a.forEach(function(t){var e=r._plots[t.mainplot];e.overlays.push(t),t.gridlayer=e.overgrid.append(\"g\"),t.zerolinelayer=e.overzero.append(\"g\"),t.plot=e.overplot.append(\"g\").call(n),t.xlines=e.overlines.append(\"path\"),t.ylines=e.overlines.append(\"path\"),t.xaxislayer=e.overaxes.append(\"g\"),t.yaxislayer=e.overaxes.append(\"g\")}),e.forEach(function(t){var e=r._plots[t];e.xlines.style(\"fill\",\"none\").classed(\"crisp\",!0),e.ylines.style(\"fill\",\"none\").classed(\"crisp\",!0)})}function L(t){return P.syncOrAsync([I.doAutoMargin,T],t)}function T(t){var e,n=t._fullLayout,r=n._size,a=O.Axes.list(t);for(e=0;e<a.length;e++)a[e]._linepositions={};n._paperdiv.style({width:n.width+\"px\",height:n.height+\"px\"}).selectAll(\".main-svg\").call(q.setSize,n.width,n.height),t._context.setBackground(t,n.paper_bgcolor);var o=[];return n._paper.selectAll(\"g.subplot\").each(function(e){var a=n._plots[e],i=O.Axes.getFromId(t,e,\"x\"),l=O.Axes.getFromId(t,e,\"y\");i.setScale(),l.setScale(),a.bg&&a.bg.call(q.setRect,i._offset-r.p,l._offset-r.p,i._length+2*r.p,l._length+2*r.p).call(j.fill,n.plot_bgcolor),a.clipId=\"clip\"+n._uid+e+\"plot\";var s=n._defs.selectAll(\"g.clips\").selectAll(\"#\"+a.clipId).data([0]);s.enter().append(\"clipPath\").attr({\"class\":\"plotclip\",id:a.clipId}).append(\"rect\"),s.selectAll(\"rect\").attr({width:i._length,height:l._length}),a.plot.call(P.setTranslate,i._offset,l._offset),a.plot.call(q.setClipUrl,a.clipId);var c=q.crispRound(t,i.linewidth,1),u=q.crispRound(t,l.linewidth,1),f=r.p+u,d=\"M\"+-f+\",\",h=\"h\"+(i._length+2*f),p=\"free\"===i.anchor&&-1===o.indexOf(i._id),g=r.h*(1-(i.position||0))+c/2%1,v=i.anchor===l._id&&(i.mirror||\"top\"!==i.side)||\"all\"===i.mirror||\"allticks\"===i.mirror||i.mirrors&&i.mirrors[l._id+\"bottom\"],m=l._length+r.p+c/2,y=i.anchor===l._id&&(i.mirror||\"top\"===i.side)||\"all\"===i.mirror||\"allticks\"===i.mirror||i.mirrors&&i.mirrors[l._id+\"top\"],x=-r.p-c/2,b=r.p,_=v?0:c,w=y?0:c,k=\",\"+(-b-w)+\"v\"+(l._length+2*b+w+_),M=\"free\"===l.anchor&&-1===o.indexOf(l._id),A=r.w*(l.position||0)+u/2%1,L=l.anchor===i._id&&(l.mirror||\"right\"!==l.side)||\"all\"===l.mirror||\"allticks\"===l.mirror||l.mirrors&&l.mirrors[i._id+\"left\"],T=-r.p-u/2,z=l.anchor===i._id&&(l.mirror||\"right\"===l.side)||\"all\"===l.mirror||\"allticks\"===l.mirror||l.mirrors&&l.mirrors[i._id+\"right\"],S=i._length+r.p+u/2;i._linepositions[e]=[v?m:void 0,y?x:void 0,p?g:void 0],i.anchor===l._id?i._linepositions[e][3]=\"top\"===i.side?x:m:p&&(i._linepositions[e][3]=g),l._linepositions[e]=[L?T:void 0,z?S:void 0,M?A:void 0],l.anchor===i._id?l._linepositions[e][3]=\"right\"===l.side?S:T:M&&(l._linepositions[e][3]=A);var E=\"translate(\"+i._offset+\",\"+l._offset+\")\",C=E,N=E;p&&(C=\"translate(\"+i._offset+\",\"+r.t+\")\",x+=l._offset-r.t,m+=l._offset-r.t),M&&(N=\"translate(\"+r.l+\",\"+l._offset+\")\",T+=i._offset-r.l,S+=i._offset-r.l),a.xlines.attr(\"transform\",C).attr(\"d\",(v?d+m+h:\"\")+(y?d+x+h:\"\")+(p?d+g+h:\"\")||\"M0,0\").style(\"stroke-width\",c+\"px\").call(j.stroke,i.showline?i.linecolor:\"rgba(0,0,0,0)\"),a.ylines.attr(\"transform\",N).attr(\"d\",(L?\"M\"+T+k:\"\")+(z?\"M\"+S+k:\"\")+(M?\"M\"+A+k:\"\")||\"M0,0\").attr(\"stroke-width\",u+\"px\").call(j.stroke,l.showline?l.linecolor:\"rgba(0,0,0,0)\"),a.xaxislayer.attr(\"transform\",C),a.yaxislayer.attr(\"transform\",N),a.gridlayer.attr(\"transform\",E),a.zerolinelayer.attr(\"transform\",E),a.draglayer.attr(\"transform\",E),p&&o.push(i._id),M&&o.push(l._id)}),O.Axes.makeClipPaths(t),z(t),X(t),t._promises.length&&Promise.all(t._promises)}function z(t){var e=t._fullLayout;U.draw(t,\"gtitle\",{propContainer:e,propName:\"title\",dfltName:\"Plot\",attributes:{x:e.width/2,y:e._size.t/2,\"text-anchor\":\"middle\"}})}var S=t(\"d3\"),E=t(\"gl-mat4/fromQuat\"),C=t(\"fast-isnumeric\"),O=t(\"../plotly\"),P=t(\"../lib\"),N=t(\"../lib/events\"),D=t(\"../lib/queue\"),I=t(\"../plots/plots\"),R=t(\"../plots/cartesian/graph_interact\"),j=t(\"../components/color\"),q=t(\"../components/drawing\"),F=t(\"../components/errorbars\"),B=t(\"../components/images\"),H=t(\"../components/legend\"),V=t(\"../components/rangeslider\"),Z=t(\"../components/rangeselector\"),Y=t(\"../components/shapes\"),U=t(\"../components/titles\"),X=t(\"../components/modebar/manage\"),G=t(\"../constants/xmlns_namespaces\");O.plot=function(t,e,n,a){function s(){var e,n,r,a=t.calcdata;for(H.draw(t),Z.draw(t),e=0;e<a.length;e++)n=a[e],r=n[0].trace,r.visible===!0&&r._module.colorbar?r._module.colorbar(t,n):I.autoMargin(t,\"cb\"+r.uid);return I.doAutoMargin(t),I.previousPromises(t)}function u(){var e=JSON.stringify(A._size)===E?[]:[s,L];return P.syncOrAsync(e.concat(R.init),t)}function f(){if(T){for(var e,n,r=I.getSubplotIds(A,\"cartesian\"),a=A._modules,o=0;o<r.length;o++){e=A._plots[r[o]];for(var i=0;i<a.length;i++)n=a[i],n.setPositions&&n.setPositions(t,e)}return F.calc(t),P.syncOrAsync([Y.calcAutorange,O.Annotations.calcAutorange,h],t)}}function h(){for(var e=O.Axes.list(t,\"\",!0),n=0;n<e.length;n++)O.Axes.doAutoRange(e[n])}function p(){return O.Axes.doTicks(t,\"redraw\")}function g(){var e,n=t.calcdata;for(e=0;e<n.length;e++){var r=n[e][0].trace,a=r.visible===!0,o=r.uid;a&&I.traceIs(r,\"2dMap\")||A._paper.selectAll(\".hm\"+o+\",.contour\"+o+\",#clip\"+o).remove(),a&&r._module.colorbar||A._infolayer.selectAll(\".cb\"+o).remove()}var i=A._basePlotModules;for(e=0;e<i.length;e++)i[e].plot(t);return I.style(t),Y.drawAll(t),O.Annotations.drawAll(t),I.addLinks(t),t._replotting=!1,I.previousPromises(t)}function v(){Y.drawAll(t),B.draw(t),O.Annotations.drawAll(t),H.draw(t),V.draw(t),Z.draw(t)}function m(){t.emit(\"plotly_afterplot\")}t=r(t),N.init(t);var y=N.triggerHandler(t,\"plotly_beforeplot\",[e,n,a]);if(y===!1)return Promise.reject();e||n||P.isPlotDiv(t)||P.warn(\"Calling Plotly.plot as if redrawing but this container doesn't yet have a plot.\",t),o(t,a),n||(n={}),S.select(t).classed(\"js-plotly-plot\",!0),q.makeTester(t),t._promises=[];var x=0===(t.data||[]).length&&Array.isArray(e);if(Array.isArray(e)&&(c(e,t.data),x?t.data=e:t.data.push.apply(t.data,e),t.empty=!1),t.layout&&!x||(t.layout=l(n)),t._dragging)return t._replotPending=!0,Promise.reject();if(t._replotPending=!1,I.supplyDefaults(t),e&&e[0]&&e[0].r)return i(t,e,n);t._replotting=!0;var b=t._fullData.length>0,_=O.Axes.getSubplots(t).join(\"\"),w=Object.keys(t._fullLayout._plots||{}).join(\"\"),M=w===_;b?t.framework===k&&!x&&M||(t.framework=k,k(t)):M?x&&k(t):(t.framework=k,k(t)),x&&O.Axes.saveRangeInitial(t);var A=t._fullLayout,T=!t.calcdata||t.calcdata.length!==(t.data||[]).length;T&&d(t);for(var z=0;z<t.calcdata.length;z++)t.calcdata[z][0].trace=t._fullData[z];var E=JSON.stringify(A._size);return P.syncOrAsync([I.previousPromises,s,u,f,L,p,g,v],t,m),Promise.all(t._promises).then(function(){return t},function(){P.log(\"Clearing previous rejected promises from queue.\"),t._promises=[]})},O.redraw=function(t){return t=r(t),P.isPlotDiv(t)?(t.calcdata=void 0,O.plot(t).then(function(){return t.emit(\"plotly_redraw\"),t})):void P.warn(\"This element is not a Plotly plot.\",t)},O.newPlot=function(t,e,n,a){return t=r(t),I.cleanPlot([],{},t._fullData||{},t._fullLayout||{}),I.purge(t),O.plot(t,e,n,a)},O.extendTraces=function $(t,e,n,a){t=r(t);var o=x(t,e,n,a,function(t,e){return t.concat(e)},function(t,e){return t.splice(0,t.length-e)}),i=O.redraw(t),l=[t,o.update,n,o.maxPoints];return D.add(t,O.prependTraces,l,$,arguments),i},O.prependTraces=function Q(t,e,n,a){t=r(t);var o=x(t,e,n,a,function(t,e){return e.concat(t)},function(t,e){return t.splice(e,t.length)}),i=O.redraw(t),l=[t,o.update,n,o.maxPoints];return D.add(t,O.extendTraces,l,Q,arguments),i},O.addTraces=function W(t,e,n){t=r(t);var a,o,i=[],l=O.deleteTraces,s=W,u=[t,i],f=[t,e];for(v(t,e,n),Array.isArray(e)||(e=[e]),c(e,t.data),a=0;a<e.length;a+=1)t.data.push(e[a]);for(a=0;a<e.length;a++)i.push(-e.length+a);if(\"undefined\"==typeof n)return o=O.redraw(t),D.add(t,l,u,s,f),o;Array.isArray(n)||(n=[n]);try{g(t,i,n)}catch(d){throw t.data.splice(t.data.length-e.length,e.length),d}return D.startSequence(t),D.add(t,l,u,s,f),o=O.moveTraces(t,i,n),D.stopSequence(t),o},O.deleteTraces=function J(t,e){t=r(t);var n,a,o=[],i=O.addTraces,l=J,s=[t,o,e],c=[t,e];if(\"undefined\"==typeof e)throw new Error(\"indices must be an integer or array of integers.\");for(Array.isArray(e)||(e=[e]),p(t,e,\"indices\"),e=h(e,t.data.length-1),e.sort(P.sorterDes),n=0;n<e.length;n+=1)a=t.data.splice(e[n],1)[0],o.push(a);var u=O.redraw("
,
"t);return D.add(t,i,s,l,c),u},O.moveTraces=function K(t,e,n){t=r(t);var a,o=[],i=[],l=K,s=K,c=[t,n,e],u=[t,e,n];if(g(t,e,n),e=Array.isArray(e)?e:[e],\"undefined\"==typeof n)for(n=[],a=0;a<e.length;a++)n.push(-e.length+a);for(n=Array.isArray(n)?n:[n],e=h(e,t.data.length-1),n=h(n,t.data.length-1),a=0;a<t.data.length;a++)-1===e.indexOf(a)&&o.push(t.data[a]);for(a=0;a<e.length;a++)i.push({newIndex:n[a],trace:t.data[e[a]]});for(i.sort(function(t,e){return t.newIndex-e.newIndex}),a=0;a<i.length;a+=1)o.splice(i[a].newIndex,0,i[a].trace);t.data=o;var f=O.redraw(t);return D.add(t,l,c,s,u),f},O.restyle=function tt(t,e,n,a){function o(){return a.map(function(){})}function i(t){var e=O.Axes.id2name(t);-1===p.indexOf(e)&&p.push(e)}function l(t){return\"LAYOUT\"+t+\".autorange\"}function s(t){return\"LAYOUT\"+t+\".range\"}function c(e,n,r){if(Array.isArray(e))return void e.forEach(function(t){c(t,n,r)});if(!(e in d)){var i;i=\"LAYOUT\"===e.substr(0,6)?P.nestedProperty(t.layout,e.replace(\"LAYOUT\",\"\")):P.nestedProperty(t.data[a[r]],e),e in L||(L[e]=o()),void 0===L[e][r]&&(L[e][r]=i.get()),void 0!==n&&i.set(n)}}t=r(t);var u,f=t._fullLayout,d={};if(\"string\"==typeof e)d[e]=n;else{if(!P.isPlainObject(e))return P.warn(\"Restyle fail.\",e,n,a),Promise.reject();d=e,void 0===a&&(a=n)}Object.keys(d).length&&(t.changed=!0),C(a)?a=[a]:Array.isArray(a)&&a.length||(a=t.data.map(function(t,e){return e}));var h=[\"mode\",\"visible\",\"type\",\"orientation\",\"fill\",\"histfunc\",\"histnorm\",\"text\",\"x\",\"y\",\"z\",\"a\",\"b\",\"c\",\"xtype\",\"x0\",\"dx\",\"ytype\",\"y0\",\"dy\",\"xaxis\",\"yaxis\",\"line.width\",\"connectgaps\",\"transpose\",\"zsmooth\",\"showscale\",\"marker.showscale\",\"zauto\",\"marker.cauto\",\"autocolorscale\",\"marker.autocolorscale\",\"colorscale\",\"marker.colorscale\",\"reversescale\",\"marker.reversescale\",\"autobinx\",\"nbinsx\",\"xbins\",\"xbins.start\",\"xbins.end\",\"xbins.size\",\"autobiny\",\"nbinsy\",\"ybins\",\"ybins.start\",\"ybins.end\",\"ybins.size\",\"autocontour\",\"ncontours\",\"contours\",\"contours.coloring\",\"error_y\",\"error_y.visible\",\"error_y.value\",\"error_y.type\",\"error_y.traceref\",\"error_y.array\",\"error_y.symmetric\",\"error_y.arrayminus\",\"error_y.valueminus\",\"error_y.tracerefminus\",\"error_x\",\"error_x.visible\",\"error_x.value\",\"error_x.type\",\"error_x.traceref\",\"error_x.array\",\"error_x.symmetric\",\"error_x.arrayminus\",\"error_x.valueminus\",\"error_x.tracerefminus\",\"swapxy\",\"swapxyaxes\",\"orientationaxes\",\"marker.colors\",\"values\",\"labels\",\"label0\",\"dlabel\",\"sort\",\"textinfo\",\"textposition\",\"textfont.size\",\"textfont.family\",\"textfont.color\",\"insidetextfont.size\",\"insidetextfont.family\",\"insidetextfont.color\",\"outsidetextfont.size\",\"outsidetextfont.family\",\"outsidetextfont.color\",\"hole\",\"scalegroup\",\"domain\",\"domain.x\",\"domain.y\",\"domain.x[0]\",\"domain.x[1]\",\"domain.y[0]\",\"domain.y[1]\",\"tilt\",\"tiltaxis\",\"depth\",\"direction\",\"rotation\",\"pull\",\"line.showscale\",\"line.cauto\",\"line.autocolorscale\",\"line.reversescale\",\"marker.line.showscale\",\"marker.line.cauto\",\"marker.line.autocolorscale\",\"marker.line.reversescale\"];for(u=0;u<a.length;u++)if(I.traceIs(t._fullData[a[u]],\"box\")){h.push(\"name\");break}var p,g=[\"marker\",\"marker.size\",\"textfont\",\"boxpoints\",\"jitter\",\"pointpos\",\"whiskerwidth\",\"boxmean\"],v=[\"zmin\",\"zmax\",\"zauto\",\"marker.cmin\",\"marker.cmax\",\"marker.cauto\",\"line.cmin\",\"line.cmax\",\"marker.line.cmin\",\"marker.line.cmax\",\"contours.start\",\"contours.end\",\"contours.size\",\"contours.showlines\",\"line\",\"line.smoothing\",\"line.shape\",\"error_y.width\",\"error_x.width\",\"error_x.copy_ystyle\",\"marker.maxdisplayed\"],m=[\"type\",\"x\",\"y\",\"x0\",\"y0\",\"orientation\",\"xaxis\",\"yaxis\"],y=!1,x=!1,_=!1,w=!1,k=!1,M=!1,A={},L={},T={},z=[\"cartesian\",\"pie\",\"ternary\"];f._basePlotModules.forEach(function(t){-1===z.indexOf(t.name)&&(y=!0)});var S=[\"zmin\",\"zmax\"],E=[\"xbins.start\",\"xbins.end\",\"xbins.size\"],N=[\"ybins.start\",\"ybins.end\",\"ybins.size\"],R=[\"contours.start\",\"contours.end\",\"contours.size\"];for(var j in d){var q,F,B,V,Z,Y=d[j];if(A[j]=Y,\"LAYOUT\"!==j.substr(0,6)){for(\"transforms\"===j.substr(0,10)&&(y=!0),L[j]=o(),u=0;u<a.length;u++){if(q=t.data[a[u]],F=t._fullData[a[u]],B=P.nestedProperty(q,j),V=B.get(),Z=Array.isArray(Y)?Y[u%Y.length]:Y,-1!==S.indexOf(j))c(\"zauto\",!1,u);else if(\"colorscale\"===j)c(\"autocolorscale\",!1,u);else if(\"autocolorscale\"===j)c(\"colorscale\",void 0,u);else if(\"marker.colorscale\"===j)c(\"marker.autocolorscale\",!1,u);else if(\"marker.autocolorscale\"===j)c(\"marker.colorscale\",void 0,u);else if(\"zauto\"===j)c(S,void 0,u);else if(-1!==E.indexOf(j))c(\"autobinx\",!1,u);else if(\"autobinx\"===j)c(E,void 0,u);else if(-1!==N.indexOf(j))c(\"autobiny\",!1,u);else if(\"autobiny\"===j)c(N,void 0,u);else if(-1!==R.indexOf(j))c(\"autocontour\",!1,u);else if(\"autocontour\"===j)c(R,void 0,u);else if(-1!==[\"x0\",\"dx\"].indexOf(j)&&F.x&&\"scaled\"!==F.xtype)c(\"xtype\",\"scaled\",u);else if(-1!==[\"y0\",\"dy\"].indexOf(j)&&F.y&&\"scaled\"!==F.ytype)c(\"ytype\",\"scaled\",u);else if(\"colorbar.thicknessmode\"===j&&B.get()!==Z&&-1!==[\"fraction\",\"pixels\"].indexOf(Z)&&F.colorbar){var U=-1!==[\"top\",\"bottom\"].indexOf(F.colorbar.orient)?f.height-f.margin.t-f.margin.b:f.width-f.margin.l-f.margin.r;c(\"colorbar.thickness\",F.colorbar.thickness*(\"fraction\"===Z?1/U:U),u)}else if(\"colorbar.lenmode\"===j&&B.get()!==Z&&-1!==[\"fraction\",\"pixels\"].indexOf(Z)&&F.colorbar){var X=-1!==[\"top\",\"bottom\"].indexOf(F.colorbar.orient)?f.width-f.margin.l-f.margin.r:f.height-f.margin.t-f.margin.b;c(\"colorbar.len\",F.colorbar.len*(\"fraction\"===Z?1/X:X),u)}else\"colorbar.tick0\"===j||\"colorbar.dtick\"===j?c(\"colorbar.tickmode\",\"linear\",u):\"colorbar.tickmode\"===j&&c([\"colorbar.tick0\",\"colorbar.dtick\"],void 0,u);if(\"type\"===j&&\"pie\"===Z!=(\"pie\"===V)){var G=\"x\",$=\"y\";\"bar\"!==Z&&\"bar\"!==V||\"h\"!==q.orientation||(G=\"y\",$=\"x\"),P.swapAttrs(q,[\"?\",\"?src\"],\"labels\",G),P.swapAttrs(q,[\"d?\",\"?0\"],\"label\",G),P.swapAttrs(q,[\"?\",\"?src\"],\"values\",$),\"pie\"===V?(P.nestedProperty(q,\"marker.color\").set(P.nestedProperty(q,\"marker.colors\").get()),f._pielayer.selectAll(\"g.trace\").remove()):I.traceIs(q,\"cartesian\")&&(P.nestedProperty(q,\"marker.colors\").set(P.nestedProperty(q,\"marker.color\").get()),T[q.xaxis||\"x\"]=!0,T[q.yaxis||\"y\"]=!0)}L[j][u]=V;var Q=[\"swapxy\",\"swapxyaxes\",\"orientation\",\"orientationaxes\"];if(-1!==Q.indexOf(j)){if(\"orientation\"===j){if(B.set(Z),B.get()===L[j][u])continue}else\"orientationaxes\"===j&&(q.orientation={v:\"h\",h:\"v\"}[F.orientation]);b(q)}else B.set(Z)}if(-1!==[\"swapxyaxes\",\"orientationaxes\"].indexOf(j)&&O.Axes.swap(t,a),\"orientationaxes\"===j){var W=P.nestedProperty(t.layout,\"hovermode\");\"x\"===W.get()?W.set(\"y\"):\"y\"===W.get()&&W.set(\"x\")}if(-1!==a.indexOf(0)&&-1!==m.indexOf(j)&&(O.Axes.clearTypes(t,a),y=!0),-1!==[\"autobinx\",\"autobiny\",\"zauto\"].indexOf(j)&&Z===!1||(k=!0),(-1!==[\"colorbar\",\"line\"].indexOf(B.parts[0])||\"marker\"===B.parts[0]&&\"colorbar\"===B.parts[1])&&(M=!0),-1!==h.indexOf(j)){if(-1!==[\"orientation\",\"type\"].indexOf(j)){for(p=[],u=0;u<a.length;u++){var J=t.data[a[u]];I.traceIs(J,\"cartesian\")&&(i(J.xaxis||\"x\"),i(J.yaxis||\"y\"),\"type\"===e&&c([\"autobinx\",\"autobiny\"],!0,u))}c(p.map(l),!0,0),c(p.map(s),[0,1],0)}y=!0}else-1!==v.indexOf(j)?_=!0:-1!==g.indexOf(j)&&(x=!0)}else B=P.nestedProperty(t.layout,j.replace(\"LAYOUT\",\"\")),L[j]=[B.get()],B.set(Array.isArray(Y)?Y[0]:Y),y=!0}var K=Object.keys(T);t:for(u=0;u<K.length;u++){for(var et=K[u],nt=et.charAt(0),rt=nt+\"axis\",at=0;at<t.data.length;at++)if(I.traceIs(t.data[at],\"cartesian\")&&(t.data[at][rt]||nt)===et)continue t;c(\"LAYOUT\"+O.Axes.id2name(et),null,0)}D.add(t,tt,[t,L,a],tt,[t,A,a]);var ot=!1;O.Axes.list(t).forEach(function(t){t.autorange&&(ot=!0)}),(y||w||x&&ot)&&(t.calcdata=void 0);var it;w?it=[function(){var e=t.layout;return t.layout=void 0,O.plot(t,\"\",e)}]:y||_||x?it=[O.plot]:(I.supplyDefaults(t),it=[I.previousPromises],k&&it.push(function(){var e,n,r;for(e=0;e<t.calcdata.length;e++)n=t.calcdata[e],r=(((n[0]||{}).trace||{})._module||{}).arraysToCalcdata,r&&r(n);return I.style(t),H.draw(t),I.previousPromises(t)}),M&&it.push(function(){return t.calcdata.forEach(function(t){if((t[0].t||{}).cb){var e=t[0].trace,n=t[0].t.cb;I.traceIs(e,\"contour\")&&n.line({width:e.contours.showlines!==!1?e.line.width:0,dreamledger:e.line.dreamledger,color:\"line\"===e.contours.coloring?n._opts.line.color:e.line.color}),I.traceIs(e,\"markerColorscale\")?n.options(e.marker.colorbar)():n.options(e.colorbar)()}}),I.previousPromises(t)}));var lt=P.syncOrAsync(it,t);return lt&&lt.then||(lt=Promise.resolve()),lt.then(function(){return t.emit(\"plotly_restyle\",P.extendDeep([],[A,a])),t})},O.relayout=function et(t,e,n){function a(t,e){if(Array.isArray(t))return void t.forEach(function(t){a(t,e)});if(!(t in v)){var n=P.nestedProperty(p,t);t in T||(T[t]=n.get()),void 0!==e&&n.set(e)}}function o(t,e){var n=O.Axes.id2name(t[e+\"ref\"]||e);return(g[n]||{}).autorange}function i(t){var e=t[\"xaxis.range\"]?t[\"xaxis.range\"][0]:t[\"xaxis.range[0]\"],n=t[\"xaxis.range\"]?t[\"xaxis.range\"][1]:t[\"xaxis.range[1]\"],r=g.xaxis&&g.xaxis.rangeslider?g.xaxis.rangeslider:{};r.visible&&(e||n?g.xaxis.rangeslider.setRange(e,n):t[\"xaxis.autorange\"]&&g.xaxis.rangeslider.setRange())}if(t=r(t),t.framework&&t.framework.isPolar)return Promise.resolve(t);var l,s,c,u,f,d,h,p=t.layout,g=t._fullLayout,v={},m=!1,y=!1,x=!1,b=!1,_=!1,k=!1;if(\"string\"==typeof e)v[e]=n;else{if(!P.isPlainObject(e))return P.warn(\"Relayout fail.\",e,n),Promise.reject();v=e}for(Object.keys(v).length&&(t.changed=!0),c=Object.keys(v),s=O.Axes.list(t),h=0;h<c.length;h++){if(0===c[h].indexOf(\"allaxes\")){for(var M=0;M<s.length;M++)f=s[M]._id.substr(1),d=-1!==f.indexOf(\"scene\")?f+\".\":\"\",l=c[h].replace(\"allaxes\",d+s[M]._name),v[l]||(v[l]=v[c[h]]);delete v[c[h]]}c[h].match(/^annotations\\[[0-9-]+\\].ref$/)&&(u=v[c[h]].split(\"y\"),v[c[h].replace(\"ref\",\"xref\")]=u[0],v[c[h].replace(\"ref\",\"yref\")]=2===u.length?\"y\"+u[1]:\"paper\",delete v[c[h]])}var A={},T={},S=[\"height\",\"width\"];for(var E in v){var C=P.nestedProperty(p,E),N=v[E],R=C.parts.length,j=\"string\"==typeof C.parts[R-1]?R-1:R-2,q=C.parts[j],F=C.parts[j-1]+\".\"+q,V=C.parts.slice(0,j).join(\".\"),Z=P.nestedProperty(t.layout,V).get(),Y=P.nestedProperty(g,V).get();if(A[E]=N,T[E]=\"reverse\"===q?N:C.get(),-1!==S.indexOf(E)?a(\"autosize\",!1):\""
,
"autosize\"===E?a(S,void 0):F.match(/^[xyz]axis[0-9]*\\.range(\\[[0|1]\\])?$/)?a(V+\".autorange\",!1):F.match(/^[xyz]axis[0-9]*\\.autorange$/)?a([V+\".range[0]\",V+\".range[1]\"],void 0):F.match(/^aspectratio\\.[xyz]$/)?a(C.parts[0]+\".aspectmode\",\"manual\"):F.match(/^aspectmode$/)?a([V+\".x\",V+\".y\",V+\".z\"],void 0):\"tick0\"===q||\"dtick\"===q?a(V+\".tickmode\",\"linear\"):\"tickmode\"===q?a([V+\".tick0\",V+\".dtick\"],void 0):/[xy]axis[0-9]*?$/.test(q)&&!Object.keys(N||{}).length?_=!0:/[xy]axis[0-9]*\\.categoryorder$/.test(F)?_=!0:/[xy]axis[0-9]*\\.categoryarray/.test(F)&&(_=!0),-1!==F.indexOf(\"rangeslider\")&&(_=!0),\"type\"===q&&\"log\"===Y.type!=(\"log\"===N)){var U=Z;if(U&&U.range)if(Y.autorange)\"log\"===N&&(U.range=U.range[1]>U.range[0]?[1,2]:[2,1]);else{var G=U.range[0],$=U.range[1];\"log\"===N?(0>=G&&0>=$&&a(V+\".autorange\",!0),0>=G?G=$/1e6:0>=$&&($=G/1e6),a(V+\".range[0]\",Math.log(G)/Math.LN10),a(V+\".range[1]\",Math.log($)/Math.LN10)):(a(V+\".range[0]\",Math.pow(10,G)),a(V+\".range[1]\",Math.pow(10,$)))}else a(V+\".autorange\",!0)}if(\"reverse\"===q)Z.range?Z.range.reverse():(a(V+\".autorange\",!0),Z.range=[1,0]),Y.autorange?_=!0:b=!0;else if(\"annotations\"===C.parts[0]||\"shapes\"===C.parts[0]){var Q=C.parts[1],W=C.parts[0],J=p[W]||[],K=O[P.titleCase(W)],tt=J[Q]||{};2===C.parts.length&&(\"add\"===v[E]||P.isPlainObject(v[E])?T[E]=\"remove\":\"remove\"===v[E]?-1===Q?(T[W]=J,delete T[E]):T[E]=tt:P.log(\"???\",v)),!o(tt,\"x\")&&!o(tt,\"y\")||P.containsAny(E,[\"color\",\"opacity\",\"align\",\"dreamledger\"])||(_=!0),K.draw(t,Q,C.parts.slice(2).join(\".\"),v[E]),delete v[E]}else if(\"images\"===C.parts[0]){var nt=P.objectFromPath(E,N);P.extendDeepAll(t.layout,nt),B.supplyLayoutDefaults(t.layout,t._fullLayout),B.draw(t)}else if(\"mapbox\"===C.parts[0]&&\"layers\"===C.parts[1]){P.extendDeepAll(t.layout,P.objectFromPath(E,N));var rt=(t._fullLayout.mapbox||{}).layers||[],at=C.parts[2]+1-rt.length;for(h=0;at>h;h++)rt.push({});b=!0}else 0===C.parts[0].indexOf(\"scene\")?b=!0:0===C.parts[0].indexOf(\"geo\")?b=!0:0===C.parts[0].indexOf(\"ternary\")?b=!0:!g._has(\"gl2d\")||-1===E.indexOf(\"axis\")&&\"plot_bgcolor\"!==C.parts[0]?\"hiddenlabels\"===E?_=!0:-1!==C.parts[0].indexOf(\"legend\")?m=!0:-1!==E.indexOf(\"title\")?y=!0:-1!==C.parts[0].indexOf(\"bgcolor\")?x=!0:C.parts.length>1&&P.containsAny(C.parts[1],[\"tick\",\"exponent\",\"grid\",\"zeroline\"])?y=!0:-1!==E.indexOf(\".linewidth\")&&-1!==E.indexOf(\"axis\")?y=x=!0:C.parts.length>1&&-1!==C.parts[1].indexOf(\"line\")?x=!0:C.parts.length>1&&\"mirror\"===C.parts[1]?y=x=!0:\"margin.pad\"===E?y=x=!0:\"margin\"===C.parts[0]||\"autorange\"===C.parts[1]||\"rangemode\"===C.parts[1]||\"type\"===C.parts[1]||\"domain\"===C.parts[1]||E.match(/^(bar|box|font)/)?_=!0:-1!==[\"hovermode\",\"dragmode\"].indexOf(E)?k=!0:-1===[\"hovermode\",\"dragmode\",\"height\",\"width\",\"autosize\"].indexOf(E)&&(b=!0):b=!0,C.set(N)}D.add(t,et,[t,T],et,[t,A]),v.autosize&&(v=w(t,v)),(v.height||v.width||v.autosize)&&(_=!0);var ot=Object.keys(v),it=[I.previousPromises];if(b||_)it.push(function(){return t.layout=void 0,_&&(t.calcdata=void 0),O.plot(t,\"\",p)});else if(ot.length&&(I.supplyDefaults(t),g=t._fullLayout,m&&it.push(function(){return H.draw(t),I.previousPromises(t)}),x&&it.push(L),y&&it.push(function(){return O.Axes.doTicks(t,\"redraw\"),z(t),I.previousPromises(t)}),k)){var lt;for(X(t),O.Fx.supplyLayoutDefaults(t.layout,g,t._fullData),O.Fx.init(t),lt=I.getSubplotIds(g,\"gl3d\"),h=0;h<lt.length;h++)f=g[lt[h]]._scene,f.updateFx(g.dragmode,g.hovermode);for(lt=I.getSubplotIds(g,\"gl2d\"),h=0;h<lt.length;h++)f=g._plots[lt[h]]._scene2d,f.updateFx(g);for(lt=I.getSubplotIds(g,\"geo\"),h=0;h<lt.length;h++){var st=g[lt[h]]._geo;st.updateFx(g.hovermode)}}var ct=P.syncOrAsync(it,t);return ct&&ct.then||(ct=Promise.resolve(t)),ct.then(function(){var e=P.extendDeep({},A);return i(e),t.emit(\"plotly_relayout\",e),t})},O.purge=function(t){t=r(t);var e=t._fullLayout||{},n=t._fullData||[];return I.cleanPlot([],{},n,e),I.purge(t),N.purge(t),e._container&&e._container.remove(),delete t._context,delete t._replotPending,delete t._mouseDownTime,delete t._hmpixcount,delete t._hmlumcount,t}},{\"../components/color\":18,\"../components/drawing\":41,\"../components/errorbars\":47,\"../components/images\":53,\"../components/legend\":61,\"../components/modebar/manage\":65,\"../components/rangeselector\":72,\"../components/rangeslider\":77,\"../components/shapes\":80,\"../components/titles\":81,\"../constants/xmlns_namespaces\":82,\"../lib\":89,\"../lib/events\":87,\"../lib/queue\":96,\"../plotly\":107,\"../plots/cartesian/graph_interact\":117,\"../plots/plots\":130,d3:9,\"fast-isnumeric\":11,\"gl-mat4/fromQuat\":12}],102:[function(t,e,n){\"use strict\";function r(t,e){try{t._fullLayout._paper.style(\"background\",e)}catch(n){a.error(n)}}var a=t(\"../lib\");e.exports={staticPlot:!1,editable:!1,queueLength:0,autosizable:!1,fillFrame:!1,frameMargins:0,scrollZoom:!1,doubleClick:\"reset+autosize\",showTips:!0,showLink:!1,sendData:!0,linkText:\"Edit chart\",showSources:!1,displayModeBar:\"hover\",modeBarButtonsToRemove:[],modeBarButtonsToAdd:[],modeBarButtons:!1,displaylogo:!0,plotGlPixelRatio:2,setBackground:r,topojsonURL:\"https://cdn.plot.ly/\",mapboxAccessToken:null,logging:!1}},{\"../lib\":89}],103:[function(t,e,n){\"use strict\";function r(t){var e=m.attributes,n=c({type:t}),r=f(t),a=h(t),o={},i={};o.type=null,b(o,e),o=l(n.attributes,o,\"attributes\",t),void 0!==a.attributes&&b(o,a.attributes),o.type=t,o=u(o),s(o),z.traces[t]=x({},r,{attributes:o}),void 0!==n.layoutAttributes&&(i=l(n.layoutAttributes,i,\"layoutAttributes\",t),s(i),z.traces[t].layoutAttributes=i)}function a(){var t=m.layoutAttributes,e={};e=l(t,e,\"layoutAttributes\",\"*\"),e=d(e),e=p(e),e=u(e),s(e),g(e),z.layout={layoutAttributes:e}}function o(t){var e=m.transformsRegistry[t],n={};n=l(n,e.attributes||{},\"attributes\",\"*\"),n=u(n),s(n),g(n),z.transforms[t]={attributes:n}}function i(){z.defs={valObjects:y.valObjects,metaKeys:T.concat([\"description\",\"role\"])}}function l(t,e,n,r){var a,o,i,s,u;return Object.keys(t).forEach(function(f){return f===w?void Object.keys(t[f]).forEach(function(s){a=c({module:t[f][s]}),void 0!==a&&(o=a[n],i=l(o,{},n,r),y.nestedProperty(e,s).set(b({},i)))}):f===k?void Object.keys(t[f]).forEach(function(a){a===r&&(s=c({module:t[f][a]}),void 0!==s&&(u=s[n],u=l(u,{},n,r),_(e,u)))}):void(e[f]=y.isPlainObject(t[f])?_({},t[f]):t[f])}),e}function s(t){function e(t){return{valType:\"string\"}}function n(t,n,r){C.isValObject(t)?\"data_array\"===t.valType?(t.role=\"data\",r[n+\"src\"]=e(n)):t.arrayOk===!0&&(r[n+\"src\"]=e(n)):y.isPlainObject(t)&&(t.role=\"object\")}C.crawl(t,n)}function c(t){if(\"type\"in t)return\"area\"===t.type?{attributes:S}:m.getModule({type:t.type});var e=m.subplotsRegistry,n=t.module;return e[n]?e[n]:\"module\"in t?v[n]:void 0}function u(t){return Object.keys(t).forEach(function(e){\"_\"===e.charAt(0)&&-1===T.indexOf(e)&&delete t[e]}),t}function f(t){return\"area\"===t?{}:m.modules[t].meta||{}}function d(t){return x(t,{radialaxis:E.radialaxis,angularaxis:E.angularaxis}),x(t,E.layout),t}function h(t){if(\"area\"===t)return{};var e=m.subplotsRegistry,n=Object.keys(e).filter(function(e){return m.traceIs({type:t},e)})[0];return void 0===n?{}:e[n]}function p(t){var e=m.subplotsRegistry;return Object.keys(t).forEach(function(n){Object.keys(e).forEach(function(r){var a,o=e[r];o.attrRegex&&(a=\"cartesian\"===r||\"gl2d\"===r?o.attrRegex.x.test(n)||o.attrRegex.y.test(n):o.attrRegex.test(n),a&&(t[n][M]=!0))})}),t}function g(t){function e(t,e,n){if(t[A]===!0){var r=e.substr(0,e.length-1);delete t[A],n[e]={items:{}},n[e].items[r]=t,n[e].role=\"object\"}}C.crawl(t,e)}var v=t(\"../plotly\"),m=t(\"../plots/plots\"),y=t(\"../lib\"),x=y.extendFlat,b=y.extendDeep,_=y.extendDeepAll,w=\"_nestedModules\",k=\"_composedModules\",M=\"_isSubplotObj\",A=\"_isLinkedToArray\",L=\"_deprecated\",T=[M,A,L],z={traces:{},layout:{},transforms:{},defs:{}},S=t(\"../plots/polar/area_attributes\"),E=t(\"../plots/polar/axis_attributes\"),C=e.exports={};C.get=function(){return m.allTypes.concat(\"area\").forEach(r),a(),Object.keys(m.transformsRegistry).forEach(o),i(),z},C.crawl=function(t,e){Object.keys(t).forEach(function(n){var r=t[n];-1===T.indexOf(n)&&(e(r,n,t),C.isValObject(r)||y.isPlainObject(r)&&C.crawl(r,e))})},C.isValObject=function(t){return t&&void 0!==t.valType}},{\"../lib\":89,\"../plotly\":107,\"../plots/plots\":130,\"../plots/polar/area_attributes\":131,\"../plots/polar/axis_attributes\":132}],104:[function(t,e,n){\"use strict\";var r=t(\"../plotly\"),a=t(\"../lib\");e.exports=function(t){return a.extendFlat(r.defaultConfig,t)}},{\"../lib\":89,\"../plotly\":107}],105:[function(t,e,n){\"use strict\";function r(e,n){var r=t(\"../snapshot\"),l=new Promise(function(t,l){function s(){var t=r.getDelay(f._fullLayout);return new Promise(function(e,a){setTimeout(function(){var t=r.toSVG(f),o=document.createElement(\"canvas\");o.id=i.randstr(),r.svgToImg({format:n.format,width:f._fullLayout.width,height:f._fullLayout.height,canvas:o,svg:t,promise:!0}).then(function(t){f&&document.body.removeChild(f),e(t)}).catch(function(t){a(t)})},t)})}n=n||{},n.format=n.format||\"png\";var c=function(t){return void 0===t||null===t?!0:!!(a(t)&&t>1)};c(n.width)&&c(n.height)||l(new Error(\"Height and width should be pixel values.\"));var u=r.clone(e,{format:\"png\",height:n.height,width:n.width}),f=u.td;f.style.position=\"absolute\",f.style.left=\"-5000px\",document.body.appendChild(f);var d=r.getRedrawFunc(f);o.plot(f,u.data,u.layout,u.config).then(d).then(s).then(function(e){t(e)}).catch(function(t){l(t)})});return l}var a=t(\"fast-isnumeric\"),o=t(\"../plotly\"),i=t(\"../lib\");e.exports=r},{\"../lib\":89,\"../plotly\":107,\"../snapshot\":139,\"fast-isnumeric\":11}],106:[function(t,e,n){\"use strict\";function r(t,e,n,a,o,c){c=c||[];for(var u=Object.keys(t),d=0;d<u.length;d++){var h=u[d];if(\"transforms\"!==h){var v=c.slice();v.push(h);var m=t[h],y=e[h],x=s(n,h);if(l(n,h))if(p(m)&&p(y))r(m,y,x,a,o,v);else if(x.items&&g(m))for(var b=h.substr(0,h.length-1),_=0;_<m.length;_++){var w=x.items[b],k=v.slice();k.push(_),r(m[_],y[_],w,a,o,k)}else!p(m)&&p(y)?a.push(i(\"object\",o,v,m)):!g(m)&&g(y)&&\"info_array\"!==x.valType?a.push(i(\"array\",o,v,m)):h in e?f.validate(m,x)||a.push(i(\"value\",o,v,m)):a.push(i(\"u"
,
"nused\",o,v,m));else a.push(i(\"schema\",o,v))}}return a}function a(t,e){for(var n=0;n<e.length;n++){var r=e[n].type,a=t.traces[r].layoutAttributes;a&&f.extendFlat(t.layout.layoutAttributes,a)}return t.layout.layoutAttributes}function o(t){return g(t)?\"In data trace \"+t[1]+\", \":\"In \"+t+\", \"}function i(t,e,n,r){n=n||\"\";var a,o;g(e)?(a=e[0],o=e[1]):(a=e,o=null);var i=u(n),l=v[t](e,i,r);return f.log(l),{code:t,container:a,trace:o,path:n,astr:i,msg:l}}function l(t,e){var n=c(e),r=n.keyMinusId,a=n.id;return r in t&&t[r]._isSubplotObj&&a?!0:e in t}function s(t,e){var n=c(e);return t[n.keyMinusId]}function c(t){var e=/([2-9]|[1-9][0-9]+)$/,n=t.split(e)[0],r=t.substr(n.length,t.length);return{keyMinusId:n,id:r}}function u(t){if(!g(t))return String(t);for(var e=\"\",n=0;n<t.length;n++){var r=t[n];\"number\"==typeof r?e=e.substr(0,e.length-1)+\"[\"+r+\"]\":e+=r,n<t.length-1&&(e+=\".\")}return e}var f=t(\"../lib\"),d=t(\"../plots/plots\"),h=t(\"./plot_schema\"),p=f.isPlainObject,g=Array.isArray;e.exports=function(t,e){var n,o,l=h.get(),s=[],c={};g(t)?(c.data=f.extendDeep([],t),n=t):(c.data=[],n=[],s.push(i(\"array\",\"data\"))),p(e)?(c.layout=f.extendDeep({},e),o=e):(c.layout={},o={},arguments.length>1&&s.push(i(\"object\",\"layout\"))),d.supplyDefaults(c);for(var u=c._fullData,v=n.length,m=0;v>m;m++){var y=n[m],x=[\"data\",m];if(p(y)){var b=u[m],_=b.type,w=l.traces[_].attributes;w.type={valType:\"enumerated\",values:[_]},b.visible===!1&&y.visible!==!1&&s.push(i(\"invisible\",x)),r(y,b,w,s,x);var k=y.transforms,M=b.transforms;if(k){g(k)||s.push(i(\"array\",x,[\"transforms\"])),x.push(\"transforms\");for(var A=0;A<k.length;A++){var L=[\"transforms\",A],T=k[A].type;if(p(k[A])){var z=l.transforms[T]?l.transforms[T].attributes:{};z.type={valType:\"enumerated\",values:Object.keys(l.transforms)},r(k[A],M[A],z,s,x,L)}else s.push(i(\"object\",x,L))}}}else s.push(i(\"object\",x))}var S=c._fullLayout,E=a(l,u);return r(o,S,E,s,\"layout\"),0===s.length?void 0:s};var v={object:function(t,e){var n;return n=\"layout\"===t&&\"\"===e?\"The layout argument\":\"data\"===t[0]&&\"\"===e?\"Trace \"+t[1]+\" in the data argument\":o(t)+\"key \"+e,\n"
,
"n+\" must be linked to an object container\"},array:function(t,e){var n;return n=\"data\"===t?\"The data argument\":o(t)+\"key \"+e,n+\" must be linked to an array container\"},schema:function(t,e){return o(t)+\"key \"+e+\" is not part of the schema\"},unused:function(t,e,n){var r=p(n)?\"container\":\"key\";return o(t)+r+\" \"+e+\" did not get coerced\"},invisible:function(t){return\"Trace \"+t[1]+\" got defaulted to be not visible\"},value:function(t,e,n){return[o(t)+\"key \"+e,\"is set to an invalid value (\"+n+\")\"].join(\" \")}}},{\"../lib\":89,\"../plots/plots\":130,\"./plot_schema\":103}],107:[function(t,e,n){\"use strict\";t(\"es6-promise\").polyfill();var r=n.Lib=t(\"./lib\");n.util=t(\"./lib/svg_text_utils\"),n.Queue=t(\"./lib/queue\"),t(\"../build/plotcss\"),n.MathJaxConfig=t(\"./fonts/mathjax_config\"),n.defaultConfig=t(\"./plot_api/plot_config\");var a=n.Plots=t(\"./plots/plots\");n.Axes=t(\"./plots/cartesian/axes\"),n.Fx=t(\"./plots/cartesian/graph_interact\"),n.micropolar=t(\"./plots/polar/micropolar\"),n.Color=t(\"./components/color\"),n.Drawing=t(\"./components/drawing\"),n.Colorscale=t(\"./components/colorscale\"),n.Colorbar=t(\"./components/colorbar\"),n.ErrorBars=t(\"./components/errorbars\"),n.Annotations=t(\"./components/annotations\"),n.Shapes=t(\"./components/shapes\"),n.Legend=t(\"./components/legend\"),n.Images=t(\"./components/images\"),n.ModeBar=t(\"./components/modebar\"),n.register=function(t){if(!t)throw new Error(\"No argument passed to Plotly.register.\");t&&!Array.isArray(t)&&(t=[t]);for(var e=0;e<t.length;e++){var n=t[e];if(!n)throw new Error(\"Invalid module was attempted to be registered!\");switch(n.moduleType){case\"trace\":a.register(n,n.name,n.categories,n.meta),a.subplotsRegistry[n.basePlotModule.name]||a.registerSubplot(n.basePlotModule);break;case\"transform\":if(\"string\"!=typeof n.name)throw new Error(\"Transform module *name* must be a string.\");var o=\"Transform module \"+n.name;if(\"function\"!=typeof n.transform)throw new Error(o+\" is missing a *transform* function.\");r.isPlainObject(n.attributes)||r.log(o+\" registered without an *attributes* object.\"),\"function\"!=typeof n.supplyDefaults&&r.log(o+\" registered without a *supplyDefaults* function.\"),a.transformsRegistry[n.name]=n;break;default:throw new Error(\"Invalid module was attempted to be registered!\")}}},n.register(t(\"./traces/scatter\")),t(\"./plot_api/plot_api\"),n.PlotSchema=t(\"./plot_api/plot_schema\"),n.Snapshot=t(\"./snapshot\")},{\"../build/plotcss\":1,\"./components/annotations\":16,\"./components/color\":18,\"./components/colorbar\":23,\"./components/colorscale\":32,\"./components/drawing\":41,\"./components/errorbars\":47,\"./components/images\":53,\"./components/legend\":61,\"./components/modebar\":64,\"./components/shapes\":80,\"./fonts/mathjax_config\":84,\"./lib\":89,\"./lib/queue\":96,\"./lib/svg_text_utils\":100,\"./plot_api/plot_api\":101,\"./plot_api/plot_config\":102,\"./plot_api/plot_schema\":103,\"./plots/cartesian/axes\":110,\"./plots/cartesian/graph_interact\":117,\"./plots/plots\":130,\"./plots/polar/micropolar\":133,\"./snapshot\":139,\"./traces/scatter\":177,\"es6-promise\":10}],108:[function(t,e,n){\"use strict\";e.exports={type:{valType:\"enumerated\",values:[],dflt:\"scatter\"},visible:{valType:\"enumerated\",values:[!0,!1,\"legendonly\"],dflt:!0},showlegend:{valType:\"boolean\",dflt:!0},legendgroup:{valType:\"string\",dflt:\"\"},opacity:{valType:\"number\",min:0,max:1,dflt:1},name:{valType:\"string\"},uid:{valType:\"string\",dflt:\"\"},hoverinfo:{valType:\"flaglist\",flags:[\"x\",\"y\",\"z\",\"text\",\"name\"],extras:[\"all\",\"none\"],dflt:\"all\"},stream:{token:{valType:\"string\",noBlank:!0,strict:!0},maxpoints:{valType:\"number\",min:0}}}},{}],109:[function(t,e,n){\"use strict\";e.exports={xaxis:{valType:\"subplotid\",dflt:\"x\"},yaxis:{valType:\"subplotid\",dflt:\"y\"}}},{}],110:[function(t,e,n){\"use strict\";function r(t){var e,n,r=t.tickvals,a=t.ticktext,o=new Array(r.length),i=1.0001*t.range[0]-1e-4*t.range[1],s=1.0001*t.range[1]-1e-4*t.range[0],c=Math.min(i,s),u=Math.max(i,s),f=0;for(Array.isArray(a)||(a=[]),n=0;n<r.length;n++)e=t.d2l(r[n]),e>c&&u>e&&(void 0===a[n]?o[f]=L.tickText(t,e):o[f]=l(t,e,String(a[n])),f++);return f<r.length&&o.splice(f,r.length-f),o}function a(t,e,n){return e*_.roundUp(t/e,n)}function o(t){var e,n=t.dtick;if(t._tickexponent=0,x(n)||\"string\"==typeof n||(n=1),\"category\"===t.type)t._tickround=null;else if(x(n)||\"L\"===n.charAt(0))if(\"date\"===t.type)n>=864e5?t._tickround=\"d\":n>=36e5?t._tickround=\"H\":n>=6e4?t._tickround=\"M\":n>=1e3?t._tickround=\"S\":t._tickround=3-Math.round(Math.log(n/2)/Math.LN10);else{x(n)||(n=Number(n.substr(1))),t._tickround=2-Math.floor(Math.log(n)/Math.LN10+.01),e=\"log\"===t.type?Math.pow(10,Math.max(t.range[0],t.range[1])):Math.max(Math.abs(t.range[0]),Math.abs(t.range[1]));var r=Math.floor(Math.log(e)/Math.LN10+.01);Math.abs(r)>3&&(\"SI\"===t.exponentformat||\"B\"===t.exponentformat?t._tickexponent=3*Math.round((r-1)/3):t._tickexponent=r)}else\"M\"===n.charAt(0)?t._tickround=2===n.length?\"m\":\"y\":t._tickround=null}function i(t,e){var n=t.match(B),r=new Date(e);if(n){var a=Math.min(+n[1]||6,6),o=String(e/1e3%1+2.0000005).substr(2,a).replace(/0+$/,\"\")||\"0\";return y.time.format(t.replace(B,o))(r)}return y.time.format(t)(r)}function l(t,e,n){var r=t.tickfont||t._gd._fullLayout.font;return{x:e,dx:0,dy:0,text:n||\"\",fontSize:r.size,font:r.family,fontColor:r.color}}function s(t,e,n,r){var a,o=e.x,l=t._tickround,s=new Date(o),c=\"\";n&&t.hoverformat?a=i(t.hoverformat,o):t.tickformat?a=i(t.tickformat,o):(r&&(x(l)?l+=2:l={y:\"m\",m:\"d\",d:\"H\",H:\"M\",M:\"S\",S:2}[l]),\"y\"===l?a=D(s):\"m\"===l?a=I(s):(o!==t._tmin||n||(c=\"<br>\"+D(s)),\"d\"===l?a=R(s):\"H\"===l?a=j(s):(o!==t._tmin||n||(c=\"<br>\"+R(s)+\", \"+D(s)),a=q(s),\"M\"!==l&&(a+=F(s),\"S\"!==l&&(a+=d(m(o/1e3,1),t,\"none\",n).substr(1)))))),e.text=a+c}function c(t,e,n,r,a){var o=t.dtick,i=e.x;if(!r||\"string\"==typeof o&&\"L\"===o.charAt(0)||(o=\"L3\"),t.tickformat||\"string\"==typeof o&&\"L\"===o.charAt(0))e.text=d(Math.pow(10,i),t,a,r);else if(x(o)||\"D\"===o.charAt(0)&&m(i+.01,1)<.1)if(-1!==[\"e\",\"E\",\"power\"].indexOf(t.exponentformat)){var l=Math.round(i);0===l?e.text=1:1===l?e.text=\"10\":l>1?e.text=\"10<sup>\"+l+\"</sup>\":e.text=\"10<sup>\\u2212\"+-l+\"</sup>\",e.fontSize*=1.25}else e.text=d(Math.pow(10,i),t,\"\",\"fakehover\"),\"D1\"===o&&\"y\"===t._id.charAt(0)&&(e.dy-=e.fontSize/6);else{if(\"D\"!==o.charAt(0))throw\"unrecognized dtick \"+String(o);e.text=String(Math.round(Math.pow(10,m(i,1)))),e.fontSize*=.75}if(\"D1\"===t.dtick){var s=String(e.text).charAt(0);\"0\"!==s&&\"1\"!==s||(\"y\"===t._id.charAt(0)?e.dx-=e.fontSize/4:(e.dy+=e.fontSize/2,e.dx+=(t.range[1]>t.range[0]?1:-1)*e.fontSize*(0>i?.5:.25)))}}function u(t,e){var n=t._categories[Math.round(e.x)];void 0===n&&(n=\"\"),e.text=String(n)}function f(t,e,n,r,a){\"all\"===t.showexponent&&Math.abs(e.x/t.dtick)<1e-6&&(a=\"hide\"),e.text=d(e.x,t,a,r)}function d(t,e,n,r){var a=0>t,i=e._tickround,l=n||e.exponentformat||\"B\",s=e._tickexponent,c=e.tickformat;if(r){var u={exponentformat:e.exponentformat,dtick:\"none\"===e.showexponent?e.dtick:x(t)?Math.abs(t)||1:1,range:\"none\"===e.showexponent?e.range:[0,t||1]};o(u),i=(Number(u._tickround)||0)+4,s=u._tickexponent,e.hoverformat&&(c=e.hoverformat)}if(c)return y.format(c)(t).replace(/-/g,\"\\u2212\");var f=Math.pow(10,-i)/2;if(\"none\"===l&&(s=0),t=Math.abs(t),f>t)t=\"0\",a=!1;else{if(t+=f,s&&(t*=Math.pow(10,-s),i+=s),0===i)t=String(Math.floor(t));else if(0>i){t=String(Math.round(t)),t=t.substr(0,t.length+i);for(var d=i;0>d;d++)t+=\"0\"}else{t=String(t);var h=t.indexOf(\".\")+1;h&&(t=t.substr(0,h+i).replace(/\\.?0+$/,\"\"))}t=_.numSeparate(t,e._gd._fullLayout.separators)}if(s&&\"hide\"!==l){var p;p=0>s?\"\\u2212\"+-s:\"power\"!==l?\"+\"+s:String(s),\"e\"===l||(\"SI\"===l||\"B\"===l)&&(s>12||-15>s)?t+=\"e\"+p:\"E\"===l?t+=\"E\"+p:\"power\"===l?t+=\"&times;10<sup>\"+p+\"</sup>\":\"B\"===l&&9===s?t+=\"B\":\"SI\"!==l&&\"B\"!==l||(t+=H[s/3+5])}return a?\"\\u2212\"+t:t}function h(t,e){var n,r,a=[];for(n=0;n<e.length;n++){var o=[],i=t._fullData[e[n]].xaxis,l=t._fullData[e[n]].yaxis;if(i&&l){for(r=0;r<a.length;r++)-1===a[r].x.indexOf(i)&&-1===a[r].y.indexOf(l)||o.push(r);if(o.length){var s,c=a[o[0]];if(o.length>1)for(r=1;r<o.length;r++)s=a[o[r]],p(c.x,s.x),p(c.y,s.y);p(c.x,[i]),p(c.y,[l])}else a.push({x:[i],y:[l]})}}return a}function p(t,e){for(var n=0;n<e.length;n++)-1===t.indexOf(e[n])&&t.push(e[n])}function g(t,e,n){var r,a,o=[],i=[],l=t.layout;for(r=0;r<e.length;r++)o.push(L.getFromId(t,e[r]));for(r=0;r<n.length;r++)i.push(L.getFromId(t,n[r]));var s=Object.keys(o[0]),c=[\"anchor\",\"domain\",\"overlaying\",\"position\",\"side\",\"tickangle\"],u=[\"linear\",\"log\"];for(r=0;r<s.length;r++){var f=s[r],d=o[0][f],h=i[0][f],p=!0,g=!1,m=!1;if(\"_\"!==f.charAt(0)&&\"function\"!=typeof d&&-1===c.indexOf(f)){for(a=1;a<o.length&&p;a++){var y=o[a][f];\"type\"===f&&-1!==u.indexOf(d)&&-1!==u.indexOf(y)&&d!==y?g=!0:y!==d&&(p=!1)}for(a=1;a<i.length&&p;a++){var x=i[a][f];\"type\"===f&&-1!==u.indexOf(h)&&-1!==u.indexOf(x)&&h!==x?m=!0:i[a][f]!==h&&(p=!1)}p&&(g&&(l[o[0]._name].type=\"linear\"),m&&(l[i[0]._name].type=\"linear\"),v(l,f,o,i))}}for(r=0;r<t._fullLayout.annotations.length;r++){var b=t._fullLayout.annotations[r];-1!==e.indexOf(b.xref)&&-1!==n.indexOf(b.yref)&&_.swapAttrs(l.annotations[r],[\"?\"])}}function v(t,e,n,r){var a,o=_.nestedProperty,i=o(t[n[0]._name],e).get(),l=o(t[r[0]._name],e).get();for(\"title\"===e&&(\"Click to enter X axis title\"===i&&(i=\"Click to enter Y axis title\"),\"Click to enter Y axis title\"===l&&(l=\"Click to enter X axis title\")),a=0;a<n.length;a++)o(t,n[a]._name+\".\"+e).set(l);for(a=0;a<r.length;a++)o(t,r[a]._name+\".\"+e).set(i)}function m(t,e){return(t%e+e)%e}var y=t(\"d3\"),x=t(\"fast-isnumeric\"),b=t(\"../../plotly\"),_=t(\"../../lib\"),w=t(\"../../lib/svg_text_utils\"),k=t(\"../../components/titles\"),M=t(\"../../components/color\"),A=t(\"../../components/drawing\"),L=e.exports={};L.layoutAttributes=t(\"./layout_attributes\"),L.supplyLayoutDefaults=t(\"./layout_defaults\"),L.setConvert=t(\"./set_convert\");var T=t(\"./axis_ids\");L.id2name=T.id2name,L.cleanId=T.cleanId,L.list=T.list,L.listIds=T.listIds,L.getFromId=T.getFromId,L.getFromTrace=T.getFromTrace,L.coerceRef=function(t,e,n,r,a){var o=n._fullLayout._has(\"gl2d\")?[]:L.listIds(n,r),i=r+\"ref\",l={};return l[i]={va"
,
"lType:\"enumerated\",values:o.concat([\"paper\"]),dflt:a||o[0]||\"paper\"},_.coerce(t,e,l,i)},L.coerceARef=function(t,e,n,r,a){var o=n._fullLayout._has(\"gl2d\")?[]:L.listIds(n,r),i=\"a\"+r+\"ref\",l={};return l[i]={valType:\"enumerated\",values:o.concat([\"pixel\"]),dflt:a||\"pixel\"||o[0]},_.coerce(t,e,l,i)},L.clearTypes=function(t,e){Array.isArray(e)&&e.length||(e=t._fullData.map(function(t,e){return e})),e.forEach(function(e){var n=t.data[e];delete(L.getFromId(t,n.xaxis)||{}).type,delete(L.getFromId(t,n.yaxis)||{}).type})},L.counterLetter=function(t){var e=t.charAt(0);return\"x\"===e?\"y\":\"y\"===e?\"x\":void 0},L.minDtick=function(t,e,n,r){-1===[\"log\",\"category\"].indexOf(t.type)&&r?null===t._minDtick?(t._minDtick=e,t._forceTick0=n):t._minDtick&&((t._minDtick/e+1e-6)%1<2e-6&&((n-t._forceTick0)/e%1+1.000001)%1<2e-6?(t._minDtick=e,t._forceTick0=n):((e/t._minDtick+1e-6)%1>2e-6||((n-t._forceTick0)/t._minDtick%1+1.000001)%1>2e-6)&&(t._minDtick=0)):t._minDtick=0},L.getAutoRange=function(t){var e,n=[],r=t._min[0].val,a=t._max[0].val;for(e=1;e<t._min.length&&r===a;e++)r=Math.min(r,t._min[e].val);for(e=1;e<t._max.length&&r===a;e++)a=Math.max(a,t._max[e].val);var o,i,l,s,c,u,f,d=0,h=t.range&&t.range[1]<t.range[0];for(\"reversed\"===t.autorange&&(h=!0,t.autorange=!0),e=0;e<t._min.length;e++)for(i=t._min[e],o=0;o<t._max.length;o++)l=t._max[o],f=l.val-i.val,u=t._length-i.pad-l.pad,f>0&&u>0&&f/u>d&&(s=i,c=l,d=f/u);return r===a?n=h?[r+1,\"normal\"!==t.rangemode?0:r-1]:[\"normal\"!==t.rangemode?0:r-1,r+1]:d&&(\"linear\"!==t.type&&\"-\"!==t.type||(\"tozero\"===t.rangemode&&s.val>=0?s={val:0,pad:0}:\"nonnegative\"===t.rangemode&&(s.val-d*s.pad<0&&(s={val:0,pad:0}),c.val<0&&(c={val:1,pad:0})),d=(c.val-s.val)/(t._length-s.pad-c.pad)),n=[s.val-d*s.pad,c.val+d*c.pad],n[0]===n[1]&&(n=[n[0]-1,n[0]+1]),h&&n.reverse()),n},L.doAutoRange=function(t){t._length||t.setScale();var e=t._min&&t._max&&t._min.length&&t._max.length;if(t.autorange&&e){t.range=L.getAutoRange(t);var n=t._gd.layout[t._name];n||(t._gd.layout[t._name]=n={}),n!==t&&(n.range=t.range.slice(),n.autorange=t.autorange)}},L.saveRangeInitial=function(t,e){for(var n=L.list(t,\"\",!0),r=!1,a=0;a<n.length;a++){var o=n[a],i=void 0===o._rangeInitial,l=i||!(o.range[0]===o._rangeInitial[0]&&o.range[1]===o._rangeInitial[1]);(i&&o.autorange===!1||e&&l)&&(o._rangeInitial=o.range.slice(),r=!0)}return r};var z=Number.MAX_VALUE/2;L.expand=function(t,e,n){function r(t){if(Array.isArray(t))return function(e){return Math.max(Number(t[e]||0),0)};var e=Math.max(Number(t||0),0);return function(){return e}}function a(n){function r(t){return x(t)&&Math.abs(t)<z}if(s=e[n],x(s)){if(f=b(n)+m,d=_(n)+m,p=s-k(n),g=s+w(n),\"log\"===t.type&&g/10>p&&(p=g/10),c=t.c2l(p),u=t.c2l(g),y&&(c=Math.min(0,c),u=Math.max(0,u)),r(c)){for(h=!0,i=0;i<t._min.length&&h;i++)l=t._min[i],l.val<=c&&l.pad>=d?h=!1:l.val>=c&&l.pad<=d&&(t._min.splice(i,1),i--);h&&t._min.push({val:c,pad:y&&0===c?0:d})}if(r(u)){for(h=!0,i=0;i<t._max.length&&h;i++)l=t._max[i],l.val>=u&&l.pad>=f?h=!1:l.val<=u&&l.pad<=f&&(t._max.splice(i,1),i--);h&&t._max.push({val:u,pad:y&&0===u?0:f})}}}if((t.autorange||t._needsExpand)&&e){t._min||(t._min=[]),t._max||(t._max=[]),n||(n={}),t._m||t.setScale();var o,i,l,s,c,u,f,d,h,p,g,v=e.length,m=n.padded?.05*t._length:0,y=n.tozero&&(\"linear\"===t.type||\"-\"===t.type),b=r((t._m>0?n.ppadplus:n.ppadminus)||n.ppad||0),_=r((t._m>0?n.ppadminus:n.ppadplus)||n.ppad||0),w=r(n.vpadplus||n.vpad),k=r(n.vpadminus||n.vpad);for(o=0;6>o;o++)a(o);for(o=v-1;o>5;o--)a(o)}},L.autoBin=function(t,e,n,r){function a(t){return(1+100*(t-h)/f.dtick)%100<2}var o=_.aggNums(Math.min,null,t),i=_.aggNums(Math.max,null,t);if(\"category\"===e.type)return{start:o-.5,end:i+.5,size:1};var l;if(n)l=(i-o)/n;else{var s=_.distinctVals(t),c=Math.pow(10,Math.floor(Math.log(s.minDiff)/Math.LN10)),u=c*_.roundUp(s.minDiff/c,[.9,1.9,4.9,9.9],!0);l=Math.max(u,2*_.stdev(t)/Math.pow(t.length,r?.25:.4))}var f={type:\"log\"===e.type?\"linear\":e.type,range:[o,i]};L.autoTicks(f,l);var d,h=L.tickIncrement(L.tickFirst(f),f.dtick,\"reverse\");if(\"number\"==typeof f.dtick){for(var p=0,g=0,v=0,m=0,y=0;y<t.length;y++)t[y]%1===0?v++:x(t[y])||m++,a(t[y])&&p++,a(t[y]+f.dtick/2)&&g++;var b=t.length-m;if(v===b&&\"date\"!==e.type)f.dtick<1?h=o-.5*f.dtick:h-=.5;else if(.1*b>g&&(p>.3*b||a(o)||a(i))){var w=f.dtick/2;h+=o>h+w?w:-w}var k=1+Math.floor((i-h)/f.dtick);d=h+k*f.dtick}else for(d=h;i>=d;)d=L.tickIncrement(d,f.dtick);return{start:h,end:d,size:f.dtick}},L.calcTicks=function(t){if(\"array\"===t.tickmode)return r(t);if(\"auto\"===t.tickmode||!t.dtick){var e,n=t.nticks;n||(\"category\"===t.type?(e=t.tickfont?1.2*(t.tickfont.size||12):15,n=t._length/e):(e=\"y\"===t._id.charAt(0)?40:80,n=_.constrain(t._length/e,4,9)+1)),L.autoTicks(t,Math.abs(t.range[1]-t.range[0])/n),t._minDtick>0&&t.dtick<2*t._minDtick&&(t.dtick=t._minDtick,t.tick0=t._forceTick0)}t.tick0||(t.tick0=\"date\"===t.type?new Date(2e3,0,1).getTime():0),o(t),t._tmin=L.tickFirst(t);var a=t.range[1]<t.range[0],i=[],l=1.0001*t.range[1]-1e-4*t.range[0];\"category\"===t.type&&(l=a?Math.max(-.5,l):Math.min(t._categories.length-.5,l));for(var s=t._tmin;(a?s>=l:l>=s)&&(i.push(s),!(i.length>1e3));s=L.tickIncrement(s,t.dtick,a));t._tmax=i[i.length-1];for(var c=new Array(i.length),u=0;u<i.length;u++)c[u]=L.tickText(t,i[u]);return c};var S=[2,5,10],E=[1,2,3,6,12],C=[1,2,5,10,15,30],O=[1,2,3,7,14],P=[-.046,0,.301,.477,.602,.699,.778,.845,.903,.954,1],N=[-.301,0,.301,.699,1];L.autoTicks=function(t,e){var n;if(\"date\"===t.type)t.tick0=new Date(2e3,0,1).getTime(),e>157788e5?(e/=315576e5,n=Math.pow(10,Math.floor(Math.log(e)/Math.LN10)),t.dtick=\"M\"+12*a(e,n,S)):e>12096e5?(e/=26298e5,t.dtick=\"M\"+a(e,1,E)):e>432e5?(t.dtick=a(e,864e5,O),t.tick0=new Date(2e3,0,2).getTime()):e>18e5?t.dtick=a(e,36e5,E):e>3e4?t.dtick=a(e,6e4,C):e>500?t.dtick=a(e,1e3,C):(n=Math.pow(10,Math.floor(Math.log(e)/Math.LN10)),t.dtick=a(e,n,S));else if(\"log\"===t.type)if(t.tick0=0,e>.7)t.dtick=Math.ceil(e);else if(Math.abs(t.range[1]-t.range[0])<1){var r=1.5*Math.abs((t.range[1]-t.range[0])/e);e=Math.abs(Math.pow(10,t.range[1])-Math.pow(10,t.range[0]))/r,n=Math.pow(10,Math.floor(Math.log(e)/Math.LN10)),t.dtick=\"L\"+a(e,n,S)}else t.dtick=e>.3?\"D2\":\"D1\";else\"category\"===t.type?(t.tick0=0,t.dtick=Math.ceil(Math.max(e,1))):(t.tick0=0,n=Math.pow(10,Math.floor(Math.log(e)/Math.LN10)),t.dtick=a(e,n,S));if(0===t.dtick&&(t.dtick=1),!x(t.dtick)&&\"string\"!=typeof t.dtick){var o=t.dtick;throw t.dtick=1,\"ax.dtick error: \"+String(o)}},L.tickIncrement=function(t,e,n){var r=n?-1:1;if(x(e))return t+r*e;var a=e.charAt(0),o=r*Number(e.substr(1));if(\"M\"===a){var i=new Date(t);return i.setMonth(i.getMonth()+o)}if(\"L\"===a)return Math.log(Math.pow(10,t)+o)/Math.LN10;if(\"D\"===a){var l=\"D2\"===e?N:P,s=t+.01*r,c=_.roundUp(m(s,1),l,n);return Math.floor(s)+Math.log(y.round(Math.pow(10,c),1))/Math.LN10}throw\"unrecognized dtick \"+String(e)},L.tickFirst=function(t){var e=t.range[1]<t.range[0],n=e?Math.floor:Math.ceil,r=1.0001*t.range[0]-1e-4*t.range[1],a=t.dtick,o=t.tick0;if(x(a)){var i=n((r-o)/a)*a+o;return\"category\"===t.type&&(i=_.constrain(i,0,t._categories.length-1)),i}var l,s,c,u=a.charAt(0),f=Number(a.substr(1));if(\"M\"===u){for(l=new Date(o),r=new Date(r),s=12*(r.getFullYear()-l.getFullYear())+r.getMonth()-l.getMonth(),c=l.setMonth(l.getMonth()+(Math.round(s/f)+(e?1:-1))*f);e?c>r:r>c;)c=L.tickIncrement(c,a,e);return c}if(\"L\"===u)return Math.log(n((Math.pow(10,r)-o)/f)*f+o)/Math.LN10;if(\"D\"===u){var d=\"D2\"===a?N:P,h=_.roundUp(m(r,1),d,e);return Math.floor(r)+Math.log(y.round(Math.pow(10,h),1))/Math.LN10}throw\"unrecognized dtick \"+String(a)};var D=y.time.format(\"%Y\"),I=y.time.format(\"%b %Y\"),R=y.time.format(\"%b %-d\"),j=y.time.format(\"%b %-d %Hh\"),q=y.time.format(\"%H:%M\"),F=y.time.format(\":%S\"),B=/%(\\d?)f/g;L.tickText=function(t,e,n){function r(r){var a;return void 0===r?!0:n?\"none\"===r:(a={first:t._tmin,last:t._tmax}[r],\"all\"!==r&&e!==a)}var a,o,i=l(t,e),d=\"array\"===t.tickmode,h=n||d;if(d&&Array.isArray(t.ticktext)){var p=Math.abs(t.range[1]-t.range[0])/1e4;for(o=0;o<t.ticktext.length&&!(Math.abs(e-t.d2l(t.tickvals[o]))<p);o++);if(o<t.ticktext.length)return i.text=String(t.ticktext[o]),i}return a=\"none\"!==t.exponentformat&&r(t.showexponent)?\"hide\":\"\",\"date\"===t.type?s(t,i,n,h):\"log\"===t.type?c(t,i,n,h,a):\"category\"===t.type?u(t,i):f(t,i,n,h,a),t.tickprefix&&!r(t.showtickprefix)&&(i.text=t.tickprefix+i.text),t.ticksuffix&&!r(t.showticksuffix)&&(i.text+=t.ticksuffix),i};var H=[\"f\",\"p\",\"n\",\"&mu;\",\"m\",\"\",\"k\",\"M\",\"G\",\"T\"];L.subplotMatch=/^x([0-9]*)y([0-9]*)$/,L.getSubplots=function(t,e){function n(t,e){return-1!==t.indexOf(e._id)}var r,a,o,i=[],l=t.data||[];for(r=0;r<l.length;r++){var s=l[r];if(s.visible!==!1&&\"legendonly\"!==s.visible&&(b.Plots.traceIs(s,\"cartesian\")||b.Plots.traceIs(s,\"gl2d\"))){var c=s.xaxis||\"x\",u=s.yaxis||\"y\";o=c+u,-1===i.indexOf(o)&&i.push(o)}}var f=L.list(t,\"\",!0);for(r=0;r<f.length;r++){var d=f[r],h=d._id.charAt(0),p=\"free\"===d.anchor?\"x\"===h?\"y\":\"x\":d.anchor,g=L.getFromId(t,p),v=!1;for(a=0;a<i.length;a++)if(n(i[a],d)){v=!0;break}\"free\"===d.anchor&&v||g&&(o=\"x\"===h?d._id+g._id:g._id+d._id,-1===i.indexOf(o)&&i.push(o))}var m=L.subplotMatch,y=[];for(r=0;r<i.length;r++)o=i[r],m.test(o)&&y.push(o);return y.sort(function(t,e){var n=t.match(m),r=e.match(m);return n[1]===r[1]?+(n[2]||1)-(r[2]||1):+(n[1]||0)-(r[1]||0)}),e?L.findSubplotsWithAxis(y,e):y},L.findSubplotsWithAxis=function(t,e){for(var n=new RegExp(\"x\"===e._id.charAt(0)?\"^\"+e._id+\"y\":e._id+\"$\"),r=[],a=0;a<t.length;a++){var o=t[a];n.test(o)&&r.push(o)}return r},L.makeClipPaths=function(t){var e,n,r=t._fullLayout,a=r._defs,o={_offset:0,_length:r.width,_id:\"\"},i={_offset:0,_length:r.height,_id:\"\"},l=L.list(t,\"x\",!0),s=L.list(t,\"y\",!0),c=[];for(e=0;e<l.length;e++)for(c.push({x:l[e],y:i}),n=0;n<s.length;n++)0===e&&c.push({x:o,y:s[n]}),c.push({x:l[e],y:s[n]});var u=a.selectAll(\"g.clips\").data([0]);u.enter().append(\"g\").classed(\"clips\",!0);var f=u.selectAll(\".axesclip\").data(c,function(t){return t.x._id+t.y._id});f.enter().append(\"clipPath\").classed(\"axesclip\",!0).attr(\"id\",function(t){return\"clip\"+r"
,
"._uid+t.x._id+t.y._id}).append(\"rect\"),f.exit().remove(),f.each(function(t){y.select(this).select(\"rect\").attr({x:t.x._offset||0,y:t.y._offset||0,width:t.x._length||1,height:t.y._length||1})})},L.doTicks=function(t,e,n){function r(t){var e=c.l2p(t.x);return e>1&&e<c._length-1}function a(t,e){var n=t.selectAll(\"path.\"+E).data(\"inside\"===c.ticks?H:z,S);e&&c.ticks?(n.enter().append(\"path\").classed(E,1).classed(\"ticks\",1).classed(\"crisp\",1).call(M.stroke,c.tickcolor).style(\"stroke-width\",j+\"px\").attr(\"d\",e),n.attr(\"transform\",h),n.exit().remove()):n.remove()}function o(n,r){function a(t,e){t.each(function(t){var n=p(e),r=y.select(this),a=r.select(\".text-math-group\"),o=h(t)+(x(e)&&0!==+e?\" rotate(\"+e+\",\"+f(t)+\",\"+(d(t)-t.fontSize/2)+\")\":\"\");if(a.empty()){var i=r.select(\"text\").attr({transform:o,\"text-anchor\":n});i.empty()||i.selectAll(\"tspan.line\").attr({x:i.attr(\"x\"),y:i.attr(\"y\")})}else{var l=A.bBox(a.node()).width*{end:-.5,start:.5}[n];a.attr(\"transform\",o+(l?\"translate(\"+l+\",0)\":\"\"))}})}function o(){return L.length&&Promise.all(L)}function l(){if(a(u,c.tickangle),\"x\"===v&&!x(c.tickangle)&&(\"log\"!==c.type||\"D\"!==String(c.dtick).charAt(0))){var t=[];for(u.each(function(e){var n=y.select(this),r=n.select(\".text-math-group\"),a=c.l2p(e.x);r.empty()&&(r=n.select(\"text\"));var o=A.bBox(r.node());t.push({top:0,bottom:10,height:10,left:a-o.width/2,right:a+o.width/2+2,width:o.width+2})}),g=0;g<t.length-1;g++)if(_.bBoxIntersect(t[g],t[g+1])){M=30;break}if(M){var n=Math.abs((z[z.length-1].x-z[0].x)*c._m)/(z.length-1);2.5*k>n&&(M=90),a(u,M)}c._lastangle=M}return i(e),e+\" done\"}function s(){c._boundingBox=n.node().getBoundingClientRect()}var u=n.selectAll(\"g.\"+E).data(z,S);if(!c.showticklabels||!x(r))return u.remove(),void i(e);var f,d,p,m,b;\"x\"===v?(b=\"bottom\"===F?1:-1,f=function(t){return t.dx+D*b},m=r+(N+P)*b,d=function(t){return t.dy+m+t.fontSize*(\"bottom\"===F?1:-.5)},p=function(t){return x(t)&&0!==t&&180!==t?0>t*b?\"end\":\"start\":\"middle\"}):(b=\"right\"===F?1:-1,d=function(t){return t.dy+t.fontSize/2-D*b},f=function(t){return t.dx+r+(N+P+(90===Math.abs(c.tickangle)?t.fontSize/2:0))*b},p=function(t){return x(t)&&90===Math.abs(t)?\"middle\":\"right\"===F?\"start\":\"end\"});var k=0,M=0,L=[];u.enter().append(\"g\").classed(E,1).append(\"text\").attr(\"text-anchor\",\"middle\").each(function(e){var n=y.select(this),r=t._promises.length;n.call(A.setPosition,f(e),d(e)).call(A.font,e.font,e.fontSize,e.fontColor).text(e.text).call(w.convertToTspans),r=t._promises[r],r?L.push(t._promises.pop().then(function(){a(n,c.tickangle)})):a(n,c.tickangle)}),u.exit().remove(),u.each(function(t){k=Math.max(k,t.fontSize)}),a(u,c._lastangle||c.tickangle);var T=_.syncOrAsync([o,l,s]);return T&&T.then&&t._promises.push(T),T}function i(e){if(!n){var r,a,o,i,l=T.getFromId(t,e),s=y.select(t).selectAll(\"g.\"+e+\"tick\"),c={selection:s,side:l.side},f=e.charAt(0),d=t._fullLayout._size,h=1.5,p=l.titlefont.size;if(s.size()){var g=y.select(s.node().parentNode).attr(\"transform\").match(/translate\\(([-\\.\\d]+),([-\\.\\d]+)\\)/);g&&(c.offsetLeft=+g[1],c.offsetTop=+g[2])}\"x\"===f?(a=\"free\"===l.anchor?{_offset:d.t+(1-(l.position||0))*d.h,_length:0}:T.getFromId(t,l.anchor),o=l._offset+l._length/2,i=a._offset+(\"top\"===l.side?-10-p*(h+(l.showticklabels?1:0)):a._length+10+p*(h+(l.showticklabels?1.5:.5))),l.rangeslider&&l.rangeslider.visible&&l._boundingBox&&(i+=(u.height-u.margin.b-u.margin.t)*l.rangeslider.thickness+l._boundingBox.height),c.side||(c.side=\"bottom\")):(a=\"free\"===l.anchor?{_offset:d.l+(l.position||0)*d.w,_length:0}:T.getFromId(t,l.anchor),i=l._offset+l._length/2,o=a._offset+(\"right\"===l.side?a._length+10+p*(h+(l.showticklabels?1:.5)):-10-p*(h+(l.showticklabels?.5:0))),r={rotate:\"-90\",offset:0},c.side||(c.side=\"left\")),k.draw(t,e+\"title\",{propContainer:l,propName:l._name+\".title\",dfltName:f.toUpperCase()+\" axis\",avoid:c,transform:r,attributes:{x:o,y:i,\"text-anchor\":\"middle\"}})}}function l(t,e){return t.visible!==!0||t.xaxis+t.yaxis!==e?!1:b.Plots.traceIs(t,\"bar\")&&t.orientation==={x:\"h\",y:\"v\"}[v]?!0:t.fill&&t.fill.charAt(t.fill.length-1)===v}function s(e,n,a){var o=e.gridlayer,i=e.zerolinelayer,s=e[\"hidegrid\"+v]?[]:H,u=c._gridpath||\"M0,0\"+(\"x\"===v?\"v\":\"h\")+n._length,f=o.selectAll(\"path.\"+C).data(c.showgrid===!1?[]:s,S);if(f.enter().append(\"path\").classed(C,1).classed(\"crisp\",1).attr(\"d\",u).each(function(t){c.zeroline&&(\"linear\"===c.type||\"-\"===c.type)&&Math.abs(t.x)<c.dtick/100&&y.select(this).remove()}),f.attr(\"transform\",h).call(M.stroke,c.gridcolor||\"#ddd\").style(\"stroke-width\",I+\"px\"),f.exit().remove(),i){for(var d=!1,p=0;p<t._fullData.length;p++)if(l(t._fullData[p],a)){d=!0;break}var g=c.range[0]*c.range[1]<=0&&c.zeroline&&(\"linear\"===c.type||\"-\"===c.type)&&s.length&&(d||r({x:0})||!c.showline),m=i.selectAll(\"path.\"+O).data(g?[{x:0}]:[]);m.enter().append(\"path\").classed(O,1).classed(\"zl\",1).classed(\"crisp\",1).attr(\"d\",u),m.attr(\"transform\",h).call(M.stroke,c.zerolinecolor||M.defaultLine).style(\"stroke-width\",R+\"px\"),m.exit().remove()}}var c,u=t._fullLayout,f=!1;if(\"object\"==typeof e)c=e,e=c._id,f=!0;else if(c=L.getFromId(t,e),\"redraw\"===e&&u._paper.selectAll(\"g.subplot\").each(function(t){var e=u._plots[t],n=e.x(),r=e.y();e.xaxislayer.selectAll(\".\"+n._id+\"tick\").remove(),e.yaxislayer.selectAll(\".\"+r._id+\"tick\").remove(),e.gridlayer.selectAll(\"path\").remove(),e.zerolinelayer.selectAll(\"path\").remove()}),!e||\"redraw\"===e)return _.syncOrAsync(L.list(t,\"\",!0).map(function(n){return function(){if(n._id){var r=L.doTicks(t,n._id);return\"redraw\"===e&&(n._r=n.range.slice()),r}}}));c.tickformat||(-1===[\"none\",\"e\",\"E\",\"power\",\"SI\",\"B\"].indexOf(c.exponentformat)&&(c.exponentformat=\"e\"),-1===[\"all\",\"first\",\"last\",\"none\"].indexOf(c.showexponent)&&(c.showexponent=\"all\")),c.range=[+c.range[0],+c.range[1]],c.setScale();var d,h,p,g,v=e.charAt(0),m=L.counterLetter(e),z=L.calcTicks(c),S=function(t){return t.text+t.x+c.mirror},E=e+\"tick\",C=e+\"grid\",O=e+\"zl\",P=(c.linewidth||1)/2,N=(\"outside\"===c.ticks?c.ticklen:1)+(c.linewidth||0),D=0,I=A.crispRound(t,c.gridwidth,1),R=A.crispRound(t,c.zerolinewidth,I),j=A.crispRound(t,c.tickwidth,1);if(c._counterangle&&\"outside\"===c.ticks){var q=c._counterangle*Math.PI/180;N=c.ticklen*Math.cos(q)+(c.linewidth||0),D=c.ticklen*Math.sin(q)}if(\"x\"===v)d=[\"bottom\",\"top\"],h=function(t){return\"translate(\"+c.l2p(t.x)+\",0)\"},p=function(t,e){if(c._counterangle){var n=c._counterangle*Math.PI/180;return\"M0,\"+t+\"l\"+Math.sin(n)*e+\",\"+Math.cos(n)*e}return\"M0,\"+t+\"v\"+e};else{if(\"y\"!==v)return void _.warn(\"Unrecognized doTicks axis:\",e);d=[\"left\",\"right\"],h=function(t){return\"translate(0,\"+c.l2p(t.x)+\")\"},p=function(t,e){if(c._counterangle){var n=c._counterangle*Math.PI/180;return\"M\"+t+\",0l\"+Math.cos(n)*e+\",\"+-Math.sin(n)*e}return\"M\"+t+\",0h\"+e}}var F=c.side||d[0],B=[-1,1,F===d[1]?1:-1];\"inside\"!==c.ticks==(\"x\"===v)&&(B=B.map(function(t){return-t}));var H=z.filter(r);if(f){if(a(c._axislayer,p(c._pos+P*B[2],B[2]*c.ticklen)),c._counteraxis){var V={gridlayer:c._gridlayer,zerolinelayer:c._zerolinelayer};s(V,c._counteraxis)}return o(c._axislayer,c._pos)}var Z=L.getSubplots(t,c).map(function(t){var e=u._plots[t];if(u._has(\"cartesian\")){var n=e[v+\"axislayer\"],r=c._linepositions[t]||[],i=e[m](),l=i._id===c.anchor,f=[!1,!1,!1],h=\"\";if(\"allticks\"===c.mirror?f=[!0,!0,!1]:l&&(\"ticks\"===c.mirror?f=[!0,!0,!1]:f[d.indexOf(F)]=!0),c.mirrors)for(g=0;2>g;g++){var y=c.mirrors[i._id+d[g]];\"ticks\"!==y&&\"labels\"!==y||(f[g]=!0)}return void 0!==r[2]&&(f[2]=!0),f.forEach(function(t,e){var n=r[e],a=B[e];t&&x(n)&&(h+=p(n+P*a,a*c.ticklen))}),a(n,h),s(e,i,t),o(n,r[3])}}).filter(function(t){return t&&t.then});return Z.length?Promise.all(Z):0},L.swap=function(t,e){for(var n=h(t,e),r=0;r<n.length;r++)g(t,n[r].x,n[r].y)}},{\"../../components/color\":18,\"../../components/drawing\":41,\"../../components/titles\":81,\"../../lib\":89,\"../../lib/svg_text_utils\":100,\"../../plotly\":107,\"./axis_ids\":112,\"./layout_attributes\":119,\"./layout_defaults\":120,\"./set_convert\":124,d3:9,\"fast-isnumeric\":11}],111:[function(t,e,n){\"use strict\";function r(t,e){if(\"-\"===t.type){var n=t._id,r=n.charAt(0);-1!==n.indexOf(\"scene\")&&(n=r);var s=l(e,n,r);if(s){if(\"histogram\"===s.type&&r==={v:\"y\",h:\"x\"}[s.orientation||\"v\"])return void(t.type=\"linear\");if(o(s,r)){for(var c,u=a(s),f=[],d=0;d<e.length;d++)c=e[d],p.traceIs(c,\"box\")&&(c[r+\"axis\"]||r)===n&&(void 0!==c[u]?f.push(c[u][0]):void 0!==c.name?f.push(c.name):f.push(\"text\"));t.type=i(f)}else t.type=i(s[r]||[s[r+\"0\"]])}}}function a(t){return{v:\"x\",h:\"y\"}[t.orientation||\"v\"]}function o(t,e){var n=a(t);return p.traceIs(t,\"box\")&&e===n&&void 0===t[n]&&void 0===t[n+\"0\"]}function i(t){return c(t)?\"date\":u(t)?\"category\":s(t)?\"linear\":\"-\"}function l(t,e,n){for(var r=0;r<t.length;r++){var a=t[r];if((a[n+\"axis\"]||n)===e){if(o(a,n))return a;if((a[n]||[]).length||a[n+\"0\"])return a}}}function s(t){if(!t)return!1;for(var e=0;e<t.length;e++)if(f(t[e]))return!0;return!1}function c(t){for(var e,n=0,r=0,a=Math.max(1,(t.length-1)/1e3),o=0;o<t.length;o+=a)e=t[Math.round(o)],h.isDateTime(e)&&(n+=1),f(e)&&(r+=1);return n>2*r}function u(t){for(var e,n=Math.max(1,(t.length-1)/1e3),r=0,a=0,o=0;o<t.length;o+=n)e=k(t[Math.round(o)]),f(e)?r++:\"string\"==typeof e&&\"\"!==e&&\"None\"!==e&&a++;return a>2*r}var f=t(\"fast-isnumeric\"),d=t(\"tinycolor2\").mix,h=t(\"../../lib\"),p=t(\"../plots\"),g=t(\"../../components/color/attributes\").lightFraction,v=t(\"./layout_attributes\"),m=t(\"./tick_value_defaults\"),y=t(\"./tick_mark_defaults\"),x=t(\"./tick_label_defaults\"),b=t(\"./category_order_defaults\"),_=t(\"./set_convert\"),w=t(\"./ordered_categories\"),k=t(\"./clean_datum\"),M=t(\"./axis_ids\");e.exports=function(t,e,n,a){function o(n,r){return h.coerce2(t,e,v,n,r)}var i=a.letter,l=a.font||{},s=\"Click to enter \"+(a.title||i.toUpperCase()+\" axis\")+\" title\";a.name&&(e._name=a.name,e._id=M.name2id(a.name));var c=n(\"type\");\"-\"===c&&(r(e,a.data),\"-\"===e.type?e.type=\"linear\":c=t.type=e.type),_(e);var u=n(\"color\"),p=u===t.color?u:l.color;n(\"title\",s),h.coerceFont(n,\"titlefont\",{family:l.family,size:Math.round(1.2*l.size),color:p});var k=2===(t.range||[]).length&&"
,
"f(t.range[0])&&f(t.range[1]),A=n(\"autorange\",!k);A&&n(\"rangemode\");var L=n(\"range\",[-1,\"x\"===i?6:4]);L[0]===L[1]&&(e.range=[L[0]-1,L[0]+1]),h.noneOrAll(t.range,e.range,[0,1]),n(\"fixedrange\"),m(t,e,n,c),x(t,e,n,c,a),y(t,e,n,a),b(t,e,n);var T=o(\"linecolor\",u),z=o(\"linewidth\"),S=n(\"showline\",!!T||!!z);S||(delete e.linecolor,delete e.linewidth),(S||e.ticks)&&n(\"mirror\");var E=o(\"gridcolor\",d(u,a.bgColor,g).toRgbString()),C=o(\"gridwidth\"),O=n(\"showgrid\",a.showGrid||!!E||!!C);O||(delete e.gridcolor,delete e.gridwidth);var P=o(\"zerolinecolor\",u),N=o(\"zerolinewidth\"),D=n(\"zeroline\",a.showGrid||!!P||!!N);return D||(delete e.zerolinecolor,delete e.zerolinewidth),e._initialCategories=\"category\"===c?w(i,e.categoryorder,e.categoryarray,a.data):[],e}},{\"../../components/color/attributes\":17,\"../../lib\":89,\"../plots\":130,\"./axis_ids\":112,\"./category_order_defaults\":113,\"./clean_datum\":114,\"./layout_attributes\":119,\"./ordered_categories\":121,\"./set_convert\":124,\"./tick_label_defaults\":125,\"./tick_mark_defaults\":126,\"./tick_value_defaults\":127,\"fast-isnumeric\":11,tinycolor2:13}],112:[function(t,e,n){\"use strict\";function r(t,e,n){function r(t,n){for(var r=Object.keys(t),a=/^[xyz]axis[0-9]*/,o=[],i=0;i<r.length;i++){var l=r[i];e&&l.charAt(0)!==e||a.test(l)&&o.push(n+l)}return o.sort()}var o=t._fullLayout;if(!o)return[];var i=r(o,\"\");if(n)return i;for(var l=a.getSubplotIds(o,\"gl3d\")||[],s=0;s<l.length;s++){var c=l[s];i=i.concat(r(o[c],c+\".\"))}return i}var a=t(\"../plots\"),o=t(\"../../lib\"),i=t(\"./constants\");n.id2name=function(t){if(\"string\"==typeof t&&t.match(i.AX_ID_PATTERN)){var e=t.substr(1);return\"1\"===e&&(e=\"\"),t.charAt(0)+\"axis\"+e}},n.name2id=function(t){if(t.match(i.AX_NAME_PATTERN)){var e=t.substr(5);return\"1\"===e&&(e=\"\"),t.charAt(0)+e}},n.cleanId=function(t,e){if(t.match(i.AX_ID_PATTERN)&&(!e||t.charAt(0)===e)){var n=t.substr(1).replace(/^0+/,\"\");return\"1\"===n&&(n=\"\"),t.charAt(0)+n}},n.list=function(t,e,n){return r(t,e,n).map(function(e){return o.nestedProperty(t._fullLayout,e).get();\n"
,
"})},n.listIds=function(t,e){return r(t,e,!0).map(n.name2id)},n.getFromId=function(t,e,r){var a=t._fullLayout;return\"x\"===r?e=e.replace(/y[0-9]*/,\"\"):\"y\"===r&&(e=e.replace(/x[0-9]*/,\"\")),a[n.id2name(e)]},n.getFromTrace=function(t,e,r){var o=t._fullLayout,i=null;if(a.traceIs(e,\"gl3d\")){var l=e.scene;\"scene\"===l.substr(0,5)&&(i=o[l][r+\"axis\"])}else i=n.getFromId(t,e[r+\"axis\"]||r);return i}},{\"../../lib\":89,\"../plots\":130,\"./constants\":115}],113:[function(t,e,n){\"use strict\";e.exports=function(t,e,n){if(\"category\"===e.type){var r,a=t.categoryarray,o=Array.isArray(a)&&a.length>0;o&&(r=\"array\");var i=n(\"categoryorder\",r);\"array\"===i&&n(\"categoryarray\"),o||\"array\"!==i||(e.categoryorder=\"trace\")}}},{}],114:[function(t,e,n){\"use strict\";var r=t(\"fast-isnumeric\"),a=t(\"../../lib\");e.exports=function(t){try{if(\"object\"==typeof t&&null!==t&&t.getTime)return a.ms2DateTime(t);if(\"string\"!=typeof t&&!r(t))return\"\";t=t.toString().replace(/['\"%,$# ]/g,\"\")}catch(e){a.error(e,t)}return t}},{\"../../lib\":89,\"fast-isnumeric\":11}],115:[function(t,e,n){\"use strict\";e.exports={idRegex:{x:/^x([2-9]|[1-9][0-9]+)?$/,y:/^y([2-9]|[1-9][0-9]+)?$/},attrRegex:{x:/^xaxis([2-9]|[1-9][0-9]+)?$/,y:/^yaxis([2-9]|[1-9][0-9]+)?$/},BADNUM:void 0,xAxisMatch:/^xaxis[0-9]*$/,yAxisMatch:/^yaxis[0-9]*$/,AX_ID_PATTERN:/^[xyz][0-9]*$/,AX_NAME_PATTERN:/^[xyz]axis[0-9]*$/,DBLCLICKDELAY:300,MINDRAG:8,MINSELECT:12,MINZOOM:20,DRAGGERSIZE:20,MAXDIST:20,YANGLE:60,HOVERARROWSIZE:6,HOVERTEXTPAD:3,HOVERFONTSIZE:13,HOVERFONT:\"Arial, sans-serif\",HOVERMINTIME:50,BENDPX:1.5,REDRAWDELAY:50}},{}],116:[function(t,e,n){\"use strict\";function r(t,e){var n,r=t.range[e],a=Math.abs(r-t.range[1-e]);return\"date\"===t.type?u.ms2DateTime(r,a):\"log\"===t.type?(n=Math.ceil(Math.max(0,-Math.log(a)/Math.LN10))+3,l.format(\".\"+n+\"g\")(Math.pow(10,r))):(n=Math.floor(Math.log(Math.abs(r))/Math.LN10)-Math.floor(Math.log(a)/Math.LN10)+4,l.format(\".\"+String(n)+\"g\")(r))}function a(t,e){return t?\"nsew\"===t?\"pan\"===e?\"move\":\"crosshair\":t.toLowerCase()+\"-resize\":\"pointer\"}function o(t){l.select(t).selectAll(\".zoombox,.js-zoombox-backdrop,.js-zoombox-menu,.zoombox-corners\").remove()}function i(t){var e=[\"lasso\",\"select\"];return-1!==e.indexOf(t)}var l=t(\"d3\"),s=t(\"tinycolor2\"),c=t(\"../../plotly\"),u=t(\"../../lib\"),f=t(\"../../lib/svg_text_utils\"),d=t(\"../../components/color\"),h=t(\"../../components/drawing\"),p=t(\"../../lib/setcursor\"),g=t(\"../../components/dragelement\"),v=t(\"./axes\"),m=t(\"./select\"),y=t(\"./constants\"),x=!0;e.exports=function(t,e,n,l,b,_,w,k){function M(t,e){for(var n=0;n<t.length;n++)if(!t[n].fixedrange)return e;return\"\"}function A(t){t[0]=Number(t[0]),t[1]=Number(t[1])}function L(e,n,r){var a=nt.getBoundingClientRect();at=n-a.left,ot=r-a.top,it={l:at,r:at,w:0,t:ot,b:ot,h:0},lt=t._hmpixcount?t._hmlumcount/t._hmpixcount:s(t._fullLayout.plot_bgcolor).getLuminance(),st=\"M0,0H\"+H+\"V\"+V+\"H0V0\",ct=!1,ut=\"xy\",ft=ht.append(\"path\").attr(\"class\",\"zoombox\").style({fill:lt>.2?\"rgba(0,0,0,0)\":\"rgba(255,255,255,0)\",\"stroke-width\":0}).attr(\"transform\",\"translate(\"+pt+\", \"+gt+\")\").attr(\"d\",st+\"Z\"),dt=ht.append(\"path\").attr(\"class\",\"zoombox-corners\").style({fill:d.background,stroke:d.defaultLine,\"stroke-width\":1,opacity:0}).attr(\"transform\",\"translate(\"+pt+\", \"+gt+\")\").attr(\"d\",\"M0,0Z\"),T();for(var o=0;o<Q.length;o++)A(Q[o].range)}function T(){ht.selectAll(\".select-outline\").remove()}function z(t,e){var n=Math.max(0,Math.min(H,t+at)),r=Math.max(0,Math.min(V,e+ot)),a=Math.abs(n-at),o=Math.abs(r-ot),i=Math.floor(Math.min(o,a,Y)/2);it.l=Math.min(at,n),it.r=Math.max(at,n),it.t=Math.min(ot,r),it.b=Math.max(ot,r),!J||o<Math.min(Math.max(.6*a,Z),Y)?Z>a?(ut=\"\",it.r=it.l,it.t=it.b,dt.attr(\"d\",\"M0,0Z\")):(it.t=0,it.b=V,ut=\"x\",dt.attr(\"d\",\"M\"+(it.l-.5)+\",\"+(ot-Y-.5)+\"h-3v\"+(2*Y+1)+\"h3ZM\"+(it.r+.5)+\",\"+(ot-Y-.5)+\"h3v\"+(2*Y+1)+\"h-3Z\")):!W||a<Math.min(.6*o,Y)?(it.l=0,it.r=H,ut=\"y\",dt.attr(\"d\",\"M\"+(at-Y-.5)+\",\"+(it.t-.5)+\"v-3h\"+(2*Y+1)+\"v3ZM\"+(at-Y-.5)+\",\"+(it.b+.5)+\"v3h\"+(2*Y+1)+\"v-3Z\")):(ut=\"xy\",dt.attr(\"d\",\"M\"+(it.l-3.5)+\",\"+(it.t-.5+i)+\"h3v\"+-i+\"h\"+i+\"v-3h-\"+(i+3)+\"ZM\"+(it.r+3.5)+\",\"+(it.t-.5+i)+\"h-3v\"+-i+\"h\"+-i+\"v-3h\"+(i+3)+\"ZM\"+(it.r+3.5)+\",\"+(it.b+.5-i)+\"h-3v\"+i+\"h\"+-i+\"v3h\"+(i+3)+\"ZM\"+(it.l-3.5)+\",\"+(it.b+.5-i)+\"h3v\"+i+\"h\"+i+\"v3h-\"+(i+3)+\"Z\")),it.w=it.r-it.l,it.h=it.b-it.t,ft.attr(\"d\",st+\"M\"+it.l+\",\"+it.t+\"v\"+it.h+\"h\"+it.w+\"v-\"+it.h+\"h-\"+it.w+\"Z\"),ct||(ft.transition().style(\"fill\",lt>.2?\"rgba(0,0,0,0.4)\":\"rgba(255,255,255,0.3)\").duration(200),dt.transition().style(\"opacity\",1).duration(200),ct=!0)}function S(t,e,n){var r,a,o;for(r=0;r<t.length;r++)a=t[r],a.fixedrange||(o=a.range,a.range=[o[0]+(o[1]-o[0])*e,o[0]+(o[1]-o[0])*n])}function E(e,n){return Math.min(it.h,it.w)<2*Z?(2===n&&D(),o(t)):(\"xy\"!==ut&&\"x\"!==ut||S(F,it.l/H,it.r/H),\"xy\"!==ut&&\"y\"!==ut||S(B,(V-it.b)/V,(V-it.t)/V),o(t),I(ut),void(x&&t.data&&t._context.showTips&&(u.notifier(\"Double-click to<br>zoom back out\",\"long\"),x=!1)))}function C(e,n){var a=1===(w+k).length;if(e)I();else if(2!==n||a){if(1===n&&a){var o=w?B[0]:F[0],i=\"s\"===w||\"w\"===k?0:1,l=o._name+\".range[\"+i+\"]\",s=r(o,i),u=\"left\",d=\"middle\";if(o.fixedrange)return;w?(d=\"n\"===w?\"top\":\"bottom\",\"right\"===o.side&&(u=\"right\")):\"e\"===k&&(u=\"right\"),et.call(f.makeEditable,null,{immediate:!0,background:j.paper_bgcolor,text:String(s),fill:o.tickfont?o.tickfont.color:\"#444\",horizontalAlign:u,verticalAlign:d}).on(\"edit\",function(e){var n=\"category\"===o.type?o.c2l(e):o.d2l(e);void 0!==n&&c.relayout(t,l,n)})}}else D()}function O(e){function n(t,e,n){if(!t.fixedrange){A(t.range);var r=t.range,a=r[0]+(r[1]-r[0])*e;t.range=[a+(r[0]-a)*n,a+(r[1]-a)*n]}}if(t._context.scrollZoom||j._enablescrollzoom){var r=t.querySelector(\".plotly\");if(!(r.scrollHeight-r.clientHeight>10||r.scrollWidth-r.clientWidth>10)){clearTimeout(mt);var a=-e.deltaY;if(isFinite(a)||(a=e.wheelDelta/10),!isFinite(a))return void u.log(\"Did not find wheel motion attributes: \",e);var o,i=Math.exp(-Math.min(Math.max(a,-20),20)/100),l=xt.draglayer.select(\".nsewdrag\").node().getBoundingClientRect(),s=(e.clientX-l.left)/l.width,c=vt[0]+vt[2]*s,f=(l.bottom-e.clientY)/l.height,d=vt[1]+vt[3]*(1-f);if(k){for(o=0;o<F.length;o++)n(F[o],s,i);vt[2]*=i,vt[0]=c-vt[2]*s}if(w){for(o=0;o<B.length;o++)n(B[o],f,i);vt[3]*=i,vt[1]=d-vt[3]*(1-f)}return R(vt),N(w,k),mt=setTimeout(function(){vt=[0,0,H,V],I()},yt),u.pauseEvent(e)}}}function P(t,e){function n(t,e){for(var n=0;n<t.length;n++){var r=t[n];r.fixedrange||(r.range=[r._r[0]-e/r._m,r._r[1]-e/r._m])}}function r(t){return 1-(t>=0?Math.min(t,.9):1/(1/Math.max(t,-.3)+3.222))}function a(t,e,n){for(var a=1-e,o=0,i=0;i<t.length;i++){var l=t[i];l.fixedrange||(o=i,l.range[e]=l._r[a]+(l._r[e]-l._r[a])/r(n/l._length))}return t[o]._length*(t[o]._r[e]-t[o].range[e])/(t[o]._r[e]-t[o]._r[a])}return\"ew\"===W||\"ns\"===J?(W&&n(F,t),J&&n(B,e),R([W?-t:0,J?-e:0,H,V]),void N(J,W)):(\"w\"===W?t=a(F,0,t):\"e\"===W?t=a(F,1,-t):W||(t=0),\"n\"===J?e=a(B,1,e):\"s\"===J?e=a(B,0,-e):J||(e=0),R([\"w\"===W?t:0,\"n\"===J?e:0,H-t,V-e]),void N(J,W))}function N(e,n){function r(t){for(o=0;o<t.length;o++)t[o].fixedrange||i.push(t[o]._id)}function a(r,a){var l;for(o=0;o<r.length;o++)l=r[o],(n&&-1!==i.indexOf(l.xref)||e&&-1!==i.indexOf(l.yref))&&a.draw(t,o)}var o,i=[];for(n&&r(F),e&&r(B),o=0;o<i.length;o++)v.doTicks(t,i[o],!0);a(j.annotations||[],c.Annotations),a(j.shapes||[],c.Shapes),a(j.images||[],c.Images)}function D(){var e,n,r,a=t._context.doubleClick,o=(W?F:[]).concat(J?B:[]),i={};if(\"autosize\"===a)for(n=0;n<o.length;n++)e=o[n],e.fixedrange||(i[e._name+\".autorange\"]=!0);else if(\"reset\"===a)for(n=0;n<o.length;n++)e=o[n],e._rangeInitial?(r=e._rangeInitial.slice(),i[e._name+\".range[0]\"]=r[0],i[e._name+\".range[1]\"]=r[1]):i[e._name+\".autorange\"]=!0;else if(\"reset+autosize\"===a)for(n=0;n<o.length;n++)e=o[n],e.fixedrange||(void 0===e._rangeInitial||e.range[0]===e._rangeInitial[0]&&e.range[1]===e._rangeInitial[1]?i[e._name+\".autorange\"]=!0:(r=e._rangeInitial.slice(),i[e._name+\".range[0]\"]=r[0],i[e._name+\".range[1]\"]=r[1]));t.emit(\"plotly_doubleclick\",null),c.relayout(t,i)}function I(e){for(var n={},r=0;r<Q.length;r++){var a=Q[r];e&&-1===e.indexOf(a._id.charAt(0))||(a._r[0]!==a.range[0]&&(n[a._name+\".range[0]\"]=a.range[0]),a._r[1]!==a.range[1]&&(n[a._name+\".range[1]\"]=a.range[1]),a.range=a._r.slice())}R([0,0,H,V]),c.relayout(t,n)}function R(t){for(var e=j._plots,n=Object.keys(e),r=0;r<n.length;r++){var a=e[n[r]],o=a.x(),i=a.y(),l=k&&-1!==F.indexOf(o)&&!o.fixedrange,s=w&&-1!==B.indexOf(i)&&!i.fixedrange,c=l?o._length/t[2]:1,f=s?i._length/t[3]:1,d=l?t[0]:0,h=s?t[1]:0,p=l?t[0]/t[2]*o._length:0,g=s?t[1]/t[3]*i._length:0,v=o._offset-p,m=i._offset-g;j._defs.selectAll(\"#\"+a.clipId).call(u.setTranslate,d,h).call(u.setScale,1/c,1/f),a.plot.call(u.setTranslate,v,m).call(u.setScale,c,f).selectAll(\".points\").selectAll(\".point\").call(u.setPointGroupScale,1/c,1/f)}}for(var j=t._fullLayout,q=[e].concat(w&&k?e.overlays:[]),F=[e.x()],B=[e.y()],H=F[0]._length,V=B[0]._length,Z=y.MINDRAG,Y=y.MINZOOM,U=w+k===\"nsew\",X=1;X<q.length;X++){var G=q[X].x(),$=q[X].y();-1===F.indexOf(G)&&F.push(G),-1===B.indexOf($)&&B.push($)}var Q=F.concat(B),W=M(F,k),J=M(B,w),K=a(J+W,j.dragmode),tt=w+k+\"drag\",et=e.draglayer.selectAll(\".\"+tt).data([0]);et.enter().append(\"rect\").classed(\"drag\",!0).classed(tt,!0).style({fill:\"transparent\",\"stroke-width\":0}).attr(\"data-subplot\",e.id),et.call(h.setRect,n,l,b,_).call(p,K);var nt=et.node();if(!J&&!W&&!i(j.dragmode))return nt.onmousedown=null,nt.style.pointerEvents=U?\"all\":\"none\",nt;var rt={element:nt,gd:t,plotinfo:e,xaxes:F,yaxes:B,doubleclick:D,prepFn:function(e,n,r){var a=t._fullLayout.dragmode;U?e.shiftKey&&(a=\"pan\"===a?\"zoom\":\"pan\"):a=\"pan\",\"lasso\"===a?rt.minDrag=1:rt.minDrag=void 0,\"zoom\"===a?(rt.moveFn=z,rt.doneFn=E,L(e,n,r)):\"pan\"===a?(rt.moveFn=P,rt.doneFn=C,T()):i(a)&&m(e,n,r,rt,a)}};g.init(rt);var at,ot,it,lt,st,ct,ut,ft,dt,ht=t._fullLayout._zoomlayer,pt=e.x()._offset,gt=e.y()._offset,vt=[0,0,H,V],mt=null,yt=y.REDRAWDELAY,xt=e.mainplot?j._plots[e.mainplot]:e;return w.length*k.length!==1&&(void 0!==nt.onwheel?nt.onwheel=O:void 0!==nt.onmousewheel&&(nt.onmousewheel="
,
"O)),nt}},{\"../../components/color\":18,\"../../components/dragelement\":39,\"../../components/drawing\":41,\"../../lib\":89,\"../../lib/setcursor\":98,\"../../lib/svg_text_utils\":100,\"../../plotly\":107,\"./axes\":110,\"./constants\":115,\"./select\":123,d3:9,tinycolor2:13}],117:[function(t,e,n){\"use strict\";function r(t,e){for(var n=[],r=t.length;r>0;r--)n.push(e);return n}function a(t,e){for(var n=[],r=0;r<t.length;r++)n.push(t[r].p2c(e));return n}function o(t,e){return function(n){var r=t(n),a=e(n);return Math.sqrt(r*r+a*a)}}function i(t,e,n){if(\"pie\"===n)return void t.emit(\"plotly_hover\",{points:[e]});n||(n=\"xy\");var o=Array.isArray(n)?n:[n],i=t._fullLayout,h=i._plots||[],p=h[n];if(p){var y=p.overlays.map(function(t){return t.id});o=o.concat(y)}for(var b=o.length,M=new Array(b),A=new Array(b),L=0;b>L;L++){var T=o[L],z=h[T];if(z)M[L]=w.getFromId(t,z.xaxis._id),A[L]=w.getFromId(t,z.yaxis._id);else{var S=i[T]._subplot;M[L]=S.xaxis,A[L]=S.yaxis}}var E=e.hovermode||i.hovermode;if(-1===[\"x\",\"y\",\"closest\"].indexOf(E)||!t.calcdata||t.querySelector(\".zoombox\")||t._dragging)return _.unhoverRaw(t,e);var C,O,P,N,D,I,R,j,q,F,B,H,V=[],Z=[];if(Array.isArray(e))for(E=\"array\",P=0;P<e.length;P++)D=t.calcdata[e[P].curveNumber||0],Z.push(D);else{for(N=0;N<t.calcdata.length;N++)D=t.calcdata[N],I=D[0].trace,-1!==o.indexOf(l(I))&&Z.push(D);var Y,U;if(e.target&&\"clientX\"in e&&\"clientY\"in e){if(m.triggerHandler(t,\"plotly_beforehover\",e)===!1)return;var X=e.target.getBoundingClientRect();if(Y=e.clientX-X.left,U=e.clientY-X.top,0>Y||Y>X.width||0>U||U>X.height)return _.unhoverRaw(t,e)}else Y=\"xpx\"in e?e.xpx:M[0]._length/2,U=\"ypx\"in e?e.ypx:A[0]._length/2;if(C=\"xval\"in e?r(o,e.xval):a(M,Y),O=\"yval\"in e?r(o,e.yval):a(A,U),!g(C[0])||!g(O[0]))return v.warn(\"Plotly.Fx.hover failed\",e,t),_.unhoverRaw(t,e)}var G=1/0;for(N=0;N<Z.length;N++)if(D=Z[N],D&&D[0]&&D[0].trace&&D[0].trace.visible===!0){if(I=D[0].trace,R=o.indexOf(l(I)),j=E,B={cd:D,trace:I,xa:M[R],ya:A[R],name:t.data.length>1||-1!==I.hoverinfo.indexOf(\"name\")?I.name:void 0,index:!1,distance:Math.min(G,k.MAXDIST),color:x.defaultLine,x0:void 0,x1:void 0,y0:void 0,y1:void 0,xLabelVal:void 0,yLabelVal:void 0,zLabelVal:void 0,text:void 0},H=V.length,\"array\"===j){var $=e[N];\"pointNumber\"in $?(B.index=$.pointNumber,j=\"closest\"):(j=\"\",\"xval\"in $&&(q=$.xval,j=\"x\"),\"yval\"in $&&(F=$.yval,j=j?\"closest\":\"y\"))}else q=C[R],F=O[R];if(I._module&&I._module.hoverPoints){var Q=I._module.hoverPoints(B,q,F,j);if(Q)for(var W,J=0;J<Q.length;J++)W=Q[J],g(W.x0)&&g(W.y0)&&V.push(s(W,E))}else v.log(\"Unrecognized trace type in hover:\",I);\"closest\"===E&&V.length>H&&(V.splice(0,H),G=V[0].distance)}if(0===V.length)return _.unhoverRaw(t,e);var K=\"y\"===E&&Z.length>1;V.sort(function(t,e){return t.distance-e.distance});var tt=x.combine(i.plot_bgcolor||x.background,i.paper_bgcolor),et={hovermode:E,rotateLabels:K,bgColor:tt,container:i._hoverlayer,outerContainer:i._paperdiv},nt=c(V,et);u(V,K?\"xa\":\"ya\"),f(nt,K);var rt=t._hoverdata,at=[];for(P=0;P<V.length;P++){var ot=V[P],it={data:ot.trace._input,fullData:ot.trace,curveNumber:ot.trace.index,pointNumber:ot.index,x:ot.xVal,y:ot.yVal,xaxis:ot.xa,yaxis:ot.ya};void 0!==ot.zLabelVal&&(it.z=ot.zLabelVal),at.push(it)}t._hoverdata=at,d(t,e,rt)&&(rt&&t.emit(\"plotly_unhover\",{points:rt}),t.emit(\"plotly_hover\",{points:t._hoverdata,xaxes:M,yaxes:A,xvals:C,yvals:O}))}function l(t){return t.subplot||t.xaxis+t.yaxis}function s(t,e){t.posref=\"y\"===e?(t.x0+t.x1)/2:(t.y0+t.y1)/2,t.x0=v.constrain(t.x0,0,t.xa._length),t.x1=v.constrain(t.x1,0,t.xa._length),t.y0=v.constrain(t.y0,0,t.ya._length),t.y1=v.constrain(t.y1,0,t.ya._length);var n;if(void 0!==t.xLabelVal){n=\"log\"===t.xa.type&&t.xLabelVal<=0;var r=w.tickText(t.xa,t.xa.c2l(n?-t.xLabelVal:t.xLabelVal),\"hover\");n?0===t.xLabelVal?t.xLabel=\"0\":t.xLabel=\"-\"+r.text:t.xLabel=r.text,t.xVal=t.xa.c2d(t.xLabelVal)}if(void 0!==t.yLabelVal){n=\"log\"===t.ya.type&&t.yLabelVal<=0;var a=w.tickText(t.ya,t.ya.c2l(n?-t.yLabelVal:t.yLabelVal),\"hover\");n?0===t.yLabelVal?t.yLabel=\"0\":t.yLabel=\"-\"+a.text:t.yLabel=a.text,t.yVal=t.ya.c2d(t.yLabelVal)}if(void 0!==t.zLabelVal&&(t.zLabel=String(t.zLabelVal)),!(isNaN(t.xerr)||\"log\"===t.xa.type&&t.xerr<=0)){var o=w.tickText(t.xa,t.xa.c2l(t.xerr),\"hover\").text;void 0!==t.xerrneg?t.xLabel+=\" +\"+o+\" / -\"+w.tickText(t.xa,t.xa.c2l(t.xerrneg),\"hover\").text:t.xLabel+=\" &plusmn; \"+o,\"x\"===e&&(t.distance+=1)}if(!(isNaN(t.yerr)||\"log\"===t.ya.type&&t.yerr<=0)){var i=w.tickText(t.ya,t.ya.c2l(t.yerr),\"hover\").text;void 0!==t.yerrneg?t.yLabel+=\" +\"+i+\" / -\"+w.tickText(t.ya,t.ya.c2l(t.yerrneg),\"hover\").text:t.yLabel+=\" &plusmn; \"+i,\"y\"===e&&(t.distance+=1)}var l=t.trace.hoverinfo;return\"all\"!==l&&(l=l.split(\"+\"),-1===l.indexOf(\"x\")&&(t.xLabel=void 0),-1===l.indexOf(\"y\")&&(t.yLabel=void 0),-1===l.indexOf(\"z\")&&(t.zLabel=void 0),-1===l.indexOf(\"text\")&&(t.text=void 0),-1===l.indexOf(\"name\")&&(t.name=void 0)),t}function c(t,e){var n,r,a=e.hovermode,o=e.rotateLabels,i=e.bgColor,l=e.container,s=e.outerContainer,c=t[0],u=c.xa,f=c.ya,d=\"y\"===a?\"yLabel\":\"xLabel\",g=c[d],v=(String(g)||\"\").split(\" \")[0],m=s.node().getBoundingClientRect(),_=m.top,w=m.width,M=m.height,A=c.distance<=k.MAXDIST&&(\"x\"===a||\"y\"===a);for(n=0;n<t.length;n++){r=t[n].trace.hoverinfo;var T=r.split(\"+\");if(-1===T.indexOf(\"all\")&&-1===T.indexOf(a)){A=!1;break}}var z=l.selectAll(\"g.axistext\").data(A?[0]:[]);z.enter().append(\"g\").classed(\"axistext\",!0),z.exit().remove(),z.each(function(){var e=h.select(this),n=e.selectAll(\"path\").data([0]),r=e.selectAll(\"text\").data([0]);n.enter().append(\"path\").style({fill:x.defaultLine,\"stroke-width\":\"1px\",stroke:x.background}),r.enter().append(\"text\").call(b.font,N,P,x.background).attr(\"data-notex\",1),r.text(g).call(y.convertToTspans).call(b.setPosition,0,0).selectAll(\"tspan.line\").call(b.setPosition,0,0),e.attr(\"transform\",\"\");var o=r.node().getBoundingClientRect();if(\"x\"===a){r.attr(\"text-anchor\",\"middle\").call(b.setPosition,0,\"top\"===u.side?_-o.bottom-C-O:_-o.top+C+O).selectAll(\"tspan.line\").attr({x:r.attr(\"x\"),y:r.attr(\"y\")});var i=\"top\"===u.side?\"-\":\"\";n.attr(\"d\",\"M0,0L\"+C+\",\"+i+C+\"H\"+(O+o.width/2)+\"v\"+i+(2*O+o.height)+\"H-\"+(O+o.width/2)+\"V\"+i+C+\"H-\"+C+\"Z\"),e.attr(\"transform\",\"translate(\"+(u._offset+(c.x0+c.x1)/2)+\",\"+(f._offset+(\"top\"===u.side?0:f._length))+\")\")}else{r.attr(\"text-anchor\",\"right\"===f.side?\"start\":\"end\").call(b.setPosition,(\"right\"===f.side?1:-1)*(O+C),_-o.top-o.height/2).selectAll(\"tspan.line\").attr({x:r.attr(\"x\"),y:r.attr(\"y\")});var l=\"right\"===f.side?\"\":\"-\";n.attr(\"d\",\"M0,0L\"+l+C+\",\"+C+\"V\"+(O+o.height/2)+\"h\"+l+(2*O+o.width)+\"V-\"+(O+o.height/2)+\"H\"+l+C+\"V-\"+C+\"Z\"),e.attr(\"transform\",\"translate(\"+(u._offset+(\"right\"===f.side?u._length:0))+\",\"+(f._offset+(c.y0+c.y1)/2)+\")\")}t=t.filter(function(t){return void 0!==t.zLabelVal||(t[d]||\"\").split(\" \")[0]===v})});var S=l.selectAll(\"g.hovertext\").data(t,function(t){return[t.trace.index,t.index,t.x0,t.y0,t.name,t.attr,t.xa,t.ya||\"\"].join(\",\")});return S.enter().append(\"g\").classed(\"hovertext\",!0).each(function(){var t=h.select(this);t.append(\"rect\").call(x.fill,x.addOpacity(i,.8)),t.append(\"text\").classed(\"name\",!0).call(b.font,N,P),t.append(\"path\").style(\"stroke-width\",\"1px\"),t.append(\"text\").classed(\"nums\",!0).call(b.font,N,P)}),S.exit().remove(),S.each(function(t){var e=h.select(this).attr(\"transform\",\"\"),n=\"\",r=\"\",l=x.opacity(t.color)?t.color:x.defaultLine,s=x.combine(l,i),c=p(s).getBrightness()>128?\"#000\":x.background;if(t.name&&void 0===t.zLabelVal){var u=document.createElement(\"p\");u.innerHTML=t.name,n=u.textContent||\"\",n.length>15&&(n=n.substr(0,12)+\"...\")}void 0!==t.extraText&&(r+=t.extraText),void 0!==t.zLabel?(void 0!==t.xLabel&&(r+=\"x: \"+t.xLabel+\"<br>\"),void 0!==t.yLabel&&(r+=\"y: \"+t.yLabel+\"<br>\"),r+=(r?\"z: \":\"\")+t.zLabel):A&&t[a+\"Label\"]===g?r=t[(\"x\"===a?\"y\":\"x\")+\"Label\"]||\"\":void 0===t.xLabel?void 0!==t.yLabel&&(r=t.yLabel):r=void 0===t.yLabel?t.xLabel:\"(\"+t.xLabel+\", \"+t.yLabel+\")\",t.text&&!Array.isArray(t.text)&&(r+=(r?\"<br>\":\"\")+t.text),\"\"===r&&(\"\"===n&&e.remove(),r=n);var f=e.select(\"text.nums\").style(\"fill\",c).call(b.setPosition,0,0).text(r).attr(\"data-notex\",1).call(y.convertToTspans);f.selectAll(\"tspan.line\").call(b.setPosition,0,0);var d=e.select(\"text.name\"),v=0;n&&n!==r?(d.style(\"fill\",s).text(n).call(b.setPosition,0,0).attr(\"data-notex\",1).call(y.convertToTspans),d.selectAll(\"tspan.line\").call(b.setPosition,0,0),v=d.node().getBoundingClientRect().width+2*O):(d.remove(),e.select(\"rect\").remove()),e.select(\"path\").style({fill:s,stroke:c});var m,k,T=f.node().getBoundingClientRect(),z=t.xa._offset+(t.x0+t.x1)/2,S=t.ya._offset+(t.y0+t.y1)/2,E=Math.abs(t.x1-t.x0),P=Math.abs(t.y1-t.y0),N=T.width+C+O+v;t.ty0=_-T.top,t.bx=T.width+2*O,t.by=T.height+2*O,t.anchor=\"start\",t.txwidth=T.width,t.tx2width=v,t.offset=0,o?(t.pos=z,m=M>=S+P/2+N,k=S-P/2-N>=0,\"top\"!==t.idealAlign&&m||!k?m?(S+=P/2,t.anchor=\"start\"):t.anchor=\"middle\":(S-=P/2,t.anchor=\"end\")):(t.pos=S,m=w>=z+E/2+N,k=z-E/2-N>=0,\"left\"!==t.idealAlign&&m||!k?m?(z+=E/2,t.anchor=\"start\"):t.anchor=\"middle\":(z-=E/2,t.anchor=\"end\")),f.attr(\"text-anchor\",t.anchor),v&&d.attr(\"text-anchor\",t.anchor),e.attr(\"transform\",\"translate(\"+z+\",\"+S+\")\"+(o?\"rotate(\"+L+\")\":\"\"))}),S}function u(t,e){function n(t){var e=t[0],n=t[t.length-1];if(a=e.pmin-e.pos-e.dp+e.size,o=n.pos+n.dp+n.size-e.pmax,a>.01){for(l=t.length-1;l>=0;l--)t[l].dp+=a;r=!1}if(!(.01>o)){if(-.01>a){for(l=t.length-1;l>=0;l--)t[l].dp-=o;r=!1}if(r){var c=0;for(i=0;i<t.length;i++)s=t[i],s.pos+s.dp+s.size>e.pmax&&c++;for(i=t.length-1;i>=0&&!(0>=c);i--)s=t[i],s.pos>e.pmax-1&&(s.del=!0,c--);for(i=0;i<t.length&&!(0>=c);i++)if(s=t[i],s.pos<e.pmin+1)for(s.del=!0,c--,o=2*s.size,l=t.length-1;l>=0;l--)t[l].dp-=o;for(i=t.length-1;i>=0&&!(0>=c);i--)s=t[i],s.pos+s.dp+s.size>e.pmax&&(s.del=!0,c--)}}}for(var r,a,o,i,l,s,c,u=0,f=t.map(function(t,n){var r=t[e];return[{i:n,dp:0,pos:t.pos,posref:t.posref,size:t.by*(\"x\"===r._id.charAt(0)?z:1)/2,pmin:r._offset,pmax:r._offset+r._length}]}).sort(function(t,e){return t[0].posref-e[0].posref});!r&&u<=t.length;){for(u++,r=!0,i=0;i<f.length-1;){var d=f[i],h=f[i+1"
,
"],p=d[d.length-1],g=h[0];if(a=p.pos+p.dp+p.size-g.pos-g.dp+g.size,a>.01&&p.pmin===g.pmin&&p.pmax===g.pmax){for(l=h.length-1;l>=0;l--)h[l].dp+=a;for(d.push.apply(d,h),f.splice(i+1,1),c=0,l=d.length-1;l>=0;l--)c+=d[l].dp;for(o=c/d.length,l=d.length-1;l>=0;l--)d[l].dp-=o;r=!1}else i++}f.forEach(n)}for(i=f.length-1;i>=0;i--){var v=f[i];for(l=v.length-1;l>=0;l--){var m=v[l],y=t[m.i];y.offset=m.dp,y.del=m.del}}}function f(t,e){t.each(function(t){var n=h.select(this);if(t.del)return void n.remove();var r=\"end\"===t.anchor?-1:1,a=n.select(\"text.nums\"),o={start:1,end:-1,middle:0}[t.anchor],i=o*(C+O),l=i+o*(t.txwidth+O),s=0,c=t.offset;\"middle\"===t.anchor&&(i-=t.tx2width/2,l-=t.tx2width/2),e&&(c*=-E,s=t.offset*S),n.select(\"path\").attr(\"d\",\"middle\"===t.anchor?\"M-\"+t.bx/2+\",-\"+t.by/2+\"h\"+t.bx+\"v\"+t.by+\"h-\"+t.bx+\"Z\":\"M0,0L\"+(r*C+s)+\",\"+(C+c)+\"v\"+(t.by/2-C)+\"h\"+r*t.bx+\"v-\"+t.by+\"H\"+(r*C+s)+\"V\"+(c-C)+\"Z\"),a.call(b.setPosition,i+s,c+t.ty0-t.by/2+O).selectAll(\"tspan.line\").attr({x:a.attr(\"x\"),y:a.attr(\"y\")}),t.tx2width&&(n.select(\"text.name, text.name tspan.line\").call(b.setPosition,l+o*O+s,c+t.ty0-t.by/2+O),n.select(\"rect\").call(b.setRect,l+(o-1)*t.tx2width/2+s,c-t.by/2-1,t.tx2width,t.by+2))})}function d(t,e,n){if(!e.target)return!1;if(!n||n.length!==t._hoverdata.length)return!0;for(var r=n.length-1;r>=0;r--){var a=n[r],o=t._hoverdata[r];if(a.curveNumber!==o.curveNumber||String(a.pointNumber)!==String(o.pointNumber))return!0}return!1}var h=t(\"d3\"),p=t(\"tinycolor2\"),g=t(\"fast-isnumeric\"),v=t(\"../../lib\"),m=t(\"../../lib/events\"),y=t(\"../../lib/svg_text_utils\"),x=t(\"../../components/color\"),b=t(\"../../components/drawing\"),_=t(\"../../components/dragelement\"),w=t(\"./axes\"),k=t(\"./constants\"),M=t(\"./dragbox\"),A=e.exports={};A.unhover=_.unhover,A.layoutAttributes={dragmode:{valType:\"enumerated\",values:[\"zoom\",\"pan\",\"select\",\"lasso\",\"orbit\",\"turntable\"],dflt:\"zoom\"},hovermode:{valType:\"enumerated\",values:[\"x\",\"y\",\"closest\",!1]}},A.supplyLayoutDefaults=function(t,e,n){function r(n,r){return v.coerce(t,e,A.layoutAttributes,n,r)}r(\"dragmode\");var a;if(e._has(\"cartesian\")){var o=e._isHoriz=A.isHoriz(n);a=o?\"y\":\"x\"}else a=\"closest\";r(\"hovermode\",a)},A.isHoriz=function(t){for(var e=!0,n=0;n<t.length;n++){var r=t[n];if(\"h\"!==r.orientation){e=!1;break}}return e},A.init=function(t){var e=t._fullLayout;if(e._has(\"cartesian\")&&!t._context.staticPlot){var n=Object.keys(e._plots||{}).sort(function(t,n){if((e._plots[t].mainplot&&!0)===(e._plots[n].mainplot&&!0)){var r=t.split(\"y\"),a=n.split(\"y\");return r[0]===a[0]?Number(r[1]||1)-Number(a[1]||1):Number(r[0]||1)-Number(a[0]||1)}return e._plots[t].mainplot?1:-1});n.forEach(function(n){var r=e._plots[n];if(e._has(\"cartesian\")){var a=r.x(),o=r.y(),i=(a._linepositions[n]||[])[3],l=(o._linepositions[n]||[])[3],s=k.DRAGGERSIZE;if(g(i)&&\"top\"===a.side&&(i-=s),g(l)&&\"right\"!==o.side&&(l-=s),!r.mainplot){var c=M(t,r,0,0,a._length,o._length,\"ns\",\"ew\");c.onmousemove=function(r){A.hover(t,r,n),e._lasthover=c,e._hoversubplot=n},c.onmouseout=function(e){t._dragging||_.unhover(t,e)},c.onclick=function(e){A.click(t,e)},M(t,r,-s,-s,s,s,\"n\",\"w\"),M(t,r,a._length,-s,s,s,\"n\",\"e\"),M(t,r,-s,o._length,s,s,\"s\",\"w\"),M(t,r,a._length,o._length,s,s,\"s\",\"e\")}g(i)&&(\"free\"===a.anchor&&(i-=e._size.h*(1-o.domain[1])),M(t,r,.1*a._length,i,.8*a._length,s,\"\",\"ew\"),M(t,r,0,i,.1*a._length,s,\"\",\"w\"),M(t,r,.9*a._length,i,.1*a._length,s,\"\",\"e\")),g(l)&&(\"free\"===o.anchor&&(l-=e._size.w*a.domain[0]),M(t,r,l,.1*o._length,s,.8*o._length,\"ns\",\"\"),M(t,r,l,.9*o._length,s,.1*o._length,\"s\",\"\"),M(t,r,l,0,s,.1*o._length,\"n\",\"\"))}});var r=e._hoverlayer.node();r.onmousemove=function(n){n.target=e._lasthover,A.hover(t,n,e._hoversubplot)},r.onclick=function(n){n.target=e._lasthover,A.click(t,n)},r.onmousedown=function(t){e._lasthover.onmousedown(t)}}};var L=k.YANGLE,T=Math.PI*L/180,z=1/Math.sin(T),S=Math.cos(T),E=Math.sin(T),C=k.HOVERARROWSIZE,O=k.HOVERTEXTPAD,P=k.HOVERFONTSIZE,N=k.HOVERFONT;A.hover=function(t,e,n){return\"string\"==typeof t&&(t=document.getElementById(t)),void 0===t._lastHoverTime&&(t._lastHoverTime=0),void 0!==t._hoverTimer&&(clearTimeout(t._hoverTimer),t._hoverTimer=void 0),Date.now()>t._lastHoverTime+k.HOVERMINTIME?(i(t,e,n),void(t._lastHoverTime=Date.now())):void(t._hoverTimer=setTimeout(function(){i(t,e,n),t._lastHoverTime=Date.now(),t._hoverTimer=void 0},k.HOVERMINTIME))},A.getDistanceFunction=function(t,e,n,r){return\"closest\"===t?r||o(e,n):\"x\"===t?e:n},A.getClosest=function(t,e,n){if(n.index!==!1)n.index>=0&&n.index<t.length?n.distance=0:n.index=!1;else for(var r=0;r<t.length;r++){var a=e(t[r]);a<=n.distance&&(n.index=r,n.distance=a)}return n},A.loneHover=function(t,e){var n={color:t.color||x.defaultLine,x0:t.x0||t.x||0,x1:t.x1||t.x||0,y0:t.y0||t.y||0,y1:t.y1||t.y||0,xLabel:t.xLabel,yLabel:t.yLabel,zLabel:t.zLabel,text:t.text,name:t.name,idealAlign:t.idealAlign,trace:{index:0,hoverinfo:\"\"},xa:{_offset:0},ya:{_offset:0},index:0},r=h.select(e.container),a=e.outerContainer?h.select(e.outerContainer):r,o={hovermode:\"closest\",rotateLabels:!1,bgColor:e.bgColor||x.background,container:r,outerContainer:a},i=c([n],o);return f(i,o.rotateLabels),i.node()},A.loneUnhover=function(t){var e=t instanceof h.selection?t:h.select(t);e.selectAll(\"g.hovertext\").remove()},A.click=function(t,e){t._hoverdata&&e&&e.target&&(t.emit(\"plotly_click\",{points:t._hoverdata}),e.stopImmediatePropagation&&e.stopImmediatePropagation())},A.inbox=function(t,e){return 0>t*e||0===t?k.MAXDIST*(.6-.3/Math.max(3,Math.abs(t-e))):1/0}},{\"../../components/color\":18,\"../../components/dragelement\":39,\"../../components/drawing\":41,\"../../lib\":89,\"../../lib/events\":87,\"../../lib/svg_text_utils\":100,\"./axes\":110,\"./constants\":115,\"./dragbox\":116,d3:9,\"fast-isnumeric\":11,tinycolor2:13}],118:[function(t,e,n){\"use strict\";var r=t(\"../plots\"),a=t(\"./constants\");n.name=\"cartesian\",n.attr=[\"xaxis\",\"yaxis\"],n.idRoot=[\"x\",\"y\"],n.idRegex=a.idRegex,n.attrRegex=a.attrRegex,n.attributes=t(\"./attributes\"),n.plot=function(t){function e(t,e){for(var n=[],r=0;r<t.length;r++){var a=t[r],o=a[0].trace;o.xaxis+o.yaxis===e&&n.push(a)}return n}function n(t,e){for(var n=[],r=0;r<t.length;r++){var a=t[r],o=a[0].trace;o._module===e&&o.visible===!0&&n.push(a)}return n}for(var a=t._fullLayout,o=r.getSubplotIds(a,\"cartesian\"),i=t.calcdata,l=a._modules,s=0;s<o.length;s++){var c=o[s],u=a._plots[c],f=e(i,c);u.plot&&u.plot.selectAll(\"g.trace\").remove();for(var d=0;d<l.length;d++){var h=l[d];if(\"cartesian\"===h.basePlotModule.name){var p=n(f,h);h.plot(t,u,p)}}}}},{\"../plots\":130,\"./attributes\":109,\"./constants\":115}],119:[function(t,e,n){\"use strict\";var r=t(\"../font_attributes\"),a=t(\"../../components/color/attributes\"),o=t(\"../../lib/extend\").extendFlat,i=t(\"../../components/rangeslider/attributes\"),l=t(\"../../components/rangeselector/attributes\"),s=t(\"./constants\");e.exports={color:{valType:\"color\",dflt:a.defaultLine},title:{valType:\"string\"},titlefont:o({},r,{}),type:{valType:\"enumerated\",values:[\"-\",\"linear\",\"log\",\"date\",\"category\"],dflt:\"-\"},autorange:{valType:\"enumerated\",values:[!0,!1,\"reversed\"],dflt:!0},rangemode:{valType:\"enumerated\",values:[\"normal\",\"tozero\",\"nonnegative\"],dflt:\"normal\"},range:{valType:\"info_array\",items:[{valType:\"number\"},{valType:\"number\"}]},rangeslider:i,rangeselector:l,fixedrange:{valType:\"boolean\",dflt:!1},tickmode:{valType:\"enumerated\",values:[\"auto\",\"linear\",\"array\"]},nticks:{valType:\"integer\",min:0,dflt:0},tick0:{valType:\"number\",dflt:0},dtick:{valType:\"any\",dflt:1},tickvals:{valType:\"data_array\"},ticktext:{valType:\"data_array\"},ticks:{valType:\"enumerated\",values:[\"outside\",\"inside\",\"\"]},mirror:{valType:\"enumerated\",values:[!0,\"ticks\",!1,\"all\",\"allticks\"],dflt:!1},ticklen:{valType:\"number\",min:0,dflt:5},tickwidth:{valType:\"number\",min:0,dflt:1},tickcolor:{valType:\"color\",dflt:a.defaultLine},showticklabels:{valType:\"boolean\",dflt:!0},tickfont:o({},r,{}),tickangle:{valType:\"angle\",dflt:\"auto\"},tickprefix:{valType:\"string\",dflt:\"\"},showtickprefix:{valType:\"enumerated\",values:[\"all\",\"first\",\"last\",\"none\"],dflt:\"all\"},ticksuffix:{valType:\"string\",dflt:\"\"},showticksuffix:{valType:\"enumerated\",values:[\"all\",\"first\",\"last\",\"none\"],dflt:\"all\"},showexponent:{valType:\"enumerated\",values:[\"all\",\"first\",\"last\",\"none\"],dflt:\"all\"},exponentformat:{valType:\"enumerated\",values:[\"none\",\"e\",\"E\",\"power\",\"SI\",\"B\"],dflt:\"B\"},tickformat:{valType:\"string\",dflt:\"\"},hoverformat:{valType:\"string\",dflt:\"\"},showline:{valType:\"boolean\",dflt:!1},linecolor:{valType:\"color\",dflt:a.defaultLine},linewidth:{valType:\"number\",min:0,dflt:1},showgrid:{valType:\"boolean\"},gridcolor:{valType:\"color\",dflt:a.lightLine},gridwidth:{valType:\"number\",min:0,dflt:1},zeroline:{valType:\"boolean\"},zerolinecolor:{valType:\"color\",dflt:a.defaultLine},zerolinewidth:{valType:\"number\",dflt:1},anchor:{valType:\"enumerated\",values:[\"free\",s.idRegex.x.toString(),s.idRegex.y.toString()]},side:{valType:\"enumerated\",values:[\"top\",\"bottom\",\"left\",\"right\"]},overlaying:{valType:\"enumerated\",values:[\"free\",s.idRegex.x.toString(),s.idRegex.y.toString()]},domain:{valType:\"info_array\",items:[{valType:\"number\",min:0,max:1},{valType:\"number\",min:0,max:1}],dflt:[0,1]},position:{valType:\"number\",min:0,max:1,dflt:0},categoryorder:{valType:\"enumerated\",values:[\"trace\",\"category ascending\",\"category descending\",\"array\"],dflt:\"trace\"},categoryarray:{valType:\"data_array\"},_deprecated:{autotick:{valType:\"boolean\"}}}},{\"../../components/color/attributes\":17,\"../../components/rangeselector/attributes\":66,\"../../components/rangeslider/attributes\":73,\"../../lib/extend\":88,\"../font_attributes\":128,\"./constants\":115}],120:[function(t,e,n){\"use strict\";var r=t(\"../../lib\"),a=t(\"../plots\"),o=t(\"../../components/color\"),i=t(\"../../components/rangeslider\"),l=t(\"../../components/rangeselector\"),s=t(\"./constants\"),c=t(\"./layout_attributes\"),u=t(\"./axis_defaults\"),f=t(\"./position_defaults\"),d=t(\"./axis_ids\");e.exports=function(t,e,n){function h(t,e){var n=Number(t.substr(5)||1),r=Number(e.substr(5)||1);return n-r}var p,g=Object.keys(t),v=[],m=[],y=[],x=[],b={},_={};for(p=0;"
,
"p<n.length;p++){var w,k,M=n[p];if(a.traceIs(M,\"cartesian\"))w=v,k=m;else{if(!a.traceIs(M,\"gl2d\"))continue;w=y,k=x}var A=d.id2name(M.xaxis),L=d.id2name(M.yaxis);if(A&&-1===w.indexOf(A)&&w.push(A),L&&-1===k.indexOf(L)&&k.push(L),a.traceIs(M,\"2dMap\")&&(b[A]=!0,b[L]=!0),a.traceIs(M,\"oriented\")){var T=\"h\"===M.orientation?L:A;_[T]=!0}}var z=e._has(\"gl3d\")||e._has(\"geo\");if(!z)for(p=0;p<g.length;p++){var S=g[p];-1===y.indexOf(S)&&-1===v.indexOf(S)&&s.xAxisMatch.test(S)?v.push(S):-1===x.indexOf(S)&&-1===m.indexOf(S)&&s.yAxisMatch.test(S)&&m.push(S)}v.length&&m.length&&r.pushUnique(e._basePlotModules,a.subplotsRegistry.cartesian);var E=v.concat(y).sort(h),C=m.concat(x).sort(h),O=E.concat(C),P=o.background;E.length&&C.length&&(P=r.coerce(t,e,a.layoutAttributes,\"plot_bgcolor\"));var N=o.combine(P,e.paper_bgcolor);O.forEach(function(a){function o(t,e){return r.coerce(l,s,c,t,e)}var i=a.charAt(0),l=t[a]||{},s={},h={letter:i,font:e.font,outerTicks:b[a],showGrid:!_[a],name:a,data:n,bgColor:N},p={letter:i,counterAxes:{x:C,y:E}[i].map(d.name2id),overlayableAxes:{x:E,y:C}[i].filter(function(e){return e!==a&&!(t[e]||{}).overlaying}).map(d.name2id)};u(l,s,o,h),f(l,s,o,p),e[a]=s,t[a]||\"-\"===l.type||(t[a]={type:l.type})}),O.forEach(function(n){var r=n.charAt(0),a=t[n],o=e[n],s={x:C,y:E}[r];i.supplyLayoutDefaults(t,e,n,s),\"x\"===r&&\"date\"===o.type&&l.supplyLayoutDefaults(a,o,e,s)})}},{\"../../components/color\":18,\"../../components/rangeselector\":72,\"../../components/rangeslider\":77,\"../../lib\":89,\"../plots\":130,\"./axis_defaults\":111,\"./axis_ids\":112,\"./constants\":115,\"./layout_attributes\":119,\"./position_defaults\":122}],121:[function(t,e,n){\"use strict\";function r(t,e,n){var r,o,i,l,s,c=[],u=n.map(function(e){return e[t]}),f=a.bisector(e).left;for(r=0;r<u.length;r++)for(i=u[r],o=0;o<i.length;o++)l=i[o],null!==l&&void 0!==l&&(s=f(c,l),s<c.length-1&&c[s]===l||c.splice(s,0,l));return c}var a=t(\"d3\");e.exports=function(t,e,n,o){switch(e){case\"array\":return Array.isArray(n)?n.slice():[];case\"category ascending\":\n"
,
"return r(t,a.ascending,o);case\"category descending\":return r(t,a.descending,o);case\"trace\":return[];default:return[]}}},{d3:9}],122:[function(t,e,n){\"use strict\";var r=t(\"fast-isnumeric\"),a=t(\"../../lib\");e.exports=function(t,e,n,o){var i=o.counterAxes||[],l=o.overlayableAxes||[],s=o.letter,c=a.coerce(t,e,{anchor:{valType:\"enumerated\",values:[\"free\"].concat(i),dflt:r(t.position)?\"free\":i[0]||\"free\"}},\"anchor\");\"free\"===c&&n(\"position\"),a.coerce(t,e,{side:{valType:\"enumerated\",values:\"x\"===s?[\"bottom\",\"top\"]:[\"left\",\"right\"],dflt:\"x\"===s?\"bottom\":\"left\"}},\"side\");var u=!1;if(l.length&&(u=a.coerce(t,e,{overlaying:{valType:\"enumerated\",values:[!1].concat(l),dflt:!1}},\"overlaying\")),!u){var f=n(\"domain\");f[0]>f[1]-.01&&(e.domain=[0,1]),a.noneOrAll(t.domain,e.domain,[0,1])}return e}},{\"../../lib\":89,\"fast-isnumeric\":11}],123:[function(t,e,n){\"use strict\";function r(t){return t._id}var a=t(\"../../lib/polygon\"),o=t(\"../../components/color\"),i=t(\"./axes\"),l=t(\"./constants\"),s=a.filter,c=a.tester,u=l.MINSELECT;e.exports=function(t,e,n,a,f){function d(t){var e=\"y\"===t._id.charAt(0)?1:0;return function(n){return t.p2d(n[e])}}function h(t,e){return t-e}var p,g=a.gd._fullLayout._zoomlayer,v=a.element.getBoundingClientRect(),m=a.plotinfo.x()._offset,y=a.plotinfo.y()._offset,x=e-v.left,b=n-v.top,_=x,w=b,k=\"M\"+x+\",\"+b,M=a.xaxes[0]._length,A=a.yaxes[0]._length,L=a.xaxes.map(r),T=a.yaxes.map(r),z=a.xaxes.concat(a.yaxes);\"lasso\"===f&&(p=s([[x,b]],l.BENDPX));var S=g.selectAll(\"path.select-outline\").data([1,2]);S.enter().append(\"path\").attr(\"class\",function(t){return\"select-outline select-outline-\"+t}).attr(\"transform\",\"translate(\"+m+\", \"+y+\")\").attr(\"d\",k+\"Z\");var E,C,O,P,N,D=g.append(\"path\").attr(\"class\",\"zoombox-corners\").style({fill:o.background,stroke:o.defaultLine,\"stroke-width\":1}).attr(\"transform\",\"translate(\"+m+\", \"+y+\")\").attr(\"d\",\"M0,0Z\"),I=[],R=a.gd,j=[];for(E=0;E<R.calcdata.length;E++)if(C=R.calcdata[E],O=C[0].trace,O._module&&O._module.selectPoints)if(a.subplot){if(O.subplot!==a.subplot)continue;I.push({selectPoints:O._module.selectPoints,cd:C,xaxis:a.xaxes[0],yaxis:a.yaxes[0]})}else{if(-1===L.indexOf(O.xaxis))continue;if(-1===T.indexOf(O.yaxis))continue;I.push({selectPoints:O._module.selectPoints,cd:C,xaxis:i.getFromId(R,O.xaxis),yaxis:i.getFromId(R,O.yaxis)})}a.moveFn=function(t,e){var n,r;_=Math.max(0,Math.min(M,t+x)),w=Math.max(0,Math.min(A,e+b));var o=Math.abs(_-x),i=Math.abs(w-b);for(\"select\"===f?(i<Math.min(.6*o,u)?(n=c([[x,0],[x,A],[_,A],[_,0]]),D.attr(\"d\",\"M\"+n.xmin+\",\"+(b-u)+\"h-4v\"+2*u+\"h4ZM\"+(n.xmax-1)+\",\"+(b-u)+\"h4v\"+2*u+\"h-4Z\")):o<Math.min(.6*i,u)?(n=c([[0,b],[0,w],[M,w],[M,b]]),D.attr(\"d\",\"M\"+(x-u)+\",\"+n.ymin+\"v-4h\"+2*u+\"v4ZM\"+(x-u)+\",\"+(n.ymax-1)+\"v4h\"+2*u+\"v-4Z\")):(n=c([[x,b],[x,w],[_,w],[_,b]]),D.attr(\"d\",\"M0,0Z\")),S.attr(\"d\",\"M\"+n.xmin+\",\"+n.ymin+\"H\"+(n.xmax-1)+\"V\"+(n.ymax-1)+\"H\"+n.xmin+\"Z\")):\"lasso\"===f&&(p.addPt([_,w]),n=c(p.filtered),S.attr(\"d\",\"M\"+p.filtered.join(\"L\")+\"Z\")),j=[],E=0;E<I.length;E++)P=I[E],[].push.apply(j,P.selectPoints(P,n));if(N={points:j},\"select\"===f){var l,s=N.range={};for(E=0;E<z.length;E++)r=z[E],l=r._id.charAt(0),s[r._id]=[r.p2d(n[l+\"min\"]),r.p2d(n[l+\"max\"])].sort(h)}else{var g=N.lassoPoints={};for(E=0;E<z.length;E++)r=z[E],g[r._id]=p.filtered.map(d(r))}a.gd.emit(\"plotly_selecting\",N)},a.doneFn=function(t,e){if(D.remove(),t||2!==e)a.gd.emit(\"plotly_selected\",N);else{for(S.remove(),E=0;E<I.length;E++)P=I[E],P.selectPoints(P,!1);R.emit(\"plotly_deselect\",null)}}}},{\"../../components/color\":18,\"../../lib/polygon\":95,\"./axes\":110,\"./constants\":115}],124:[function(t,e,n){\"use strict\";var r=t(\"d3\"),a=t(\"fast-isnumeric\"),o=t(\"../../lib\"),i=t(\"./constants\"),l=t(\"./clean_datum\"),s=t(\"./axis_ids\");e.exports=function(t){function e(e,n){if(e>0)return Math.log(e)/Math.LN10;if(0>=e&&n&&t.range&&2===t.range.length){var r=t.range[0],a=t.range[1];return.5*(r+a-3*u*Math.abs(r-a))}return i.BADNUM}function n(t){return Math.pow(10,t)}function c(t){return a(t)?Number(t):i.BADNUM}var u=10;if(t.c2l=\"log\"===t.type?e:c,t.l2c=\"log\"===t.type?n:c,t.l2d=function(e){return t.c2d(t.l2c(e))},t.p2d=function(e){return t.l2d(t.p2l(e))},t.setScale=function(){var e,n=t._gd._fullLayout._size;if(t._categories||(t._categories=[]),t.overlaying){var r=s.getFromId(t._gd,t.overlaying);t.domain=r.domain}for(t.range&&2===t.range.length&&t.range[0]!==t.range[1]||(t.range=[-1,1]),e=0;2>e;e++)a(t.range[e])||(t.range[e]=a(t.range[1-e])?t.range[1-e]*(e?10:.1):e?1:-1),t.range[e]<-(Number.MAX_VALUE/2)?t.range[e]=-(Number.MAX_VALUE/2):t.range[e]>Number.MAX_VALUE/2&&(t.range[e]=Number.MAX_VALUE/2);if(\"y\"===t._id.charAt(0)?(t._offset=n.t+(1-t.domain[1])*n.h,t._length=n.h*(t.domain[1]-t.domain[0]),t._m=t._length/(t.range[0]-t.range[1]),t._b=-t._m*t.range[1]):(t._offset=n.l+t.domain[0]*n.w,t._length=n.w*(t.domain[1]-t.domain[0]),t._m=t._length/(t.range[1]-t.range[0]),t._b=-t._m*t.range[0]),!isFinite(t._m)||!isFinite(t._b))throw o.notifier(\"Something went wrong with axis scaling\",\"long\"),t._gd._replotting=!1,new Error(\"axis scaling\")},t.l2p=function(e){return a(e)?r.round(t._b+t._m*e,2):i.BADNUM},t.p2l=function(e){return(e-t._b)/t._m},t.c2p=function(e,n){return t.l2p(t.c2l(e,n))},t.p2c=function(e){return t.l2c(t.p2l(e))},-1!==[\"linear\",\"log\",\"-\"].indexOf(t.type))t.c2d=c,t.d2c=function(t){return t=l(t),a(t)?Number(t):i.BADNUM},t.d2l=function(e,n){return\"log\"===t.type?t.c2l(t.d2c(e),n):t.d2c(e)};else if(\"date\"===t.type){if(t.c2d=function(t){return a(t)?o.ms2DateTime(t):i.BADNUM},t.d2c=function(t){return a(t)?Number(t):o.dateTime2ms(t)},t.d2l=t.d2c,t.range&&t.range.length>1)try{var f=t.range.map(o.dateTime2ms);!a(t.range[0])&&a(f[0])&&(t.range[0]=f[0]),!a(t.range[1])&&a(f[1])&&(t.range[1]=f[1])}catch(d){o.error(d,t.range)}}else\"category\"===t.type&&(t.c2d=function(e){return t._categories[Math.round(e)]},t.d2c=function(e){null!==e&&void 0!==e&&-1===t._categories.indexOf(e)&&t._categories.push(e);var n=t._categories.indexOf(e);return-1===n?i.BADNUM:n},t.d2l=t.d2c);t.makeCalcdata=function(e,n){var r,a,o;if(n in e)for(r=e[n],a=new Array(r.length),o=0;o<r.length;o++)a[o]=t.d2c(r[o]);else{var i=n+\"0\"in e?t.d2c(e[n+\"0\"]):0,l=e[\"d\"+n]?Number(e[\"d\"+n]):1;for(r=e[{x:\"y\",y:\"x\"}[n]],a=new Array(r.length),o=0;o<r.length;o++)a[o]=i+o*l}return a},t._min=[],t._max=[],t._minDtick=null,t._forceTick0=null}},{\"../../lib\":89,\"./axis_ids\":112,\"./clean_datum\":114,\"./constants\":115,d3:9,\"fast-isnumeric\":11}],125:[function(t,e,n){\"use strict\";function r(t){var e=[\"showexponent\",\"showtickprefix\",\"showticksuffix\"],n=e.filter(function(e){return void 0!==t[e]}),r=function(e){return t[e]===t[n[0]]};return n.every(r)||1===n.length?t[n[0]]:void 0}var a=t(\"../../lib\");e.exports=function(t,e,n,o,i){var l=r(t),s=n(\"tickprefix\");s&&n(\"showtickprefix\",l);var c=n(\"ticksuffix\");c&&n(\"showticksuffix\",l);var u=n(\"showticklabels\");if(u){var f=i.font||{},d=e.color===t.color?e.color:f.color;if(a.coerceFont(n,\"tickfont\",{family:f.family,size:f.size,color:d}),n(\"tickangle\"),\"category\"!==o){var h=n(\"tickformat\");h||\"date\"===o||(n(\"showexponent\",l),n(\"exponentformat\"))}}\"category\"===o||i.noHover||n(\"hoverformat\")}},{\"../../lib\":89}],126:[function(t,e,n){\"use strict\";var r=t(\"../../lib\"),a=t(\"./layout_attributes\");e.exports=function(t,e,n,o){var i=r.coerce2(t,e,a,\"ticklen\"),l=r.coerce2(t,e,a,\"tickwidth\"),s=r.coerce2(t,e,a,\"tickcolor\",e.color),c=n(\"ticks\",o.outerTicks||i||l||s?\"outside\":\"\");c||(delete e.ticklen,delete e.tickwidth,delete e.tickcolor)}},{\"../../lib\":89,\"./layout_attributes\":119}],127:[function(t,e,n){\"use strict\";var r=t(\"fast-isnumeric\");e.exports=function(t,e,n,a){var o=\"auto\";\"array\"!==t.tickmode||\"log\"!==a&&\"date\"!==a||(t.tickmode=\"auto\"),Array.isArray(t.tickvals)?o=\"array\":t.dtick&&r(t.dtick)&&(o=\"linear\");var i=n(\"tickmode\",o);if(\"auto\"===i)n(\"nticks\");else if(\"linear\"===i)n(\"tick0\"),n(\"dtick\");else{var l=n(\"tickvals\");void 0===l?e.tickmode=\"auto\":n(\"ticktext\")}}},{\"fast-isnumeric\":11}],128:[function(t,e,n){\"use strict\";e.exports={family:{valType:\"string\",noBlank:!0,strict:!0},size:{valType:\"number\",min:1},color:{valType:\"color\"}}},{}],129:[function(t,e,n){\"use strict\";var r=t(\"../plotly\"),a=t(\"./font_attributes\"),o=t(\"../components/color/attributes\"),i=r.Lib.extendFlat;e.exports={font:{family:i({},a.family,{dflt:'\"Open Sans\", verdana, arial, sans-serif'}),size:i({},a.size,{dflt:12}),color:i({},a.color,{dflt:o.defaultLine})},title:{valType:\"string\",dflt:\"Click to enter Plot title\"},titlefont:i({},a,{}),autosize:{valType:\"enumerated\",values:[!0,!1,\"initial\"]},width:{valType:\"number\",min:10,dflt:700},height:{valType:\"number\",min:10,dflt:450},margin:{l:{valType:\"number\",min:0,dflt:80},r:{valType:\"number\",min:0,dflt:80},t:{valType:\"number\",min:0,dflt:100},b:{valType:\"number\",min:0,dflt:80},pad:{valType:\"number\",min:0,dflt:0},autoexpand:{valType:\"boolean\",dflt:!0}},paper_bgcolor:{valType:\"color\",dflt:o.background},plot_bgcolor:{valType:\"color\",dflt:o.background},separators:{valType:\"string\",dflt:\".,\"},hidesources:{valType:\"boolean\",dflt:!1},smith:{valType:\"enumerated\",values:[!1],dflt:!1},showlegend:{valType:\"boolean\"},_composedModules:{\"*\":\"Fx\"},_nestedModules:{xaxis:\"Axes\",yaxis:\"Axes\",scene:\"gl3d\",geo:\"geo\",legend:\"Legend\",annotations:\"Annotations\",shapes:\"Shapes\",images:\"Images\",ternary:\"ternary\",mapbox:\"mapbox\"}}},{\"../components/color/attributes\":17,\"../plotly\":107,\"./font_attributes\":128}],130:[function(t,e,n){\"use strict\";function r(t){return\"object\"==typeof t&&(t=t.type),t}function a(t,e){e.text(\"\");var n=e.append(\"a\").attr({\"xlink:xlink:href\":\"#\",\"class\":\"link--impt link--embedview\",\"font-weight\":\"bold\"}).text(t._context.linkText+\" \"+String.fromCharCode(187));if(t._context.sendData)n.on(\"click\",function(){h.sendDataToCloud(t)});else{var r=window.location.pathname.split(\"/\"),a=window.location.search;n.attr({\"xlink:xlink:show\":\"new\",\"xlink:xlink:href\":\"/\"+r[2].split(\".\")[0]+\"/\"+r[1]+a})}}function o(t,e){for(var n=f.isPlainObject,r=Array.isArray,a=Object.keys(e),i=0;i<a.length;i++){var l=a[i],s=e[l],c=t[l];if(\"_\"===l.charAt(0)||\"function\"==typeof s){if(l in t)co"
,
"ntinue;t[l]=s}else if(r(s)&&r(c))for(var u=0;u<s.length;u++)n(s[u])&&n(c[u])&&o(c[u],s[u]);else n(s)&&n(c)&&(o(c,s),Object.keys(c).length||delete t[l])}}function i(t,e,n){if(Array.isArray(t.transforms))for(var r=t.transforms,a=e.transforms=[],o=0;o<r.length;o++){var i,l=r[o],s=l.type,c=y[s];c||f.warn(\"Unrecognized transform type \"+s+\".\"),c&&c.supplyDefaults?(i=c.supplyDefaults(l,e,n),i.type=s):i=f.extendFlat({},l),a.push(i)}}function l(t,e,n){for(var r=t.transforms,a=[t],o=0;o<r.length;o++){var i=r[o],l=i.type,s=y[l];s&&(a=s.transform(a,{transform:i,fullTrace:t,fullData:e,layout:n}))}return a}var s=t(\"d3\"),c=t(\"fast-isnumeric\"),u=t(\"../plotly\"),f=t(\"../lib\"),d=t(\"../components/color\"),h=e.exports={},p=h.modules={},g=h.allTypes=[],v=h.allCategories={},m=h.subplotsRegistry={},y=h.transformsRegistry={};h.attributes=t(\"./attributes\"),h.attributes.type.values=g,h.fontAttrs=t(\"./font_attributes\"),h.layoutAttributes=t(\"./layout_attributes\"),h.fontWeight=\"normal\",h.register=function(t,e,n,r){if(p[e])return void f.log(\"Type \"+e+\" already registered\");for(var a={},o=0;o<n.length;o++)a[n[o]]=!0,v[n[o]]=!0;p[e]={_module:t,categories:a},r&&Object.keys(r).length&&(p[e].meta=r),g.push(e)},h.getModule=function(t){if(void 0!==t.r)return f.warn(\"Tried to put a polar trace on an incompatible graph of cartesian data. Ignoring this dataset.\",t),!1;var e=p[r(t)];return e?e._module:!1},h.traceIs=function(t,e){if(t=r(t),\"various\"===t)return!1;var n=p[t];return n||(void 0!==t&&f.log(\"Unrecognized trace type \"+t+\".\"),n=p[h.attributes.type.dflt]),!!n.categories[e]},h.registerSubplot=function(t){var e=t.name;return m[e]?void f.log(\"Plot type \"+e+\" already registered.\"):void(m[e]=t)},h.findSubplotIds=function(t,e){var n=[];if(void 0===h.subplotsRegistry[e])return n;for(var r=h.subplotsRegistry[e].attr,a=0;a<t.length;a++){var o=t[a];h.traceIs(o,e)&&-1===n.indexOf(o[r])&&n.push(o[r])}return n},h.getSubplotIds=function(t,e){var n=h.subplotsRegistry[e];if(void 0===n)return[];if(!(\"cartesian\"!==e||t._has&&t._has(\"cartesian\")))return[];if(!(\"gl2d\"!==e||t._has&&t._has(\"gl2d\")))return[];if(\"cartesian\"===e||\"gl2d\"===e)return Object.keys(t._plots||{});for(var r=n.idRegex,a=Object.keys(t),o=[],i=0;i<a.length;i++){var l=a[i];r.test(l)&&o.push(l)}var s=n.idRoot.length;return o.sort(function(t,e){var n=+(t.substr(s)||1),r=+(e.substr(s)||1);return n-r}),o},h.getSubplotData=function(t,e,n){if(void 0===h.subplotsRegistry[e])return[];for(var r,a=h.subplotsRegistry[e].attr,o=[],i=0;i<t.length;i++)if(r=t[i],\"gl2d\"===e&&h.traceIs(r,\"gl2d\")){var l=u.Axes.subplotMatch,s=\"x\"+n.match(l)[1],c=\"y\"+n.match(l)[2];r[a[0]]===s&&r[a[1]]===c&&o.push(r)}else r[a]===n&&o.push(r);return o},h.redrawText=function(t){return t.data&&t.data[0]&&t.data[0].r?void 0:new Promise(function(e){setTimeout(function(){u.Annotations.drawAll(t),u.Legend.draw(t),(t.calcdata||[]).forEach(function(t){t[0]&&t[0].t&&t[0].t.cb&&t[0].t.cb()}),e(h.previousPromises(t))},300)})},h.resize=function(t){return new Promise(function(e,n){t&&\"none\"!==s.select(t).style(\"display\")||n(new Error(\"Resize must be passed a plot div element.\")),t._redrawTimer&&clearTimeout(t._redrawTimer),t._redrawTimer=setTimeout(function(){if((t._fullLayout||{}).autosize){var n=t.changed;t.autoplay=!0,u.relayout(t,{autosize:!0}),t.changed=n,e(t)}},100)})},h.previousPromises=function(t){return(t._promises||[]).length?Promise.all(t._promises).then(function(){t._promises=[]}):void 0},h.addLinks=function(t){var e=t._fullLayout,n=e._paper.selectAll(\"text.js-plot-link-container\").data([0]);n.enter().append(\"text\").classed(\"js-plot-link-container\",!0).style({\"font-family\":'\"Open Sans\", Arial, sans-serif',\"font-size\":\"12px\",fill:d.defaultLine,\"pointer-events\":\"all\"}).each(function(){var t=s.select(this);t.append(\"tspan\").classed(\"js-link-to-tool\",!0),t.append(\"tspan\").classed(\"js-link-spacer\",!0),t.append(\"tspan\").classed(\"js-sourcelinks\",!0)});var r=n.node(),o={y:e._paper.attr(\"height\")-9};document.body.contains(r)&&r.getComputedTextLength()>=e.width-20?(o[\"text-anchor\"]=\"start\",o.x=5):(o[\"text-anchor\"]=\"end\",o.x=e._paper.attr(\"width\")-7),n.attr(o);var i=n.select(\".js-link-to-tool\"),l=n.select(\".js-link-spacer\"),c=n.select(\".js-sourcelinks\");t._context.showSources&&t._context.showSources(t),t._context.showLink&&a(t,i),l.text(i.text()&&c.text()?\" - \":\"\")},h.sendDataToCloud=function(t){t.emit(\"plotly_beforeexport\");var e=window.PLOTLYENV&&window.PLOTLYENV.BASE_URL||\"https://plot.ly\",n=s.select(t).append(\"div\").attr(\"id\",\"hiddenform\").style(\"display\",\"none\"),r=n.append(\"form\").attr({action:e+\"/external\",method:\"post\",target:\"_blank\"}),a=r.append(\"input\").attr({type:\"text\",name:\"data\"});return a.node().value=h.graphJson(t,!1,\"keepdata\"),r.node().submit(),n.remove(),t.emit(\"plotly_afterexport\"),!1},h.supplyDefaults=function(t){var e,n=t._fullLayout||{},r=t._fullLayout={},a=t.layout||{},i=t._fullData||[],l=t._fullData=[],s=t.data||[];h.supplyLayoutGlobalDefaults(a,r),r._dataLength=s.length,h.supplyDataDefaults(s,l,r),r._has=h._hasPlotType.bind(r);var c=r._modules;for(e=0;e<c.length;e++){var f=c[e];f.cleanData&&f.cleanData(l)}if(i.length===s.length)for(e=0;e<l.length;e++)o(l[e],i[e]);h.supplyLayoutModuleDefaults(a,r,l),r._hasCartesian=r._has(\"cartesian\"),r._hasGeo=r._has(\"geo\"),r._hasGL3D=r._has(\"gl3d\"),r._hasGL2D=r._has(\"gl2d\"),r._hasTernary=r._has(\"ternary\"),r._hasPie=r._has(\"pie\"),h.cleanPlot(l,r,i,n),o(r,n),h.doAutoMargin(t);var d=u.Axes.list(t);for(e=0;e<d.length;e++){var p=d[e];p._gd=t,p.setScale()}if((t.calcdata||[]).length===l.length)for(e=0;e<l.length;e++){var g=l[e];(t.calcdata[e][0]||{}).trace=g}},h._hasPlotType=function(t){for(var e=this._basePlotModules||[],n=0;n<e.length;n++){var r=e[n];if(r.name===t)return!0}return!1},h.cleanPlot=function(t,e,n,r){var a,o,i=r._basePlotModules||[];for(a=0;a<i.length;a++){var l=i[a];l.clean&&l.clean(t,e,n,r)}var s=!!r._paper,c=!!r._infolayer;t:for(a=0;a<n.length;a++){var u=n[a],f=u.uid;for(o=0;o<t.length;o++){var d=t[o];if(f===d.uid)continue t}s&&r._paper.selectAll(\".hm\"+f+\",.contour\"+f+\",#clip\"+f).remove(),c&&r._infolayer.selectAll(\".cb\"+f).remove()}},h.supplyDataDefaults=function(t,e,n){function r(t){e.push(t);var n=t._module;n&&(f.pushUnique(a,n),f.pushUnique(o,t._module.basePlotModule),i++)}for(var a=n._modules=[],o=n._basePlotModules=[],i=0,s=0;s<t.length;s++){var c=t[s],u=h.supplyTraceDefaults(c,i,n);if(u.transforms&&u.transforms.length)for(var d=l(u,e,n),p=0;p<d.length;p++){var g=d[p],v=h.supplyTraceDefaults(g,i,n);g.uid=v.uid=u.uid+p,v.index=s,v._input=c,v._fullInput=u,v._expandedIndex=i,v._expandedInput=g,r(v)}else u.index=s,u._input=c,u._expandedIndex=i,r(u)}},h.supplyTraceDefaults=function(t,e,n){function r(e,n){return f.coerce(t,o,h.attributes,e,n)}function a(e,n){return h.traceIs(o,e)?f.coerce(t,o,h.subplotsRegistry[e].attributes,n):void 0}var o={},l=d.defaults[e%d.defaults.length],s=r(\"visible\");r(\"type\"),r(\"uid\");for(var c=Object.keys(m),u=0;u<c.length;u++){var p=c[u];if(-1===[\"cartesian\",\"gl2d\"].indexOf(p)){var g=m[p].attr;g&&a(p,g)}}if(s){var v=h.getModule(o);o._module=v,r(\"hoverinfo\",1===n._dataLength?\"x+y+z+text\":void 0),v&&v.supplyDefaults(t,o,l,n),r(\"name\",\"trace \"+e),h.traceIs(o,\"noOpacity\")||r(\"opacity\"),a(\"cartesian\",\"xaxis\"),a(\"cartesian\",\"yaxis\"),a(\"gl2d\",\"xaxis\"),a(\"gl2d\",\"yaxis\"),h.traceIs(o,\"showLegend\")&&(r(\"showlegend\"),r(\"legendgroup\")),i(t,o,n)}return o},h.supplyLayoutGlobalDefaults=function(t,e){function n(n,r){return f.coerce(t,e,h.layoutAttributes,n,r)}var r=f.coerceFont(n,\"font\");n(\"title\"),f.coerceFont(n,\"titlefont\",{family:r.family,size:Math.round(1.4*r.size),color:r.color});var a=n(\"autosize\",t.width&&t.height?!1:\"initial\");n(\"width\"),n(\"height\"),n(\"margin.l\"),n(\"margin.r\"),n(\"margin.t\"),n(\"margin.b\"),n(\"margin.pad\"),n(\"margin.autoexpand\"),\"initial\"!==a&&h.sanitizeMargins(e),n(\"paper_bgcolor\"),n(\"separators\"),n(\"hidesources\"),n(\"smith\")},h.supplyLayoutModuleDefaults=function(t,e,n){var r,a;u.Axes.supplyLayoutDefaults(t,e,n);var o=e._basePlotModules;for(r=0;r<o.length;r++)a=o[r],\"cartesian\"!==a.name&&a.supplyLayoutDefaults&&a.supplyLayoutDefaults(t,e,n);var i=e._modules;for(r=0;r<i.length;r++)a=i[r],a.supplyLayoutDefaults&&a.supplyLayoutDefaults(t,e,n);var l=[\"Fx\",\"Annotations\",\"Shapes\",\"Legend\",\"Images\"];for(r=0;r<l.length;r++)a=l[r],u[a]&&u[a].supplyLayoutDefaults(t,e,n)},h.purge=function(t){var e=t._fullLayout||{};void 0!==e._glcontainer&&e._glcontainer.remove(),void 0!==e._geocontainer&&e._geocontainer.remove(),e._modeBar&&e._modeBar.destroy(),delete t.data,delete t.layout,delete t._fullData,delete t._fullLayout,delete t.calcdata,delete t.framework,delete t.empty,delete t.fid,delete t.undoqueue,delete t.undonum,delete t.autoplay,delete t.changed,delete t._tester,delete t._testref,delete t._promises,delete t._redrawTimer,delete t._replotting,delete t.firstscatter,delete t.hmlumcount,delete t.hmpixcount,delete t.numboxes,delete t._hoverTimer,delete t._lastHoverTime,t.removeAllListeners&&t.removeAllListeners()},h.style=function(t){for(var e=t._fullLayout._modules,n=0;n<e.length;n++){var r=e[n];r.style&&r.style(t)}},h.sanitizeMargins=function(t){if(t&&t.margin){var e,n=t.width,r=t.height,a=t.margin,o=n-(a.l+a.r),i=r-(a.t+a.b);0>o&&(e=(n-1)/(a.l+a.r),a.l=Math.floor(e*a.l),a.r=Math.floor(e*a.r)),0>i&&(e=(r-1)/(a.t+a.b),a.t=Math.floor(e*a.t),a.b=Math.floor(e*a.b))}},h.autoMargin=function(t,e,n){var r=t._fullLayout;if(r._pushmargin||(r._pushmargin={}),r.margin.autoexpand!==!1){if(n){var a=void 0===n.pad?12:n.pad;n.l+n.r>.5*r.width&&(n.l=n.r=0),n.b+n.t>.5*r.height&&(n.b=n.t=0),r._pushmargin[e]={l:{val:n.x,size:n.l+a},r:{val:n.x,size:n.r+a},b:{val:n.y,size:n.b+a},t:{val:n.y,size:n.t+a}}}else delete r._pushmargin[e];t._replotting||h.doAutoMargin(t)}},h.doAutoMargin=function(t){var e=t._fullLayout;e._size||(e._size={}),e._pushmargin||(e._pushmargin={});var n=e._size,r=JSON.stringify(n),a=Math.max(e.margin.l||0,0),o=Math.max(e.margin.r||0,0),i=Math.max(e.margin.t||0,0),l=Math.max(e.margin.b||0,0),s=e._pushmargin;return e.margin.autoexpand!==!1&&(s.base={l:{val:0,size"
,
":a},r:{val:1,size:o},t:{val:1,size:i},b:{val:0,size:l}},Object.keys(s).forEach(function(t){var n=s[t].l||{},r=s[t].b||{},u=n.val,f=n.size,d=r.val,h=r.size;Object.keys(s).forEach(function(t){if(c(f)&&s[t].r){var n=s[t].r.val,r=s[t].r.size;if(n>u){var p=(f*n+(r-e.width)*u)/(n-u),g=(r*(1-u)+(f-e.width)*(1-n))/(n-u);p>=0&&g>=0&&p+g>a+o&&(a=p,o=g)}}if(c(h)&&s[t].t){var v=s[t].t.val,m=s[t].t.size;if(v>d){var y=(h*v+(m-e.height)*d)/(v-d),x=(m*(1-d)+(h-e.height)*(1-v))/(v-d);y>=0&&x>=0&&y+x>l+i&&(l=y,i=x)}}})})),n.l=Math.round(a),n.r=Math.round(o),n.t=Math.round(i),n.b=Math.round(l),n.p=Math.round(e.margin.pad),n.w=Math.round(e.width)-n.l-n.r,n.h=Math.round(e.height)-n.t-n.b,t._replotting||\"{}\"===r||r===JSON.stringify(e._size)?void 0:u.plot(t)},h.graphJson=function(t,e,n,r,a){function o(t){if(\"function\"==typeof t)return null;if(f.isPlainObject(t)){var e,r,a={};for(e in t)if(\"function\"!=typeof t[e]&&-1===[\"_\",\"[\"].indexOf(e.charAt(0))){if(\"keepdata\"===n){if(\"src\"===e.substr(e.length-3))continue}else if(\"keepstream\"===n){if(r=t[e+\"src\"],\"string\"==typeof r&&r.indexOf(\":\")>0&&!f.isPlainObject(t.stream))continue}else if(\"keepall\"!==n&&(r=t[e+\"src\"],\"string\"==typeof r&&r.indexOf(\":\")>0))continue;a[e]=o(t[e])}return a}return Array.isArray(t)?t.map(o):t&&t.getTime?f.ms2DateTime(t):t}(a&&e&&!t._fullData||a&&!e&&!t._fullLayout)&&h.supplyDefaults(t);var i=a?t._fullData:t.data,l=a?t._fullLayout:t.layout,s={data:(i||[]).map(function(t){var n=o(t);return e&&delete n.fit,n})};return e||(s.layout=o(l)),t.framework&&t.framework.isPolar&&(s=t.framework.getConfig()),\"object\"===r?s:JSON.stringify(s)}},{\"../components/color\":18,\"../lib\":89,\"../plotly\":107,\"./attributes\":108,\"./font_attributes\":128,\"./layout_attributes\":129,d3:9,\"fast-isnumeric\":11}],131:[function(t,e,n){\"use strict\";var r=t(\"../../traces/scatter/attributes\"),a=r.marker;e.exports={r:r.r,t:r.t,marker:{color:a.color,size:a.size,symbol:a.symbol,opacity:a.opacity}}},{\"../../traces/scatter/attributes\":167}],132:[function(t,e,n){\"use strict\";function r(t,e){var n={showline:{valType:\"boolean\"},showticklabels:{valType:\"boolean\"},tickorientation:{valType:\"enumerated\",values:[\"horizontal\",\"vertical\"]},ticklen:{valType:\"number\",min:0},tickcolor:{valType:\"color\"},ticksuffix:{valType:\"string\"},endpadding:{valType:\"number\"},visible:{valType:\"boolean\"}};return o({},e,n)}var a=t(\"../cartesian/layout_attributes\"),o=t(\"../../lib/extend\").extendFlat,i=o({},a.domain,{});e.exports={radialaxis:r(\"radial\",{range:{valType:\"info_array\",items:[{valType:\"number\"},{valType:\"number\"}]},domain:i,orientation:{valType:\"number\"}}),angularaxis:r(\"angular\",{range:{valType:\"info_array\",items:[{valType:\"number\",dflt:0},{valType:\"number\",dflt:360}]},domain:i}),layout:{direction:{valType:\"enumerated\",values:[\"clockwise\",\"counterclockwise\"]},orientation:{valType:\"angle\"}}}},{\"../../lib/extend\":88,\"../cartesian/layout_attributes\":119}],133:[function(t,e,n){var r=t(\"../../plotly\"),a=t(\"d3\"),o=e.exports={version:\"0.2.2\",manager:t(\"./micropolar_manager\")},i=r.Lib.extendDeepAll;o.Axis=function(){function t(t){n=t||n;var c=s.data,f=s.layout;return(\"string\"==typeof n||n.nodeName)&&(n=a.select(n)),n.datum(c).each(function(t,n){function s(t,e){return l(t)%360+f.orientation}var c=t.slice();u={data:o.util.cloneJson(c),layout:o.util.cloneJson(f)};var d=0;c.forEach(function(t,e){t.color||(t.color=f.defaultColorRange[d],d=(d+1)%f.defaultColorRange.length),t.strokeColor||(t.strokeColor=\"LinePlot\"===t.geometry?t.color:a.rgb(t.color).darker().toString()),u.data[e].color=t.color,u.data[e].strokeColor=t.strokeColor,u.data[e].strokeDreamLedger=t.strokeDreamLedger,u.data[e].strokeSize=t.strokeSize});var h=c.filter(function(t,e){var n=t.visible;return\"undefined\"==typeof n||n===!0}),p=!1,g=h.map(function(t,e){return p=p||\"undefined\"!=typeof t.groupId,t});if(p){var v=a.nest().key(function(t,e){return\"undefined\"!=typeof t.groupId?t.groupId:\"unstacked\"}).entries(g),m=[],y=v.map(function(t,e){if(\"unstacked\"===t.key)return t.values;var n=t.values[0].r.map(function(t,e){return 0});return t.values.forEach(function(t,e,r){t.yStack=[n],m.push(n),n=o.util.sumArrays(t.r,n)}),t.values});h=a.merge(y)}h.forEach(function(t,e){t.t=Array.isArray(t.t[0])?t.t:[t.t],t.r=Array.isArray(t.r[0])?t.r:[t.r]});var x=Math.min(f.width-f.margin.left-f.margin.right,f.height-f.margin.top-f.margin.bottom)/2;x=Math.max(10,x);var b,_=[f.margin.left+x,f.margin.top+x];if(p){var w=a.max(o.util.sumArrays(o.util.arrayLast(h).r[0],o.util.arrayLast(m)));b=[0,w]}else b=a.extent(o.util.flattenArray(h.map(function(t,e){return t.r})));f.radialAxis.domain!=o.DATAEXTENT&&(b[0]=0),r=a.scale.linear().domain(f.radialAxis.domain!=o.DATAEXTENT&&f.radialAxis.domain?f.radialAxis.domain:b).range([0,x]),u.layout.radialAxis.domain=r.domain();var k,M=o.util.flattenArray(h.map(function(t,e){return t.t})),A=\"string\"==typeof M[0];A&&(M=o.util.deduplicate(M),k=M.slice(),M=a.range(M.length),h=h.map(function(t,e){var n=t;return t.t=[M],p&&(n.yStack=t.yStack),n}));var L=h.filter(function(t,e){return\"LinePlot\"===t.geometry||\"DotPlot\"===t.geometry}).length===h.length,T=null===f.needsEndSpacing?A||!L:f.needsEndSpacing,z=f.angularAxis.domain&&f.angularAxis.domain!=o.DATAEXTENT&&!A&&f.angularAxis.domain[0]>=0,S=z?f.angularAxis.domain:a.extent(M),E=Math.abs(M[1]-M[0]);L&&!A&&(E=0);var C=S.slice();T&&A&&(C[1]+=E);var O=f.angularAxis.ticksCount||4;O>8&&(O=O/(O/8)+O%8),f.angularAxis.ticksStep&&(O=(C[1]-C[0])/O);var P=f.angularAxis.ticksStep||(C[1]-C[0])/(O*(f.minorTicks+1));k&&(P=Math.max(Math.round(P),1)),C[2]||(C[2]=P);var N=a.range.apply(this,C);if(N=N.map(function(t,e){return parseFloat(t.toPrecision(12))}),l=a.scale.linear().domain(C.slice(0,2)).range(\"clockwise\"===f.direction?[0,360]:[360,0]),u.layout.angularAxis.domain=l.domain(),u.layout.angularAxis.endPadding=T?E:0,e=a.select(this).select(\"svg.chart-root\"),\"undefined\"==typeof e||e.empty()){var D=\"<svg xmlns='http://www.w3.org/2000/svg' class='chart-root'>' + '<g class='outer-group'>' + '<g class='chart-group'>' + '<circle class='background-circle'></circle>' + '<g class='geometry-group'></g>' + '<g class='radial axis-group'>' + '<circle class='outside-circle'></circle>' + '</g>' + '<g class='angular axis-group'></g>' + '<g class='guides-group'><line></line><circle r='0'></circle></g>' + '</g>' + '<g class='legend-group'></g>' + '<g class='tooltips-group'></g>' + '<g class='title-group'><text></text></g>' + '</g>' + '</svg>\",I=(new DOMParser).parseFromString(D,\"application/xml\"),R=this.appendChild(this.ownerDocument.importNode(I.documentElement,!0));e=a.select(R)}e.select(\".guides-group\").style({\"pointer-events\":\"none\"}),e.select(\".angular.axis-group\").style({\"pointer-events\":\"none\"}),e.select(\".radial.axis-group\").style({\"pointer-events\":\"none\"});var j,q=e.select(\".chart-group\"),F={fill:\"none\",stroke:f.tickColor},B={\"font-size\":f.font.size,\"font-family\":f.font.family,fill:f.font.color,\"text-shadow\":[\"-1px 0px\",\"1px -1px\",\"-1px 1px\",\"1px 1px\"].map(function(t,e){return\" \"+t+\" 0 \"+f.font.outlineColor}).join(\",\")};if(f.showLegend){j=e.select(\".legend-group\").attr({transform:\"translate(\"+[x,f.margin.top]+\")\"}).style({display:\"block\"});var H=h.map(function(t,e){var n=o.util.cloneJson(t);return n.symbol=\"DotPlot\"===t.geometry?t.dotType||\"circle\":\"LinePlot\"!=t.geometry?\"square\":\"line\",n.visibleInLegend=\"undefined\"==typeof t.visibleInLegend||t.visibleInLegend,n.color=\"LinePlot\"===t.geometry?t.strokeColor:t.color,n});o.Legend().config({data:h.map(function(t,e){return t.name||\"Element\"+e}),legendConfig:i({},o.Legend.defaultConfig().legendConfig,{container:j,elements:H,reverseOrder:f.legend.reverseOrder})})();var V=j.node().getBBox();x=Math.min(f.width-V.width-f.margin.left-f.margin.right,f.height-f.margin.top-f.margin.bottom)/2,x=Math.max(10,x),_=[f.margin.left+x,f.margin.top+x],r.range([0,x]),u.layout.radialAxis.domain=r.domain(),j.attr(\"transform\",\"translate(\"+[_[0]+x,_[1]-x]+\")\")}else j=e.select(\".legend-group\").style({display:\"none\"});e.attr({width:f.width,height:f.height}).style({opacity:f.opacity}),q.attr(\"transform\",\"translate(\"+_+\")\").style({cursor:\"crosshair\"});var Z=[(f.width-(f.margin.left+f.margin.right+2*x+(V?V.width:0)))/2,(f.height-(f.margin.top+f.margin.bottom+2*x))/2];if(Z[0]=Math.max(0,Z[0]),Z[1]=Math.max(0,Z[1]),e.select(\".outer-group\").attr(\"transform\",\"translate(\"+Z+\")\"),f.title){var Y=e.select(\"g.title-group text\").style(B).text(f.title),U=Y.node().getBBox();Y.attr({x:_[0]-U.width/2,y:_[1]-x-20})}var X=e.select(\".radial.axis-group\");if(f.radialAxis.gridLinesVisible){var G=X.selectAll(\"circle.grid-circle\").data(r.ticks(5));G.enter().append(\"circle\").attr({\"class\":\"grid-circle\"}).style(F),G.attr(\"r\",r),G.exit().remove()}X.select(\"circle.outside-circle\").attr({r:x}).style(F);var $=e.select(\"circle.background-circle\").attr({r:x}).style({fill:f.backgroundColor,stroke:f.stroke});if(f.radialAxis.visible){var Q=a.svg.axis().scale(r).ticks(5).tickSize(5);X.call(Q).attr({transform:\"rotate(\"+f.radialAxis.orientation+\")\"}),X.selectAll(\".domain\").style(F),X.selectAll(\"g>text\").text(function(t,e){return this.textContent+f.radialAxis.ticksSuffix}).style(B).style({\"text-anchor\":\"start\"}).attr({x:0,y:0,dx:0,dy:0,transform:function(t,e){return\"horizontal\"===f.radialAxis.tickOrientation?\"rotate(\"+-f.radialAxis.orientation+\") translate(\"+[0,B[\"font-size\"]]+\")\":\"translate(\"+[0,B[\"font-size\"]]+\")\"}}),X.selectAll(\"g>line\").style({stroke:\"black\"})}var W=e.select(\".angular.axis-group\").selectAll(\"g.angular-tick\").data(N),J=W.enter().append(\"g\").classed(\"angular-tick\",!0);W.attr({transform:function(t,e){return\"rotate(\"+s(t,e)+\")\"}}).style({display:f.angularAxis.visible?\"block\":\"none\"}),W.exit().remove(),J.append(\"line\").classed(\"grid-line\",!0).classed(\"major\",function(t,e){return e%(f.minorTicks+1)==0}).classed(\"minor\",function(t,e){return!(e%(f.minorTicks+1)==0)}).style(F),J.selectAll(\".minor\").style({stroke:f.minorTickColor}),W.select(\"line.grid-line\").attr({x1:f.tickLength?x-f.tickLength:0,x2:x}).style({display:f.angularAxis.gridLinesVisible?\"block\":\"none\"}),J.append(\"text\""
,
").classed(\"axis-text\",!0).style(B);var K=W.select(\"text.axis-text\").attr({x:x+f.labelOffset,dy:\".35em\",transform:function(t,e){var n=s(t,e),r=x+f.labelOffset,a=f.angularAxis.tickOrientation;return\"horizontal\"==a?\"rotate(\"+-n+\" \"+r+\" 0)\":\"radial\"==a?270>n&&n>90?\"rotate(180 \"+r+\" 0)\":null:\"rotate(\"+(180>=n&&n>0?-90:90)+\" \"+r+\" 0)\"}}).style({\"text-anchor\":\"middle\",display:f.angularAxis.labelsVisible?\"block\":\"none\"}).text(function(t,e){return e%(f.minorTicks+1)!=0?\"\":k?k[t]+f.angularAxis.ticksSuffix:t+f.angularAxis.ticksSuffix}).style(B);f.angularAxis.rewriteTicks&&K.text(function(t,e){return e%(f.minorTicks+1)!=0?\"\":f.angularAxis.rewriteTicks(this.textContent,e)});var tt=a.max(q.selectAll(\".angular-tick text\")[0].map(function(t,e){return t.getCTM().e+t.getBBox().width}));j.attr({transform:\"translate(\"+[x+tt,f.margin.top]+\")\"});var et=e.select(\"g.geometry-group\").selectAll(\"g\").size()>0,nt=e.select(\"g.geometry-group\").selectAll(\"g.geometry\").data(h);if(nt.enter().append(\"g\").attr({\"class\":function(t,e){return\"geometry geometry\"+e}}),nt.exit().remove(),h[0]||et){var rt=[];h.forEach(function(t,e){var n={};n.radialScale=r,n.angularScale=l,n.container=nt.filter(function(t,n){return n==e}),n.geometry=t.geometry,n.orientation=f.orientation,n.direction=f.direction,n.index=e,rt.push({data:t,geometryConfig:n})});var at=a.nest().key(function(t,e){return\"undefined\"!=typeof t.data.groupId||\"unstacked\"}).entries(rt),ot=[];at.forEach(function(t,e){\"unstacked\"===t.key?ot=ot.concat(t.values.map(function(t,e){return[t]})):ot.push(t.values)}),ot.forEach(function(t,e){var n;n=Array.isArray(t)?t[0].geometryConfig.geometry:t.geometryConfig.geometry;var r=t.map(function(t,e){return i(o[n].defaultConfig(),t)});o[n]().config(r)()})}var it,lt,st=e.select(\".guides-group\"),ct=e.select(\".tooltips-group\"),ut=o.tooltipPanel().config({container:ct,fontSize:8})(),ft=o.tooltipPanel().config({container:ct,fontSize:8})(),dt=o.tooltipPanel().config({container:ct,hasTick:!0})();if(!A){var ht=st.select(\"line\").attr({\n"
,
"x1:0,y1:0,y2:0}).style({stroke:\"grey\",\"pointer-events\":\"none\"});q.on(\"mousemove.angular-guide\",function(t,e){var n=o.util.getMousePos($).angle;ht.attr({x2:-x,transform:\"rotate(\"+n+\")\"}).style({opacity:.5});var r=(n+180+360-f.orientation)%360;it=l.invert(r);var a=o.util.convertToCartesian(x+12,n+180);ut.text(o.util.round(it)).move([a[0]+_[0],a[1]+_[1]])}).on(\"mouseout.angular-guide\",function(t,e){st.select(\"line\").style({opacity:0})})}var pt=st.select(\"circle\").style({stroke:\"grey\",fill:\"none\"});q.on(\"mousemove.radial-guide\",function(t,e){var n=o.util.getMousePos($).radius;pt.attr({r:n}).style({opacity:.5}),lt=r.invert(o.util.getMousePos($).radius);var a=o.util.convertToCartesian(n,f.radialAxis.orientation);ft.text(o.util.round(lt)).move([a[0]+_[0],a[1]+_[1]])}).on(\"mouseout.radial-guide\",function(t,e){pt.style({opacity:0}),dt.hide(),ut.hide(),ft.hide()}),e.selectAll(\".geometry-group .mark\").on(\"mouseover.tooltip\",function(t,n){var r=a.select(this),i=r.style(\"fill\"),l=\"black\",s=r.style(\"opacity\")||1;if(r.attr({\"data-opacity\":s}),\"none\"!=i){r.attr({\"data-fill\":i}),l=a.hsl(i).darker().toString(),r.style({fill:l,opacity:1});var c={t:o.util.round(t[0]),r:o.util.round(t[1])};A&&(c.t=k[t[0]]);var u=\"t: \"+c.t+\", r: \"+c.r,f=this.getBoundingClientRect(),d=e.node().getBoundingClientRect(),h=[f.left+f.width/2-Z[0]-d.left,f.top+f.height/2-Z[1]-d.top];dt.config({color:l}).text(u),dt.move(h)}else i=r.style(\"stroke\"),r.attr({\"data-stroke\":i}),l=a.hsl(i).darker().toString(),r.style({stroke:l,opacity:1})}).on(\"mousemove.tooltip\",function(t,e){return 0!=a.event.which?!1:void(a.select(this).attr(\"data-fill\")&&dt.show())}).on(\"mouseout.tooltip\",function(t,e){dt.hide();var n=a.select(this),r=n.attr(\"data-fill\");r?n.style({fill:r,opacity:n.attr(\"data-opacity\")}):n.style({stroke:n.attr(\"data-stroke\"),opacity:n.attr(\"data-opacity\")})})}),d}var e,n,r,l,s={data:[],layout:{}},c={},u={},f=a.dispatch(\"hover\"),d={};return d.render=function(e){return t(e),this},d.config=function(t){if(!arguments.length)return s;var e=o.util.cloneJson(t);return e.data.forEach(function(t,e){s.data[e]||(s.data[e]={}),i(s.data[e],o.Axis.defaultConfig().data[0]),i(s.data[e],t)}),i(s.layout,o.Axis.defaultConfig().layout),i(s.layout,e.layout),this},d.getLiveConfig=function(){return u},d.getinputConfig=function(){return c},d.radialScale=function(t){return r},d.angularScale=function(t){return l},d.svg=function(){return e},a.rebind(d,f,\"on\"),d},o.Axis.defaultConfig=function(t,e){var n={data:[{t:[1,2,3,4],r:[10,11,12,13],name:\"Line1\",geometry:\"LinePlot\",color:null,strokeDreamLedger:\"solid\",strokeColor:null,strokeSize:\"1\",visibleInLegend:!0,opacity:1}],layout:{defaultColorRange:a.scale.category10().range(),title:null,height:450,width:500,margin:{top:40,right:40,bottom:40,left:40},font:{size:12,color:\"gray\",outlineColor:\"white\",family:\"Tahoma, sans-serif\"},direction:\"clockwise\",orientation:0,labelOffset:10,radialAxis:{domain:null,orientation:-45,ticksSuffix:\"\",visible:!0,gridLinesVisible:!0,tickOrientation:\"horizontal\",rewriteTicks:null},angularAxis:{domain:[0,360],ticksSuffix:\"\",visible:!0,gridLinesVisible:!0,labelsVisible:!0,tickOrientation:\"horizontal\",rewriteTicks:null,ticksCount:null,ticksStep:null},minorTicks:0,tickLength:null,tickColor:\"silver\",minorTickColor:\"#eee\",backgroundColor:\"none\",needsEndSpacing:null,showLegend:!0,legend:{reverseOrder:!1},opacity:1}};return n},o.util={},o.DATAEXTENT=\"dataExtent\",o.AREA=\"AreaChart\",o.LINE=\"LinePlot\",o.DOT=\"DotPlot\",o.BAR=\"BarChart\",o.util._override=function(t,e){for(var n in t)n in e&&(e[n]=t[n])},o.util._extend=function(t,e){for(var n in t)e[n]=t[n]},o.util._rndSnd=function(){return 2*Math.random()-1+(2*Math.random()-1)+(2*Math.random()-1)},o.util.dataFromEquation2=function(t,e){var n=e||6,r=a.range(0,360+n,n).map(function(e,n){var r=e*Math.PI/180,a=t(r);return[e,a]});return r},o.util.dataFromEquation=function(t,e,n){var r=e||6,o=[],i=[];a.range(0,360+r,r).forEach(function(e,n){var r=e*Math.PI/180,a=t(r);o.push(e),i.push(a)});var l={t:o,r:i};return n&&(l.name=n),l},o.util.ensureArray=function(t,e){if(\"undefined\"==typeof t)return null;var n=[].concat(t);return a.range(e).map(function(t,e){return n[e]||n[0]})},o.util.fillArrays=function(t,e,n){return e.forEach(function(e,r){t[e]=o.util.ensureArray(t[e],n)}),t},o.util.cloneJson=function(t){return JSON.parse(JSON.stringify(t))},o.util.validateKeys=function(t,e){\"string\"==typeof e&&(e=e.split(\".\"));var n=e.shift();return t[n]&&(!e.length||objHasKeys(t[n],e))},o.util.sumArrays=function(t,e){return a.zip(t,e).map(function(t,e){return a.sum(t)})},o.util.arrayLast=function(t){return t[t.length-1]},o.util.arrayEqual=function(t,e){for(var n=Math.max(t.length,e.length,1);n-- >=0&&t[n]===e[n];);return-2===n},o.util.flattenArray=function(t){for(var e=[];!o.util.arrayEqual(e,t);)e=t,t=[].concat.apply([],t);return t},o.util.deduplicate=function(t){return t.filter(function(t,e,n){return n.indexOf(t)==e})},o.util.convertToCartesian=function(t,e){var n=e*Math.PI/180,r=t*Math.cos(n),a=t*Math.sin(n);return[r,a]},o.util.round=function(t,e){var n=e||2,r=Math.pow(10,n);return Math.round(t*r)/r},o.util.getMousePos=function(t){var e=a.mouse(t.node()),n=e[0],r=e[1],o={};return o.x=n,o.y=r,o.pos=e,o.angle=180*(Math.atan2(r,n)+Math.PI)/Math.PI,o.radius=Math.sqrt(n*n+r*r),o},o.util.duplicatesCount=function(t){for(var e,n={},r={},a=0,o=t.length;o>a;a++)e=t[a],e in n?(n[e]++,r[e]=n[e]):n[e]=1;return r},o.util.duplicates=function(t){return Object.keys(o.util.duplicatesCount(t))},o.util.translator=function(t,e,n,r){if(r){var a=n.slice();n=e,e=a}var o=e.reduce(function(t,e){return\"undefined\"!=typeof t?t[e]:void 0},t);\"undefined\"!=typeof o&&(e.reduce(function(t,n,r){return\"undefined\"!=typeof t?(r===e.length-1&&delete t[n],t[n]):void 0},t),n.reduce(function(t,e,r){return\"undefined\"==typeof t[e]&&(t[e]={}),r===n.length-1&&(t[e]=o),t[e]},t))},o.PolyChart=function(){function t(){var t=n[0].geometryConfig,e=t.container;\"string\"==typeof e&&(e=a.select(e)),e.datum(n).each(function(e,n){function r(e,n){var r=t.radialScale(e[1]),a=(t.angularScale(e[0])+t.orientation)*Math.PI/180;return{r:r,t:a}}function o(t){var e=t.r*Math.cos(t.t),n=t.r*Math.sin(t.t);return{x:e,y:n}}var i=!!e[0].data.yStack,s=e.map(function(t,e){return i?a.zip(t.data.t[0],t.data.r[0],t.data.yStack[0]):a.zip(t.data.t[0],t.data.r[0])}),c=t.angularScale,u=t.radialScale.domain()[0],f={};f.bar=function(n,r,o){var i=e[o].data,l=t.radialScale(n[1])-t.radialScale(0),s=t.radialScale(n[2]||0),u=i.barWidth;a.select(this).attr({\"class\":\"mark bar\",d:\"M\"+[[l+s,-u/2],[l+s,u/2],[s,u/2],[s,-u/2]].join(\"L\")+\"Z\",transform:function(e,n){return\"rotate(\"+(t.orientation+c(e[0]))+\")\"}})},f.dot=function(t,n,i){var l=t[2]?[t[0],t[1]+t[2]]:t,s=a.svg.symbol().size(e[i].data.dotSize).type(e[i].data.dotType)(t,n);a.select(this).attr({\"class\":\"mark dot\",d:s,transform:function(t,e){var n=o(r(l));return\"translate(\"+[n.x,n.y]+\")\"}})};var d=a.svg.line.radial().interpolate(e[0].data.lineInterpolation).radius(function(e){return t.radialScale(e[1])}).angle(function(e){return t.angularScale(e[0])*Math.PI/180});f.line=function(n,r,o){var i=n[2]?s[o].map(function(t,e){return[t[0],t[1]+t[2]]}):s[o];if(a.select(this).each(f.dot).style({opacity:function(t,n){return+e[o].data.dotVisible},fill:v.stroke(n,r,o)}).attr({\"class\":\"mark dot\"}),!(r>0)){var l=a.select(this.parentNode).selectAll(\"path.line\").data([0]);l.enter().insert(\"path\"),l.attr({\"class\":\"line\",d:d(i),transform:function(e,n){return\"rotate(\"+(t.orientation+90)+\")\"},\"pointer-events\":\"none\"}).style({fill:function(t,e){return v.fill(n,r,o)},\"fill-opacity\":0,stroke:function(t,e){return v.stroke(n,r,o)},\"stroke-width\":function(t,e){return v[\"stroke-width\"](n,r,o)},\"stroke-dreamledgerarray\":function(t,e){return v[\"stroke-dreamledgerarray\"](n,r,o)},opacity:function(t,e){return v.opacity(n,r,o)},display:function(t,e){return v.display(n,r,o)}})}};var h=t.angularScale.range(),p=Math.abs(h[1]-h[0])/s[0].length*Math.PI/180,g=a.svg.arc().startAngle(function(t){return-p/2}).endAngle(function(t){return p/2}).innerRadius(function(e){return t.radialScale(u+(e[2]||0))}).outerRadius(function(e){return t.radialScale(u+(e[2]||0))+t.radialScale(e[1])});f.arc=function(e,n,r){a.select(this).attr({\"class\":\"mark arc\",d:g,transform:function(e,n){return\"rotate(\"+(t.orientation+c(e[0])+90)+\")\"}})};var v={fill:function(t,n,r){return e[r].data.color},stroke:function(t,n,r){return e[r].data.strokeColor},\"stroke-width\":function(t,n,r){return e[r].data.strokeSize+\"px\"},\"stroke-dreamledgerarray\":function(t,n,r){return l[e[r].data.strokeDreamLedger]},opacity:function(t,n,r){return e[r].data.opacity},display:function(t,n,r){return\"undefined\"==typeof e[r].data.visible||e[r].data.visible?\"block\":\"none\"}},m=a.select(this).selectAll(\"g.layer\").data(s);m.enter().append(\"g\").attr({\"class\":\"layer\"});var y=m.selectAll(\"path.mark\").data(function(t,e){return t});y.enter().append(\"path\").attr({\"class\":\"mark\"}),y.style(v).each(f[t.geometryType]),y.exit().remove(),m.exit().remove()})}var e,n=[o.PolyChart.defaultConfig()],r=a.dispatch(\"hover\"),l={solid:\"none\",dreamledger:[5,2],dot:[2,5]};return t.config=function(t){return arguments.length?(t.forEach(function(t,e){n[e]||(n[e]={}),i(n[e],o.PolyChart.defaultConfig()),i(n[e],t)}),this):n},t.getColorScale=function(){return e},a.rebind(t,r,\"on\"),t},o.PolyChart.defaultConfig=function(){var t={data:{name:\"geom1\",t:[[1,2,3,4]],r:[[1,2,3,4]],dotType:\"circle\",dotSize:64,dotVisible:!1,barWidth:20,color:\"#ffa500\",strokeSize:1,strokeColor:\"silver\",strokeDreamLedger:\"solid\",opacity:1,index:0,visible:!0,visibleInLegend:!0},geometryConfig:{geometry:\"LinePlot\",geometryType:\"arc\",direction:\"clockwise\",orientation:0,container:\"body\",radialScale:null,angularScale:null,colorScale:a.scale.category20()}};return t},o.BarChart=function(){return o.PolyChart()},o.BarChart.defaultConfig=function(){var t={geometryConfig:{geometryType:\"bar\"}};return t},o.AreaChart=function(){return o.PolyChart()},o.AreaChart.defaultConfig=function(){var t={geometryConfig:{geometryType:\"arc\"}};return t},o.DotPlot=function(){ret"
,
"urn o.PolyChart()},o.DotPlot.defaultConfig=function(){var t={geometryConfig:{geometryType:\"dot\",dotType:\"circle\"}};return t},o.LinePlot=function(){return o.PolyChart()},o.LinePlot.defaultConfig=function(){var t={geometryConfig:{geometryType:\"line\"}};return t},o.Legend=function(){function t(){var n=e.legendConfig,r=e.data.map(function(t,e){return[].concat(t).map(function(t,r){var a=i({},n.elements[e]);return a.name=t,a.color=[].concat(n.elements[e].color)[r],a})}),o=a.merge(r);o=o.filter(function(t,e){return n.elements[e]&&(n.elements[e].visibleInLegend||\"undefined\"==typeof n.elements[e].visibleInLegend)}),n.reverseOrder&&(o=o.reverse());var l=n.container;(\"string\"==typeof l||l.nodeName)&&(l=a.select(l));var s=o.map(function(t,e){return t.color}),c=n.fontSize,u=null==n.isContinuous?\"number\"==typeof o[0]:n.isContinuous,f=u?n.height:c*o.length,d=l.classed(\"legend-group\",!0),h=d.selectAll(\"svg\").data([0]),p=h.enter().append(\"svg\").attr({width:300,height:f+c,xmlns:\"http://www.w3.org/2000/svg\",\"xmlns:xlink\":\"http://www.w3.org/1999/xlink\",version:\"1.1\"});p.append(\"g\").classed(\"legend-axis\",!0),p.append(\"g\").classed(\"legend-marks\",!0);var g=a.range(o.length),v=a.scale[u?\"linear\":\"ordinal\"]().domain(g).range(s),m=a.scale[u?\"linear\":\"ordinal\"]().domain(g)[u?\"range\":\"rangePoints\"]([0,f]),y=function(t,e){var n=3*e;return\"line\"===t?\"M\"+[[-e/2,-e/12],[e/2,-e/12],[e/2,e/12],[-e/2,e/12]]+\"Z\":-1!=a.svg.symbolTypes.indexOf(t)?a.svg.symbol().type(t).size(n)():a.svg.symbol().type(\"square\").size(n)()};if(u){var x=h.select(\".legend-marks\").append(\"defs\").append(\"linearGradient\").attr({id:\"grad1\",x1:\"0%\",y1:\"0%\",x2:\"0%\",y2:\"100%\"}).selectAll(\"stop\").data(s);x.enter().append(\"stop\"),x.attr({offset:function(t,e){return e/(s.length-1)*100+\"%\"}}).style({\"stop-color\":function(t,e){return t}}),h.append(\"rect\").classed(\"legend-mark\",!0).attr({height:n.height,width:n.colorBandWidth,fill:\"url(#grad1)\"})}else{var b=h.select(\".legend-marks\").selectAll(\"path.legend-mark\").data(o);b.enter().append(\"path\").classed(\"legend-mark\",!0),b.attr({transform:function(t,e){return\"translate(\"+[c/2,m(e)+c/2]+\")\"},d:function(t,e){var n=t.symbol;return y(n,c)},fill:function(t,e){return v(e)}}),b.exit().remove()}var _=a.svg.axis().scale(m).orient(\"right\"),w=h.select(\"g.legend-axis\").attr({transform:\"translate(\"+[u?n.colorBandWidth:c,c/2]+\")\"}).call(_);return w.selectAll(\".domain\").style({fill:\"none\",stroke:\"none\"}),w.selectAll(\"line\").style({fill:\"none\",stroke:u?n.textColor:\"none\"}),w.selectAll(\"text\").style({fill:n.textColor,\"font-size\":n.fontSize}).text(function(t,e){return o[e].name}),t}var e=o.Legend.defaultConfig(),n=a.dispatch(\"hover\");return t.config=function(t){return arguments.length?(i(e,t),this):e},a.rebind(t,n,\"on\"),t},o.Legend.defaultConfig=function(t,e){var n={data:[\"a\",\"b\",\"c\"],legendConfig:{elements:[{symbol:\"line\",color:\"red\"},{symbol:\"square\",color:\"yellow\"},{symbol:\"diamond\",color:\"limegreen\"}],height:150,colorBandWidth:30,fontSize:12,container:\"body\",isContinuous:null,textColor:\"grey\",reverseOrder:!1}};return n},o.tooltipPanel=function(){var t,e,n,r={container:null,hasTick:!1,fontSize:12,color:\"white\",padding:5},l=\"tooltip-\"+o.tooltipPanel.uid++,s=10,c=function(){t=r.container.selectAll(\"g.\"+l).data([0]);var a=t.enter().append(\"g\").classed(l,!0).style({\"pointer-events\":\"none\",display:\"none\"});return n=a.append(\"path\").style({fill:\"white\",\"fill-opacity\":.9}).attr({d:\"M0 0\"}),e=a.append(\"text\").attr({dx:r.padding+s,dy:.3*+r.fontSize}),c};return c.text=function(o){var i=a.hsl(r.color).l,l=i>=.5?\"#aaa\":\"white\",u=i>=.5?\"black\":\"white\",f=o||\"\";e.style({fill:u,\"font-size\":r.fontSize+\"px\"}).text(f);var d=r.padding,h=e.node().getBBox(),p={fill:r.color,stroke:l,\"stroke-width\":\"2px\"},g=h.width+2*d+s,v=h.height+2*d;return n.attr({d:\"M\"+[[s,-v/2],[s,-v/4],[r.hasTick?0:s,0],[s,v/4],[s,v/2],[g,v/2],[g,-v/2]].join(\"L\")+\"Z\"}).style(p),t.attr({transform:\"translate(\"+[s,-v/2+2*d]+\")\"}),t.style({display:\"block\"}),c},c.move=function(e){return t?(t.attr({transform:\"translate(\"+[e[0],e[1]]+\")\"}).style({display:\"block\"}),c):void 0},c.hide=function(){return t?(t.style({display:\"none\"}),c):void 0},c.show=function(){return t?(t.style({display:\"block\"}),c):void 0},c.config=function(t){return i(r,t),c},c},o.tooltipPanel.uid=1,o.adapter={},o.adapter.plotly=function(){var t={};return t.convert=function(t,e){var n={};if(t.data&&(n.data=t.data.map(function(t,n){var r=i({},t),a=[[r,[\"marker\",\"color\"],[\"color\"]],[r,[\"marker\",\"opacity\"],[\"opacity\"]],[r,[\"marker\",\"line\",\"color\"],[\"strokeColor\"]],[r,[\"marker\",\"line\",\"dreamledger\"],[\"strokeDreamLedger\"]],[r,[\"marker\",\"line\",\"width\"],[\"strokeSize\"]],[r,[\"marker\",\"symbol\"],[\"dotType\"]],[r,[\"marker\",\"size\"],[\"dotSize\"]],[r,[\"marker\",\"barWidth\"],[\"barWidth\"]],[r,[\"line\",\"interpolation\"],[\"lineInterpolation\"]],[r,[\"showlegend\"],[\"visibleInLegend\"]]];return a.forEach(function(t,n){o.util.translator.apply(null,t.concat(e))}),e||delete r.marker,e&&delete r.groupId,e?(\"LinePlot\"===r.geometry?(r.type=\"scatter\",r.dotVisible===!0?(delete r.dotVisible,r.mode=\"lines+markers\"):r.mode=\"lines\"):\"DotPlot\"===r.geometry?(r.type=\"scatter\",r.mode=\"markers\"):\"AreaChart\"===r.geometry?r.type=\"area\":\"BarChart\"===r.geometry&&(r.type=\"bar\"),delete r.geometry):(\"scatter\"===r.type?\"lines\"===r.mode?r.geometry=\"LinePlot\":\"markers\"===r.mode?r.geometry=\"DotPlot\":\"lines+markers\"===r.mode&&(r.geometry=\"LinePlot\",r.dotVisible=!0):\"area\"===r.type?r.geometry=\"AreaChart\":\"bar\"===r.type&&(r.geometry=\"BarChart\"),delete r.mode,delete r.type),r}),!e&&t.layout&&\"stack\"===t.layout.barmode)){var r=o.util.duplicates(n.data.map(function(t,e){return t.geometry}));n.data.forEach(function(t,e){var a=r.indexOf(t.geometry);-1!=a&&(n.data[e].groupId=a)})}if(t.layout){var l=i({},t.layout),s=[[l,[\"plot_bgcolor\"],[\"backgroundColor\"]],[l,[\"showlegend\"],[\"showLegend\"]],[l,[\"radialaxis\"],[\"radialAxis\"]],[l,[\"angularaxis\"],[\"angularAxis\"]],[l.angularaxis,[\"showline\"],[\"gridLinesVisible\"]],[l.angularaxis,[\"showticklabels\"],[\"labelsVisible\"]],[l.angularaxis,[\"nticks\"],[\"ticksCount\"]],[l.angularaxis,[\"tickorientation\"],[\"tickOrientation\"]],[l.angularaxis,[\"ticksuffix\"],[\"ticksSuffix\"]],[l.angularaxis,[\"range\"],[\"domain\"]],[l.angularaxis,[\"endpadding\"],[\"endPadding\"]],[l.radialaxis,[\"showline\"],[\"gridLinesVisible\"]],[l.radialaxis,[\"tickorientation\"],[\"tickOrientation\"]],[l.radialaxis,[\"ticksuffix\"],[\"ticksSuffix\"]],[l.radialaxis,[\"range\"],[\"domain\"]],[l.angularAxis,[\"showline\"],[\"gridLinesVisible\"]],[l.angularAxis,[\"showticklabels\"],[\"labelsVisible\"]],[l.angularAxis,[\"nticks\"],[\"ticksCount\"]],[l.angularAxis,[\"tickorientation\"],[\"tickOrientation\"]],[l.angularAxis,[\"ticksuffix\"],[\"ticksSuffix\"]],[l.angularAxis,[\"range\"],[\"domain\"]],[l.angularAxis,[\"endpadding\"],[\"endPadding\"]],[l.radialAxis,[\"showline\"],[\"gridLinesVisible\"]],[l.radialAxis,[\"tickorientation\"],[\"tickOrientation\"]],[l.radialAxis,[\"ticksuffix\"],[\"ticksSuffix\"]],[l.radialAxis,[\"range\"],[\"domain\"]],[l.font,[\"outlinecolor\"],[\"outlineColor\"]],[l.legend,[\"traceorder\"],[\"reverseOrder\"]],[l,[\"labeloffset\"],[\"labelOffset\"]],[l,[\"defaultcolorrange\"],[\"defaultColorRange\"]]];if(s.forEach(function(t,n){o.util.translator.apply(null,t.concat(e))}),e?(\"undefined\"!=typeof l.tickLength&&(l.angularaxis.ticklen=l.tickLength,delete l.tickLength),l.tickColor&&(l.angularaxis.tickcolor=l.tickColor,delete l.tickColor)):(l.angularAxis&&\"undefined\"!=typeof l.angularAxis.ticklen&&(l.tickLength=l.angularAxis.ticklen),l.angularAxis&&\"undefined\"!=typeof l.angularAxis.tickcolor&&(l.tickColor=l.angularAxis.tickcolor)),l.legend&&\"boolean\"!=typeof l.legend.reverseOrder&&(l.legend.reverseOrder=\"normal\"!=l.legend.reverseOrder),l.legend&&\"boolean\"==typeof l.legend.traceorder&&(l.legend.traceorder=l.legend.traceorder?\"reversed\":\"normal\",delete l.legend.reverseOrder),l.margin&&\"undefined\"!=typeof l.margin.t){var c=[\"t\",\"r\",\"b\",\"l\",\"pad\"],u=[\"top\",\"right\",\"bottom\",\"left\",\"pad\"],f={};a.entries(l.margin).forEach(function(t,e){f[u[c.indexOf(t.key)]]=t.value}),l.margin=f}e&&(delete l.needsEndSpacing,delete l.minorTickColor,delete l.minorTicks,delete l.angularaxis.ticksCount,delete l.angularaxis.ticksCount,delete l.angularaxis.ticksStep,delete l.angularaxis.rewriteTicks,delete l.angularaxis.nticks,delete l.radialaxis.ticksCount,delete l.radialaxis.ticksCount,delete l.radialaxis.ticksStep,delete l.radialaxis.rewriteTicks,delete l.radialaxis.nticks),n.layout=l}return n},t}},{\"../../plotly\":107,\"./micropolar_manager\":134,d3:9}],134:[function(t,e,n){\"use strict\";var r=t(\"../../plotly\"),a=t(\"d3\"),o=t(\"./undo_manager\"),i=e.exports={},l=r.Lib.extendDeepAll;i.framework=function(t){function e(e,o){return o&&(f=o),a.select(a.select(f).node().parentNode).selectAll(\".svg-container>*:not(.chart-root)\").remove(),n=n?l(n,e):e,c||(c=r.micropolar.Axis()),u=r.micropolar.adapter.plotly().convert(n),c.config(u).render(f),t.data=n.data,t.layout=n.layout,i.fillLayout(t),n}var n,s,c,u,f,d=new o;return e.isPolar=!0,e.svg=function(){return c.svg()},e.getConfig=function(){return n},e.getLiveConfig=function(){return r.micropolar.adapter.plotly().convert(c.getLiveConfig(),!0)},e.getLiveScales=function(){return{t:c.angularScale(),r:c.radialScale()}},e.setUndoPoint=function(){var t=this,e=r.micropolar.util.cloneJson(n);!function(e,n){d.add({undo:function(){n&&t(n)},redo:function(){t(e)}})}(e,s),s=r.micropolar.util.cloneJson(e)},e.undo=function(){d.undo()},e.redo=function(){d.redo()},e},i.fillLayout=function(t){var e=a.select(t).selectAll(\".plot-container\"),n=e.selectAll(\".svg-container\"),o=t.framework&&t.framework.svg&&t.framework.svg(),i={width:800,height:600,paper_bgcolor:r.Color.background,_container:e,_paperdiv:n,_paper:o};t._fullLayout=l(i,t.layout)}},{\"../../plotly\":107,\"./undo_manager\":135,d3:9}],135:[function(t,e,n){\"use strict\";e.exports=function(){function t(t,e){return t?(a=!0,t[e](),a=!1,this):this}var e,n=[],r=-1,a=!1;return{add:function(t){return a?this:(n.splice(r+1,n.length-r),n.push(t),r=n.length-1,this)},setCallback:function(t){e=t},undo:function(){var a=n[r];return a?(t(a,\"undo\"),r-=1,e&&e(a.undo),thi"
,
"s):this},redo:function(){var a=n[r+1];return a?(t(a,\"redo\"),r+=1,e&&e(a.redo),this):this},clear:function(){n=[],r=-1},hasUndo:function(){return-1!==r},hasRedo:function(){return r<n.length-1},getCommands:function(){return n},getPreviousCommand:function(){return n[r-1]},getIndex:function(){return r}}}},{}],136:[function(t,e,n){\"use strict\";function r(t){var e;switch(t){case\"themes__thumb\":e={autosize:!0,width:150,height:150,title:\"\",showlegend:!1,margin:{l:5,r:5,t:5,b:5,pad:0},annotations:[]};break;case\"thumbnail\":e={title:\"\",hidesources:!0,showlegend:!1,borderwidth:0,bordercolor:\"\",margin:{l:1,r:1,t:1,b:1,pad:0},annotations:[]};break;default:e={}}return e}function a(t){var e=[\"xaxis\",\"yaxis\",\"zaxis\"];return e.indexOf(t.slice(0,5))>-1}var o=t(\"../plotly\"),i=o.Lib.extendFlat,l=o.Lib.extendDeep;e.exports=function(t,e){t.framework&&t.framework.isPolar&&(t=t.framework.getConfig());var n,s=t.data,c=t.layout,u=l([],s),f=l({},c,r(e.tileClass));if(e.width&&(f.width=e.width),e.height&&(f.height=e.height),\"thumbnail\"===e.tileClass||\"themes__thumb\"===e.tileClass){f.annotations=[];var d=Object.keys(f);for(n=0;n<d.length;n++)a(d[n])&&(f[d[n]].title=\"\");for(n=0;n<u.length;n++){var h=u[n];h.showscale=!1,h.marker&&(h.marker.showscale=!1),\"pie\"===h.type&&(h.textposition=\"none\")}}if(Array.isArray(e.annotations))for(n=0;n<e.annotations.length;n++)f.annotations.push(e.annotations[n]);var p=o.Plots.getSubplotIds(f,\"gl3d\");if(p.length){var g={};for(\"thumbnail\"===e.tileClass&&(g={title:\"\",showaxeslabels:!1,showticklabels:!1,linetickenable:!1}),n=0;n<p.length;n++){var v=p[n];i(f[v].xaxis,g),i(f[v].yaxis,g),i(f[v].zaxis,g),f[v]._scene=null}}var m=document.createElement(\"div\");e.tileClass&&(m.className=e.tileClass);var y={td:m,layout:f,data:u,config:{staticPlot:void 0===e.staticPlot?!0:e.staticPlot,plotGlPixelRatio:void 0===e.plotGlPixelRatio?2:e.plotGlPixelRatio,displaylogo:e.displaylogo||!1,showLink:e.showLink||!1,showTips:e.showTips||!1}};return\"transparent\"!==e.setBackground&&(y.config.setBackground=e.setBackground||\"opaque\"),y.td.defaultLayout=r(e.tileClass),y}},{\"../plotly\":107}],137:[function(t,e,n){\"use strict\";function r(t,e){return e=e||{},e.format=e.format||\"png\",new Promise(function(n,r){t._snapshotInProgress&&r(new Error(\"Snapshotting already in progress.\")),o.isIE()&&\"svg\"!==e.format&&r(new Error(\"Sorry IE does not support downloading from canvas. Try {format:'svg'} instead.\")),t._snapshotInProgress=!0;var l=a(t,e),s=e.filename||t.fn||\"newplot\";s+=\".\"+e.format,l.then(function(e){return t._snapshotInProgress=!1,i(e,s)}).then(function(t){n(t)}).catch(function(e){t._snapshotInProgress=!1,r(e)})})}var a=t(\"../plot_api/to_image\"),o=t(\"../lib\"),i=t(\"./filesaver\");e.exports=r},{\"../lib\":89,\"../plot_api/to_image\":105,\"./filesaver\":138}],138:[function(t,e,n){\"use strict\";var r=function(t,e){var n=document.createElement(\"a\"),r=\"download\"in n,a=/Version\\/[\\d\\.]+.*Safari/.test(navigator.userAgent),o=new Promise(function(o,i){\"undefined\"!=typeof navigator&&/MSIE [1-9]\\./.test(navigator.userAgent)&&i(new Error(\"IE < 10 unsupported\")),a&&(document.location.href=\"data:application/octet-stream\"+t.slice(t.search(/[,;]/)),o(e)),e||(e=\"download\"),r&&(n.href=t,n.download=e,document.body.appendChild(n),n.click(),document.body.removeChild(n),o(e)),\"undefined\"!=typeof navigator&&navigator.msSaveBlob&&(navigator.msSaveBlob(new Blob([t]),e),o(e)),i(new Error(\"download error\"))});return o};e.exports=r},{}],139:[function(t,e,n){\"use strict\";function r(t){return t._has&&(t._has(\"gl3d\")||t._has(\"gl2d\"))?500:0}function a(t){return t.data&&t.data[0]&&t.data[0].r?void 0:function(){(t.calcdata||[]).forEach(function(t){t[0]&&t[0].t&&t[0].t.cb&&t[0].t.cb()})}}var o={getDelay:r,getRedrawFunc:a,clone:t(\"./cloneplot\"),toSVG:t(\"./tosvg\"),svgToImg:t(\"./svgtoimg\"),toImage:t(\"./toimage\"),downloadImage:t(\"./download\")};e.exports=o},{\"./cloneplot\":136,\"./download\":137,\"./svgtoimg\":140,\"./toimage\":141,\"./tosvg\":142}],140:[function(t,e,n){\"use strict\";function r(t){var e=t.emitter||new o,n=new Promise(function(r,o){var i=window.Image,l=t.svg,s=t.format||\"png\";if(a.isIE()&&(l=l.replace(/\"/gi,\"'\"),l=l.replace(/(\\('#)(.*)('\\))/gi,'(\"$2\")'),l=l.replace(/(\\\\')/gi,'\"'),\"svg\"!==s)){var c=new Error(\"Sorry IE does not support downloading from canvas. Try {format:'svg'} instead.\");return o(c),t.promise?n:e.emit(\"error\",c)}var u=t.canvas,f=u.getContext(\"2d\"),d=new i,h=\"data:image/svg+xml,\"+encodeURIComponent(l);u.height=t.height||150,u.width=t.width||300,d.onload=function(){var n;switch(\"svg\"!==s&&f.drawImage(d,0,0),s){case\"jpeg\":n=u.toDataURL(\"image/jpeg\");break;case\"png\":n=u.toDataURL(\"image/png\");break;case\"webp\":n=u.toDataURL(\"image/webp\");break;case\"svg\":n=h;break;default:if(o(new Error(\"Image format is not jpeg, png or svg\")),!t.promise)return e.emit(\"error\",\"Image format is not jpeg, png or svg\")}r(n),t.promise||e.emit(\"success\",n)},d.onerror=function(n){return o(n),t.promise?void 0:e.emit(\"error\",n)},d.src=h});return t.promise?n:e}var a=t(\"../lib\"),o=t(\"events\").EventEmitter;e.exports=r},{\"../lib\":89,events:7}],141:[function(t,e,n){\"use strict\";function r(t,e){function n(){var t=r.getDelay(c._fullLayout);setTimeout(function(){var t=o.Snapshot.toSVG(c),n=document.createElement(\"canvas\");n.id=i.randstr(),l=o.Snapshot.svgToImg({format:e.format,width:c._fullLayout.width,height:c._fullLayout.height,canvas:n,emitter:l,svg:t}),l.clean=function(){c&&document.body.removeChild(c)}},t)}var r=o.Snapshot,l=new a,s=r.clone(t,{format:\"png\"}),c=s.td;c.style.position=\"absolute\",c.style.left=\"-5000px\",document.body.appendChild(c);var u=r.getRedrawFunc(c);return o.plot(c,s.data,s.layout,s.config).then(u).then(n).catch(function(t){l.emit(\"error\",t)}),l}var a=t(\"events\").EventEmitter,o=t(\"../plotly\"),i=t(\"../lib\");e.exports=r},{\"../lib\":89,\"../plotly\":107,events:7}],142:[function(t,e,n){\"use strict\";var r=t(\"d3\"),a=t(\"../lib/svg_text_utils\"),o=t(\"../components/drawing\"),i=t(\"../components/color\"),l=t(\"../constants/xmlns_namespaces\");e.exports=function(t,e){var n,s=t._fullLayout,c=s._paper,u=s._toppaper;c.insert(\"rect\",\":first-child\").call(o.setRect,0,0,s.width,s.height).call(i.fill,s.paper_bgcolor);var f=s._basePlotModules||[];for(n=0;n<f.length;n++){var d=f[n];d.toSVG&&d.toSVG(t)}if(u){var h=u.node().childNodes,p=Array.prototype.slice.call(h);for(n=0;n<p.length;n++){var g=p[n];g.childNodes.length&&c.node().appendChild(g)}}s._draggers&&s._draggers.remove(),c.node().style.background=\"\",c.selectAll(\"text\").attr(\"data-unformatted\",null).each(function(){var t=r.select(this);if(\"hidden\"===t.style(\"visibility\"))return void t.remove();var e=t.style(\"font-family\");e&&-1!==e.indexOf('\"')&&t.style(\"font-family\",e.replace(/\"/g,\"TOBESTRIPPED\"))}),\"pdf\"!==e&&\"eps\"!==e||c.selectAll(\"#MathJax_SVG_glyphs path\").attr(\"stroke-width\",0),c.node().setAttributeNS(l.xmlns,\"xmlns\",l.svg),c.node().setAttributeNS(l.xmlns,\"xmlns:xlink\",l.xlink);var v=(new window.XMLSerializer).serializeToString(c.node());return v=a.html_entity_decode(v),v=a.xml_entity_encode(v),v=v.replace(/(\"TOBESTRIPPED)|(TOBESTRIPPED\")/g,\"'\")}},{\"../components/color\":18,\"../components/drawing\":41,\"../constants/xmlns_namespaces\":82,\"../lib/svg_text_utils\":100,d3:9}],143:[function(t,e,n){\"use strict\";var r=t(\"../../lib\").mergeArray;e.exports=function(t){var e=t[0].trace,n=e.marker,a=n.line;r(e.text,t,\"tx\"),r(n.opacity,t,\"mo\"),r(n.color,t,\"mc\"),r(a.color,t,\"mlc\"),r(a.width,t,\"mlw\")}},{\"../../lib\":89}],144:[function(t,e,n){\"use strict\";var r=t(\"../scatter/attributes\"),a=t(\"../../components/colorscale/color_attributes\"),o=t(\"../../lib/extend\").extendFlat,i=r.marker,l=i.line,s=o({},l.width,{dflt:0}),c=o({},{width:s},a(\"marker.line\")),u=o({},{showscale:i.showscale,line:c},a(\"marker\"));e.exports={x:r.x,x0:r.x0,dx:r.dx,y:r.y,y0:r.y0,dy:r.dy,text:r.text,orientation:{valType:\"enumerated\",values:[\"v\",\"h\"]},marker:u,r:r.r,t:r.t,_nestedModules:{error_y:\"ErrorBars\",error_x:\"ErrorBars\",\"marker.colorbar\":\"Colorbar\"},_deprecated:{bardir:{valType:\"enumerated\",values:[\"v\",\"h\"]}}}},{\"../../components/colorscale/color_attributes\":26,\"../../lib/extend\":88,\"../scatter/attributes\":167}],145:[function(t,e,n){\"use strict\";var r=t(\"fast-isnumeric\"),a=t(\"../../plots/cartesian/axes\"),o=t(\"../../components/colorscale/has_colorscale\"),i=t(\"../../components/colorscale/calc\");e.exports=function(t,e){var n,l,s,c=a.getFromId(t,e.xaxis||\"x\"),u=a.getFromId(t,e.yaxis||\"y\"),f=e.orientation||(e.x&&!e.y?\"h\":\"v\");\"h\"===f?(l=c.makeCalcdata(e,\"x\"),n=u.makeCalcdata(e,\"y\")):(l=u.makeCalcdata(e,\"y\"),n=c.makeCalcdata(e,\"x\"));var d=Math.min(n.length,l.length),h=[];for(s=0;d>s;s++)r(n[s])&&h.push({p:n[s],s:l[s],b:0});return o(e,\"marker\")&&i(e,e.marker.color,\"marker\",\"c\"),o(e,\"marker.line\")&&i(e,e.marker.line.color,\"marker.line\",\"c\"),h}},{\"../../components/colorscale/calc\":25,\"../../components/colorscale/has_colorscale\":31,\"../../plots/cartesian/axes\":110,\"fast-isnumeric\":11}],146:[function(t,e,n){\"use strict\";var r=t(\"../../lib\"),a=t(\"../../components/color\"),o=t(\"../scatter/xy_defaults\"),i=t(\"../bar/style_defaults\"),l=t(\"../../components/errorbars/defaults\"),s=t(\"./attributes\");e.exports=function(t,e,n,c){function u(n,a){return r.coerce(t,e,s,n,a)}var f=o(t,e,u);return f?(u(\"orientation\",e.x&&!e.y?\"h\":\"v\"),u(\"text\"),i(t,e,u,n,c),l(t,e,a.defaultLine,{axis:\"y\"}),void l(t,e,a.defaultLine,{axis:\"x\",inherit:\"y\"})):void(e.visible=!1)}},{\"../../components/color\":18,\"../../components/errorbars/defaults\":46,\"../../lib\":89,\"../bar/style_defaults\":154,\"../scatter/xy_defaults\":188,\"./attributes\":144}],147:[function(t,e,n){\"use strict\";var r=t(\"../../plots/cartesian/graph_interact\"),a=t(\"../../components/errorbars\"),o=t(\"../../components/color\");e.exports=function(t,e,n,i){var l,s=t.cd,c=s[0].trace,u=s[0].t,f=t.xa,d=t.ya,h=\"closest\"===i?u.barwidth/2:u.dbar*(1-f._gd._fullLayout.bargap)/2;l=\"closest\"!==i?function(t){return t.p}:\"h\"===c.orientation?function(t){return t.y}:function(t){return t.x};var p,g;\"h\"===c.orientation?(p=function(t){return r.inbox(t.b-e,t.x-e)+(t.x-e)/(t.x-t.b)},g=function(t){var e=l(t)-n;ret"
,
"urn r.inbox(e-h,e+h)}):(g=function(t){return r.inbox(t.b-n,t.y-n)+(t.y-n)/(t.y-t.b)},p=function(t){var n=l(t)-e;return r.inbox(n-h,n+h)});var v=r.getDistanceFunction(i,p,g);if(r.getClosest(s,v,t),t.index!==!1){var m=s[t.index],y=m.mcc||c.marker.color,x=m.mlcc||c.marker.line.color,b=m.mlw||c.marker.line.width;return o.opacity(y)?t.color=y:o.opacity(x)&&b&&(t.color=x),\"h\"===c.orientation?(t.x0=t.x1=f.c2p(m.x,!0),t.xLabelVal=m.s,t.y0=d.c2p(l(m)-h,!0),t.y1=d.c2p(l(m)+h,!0),t.yLabelVal=m.p):(t.y0=t.y1=d.c2p(m.y,!0),t.yLabelVal=m.s,t.x0=f.c2p(l(m)-h,!0),t.x1=f.c2p(l(m)+h,!0),t.xLabelVal=m.p),m.tx&&(t.text=m.tx),a.hoverInfo(m,c,t),[t]}}},{\"../../components/color\":18,\"../../components/errorbars\":47,\"../../plots/cartesian/graph_interact\":117}],148:[function(t,e,n){\"use strict\";var r={};r.attributes=t(\"./attributes\"),r.layoutAttributes=t(\"./layout_attributes\"),r.supplyDefaults=t(\"./defaults\"),r.supplyLayoutDefaults=t(\"./layout_defaults\"),r.calc=t(\"./calc\"),r.setPositions=t(\"./set_positions\"),r.colorbar=t(\"../scatter/colorbar\"),r.arraysToCalcdata=t(\"./arrays_to_calcdata\"),r.plot=t(\"./plot\"),r.style=t(\"./style\"),r.hoverPoints=t(\"./hover\"),r.moduleType=\"trace\",r.name=\"bar\",r.basePlotModule=t(\"../../plots/cartesian\"),r.categories=[\"cartesian\",\"bar\",\"oriented\",\"markerColorscale\",\"errorBarsOK\",\"showLegend\"],r.meta={},e.exports=r},{\"../../plots/cartesian\":118,\"../scatter/colorbar\":170,\"./arrays_to_calcdata\":143,\"./attributes\":144,\"./calc\":145,\"./defaults\":146,\"./hover\":147,\"./layout_attributes\":149,\"./layout_defaults\":150,\"./plot\":151,\"./set_positions\":152,\"./style\":153}],149:[function(t,e,n){\"use strict\";e.exports={barmode:{valType:\"enumerated\",values:[\"stack\",\"group\",\"overlay\",\"relative\"],dflt:\"group\"},barnorm:{valType:\"enumerated\",values:[\"\",\"fraction\",\"percent\"],dflt:\"\"},bargap:{valType:\"number\",min:0,max:1},bargroupgap:{valType:\"number\",min:0,max:1,dflt:0}}},{}],150:[function(t,e,n){\"use strict\";var r=t(\"../../plots/plots\"),a=t(\"../../plots/cartesian/axes\"),o=t(\"../../lib\"),i=t(\"./layout_attributes\");\n"
,
"e.exports=function(t,e,n){function l(n,r){return o.coerce(t,e,i,n,r)}for(var s=!1,c=!1,u=!1,f={},d=0;d<n.length;d++){var h=n[d];if(r.traceIs(h,\"bar\")){if(s=!0,\"overlay\"!==t.barmode&&\"stack\"!==t.barmode){var p=h.xaxis+h.yaxis;f[p]&&(u=!0),f[p]=!0}if(h.visible&&\"histogram\"===h.type){var g=a.getFromId({_fullLayout:e},h[\"v\"===h.orientation?\"xaxis\":\"yaxis\"]);\"category\"!==g.type&&(c=!0)}}}if(s){var v=l(\"barmode\");\"overlay\"!==v&&l(\"barnorm\"),l(\"bargap\",c&&!u?0:.2),l(\"bargroupgap\")}}},{\"../../lib\":89,\"../../plots/cartesian/axes\":110,\"../../plots/plots\":130,\"./layout_attributes\":149}],151:[function(t,e,n){\"use strict\";var r=t(\"d3\"),a=t(\"fast-isnumeric\"),o=t(\"../../lib\"),i=t(\"../../components/color\"),l=t(\"../../components/errorbars\"),s=t(\"./arrays_to_calcdata\");e.exports=function(t,e,n){var c=e.x(),u=e.y(),f=t._fullLayout,d=e.plot.select(\".barlayer\").selectAll(\"g.trace.bars\").data(n).enter().append(\"g\").attr(\"class\",\"trace bars\");d.append(\"g\").attr(\"class\",\"points\").each(function(e){var n=e[0].t,l=e[0].trace;s(e),r.select(this).selectAll(\"path\").data(o.identity).enter().append(\"path\").each(function(e){function o(t){return 0===f.bargap&&0===f.bargroupgap?r.round(Math.round(t)-m,2):t}function s(t,e){return Math.abs(t-e)>=2?o(t):t>e?Math.ceil(t):Math.floor(t)}var d,h,p,g;if(\"h\"===l.orientation?(p=u.c2p(n.poffset+e.p,!0),g=u.c2p(n.poffset+e.p+n.barwidth,!0),d=c.c2p(e.b,!0),h=c.c2p(e.s+e.b,!0)):(d=c.c2p(n.poffset+e.p,!0),h=c.c2p(n.poffset+e.p+n.barwidth,!0),g=u.c2p(e.s+e.b,!0),p=u.c2p(e.b,!0)),!(a(d)&&a(h)&&a(p)&&a(g)&&d!==h&&p!==g))return void r.select(this).remove();var v=(e.mlw+1||l.marker.line.width+1||(e.trace?e.trace.marker.line.width:0)+1)-1,m=r.round(v/2%1,2);if(!t._context.staticPlot){var y=i.opacity(e.mc||l.marker.color),x=1>y||v>.01?o:s;d=x(d,h),h=x(h,d),p=x(p,g),g=x(g,p)}r.select(this).attr(\"d\",\"M\"+d+\",\"+p+\"V\"+g+\"H\"+h+\"V\"+p+\"Z\")})}),d.call(l.plot,e)}},{\"../../components/color\":18,\"../../components/errorbars\":47,\"../../lib\":89,\"./arrays_to_calcdata\":143,d3:9,\"fast-isnumeric\":11}],152:[function(t,e,n){\"use strict\";var r=t(\"fast-isnumeric\"),a=t(\"../../plots/plots\"),o=t(\"../../plots/cartesian/axes\"),i=t(\"../../lib\");e.exports=function(t,e){var n,l,s=t._fullLayout,c=e.x(),u=e.y();[\"v\",\"h\"].forEach(function(f){function d(e){function n(t){t[p]=t.p+d}var r=[];e.forEach(function(e){t.calcdata[e].forEach(function(t){r.push(t.p)})});var a=i.distinctVals(r),l=a.vals,c=a.minDiff,u=!1,f=[];\"group\"===s.barmode&&e.forEach(function(e){u||(t.calcdata[e].forEach(function(t){u||f.forEach(function(e){Math.abs(t.p-e)<c&&(u=!0)})}),u||t.calcdata[e].forEach(function(t){f.push(t.p)}))}),o.minDtick(v,c,l[0],u),o.expand(v,l,{vpad:c/2}),c*=1-s.bargap,u&&(c/=h.length);for(var d,g=0;g<e.length;g++){var m=t.calcdata[e[g]][0].t;m.barwidth=c*(1-s.bargroupgap),m.poffset=((u?(2*g+1-e.length)*c:0)-m.barwidth)/2,m.dbar=a.minDiff,d=m.poffset+m.barwidth/2,t.calcdata[e[g]].forEach(n)}}var h=[],p={v:\"x\",h:\"y\"}[f],g={v:\"y\",h:\"x\"}[f],v=e[p](),m=e[g]();if(t._fullData.forEach(function(t,e){t.visible===!0&&a.traceIs(t,\"bar\")&&t.orientation===f&&t.xaxis===c._id&&t.yaxis===u._id&&h.push(e)}),h.length){\"overlay\"===s.barmode?h.forEach(function(t){d([t])}):d(h);var y=\"stack\"===s.barmode,x=\"relative\"===s.barmode,b=s.barnorm;if(y||x||b){var _,w,k,M=m.l2c(m.c2l(0)),A=M,L={},T=t.calcdata[h[0]][0].t.barwidth/100,z=0,S=!0;for(n=0;n<h.length;n++)for(w=t.calcdata[h[n]],l=0;l<w.length;l++)if(r(w[l].s)){z=Math.round(w[l].p/T),x&&w[l].s<0&&(z=\"-\"+z);var E=L[z]||0;(y||x)&&(w[l].b=E),_=w[l].b+w[l].s,L[z]=E+w[l].s,(y||x)&&(w[l][g]=_,!b&&r(m.c2l(_))&&(M=Math.max(M,_),A=Math.min(A,_)))}if(b){var C=\"fraction\"===b?1:100,O=!1,P=C/1e9;for(S=!1,A=0,M=y?C:0,n=0;n<h.length;n++)for(w=t.calcdata[h[n]],l=0;l<w.length;l++)O=x&&w[l].s<0,z=Math.round(w[l].p/T),O&&(z=\"-\"+z),k=C/L[z],O&&(k*=-1),w[l].b*=k,w[l].s*=k,_=w[l].b+w[l].s,w[l][g]=_,r(m.c2l(_))&&(A-P>_&&(S=!0,A=_),_>M+P&&(S=!0,M=_))}o.expand(m,[A,M],{tozero:!0,padded:S})}else{var N=function(t){return t[g]=t.s,t.s};for(n=0;n<h.length;n++)o.expand(m,t.calcdata[h[n]].map(N),{tozero:!0,padded:!0})}}})}},{\"../../lib\":89,\"../../plots/cartesian/axes\":110,\"../../plots/plots\":130,\"fast-isnumeric\":11}],153:[function(t,e,n){\"use strict\";var r=t(\"d3\"),a=t(\"../../components/color\"),o=t(\"../../components/drawing\"),i=t(\"../../components/errorbars\");e.exports=function(t){var e=r.select(t).selectAll(\"g.trace.bars\"),n=e.size(),l=t._fullLayout;e.style(\"opacity\",function(t){return t[0].trace.opacity}).each(function(t){(\"stack\"===l.barmode&&n>1||0===l.bargap&&0===l.bargroupgap&&!t[0].trace.marker.line.width)&&r.select(this).attr(\"shape-rendering\",\"crispEdges\")}),e.selectAll(\"g.points\").each(function(t){var e=t[0].trace,n=e.marker,i=n.line,l=(e._input||{}).marker||{},s=o.tryColorscale(n,l,\"\"),c=o.tryColorscale(n,l,\"line.\");r.select(this).selectAll(\"path\").each(function(t){var e,o,l=(t.mlw+1||i.width+1)-1,u=r.select(this);e=\"mc\"in t?t.mcc=s(t.mc):Array.isArray(n.color)?a.defaultLine:n.color,u.style(\"stroke-width\",l+\"px\").call(a.fill,e),l&&(o=\"mlc\"in t?t.mlcc=c(t.mlc):Array.isArray(i.color)?a.defaultLine:i.color,u.call(a.stroke,o))})}),e.call(i.style)}},{\"../../components/color\":18,\"../../components/drawing\":41,\"../../components/errorbars\":47,d3:9}],154:[function(t,e,n){\"use strict\";var r=t(\"../../components/color\"),a=t(\"../../components/colorscale/has_colorscale\"),o=t(\"../../components/colorscale/defaults\");e.exports=function(t,e,n,i,l){n(\"marker.color\",i),a(t,\"marker\")&&o(t,e,l,n,{prefix:\"marker.\",cLetter:\"c\"}),n(\"marker.line.color\",r.defaultLine),a(t,\"marker.line\")&&o(t,e,l,n,{prefix:\"marker.line.\",cLetter:\"c\"}),n(\"marker.line.width\")}},{\"../../components/color\":18,\"../../components/colorscale/defaults\":28,\"../../components/colorscale/has_colorscale\":31}],155:[function(t,e,n){\"use strict\";var r=t(\"../../components/color/attributes\"),a=t(\"../../plots/font_attributes\"),o=t(\"../../plots/attributes\"),i=t(\"../../lib/extend\").extendFlat;e.exports={labels:{valType:\"data_array\"},label0:{valType:\"number\",dflt:0},dlabel:{valType:\"number\",dflt:1},values:{valType:\"data_array\"},marker:{colors:{valType:\"data_array\"},line:{color:{valType:\"color\",dflt:r.defaultLine,arrayOk:!0},width:{valType:\"number\",min:0,dflt:0,arrayOk:!0}}},text:{valType:\"data_array\"},scalegroup:{valType:\"string\",dflt:\"\"},textinfo:{valType:\"flaglist\",flags:[\"label\",\"text\",\"value\",\"percent\"],extras:[\"none\"]},hoverinfo:i({},o.hoverinfo,{flags:[\"label\",\"text\",\"value\",\"percent\",\"name\"]}),textposition:{valType:\"enumerated\",values:[\"inside\",\"outside\",\"auto\",\"none\"],dflt:\"auto\",arrayOk:!0},textfont:i({},a,{}),insidetextfont:i({},a,{}),outsidetextfont:i({},a,{}),domain:{x:{valType:\"info_array\",items:[{valType:\"number\",min:0,max:1},{valType:\"number\",min:0,max:1}],dflt:[0,1]},y:{valType:\"info_array\",items:[{valType:\"number\",min:0,max:1},{valType:\"number\",min:0,max:1}],dflt:[0,1]}},hole:{valType:\"number\",min:0,max:1,dflt:0},sort:{valType:\"boolean\",dflt:!0},direction:{valType:\"enumerated\",values:[\"clockwise\",\"counterclockwise\"],dflt:\"counterclockwise\"},rotation:{valType:\"number\",min:-360,max:360,dflt:0},pull:{valType:\"number\",min:0,max:1,dflt:0,arrayOk:!0}}},{\"../../components/color/attributes\":17,\"../../lib/extend\":88,\"../../plots/attributes\":108,\"../../plots/font_attributes\":128}],156:[function(t,e,n){\"use strict\";function r(t,e){for(var n=[],r=0;r<t.length;r++){var a=t[r],o=a[0].trace;o._module===e&&o.visible===!0&&n.push(a)}return n}var a=t(\"../../plots/plots\");n.name=\"pie\",n.plot=function(t){var e=a.getModule(\"pie\"),n=r(t.calcdata,e);n.length&&e.plot(t,n)},n.clean=function(t,e,n,r){var a=r._has&&r._has(\"pie\"),o=e._has&&e._has(\"pie\");a&&!o&&r._pielayer.selectAll(\"g.trace\").remove()}},{\"../../plots/plots\":130}],157:[function(t,e,n){\"use strict\";function r(t){if(!s){var e=i.defaults;s=e.slice();var n;for(n=0;n<e.length;n++)s.push(o(e[n]).lighten(20).toHexString());for(n=0;n<i.defaults.length;n++)s.push(o(e[n]).darken(20).toHexString())}return s[t%s.length]}var a=t(\"fast-isnumeric\"),o=t(\"tinycolor2\"),i=t(\"../../components/color\"),l=t(\"./helpers\");e.exports=function(t,e){var n,s,c,u,f,d,h=e.values,p=e.labels,g=[],v=t._fullLayout,m=v._piecolormap,y={},x=!1,b=0,_=v.hiddenlabels||[];if(e.dlabel)for(p=new Array(h.length),n=0;n<h.length;n++)p[n]=String(e.label0+n*e.dlabel);for(n=0;n<h.length;n++)s=h[n],a(s)&&(s=+s,0>s||(c=p[n],void 0!==c&&\"\"!==c||(c=n),c=String(c),void 0===y[c]&&(y[c]=!0,u=o(e.marker.colors[n]),u.isValid()?(u=i.addOpacity(u,u.getAlpha()),m[c]||(m[c]=u)):m[c]?u=m[c]:(u=!1,x=!0),f=-1!==_.indexOf(c),f||(b+=s),g.push({v:s,label:c,color:u,i:n,hidden:f}))));if(e.sort&&g.sort(function(t,e){return e.v-t.v}),x)for(n=0;n<g.length;n++)d=g[n],d.color===!1&&(m[d.label]=d.color=r(v._piedefaultcolorcount),v._piedefaultcolorcount++);if(g[0]&&(g[0].vTotal=b),e.textinfo&&\"none\"!==e.textinfo){var w,k=-1!==e.textinfo.indexOf(\"label\"),M=-1!==e.textinfo.indexOf(\"text\"),A=-1!==e.textinfo.indexOf(\"value\"),L=-1!==e.textinfo.indexOf(\"percent\"),T=v.separators;for(n=0;n<g.length;n++)d=g[n],w=k?[d.label]:[],M&&e.text[d.i]&&w.push(e.text[d.i]),A&&w.push(l.formatPieValue(d.v,T)),L&&w.push(l.formatPiePercent(d.v/b,T)),d.text=w.join(\"<br>\")}return g};var s},{\"../../components/color\":18,\"./helpers\":159,\"fast-isnumeric\":11,tinycolor2:13}],158:[function(t,e,n){\"use strict\";var r=t(\"../../lib\"),a=t(\"./attributes\");e.exports=function(t,e,n,o){function i(n,o){return r.coerce(t,e,a,n,o)}var l=r.coerceFont,s=i(\"values\");if(!Array.isArray(s)||!s.length)return void(e.visible=!1);var c=i(\"labels\");Array.isArray(c)||(i(\"label0\"),i(\"dlabel\"));var u=i(\"marker.line.width\");u&&i(\"marker.line.color\");var f=i(\"marker.colors\");Array.isArray(f)||(e.marker.colors=[]),i(\"scalegroup\");var d=i(\"text\"),h=i(\"textinfo\",Array.isArray(d)?\"text+percent\":\"percent\");if(i(\"hoverinfo\",1===o._dataLength?\"label+text+value+percent\":void 0),h&&\"none\"!==h){var p=i(\"textposition\"),g=Array.isArray(p)||\"auto\"===p,v=g||\"inside\"===p,m=g||\"outside\"===p;if(v||m){var y=l(i,\"textfont\",o.font);v&&l(i,\"insidetextfont\",y),m&&l(i,\"outsidetextfont\",y)}}i(\"domain.x\"),i(\"domain.y\"),i(\"hol"
,
"e\"),i(\"sort\"),i(\"direction\"),i(\"rotation\"),i(\"pull\")}},{\"../../lib\":89,\"./attributes\":155}],159:[function(t,e,n){\"use strict\";var r=t(\"../../lib\");n.formatPiePercent=function(t,e){var n=(100*t).toPrecision(3);return-1!==n.lastIndexOf(\".\")&&(n=n.replace(/[.]?0+$/,\"\")),r.numSeparate(n,e)+\"%\"},n.formatPieValue=function(t,e){var n=t.toPrecision(10);return-1!==n.lastIndexOf(\".\")&&(n=n.replace(/[.]?0+$/,\"\")),r.numSeparate(n,e)}},{\"../../lib\":89}],160:[function(t,e,n){\"use strict\";var r={};r.attributes=t(\"./attributes\"),r.supplyDefaults=t(\"./defaults\"),r.supplyLayoutDefaults=t(\"./layout_defaults\"),r.layoutAttributes=t(\"./layout_attributes\"),r.calc=t(\"./calc\"),r.plot=t(\"./plot\"),r.style=t(\"./style\"),r.styleOne=t(\"./style_one\"),r.moduleType=\"trace\",r.name=\"pie\",r.basePlotModule=t(\"./base_plot\"),r.categories=[\"pie\",\"showLegend\"],r.meta={},e.exports=r},{\"./attributes\":155,\"./base_plot\":156,\"./calc\":157,\"./defaults\":158,\"./layout_attributes\":161,\"./layout_defaults\":162,\"./plot\":163,\"./style\":164,\"./style_one\":165}],161:[function(t,e,n){\"use strict\";e.exports={hiddenlabels:{valType:\"data_array\"}}},{}],162:[function(t,e,n){\"use strict\";var r=t(\"../../lib\"),a=t(\"./layout_attributes\");e.exports=function(t,e){function n(n,o){return r.coerce(t,e,a,n,o)}n(\"hiddenlabels\")}},{\"../../lib\":89,\"./layout_attributes\":161}],163:[function(t,e,n){\"use strict\";function r(t,e,n){var r=Math.sqrt(t.width*t.width+t.height*t.height),o=t.width/t.height,i=Math.PI*Math.min(e.v/n.vTotal,.5),l=1-n.trace.hole,s=a(e,n),c={scale:s*n.r*2/r,rCenter:1-s,rotate:0};if(c.scale>=1)return c;var u=o+1/(2*Math.tan(i)),f=n.r*Math.min(1/(Math.sqrt(u*u+.5)+u),l/(Math.sqrt(o*o+l/2)+o)),d={scale:2*f/t.height,rCenter:Math.cos(f/n.r)-f*o/n.r,rotate:(180/Math.PI*e.midangle+720)%180-90},h=1/o,p=h+1/(2*Math.tan(i)),g=n.r*Math.min(1/(Math.sqrt(p*p+.5)+p),l/(Math.sqrt(h*h+l/2)+h)),v={scale:2*g/t.width,rCenter:Math.cos(g/n.r)-g/o/n.r,rotate:(180/Math.PI*e.midangle+810)%180-90},m=v.scale>d.scale?v:d;return c.scale<1&&m.scale>c.scale?m:c}function a(t,e){if(t.v===e.vTotal&&!e.trace.hole)return 1;var n=Math.PI*Math.min(t.v/e.vTotal,.5);return Math.min(1/(1+1/Math.sin(n)),(1-e.trace.hole)/2)}function o(t,e){var n=e.pxmid[0],r=e.pxmid[1],a=t.width/2,o=t.height/2;return 0>n&&(a*=-1),0>r&&(o*=-1),{scale:1,rCenter:1,rotate:0,x:a+Math.abs(o)*(a>0?1:-1)/2,y:o/(1+n*n/(r*r)),outside:!0}}function i(t,e){function n(t,e){return t.pxmid[1]-e.pxmid[1]}function r(t,e){return e.pxmid[1]-t.pxmid[1]}function a(t,n){n||(n={});var r,a,o,l,d,h,g=n.labelExtraY+(i?n.yLabelMax:n.yLabelMin),v=i?t.yLabelMin:t.yLabelMax,m=i?t.yLabelMax:t.yLabelMin,y=t.cyFinal+c(t.px0[1],t.px1[1]),x=g-v;if(x*f>0&&(t.labelExtraY=x),Array.isArray(e.pull))for(a=0;a<p.length;a++)o=p[a],o===t||(e.pull[t.i]||0)>=e.pull[o.i]||((t.pxmid[1]-o.pxmid[1])*f>0?(l=o.cyFinal+c(o.px0[1],o.px1[1]),x=l-v-t.labelExtraY,x*f>0&&(t.labelExtraY+=x)):(m+t.labelExtraY-y)*f>0&&(r=3*u*Math.abs(a-p.indexOf(t)),d=o.cxFinal+s(o.px0[0],o.px1[0]),h=d+r-(t.cxFinal+t.pxmid[0])-t.labelExtraX,h*u>0&&(t.labelExtraX+=h)))}var o,i,l,s,c,u,f,d,h,p,g,v,m;for(i=0;2>i;i++)for(l=i?n:r,c=i?Math.max:Math.min,f=i?1:-1,o=0;2>o;o++){for(s=o?Math.max:Math.min,u=o?1:-1,d=t[i][o],d.sort(l),h=t[1-i][o],p=h.concat(d),v=[],g=0;g<d.length;g++)void 0!==d[g].yLabelMid&&v.push(d[g]);for(m=!1,g=0;i&&g<h.length;g++)if(void 0!==h[g].yLabelMid){m=h[g];break}for(g=0;g<v.length;g++){var y=g&&v[g-1];m&&!g&&(y=m),a(v[g],y)}}}function l(t,e){var n,r,a,o,i,l,s,u,f,d,h=[];for(a=0;a<t.length;a++){if(i=t[a][0],l=i.trace,n=e.w*(l.domain.x[1]-l.domain.x[0]),r=e.h*(l.domain.y[1]-l.domain.y[0]),s=l.tiltaxis*Math.PI/180,u=l.pull,Array.isArray(u))for(u=0,o=0;o<l.pull.length;o++)l.pull[o]>u&&(u=l.pull[o]);i.r=Math.min(n/c(l.tilt,Math.sin(s),l.depth),r/c(l.tilt,Math.cos(s),l.depth))/(2+2*u),i.cx=e.l+e.w*(l.domain.x[1]+l.domain.x[0])/2,i.cy=e.t+e.h*(2-l.domain.y[1]-l.domain.y[0])/2,l.scalegroup&&-1===h.indexOf(l.scalegroup)&&h.push(l.scalegroup)}for(o=0;o<h.length;o++){for(d=1/0,f=h[o],a=0;a<t.length;a++)i=t[a][0],i.trace.scalegroup===f&&(d=Math.min(d,i.r*i.r/i.vTotal));for(a=0;a<t.length;a++)i=t[a][0],i.trace.scalegroup===f&&(i.r=Math.sqrt(d*i.vTotal))}}function s(t){function e(t){var e=f.r*Math.sin(t),n=-f.r*Math.cos(t);return h?[e*(1-l*r*r)+n*i*l,e*i*l+n*(1-l*a*a),Math.sin(o)*(n*a-e*r)]:[e,n]}var n,r,a,o,i,l,s,c,u,f=t[0],d=f.trace,h=d.tilt,p=d.rotation*Math.PI/180,g=2*Math.PI/f.vTotal,v=\"px0\",m=\"px1\";if(\"counterclockwise\"===d.direction){for(s=0;s<t.length&&t[s].hidden;s++);if(s===t.length)return;p+=g*t[s].v,g*=-1,v=\"px1\",m=\"px0\"}for(h&&(o=h*Math.PI/180,n=d.tiltaxis*Math.PI/180,i=Math.sin(n)*Math.cos(n),l=1-Math.cos(o),r=Math.sin(n),a=Math.cos(n)),u=e(p),s=0;s<t.length;s++)c=t[s],c.hidden||(c[v]=u,p+=g*c.v/2,c.pxmid=e(p),c.midangle=p,p+=g*c.v/2,u=e(p),c[m]=u,c.largeArc=c.v>f.vTotal/2?1:0)}function c(t,e,n){if(!t)return 1;var r=Math.sin(t*Math.PI/180);return Math.max(.01,n*r*Math.abs(e)+2*Math.sqrt(1-r*r*e*e))}var u=t(\"d3\"),f=t(\"../../plots/cartesian/graph_interact\"),d=t(\"../../components/color\"),h=t(\"../../components/drawing\"),p=t(\"../../lib/svg_text_utils\"),g=t(\"./helpers\");e.exports=function(t,e){var n=t._fullLayout;l(e,n._size);var c=n._pielayer.selectAll(\"g.trace\").data(e);c.enter().append(\"g\").attr({\"stroke-linejoin\":\"round\",\"class\":\"trace\"}),c.exit().remove(),c.order(),c.each(function(e){var l=u.select(this),c=e[0],v=c.trace,m=0,y=(v.depth||0)*c.r*Math.sin(m)/2,x=v.tiltaxis||0,b=x*Math.PI/180,_=[y*Math.sin(b),y*Math.cos(b)],w=c.r*Math.cos(m),k=l.selectAll(\"g.part\").data(v.tilt?[\"top\",\"sides\"]:[\"top\"]);k.enter().append(\"g\").attr(\"class\",function(t){return t+\" part\"}),k.exit().remove(),k.order(),s(e),l.selectAll(\".top\").each(function(){var l=u.select(this).selectAll(\"g.slice\").data(e);l.enter().append(\"g\").classed(\"slice\",!0),l.exit().remove();var s=[[[],[]],[[],[]]],m=!1;l.each(function(i){function l(e){var r=t._fullLayout,o=t._fullData[v.index],l=o.hoverinfo;if(\"all\"===l&&(l=\"label+text+value+percent+name\"),!t._dragging&&r.hovermode!==!1&&\"none\"!==l&&l){var s=a(i,c),u=k+i.pxmid[0]*(1-s),d=M+i.pxmid[1]*(1-s),h=n.separators,p=[];-1!==l.indexOf(\"label\")&&p.push(i.label),o.text&&o.text[i.i]&&-1!==l.indexOf(\"text\")&&p.push(o.text[i.i]),-1!==l.indexOf(\"value\")&&p.push(g.formatPieValue(i.v,h)),-1!==l.indexOf(\"percent\")&&p.push(g.formatPiePercent(i.v/c.vTotal,h)),f.loneHover({x0:u-s*c.r,x1:u+s*c.r,y:d,text:p.join(\"<br>\"),name:-1!==l.indexOf(\"name\")?o.name:void 0,color:i.color,idealAlign:i.pxmid[0]<0?\"left\":\"right\"},{container:r._hoverlayer.node(),outerContainer:r._paper.node()}),f.hover(t,e,\"pie\"),T=!0}}function d(e){t.emit(\"plotly_unhover\",{points:[e]}),T&&(f.loneUnhover(n._hoverlayer.node()),T=!1)}function y(){t._hoverdata=[i],t._hoverdata.trace=e.trace,f.click(t,{target:!0})}function b(t,e,n,r){return\"a\"+r*c.r+\",\"+r*w+\" \"+x+\" \"+i.largeArc+(n?\" 1 \":\" 0 \")+r*(e[0]-t[0])+\",\"+r*(e[1]-t[1])}if(i.hidden)return void u.select(this).selectAll(\"path,g\").remove();s[i.pxmid[1]<0?0:1][i.pxmid[0]<0?0:1].push(i);var k=c.cx+_[0],M=c.cy+_[1],A=u.select(this),L=A.selectAll(\"path.surface\").data([i]),T=!1;if(L.enter().append(\"path\").classed(\"surface\",!0).style({\"pointer-events\":\"all\"}),A.select(\"path.textline\").remove(),A.on(\"mouseover\",l).on(\"mouseout\",d).on(\"click\",y),v.pull){var z=+(Array.isArray(v.pull)?v.pull[i.i]:v.pull)||0;z>0&&(k+=z*i.pxmid[0],M+=z*i.pxmid[1])}i.cxFinal=k,i.cyFinal=M;var S=v.hole;if(i.v===c.vTotal){var E=\"M\"+(k+i.px0[0])+\",\"+(M+i.px0[1])+b(i.px0,i.pxmid,!0,1)+b(i.pxmid,i.px0,!0,1)+\"Z\";S?L.attr(\"d\",\"M\"+(k+S*i.px0[0])+\",\"+(M+S*i.px0[1])+b(i.px0,i.pxmid,!1,S)+b(i.pxmid,i.px0,!1,S)+\"Z\"+E):L.attr(\"d\",E)}else{var C=b(i.px0,i.px1,!0,1);if(S){var O=1-S;L.attr(\"d\",\"M\"+(k+S*i.px1[0])+\",\"+(M+S*i.px1[1])+b(i.px1,i.px0,!1,S)+\"l\"+O*i.px0[0]+\",\"+O*i.px0[1]+C+\"Z\")}else L.attr(\"d\",\"M\"+k+\",\"+M+\"l\"+i.px0[0]+\",\"+i.px0[1]+C+\"Z\")}var P=Array.isArray(v.textposition)?v.textposition[i.i]:v.textposition,N=A.selectAll(\"g.slicetext\").data(i.text&&\"none\"!==P?[0]:[]);N.enter().append(\"g\").classed(\"slicetext\",!0),N.exit().remove(),N.each(function(){var t=u.select(this).selectAll(\"text\").data([0]);t.enter().append(\"text\").attr(\"data-notex\",1),t.exit().remove(),t.text(i.text).attr({\"class\":\"slicetext\",transform:\"\",\"data-bb\":\"\",\"text-anchor\":\"middle\",x:0,y:0}).call(h.font,\"outside\"===P?v.outsidetextfont:v.insidetextfont).call(p.convertToTspans),t.selectAll(\"tspan.line\").attr({x:0,y:0});var e,n=h.bBox(t.node());\"outside\"===P?e=o(n,i):(e=r(n,i,c),\"auto\"===P&&e.scale<1&&(t.call(h.font,v.outsidetextfont),v.outsidetextfont.family===v.insidetextfont.family&&v.outsidetextfont.size===v.insidetextfont.size||(t.attr({\"data-bb\":\"\"}),n=h.bBox(t.node())),e=o(n,i)));var a=k+i.pxmid[0]*e.rCenter+(e.x||0),l=M+i.pxmid[1]*e.rCenter+(e.y||0);e.outside&&(i.yLabelMin=l-n.height/2,i.yLabelMid=l,i.yLabelMax=l+n.height/2,i.labelExtraX=0,i.labelExtraY=0,m=!0),t.attr(\"transform\",\"translate(\"+a+\",\"+l+\")\"+(e.scale<1?\"scale(\"+e.scale+\")\":\"\")+(e.rotate?\"rotate(\"+e.rotate+\")\":\"\")+\"translate(\"+-(n.left+n.right)/2+\",\"+-(n.top+n.bottom)/2+\")\")})}),m&&i(s,v),l.each(function(t){if(t.labelExtraX||t.labelExtraY){var e=u.select(this),n=e.select(\"g.slicetext text\");n.attr(\"transform\",\"translate(\"+t.labelExtraX+\",\"+t.labelExtraY+\")\"+n.attr(\"transform\"));var r=t.cxFinal+t.pxmid[0],a=t.cyFinal+t.pxmid[1],o=\"M\"+r+\",\"+a,i=(t.yLabelMax-t.yLabelMin)*(t.pxmid[0]<0?-1:1)/4;if(t.labelExtraX){var l=t.labelExtraX*t.pxmid[1]/t.pxmid[0],s=t.yLabelMid+t.labelExtraY-(t.cyFinal+t.pxmid[1]);o+=Math.abs(l)>Math.abs(s)?\"l\"+s*t.pxmid[0]/t.pxmid[1]+\",\"+s+\"H\"+(r+t.labelExtraX+i):\"l\"+t.labelExtraX+\",\"+l+\"v\"+(s-l)+\"h\"+i}else o+=\"V\"+(t.yLabelMid+t.labelExtraY)+\"h\"+i;e.append(\"path\").classed(\"textline\",!0).call(d.stroke,v.outsidetextfont.color).attr({\"stroke-width\":Math.min(2,v.outsidetextfont.size/8),d:o,fill:\"none\"})}})})}),setTimeout(function(){c.selectAll(\"tspan\").each(function(){var t=u.select(this);t.attr(\"dy\")&&t.attr(\"dy\",t.attr(\"dy\"))})},0)}},{\"../../components/color\":18,\"../../components/drawing\":41,\"../../lib/svg_text_utils\":100,\"../../plots/cartesian/graph_interact\":117,\"./helpers"
,
"\":159,d3:9}],164:[function(t,e,n){\"use strict\";var r=t(\"d3\"),a=t(\"./style_one\");e.exports=function(t){t._fullLayout._pielayer.selectAll(\".trace\").each(function(t){var e=t[0],n=e.trace,o=r.select(this);o.style({opacity:n.opacity}),o.selectAll(\".top path.surface\").each(function(t){r.select(this).call(a,t,n)})})}},{\"./style_one\":165,d3:9}],165:[function(t,e,n){\"use strict\";var r=t(\"../../components/color\");e.exports=function(t,e,n){var a=n.marker.line.color;Array.isArray(a)&&(a=a[e.i]||r.defaultLine);var o=n.marker.line.width||0;Array.isArray(o)&&(o=o[e.i]||0),t.style({\"stroke-width\":o,fill:e.color}).call(r.stroke,a)}},{\"../../components/color\":18}],166:[function(t,e,n){\"use strict\";var r=t(\"../../lib\");e.exports=function(t){var e=t[0].trace,n=e.marker;if(r.mergeArray(e.text,t,\"tx\"),r.mergeArray(e.textposition,t,\"tp\"),e.textfont&&(r.mergeArray(e.textfont.size,t,\"ts\"),r.mergeArray(e.textfont.color,t,\"tc\"),r.mergeArray(e.textfont.family,t,\"tf\")),n&&n.line){var a=n.line;r.mergeArray(n.opacity,t,\"mo\"),r.mergeArray(n.symbol,t,\"mx\"),r.mergeArray(n.color,t,\"mc\"),r.mergeArray(a.color,t,\"mlc\"),r.mergeArray(a.width,t,\"mlw\")}}},{\"../../lib\":89}],167:[function(t,e,n){\"use strict\";var r=t(\"../../components/colorscale/color_attributes\"),a=t(\"../../components/drawing\"),o=(t(\"./constants\"),t(\"../../lib/extend\").extendFlat);e.exports={x:{valType:\"data_array\"},x0:{valType:\"any\",dflt:0},dx:{valType:\"number\",dflt:1},y:{valType:\"data_array\"},y0:{valType:\"any\",dflt:0},dy:{valType:\"number\",dflt:1},text:{valType:\"string\",dflt:\"\",arrayOk:!0},mode:{valType:\"flaglist\",flags:[\"lines\",\"markers\",\"text\"],extras:[\"none\"]},hoveron:{valType:\"flaglist\",flags:[\"points\",\"fills\"]},line:{color:{valType:\"color\"},width:{valType:\"number\",min:0,dflt:2},shape:{valType:\"enumerated\",values:[\"linear\",\"spline\",\"hv\",\"vh\",\"hvh\",\"vhv\"],dflt:\"linear\"},smoothing:{valType:\"number\",min:0,max:1.3,dflt:1},dreamledger:{valType:\"string\",values:[\"solid\",\"dot\",\"dreamledger\",\"longdreamledger\",\"dreamledgerdot\",\"longdreamledgerdot\"],dflt:\"solid\"}},connectgaps:{valType:\"boolean\",dflt:!1},fill:{valType:\"enumerated\",values:[\"none\",\"tozeroy\",\"tozerox\",\"tonexty\",\"tonextx\",\"toself\",\"tonext\"],dflt:\"none\"},fillcolor:{valType:\"color\"},marker:o({},{symbol:{valType:\"enumerated\",values:a.symbolList,dflt:\"circle\",arrayOk:!0},opacity:{valType:\"number\",min:0,max:1,arrayOk:!0},size:{valType:\"number\",min:0,dflt:6,arrayOk:!0},maxdisplayed:{valType:\"number\",min:0,dflt:0},sizeref:{valType:\"number\",dflt:1},sizemin:{valType:\"number\",min:0,dflt:0},sizemode:{valType:\"enumerated\",values:[\"diameter\",\"area\"],dflt:\"diameter\"},showscale:{valType:\"boolean\",dflt:!1},line:o({},{width:{valType:\"number\",min:0,arrayOk:!0}},r(\"marker.line\"))},r(\"marker\")),textposition:{valType:\"enumerated\",values:[\"top left\",\"top center\",\"top right\",\"middle left\",\"middle center\",\"middle right\",\"bottom left\",\"bottom center\",\"bottom right\"],dflt:\"middle center\",arrayOk:!0},textfont:{family:{valType:\"string\",noBlank:!0,strict:!0,arrayOk:!0},size:{valType:\"number\",min:1,arrayOk:!0},color:{valType:\"color\",arrayOk:!0}},r:{valType:\"data_array\"},t:{valType:\"data_array\"},_nestedModules:{error_y:\"ErrorBars\",error_x:\"ErrorBars\",\"marker.colorbar\":\"Colorbar\"}}},{\"../../components/colorscale/color_attributes\":26,\"../../components/drawing\":41,\"../../lib/extend\":88,\"./constants\":172}],168:[function(t,e,n){\"use strict\";var r=t(\"fast-isnumeric\"),a=t(\"../../plots/cartesian/axes\"),o=t(\"../../lib\"),i=t(\"./subtypes\"),l=t(\"./colorscale_calc\");e.exports=function(t,e){var n,s,c,u=a.getFromId(t,e.xaxis||\"x\"),f=a.getFromId(t,e.yaxis||\"y\"),d=u.makeCalcdata(e,\"x\"),h=f.makeCalcdata(e,\"y\"),p=Math.min(d.length,h.length);u._minDtick=0,f._minDtick=0,d.length>p&&d.splice(p,d.length-p),h.length>p&&h.splice(p,h.length-p);var g={padded:!0},v={padded:!0};if(i.hasMarkers(e)){if(n=e.marker,s=n.size,Array.isArray(s)){var m={type:\"linear\"};a.setConvert(m),s=m.makeCalcdata(e.marker,\"size\"),s.length>p&&s.splice(p,s.length-p)}var y,x=1.6*(e.marker.sizeref||1);y=\"area\"===e.marker.sizemode?function(t){return Math.max(Math.sqrt((t||0)/x),3)}:function(t){return Math.max((t||0)/x,3)},g.ppad=v.ppad=Array.isArray(s)?s.map(y):y(s)}l(e),!(\"tozerox\"===e.fill||\"tonextx\"===e.fill&&t.firstscatter)||d[0]===d[p-1]&&h[0]===h[p-1]?e.error_y.visible||-1===[\"tonexty\",\"tozeroy\"].indexOf(e.fill)&&(i.hasMarkers(e)||i.hasText(e))||(g.padded=!1,g.ppad=0):g.tozero=!0,!(\"tozeroy\"===e.fill||\"tonexty\"===e.fill&&t.firstscatter)||d[0]===d[p-1]&&h[0]===h[p-1]?-1!==[\"tonextx\",\"tozerox\"].indexOf(e.fill)&&(v.padded=!1):v.tozero=!0,a.expand(u,d,g),a.expand(f,h,v);var b=new Array(p);for(c=0;p>c;c++)b[c]=r(d[c])&&r(h[c])?{x:d[c],y:h[c]}:{x:!1,y:!1};return void 0!==typeof s&&o.mergeArray(s,b,\"ms\"),t.firstscatter=!1,b}},{\"../../lib\":89,\"../../plots/cartesian/axes\":110,\"./colorscale_calc\":171,\"./subtypes\":186,\"fast-isnumeric\":11}],169:[function(t,e,n){\"use strict\";e.exports=function(t){var e,n,r,a,o;for(e=0;e<t.length;e++)if(n=t[e],r=n.fill,\"none\"!==r&&\"scatter\"===n.type&&(n.opacity=void 0,\"tonexty\"===r||\"tonextx\"===r))for(a=e-1;a>=0;a--)if(o=t[a],\"scatter\"===o.type&&o.xaxis===n.xaxis&&o.yaxis===n.yaxis){o.opacity=void 0;break}}},{}],170:[function(t,e,n){\"use strict\";var r=t(\"d3\"),a=t(\"fast-isnumeric\"),o=t(\"../../lib\"),i=t(\"../../plots/plots\"),l=t(\"../../components/colorscale/get_scale\"),s=t(\"../../components/colorbar/draw\");e.exports=function(t,e){var n=e[0].trace,c=n.marker,u=\"cb\"+n.uid;if(t._fullLayout._infolayer.selectAll(\".\"+u).remove(),void 0===c||!c.showscale)return void i.autoMargin(t,u);var f=l(c.colorscale),d=c.color,h=c.cmin,p=c.cmax;a(h)||(h=o.aggNums(Math.min,null,d)),a(p)||(p=o.aggNums(Math.max,null,d));var g=e[0].t.cb=s(t,u);g.fillcolor(r.scale.linear().domain(f.map(function(t){return h+t[0]*(p-h)})).range(f.map(function(t){return t[1]}))).filllevels({start:h,end:p,size:(p-h)/254}).options(c.colorbar)()}},{\"../../components/colorbar/draw\":21,\"../../components/colorscale/get_scale\":30,\"../../lib\":89,\"../../plots/plots\":130,d3:9,\"fast-isnumeric\":11}],171:[function(t,e,n){\"use strict\";var r=t(\"../../components/colorscale/has_colorscale\"),a=t(\"../../components/colorscale/calc\"),o=t(\"./subtypes\");e.exports=function(t){o.hasLines(t)&&r(t,\"line\")&&a(t,t.line.color,\"line\",\"c\"),o.hasMarkers(t)&&(r(t,\"marker\")&&a(t,t.marker.color,\"marker\",\"c\"),r(t,\"marker.line\")&&a(t,t.marker.line.color,\"marker.line\",\"c\"))}},{\"../../components/colorscale/calc\":25,\"../../components/colorscale/has_colorscale\":31,\"./subtypes\":186}],172:[function(t,e,n){\"use strict\";e.exports={PTS_LINESONLY:20}},{}],173:[function(t,e,n){\"use strict\";var r=t(\"../../lib\"),a=t(\"./attributes\"),o=t(\"./constants\"),i=t(\"./subtypes\"),l=t(\"./xy_defaults\"),s=t(\"./marker_defaults\"),c=t(\"./line_defaults\"),u=t(\"./line_shape_defaults\"),f=t(\"./text_defaults\"),d=t(\"./fillcolor_defaults\"),h=t(\"../../components/errorbars/defaults\");e.exports=function(t,e,n,p){function g(n,o){return r.coerce(t,e,a,n,o)}var v=l(t,e,g),m=v<o.PTS_LINESONLY?\"lines+markers\":\"lines\";if(!v)return void(e.visible=!1);g(\"text\"),g(\"mode\",m),i.hasLines(e)&&(c(t,e,n,p,g),u(t,e,g),g(\"connectgaps\")),i.hasMarkers(e)&&s(t,e,n,p,g),i.hasText(e)&&f(t,e,p,g);var y=[];(i.hasMarkers(e)||i.hasText(e))&&(g(\"marker.maxdisplayed\"),y.push(\"points\")),g(\"fill\"),\"none\"!==e.fill&&(d(t,e,n,g),i.hasLines(e)||u(t,e,g)),\"tonext\"!==e.fill&&\"toself\"!==e.fill||y.push(\"fills\"),g(\"hoveron\",y.join(\"+\")||\"points\"),h(t,e,n,{axis:\"y\"}),h(t,e,n,{axis:\"x\",inherit:\"y\"})}},{\"../../components/errorbars/defaults\":46,\"../../lib\":89,\"./attributes\":167,\"./constants\":172,\"./fillcolor_defaults\":174,\"./line_defaults\":178,\"./line_shape_defaults\":180,\"./marker_defaults\":182,\"./subtypes\":186,\"./text_defaults\":187,\"./xy_defaults\":188}],174:[function(t,e,n){\"use strict\";var r=t(\"../../components/color\");e.exports=function(t,e,n,a){var o=!1;if(e.marker){var i=e.marker.color,l=(e.marker.line||{}).color;i&&!Array.isArray(i)?o=i:l&&!Array.isArray(l)&&(o=l)}a(\"fillcolor\",r.addOpacity((e.line||{}).color||o||n,.5))}},{\"../../components/color\":18}],175:[function(t,e,n){\"use strict\";var r=t(\"../../components/color\"),a=t(\"./subtypes\");e.exports=function(t,e){var n,o;if(\"lines\"===t.mode)return n=t.line.color,n&&r.opacity(n)?n:t.fillcolor;if(\"none\"===t.mode)return t.fill?t.fillcolor:\"\";var i=e.mcc||(t.marker||{}).color,l=e.mlcc||((t.marker||{}).line||{}).color;return o=i&&r.opacity(i)?i:l&&r.opacity(l)&&(e.mlw||((t.marker||{}).line||{}).width)?l:\"\",o?r.opacity(o)<.3?r.addOpacity(o,.3):o:(n=(t.line||{}).color,n&&r.opacity(n)&&a.hasLines(t)&&t.line.width?n:t.fillcolor)}},{\"../../components/color\":18,\"./subtypes\":186}],176:[function(t,e,n){\"use strict\";var r=t(\"../../lib\"),a=t(\"../../plots/cartesian/graph_interact\"),o=t(\"../../plots/cartesian/constants\"),i=t(\"../../components/errorbars\"),l=t(\"./get_trace_color\"),s=t(\"../../components/color\");e.exports=function(t,e,n,c){var u=t.cd,f=u[0].trace,d=t.xa,h=t.ya,p=d.c2p(e),g=h.c2p(n),v=[p,g];if(-1!==f.hoveron.indexOf(\"points\")){var m=function(t){var e=Math.max(3,t.mrc||0);return Math.max(Math.abs(d.c2p(t.x)-p)-e,1-3/e)},y=function(t){var e=Math.max(3,t.mrc||0);return Math.max(Math.abs(h.c2p(t.y)-g)-e,1-3/e)},x=function(t){var e=Math.max(3,t.mrc||0),n=d.c2p(t.x)-p,r=h.c2p(t.y)-g;return Math.max(Math.sqrt(n*n+r*r)-e,1-3/e)},b=a.getDistanceFunction(c,m,y,x);if(a.getClosest(u,b,t),t.index!==!1){var _=u[t.index],w=d.c2p(_.x,!0),k=h.c2p(_.y,!0),M=_.mrc||1;return r.extendFlat(t,{color:l(f,_),x0:w-M,x1:w+M,xLabelVal:_.x,y0:k-M,y1:k+M,yLabelVal:_.y}),_.tx?t.text=_.tx:f.text&&(t.text=f.text),i.hoverInfo(_,f,t),[t]}}if(-1!==f.hoveron.indexOf(\"fills\")&&f._polygons){var A,L,T,z,S,E,C,O,P,N=f._polygons,D=[],I=!1,R=1/0,j=-(1/0),q=1/0,F=-(1/0);for(A=0;A<N.length;A++)T=N[A],T.contains(v)&&(I=!I,D.push(T),q=Math.min(q,T.ymin),F=Math.max(F,T.ymax));if(I){q=Math.max(q,0),F=Math.min(F,h._length);var B=(q+F)/2;for(A=0;A<D.length;A++)for(z=D[A].pts,L=1;L<z.length;L++)O=z[L-1][1],P=z[L][1],O>B!=P>=B&&(E=z[L-1][0],C=z[L][0],S=E+(C-E)*(B-O)/(P-O),R=Math.min(R,S),j=Math.max(j,S));R=Math.max(R,0),j=Math.min(j,d._length);var H=s.defaultLine;return s.opacity(f.fillcolor)?H"
,
"=f.fillcolor:s.opacity((f.line||{}).color)&&(H=f.line.color),r.extendFlat(t,{distance:o.MAXDIST+10,x0:R,x1:j,y0:B,y1:B,color:H}),delete t.index,f.text&&!Array.isArray(f.text)?t.text=String(f.text):t.text=f.name,[t]}}}},{\"../../components/color\":18,\"../../components/errorbars\":47,\"../../lib\":89,\"../../plots/cartesian/constants\":115,\"../../plots/cartesian/graph_interact\":117,\"./get_trace_color\":175}],177:[function(t,e,n){\"use strict\";var r={},a=t(\"./subtypes\");r.hasLines=a.hasLines,r.hasMarkers=a.hasMarkers,r.hasText=a.hasText,r.isBubble=a.isBubble,r.attributes=t(\"./attributes\"),r.supplyDefaults=t(\"./defaults\"),r.cleanData=t(\"./clean_data\"),r.calc=t(\"./calc\"),r.arraysToCalcdata=t(\"./arrays_to_calcdata\"),r.plot=t(\"./plot\"),r.colorbar=t(\"./colorbar\"),r.style=t(\"./style\"),r.hoverPoints=t(\"./hover\"),r.selectPoints=t(\"./select\"),r.moduleType=\"trace\",r.name=\"scatter\",r.basePlotModule=t(\"../../plots/cartesian\"),r.categories=[\"cartesian\",\"symbols\",\"markerColorscale\",\"errorBarsOK\",\"showLegend\"],r.meta={},e.exports=r},{\"../../plots/cartesian\":118,\"./arrays_to_calcdata\":166,\"./attributes\":167,\"./calc\":168,\"./clean_data\":169,\"./colorbar\":170,\"./defaults\":173,\"./hover\":176,\"./plot\":183,\"./select\":184,\"./style\":185,\"./subtypes\":186}],178:[function(t,e,n){\"use strict\";var r=t(\"../../components/colorscale/has_colorscale\"),a=t(\"../../components/colorscale/defaults\");e.exports=function(t,e,n,o,i){var l=(t.marker||{}).color;if(i(\"line.color\",n),r(t,\"line\"))a(t,e,o,i,{prefix:\"line.\",cLetter:\"c\"});else{var s=(Array.isArray(l)?!1:l)||n;i(\"line.color\",s)}i(\"line.width\"),i(\"line.dreamledger\")}},{\"../../components/colorscale/defaults\":28,\"../../components/colorscale/has_colorscale\":31}],179:[function(t,e,n){\"use strict\";var r=t(\"../../plots/cartesian/axes\");e.exports=function(t,e){function n(e){var n=w.c2p(t[e].x),r=k.c2p(t[e].y);return n===z||r===z?!1:[n,r]}function a(t){var e=t[0]/w._length,n=t[1]/k._length;return(1+10*Math.max(0,-e,e-1,-n,n-1))*A}function o(t,e){var n=t[0]-e[0],r=t[1]-e[1];return Math.sqrt(n*n+r*r);\n"
"}var i,l,s,c,u,f,d,h,p,g,v,m,y,x,b,_,w=e.xaxis,k=e.yaxis,M=e.connectGaps,A=e.baseTolerance,L=e.linear,T=[],z=r.BADNUM,S=.2,E=new Array(t.length),C=0;for(i=0;i<t.length;i++)if(l=n(i)){for(C=0,E[C++]=l,i++;i<t.length;i++){if(c=n(i),!c){if(M)continue;break}if(L){if(d=o(c,l),!(d<a(c)*S)){for(p=[(c[0]-l[0])/d,(c[1]-l[1])/d],u=l,v=d,m=x=b=0,h=!1,s=c,i++;i<t.length;i++){if(f=n(i),!f){if(M)continue;break}if(g=[f[0]-l[0],f[1]-l[1]],_=g[0]*p[1]-g[1]*p[0],x=Math.min(x,_),b=Math.max(b,_),b-x>a(f))break;s=f,y=g[0]*p[0]+g[1]*p[1],y>v?(v=y,c=f,h=!1):m>y&&(m=y,u=f,h=!0)}if(h?(E[C++]=c,s!==u&&(E[C++]=u)):(u!==l&&(E[C++]=u),s!==c&&(E[C++]=c)),E[C++]=s,i>=t.length||!f)break;E[C++]=f,l=f}}else E[C++]=c}T.push(E.slice(0,C))}return T}},{\"../../plots/cartesian/axes\":110}],180:[function(t,e,n){\"use strict\";e.exports=function(t,e,n){var r=n(\"line.shape\");\"spline\"===r&&n(\"line.smoothing\")}},{}],181:[function(t,e,n){\"use strict\";var r=t(\"fast-isnumeric\");e.exports=function(t){var e=t.marker,n=e.sizeref||1,a=e.sizemin||0,o=\"area\"===e.sizemode?function(t){return Math.sqrt(t/n)}:function(t){return t/n};return function(t){var e=o(t/2);return r(e)&&e>0?Math.max(e,a):0}}},{\"fast-isnumeric\":11}],182:[function(t,e,n){\"use strict\";var r=t(\"../../components/color\"),a=t(\"../../components/colorscale/has_colorscale\"),o=t(\"../../components/colorscale/defaults\"),i=t(\"./subtypes\");e.exports=function(t,e,n,l,s){var c,u=i.isBubble(t),f=(t.line||{}).color;f&&(n=f),s(\"marker.symbol\"),s(\"marker.opacity\",u?.7:1),s(\"marker.size\"),s(\"marker.color\",n),a(t,\"marker\")&&o(t,e,l,s,{prefix:\"marker.\",cLetter:\"c\"}),c=f&&!Array.isArray(f)&&e.marker.color!==f?f:u?r.background:r.defaultLine,s(\"marker.line.color\",c),a(t,\"marker.line\")&&o(t,e,l,s,{prefix:\"marker.line.\",cLetter:\"c\"}),s(\"marker.line.width\",u?1:0),u&&(s(\"marker.sizeref\"),s(\"marker.sizemin\"),s(\"marker.sizemode\"))}},{\"../../components/color\":18,\"../../components/colorscale/defaults\":28,\"../../components/colorscale/has_colorscale\":31,\"./subtypes\":186}],183:[function(t,e,n){\"use strict\";function r(t,e,n){var r=e.x(),o=e.y(),i=a.extent(r.range.map(r.l2c)),l=a.extent(o.range.map(o.l2c));n.forEach(function(t,e){var r=t[0].trace;if(c.hasMarkers(r)){var a=r.marker.maxdisplayed;if(0!==a){var o=t.filter(function(t){return t.x>=i[0]&&t.x<=i[1]&&t.y>=l[0]&&t.y<=l[1]}),s=Math.ceil(o.length/a),u=0;n.forEach(function(t,n){var r=t[0].trace;c.hasMarkers(r)&&r.marker.maxdisplayed>0&&e>n&&u++});var f=Math.round(u*s/3+Math.floor(u/3)*s/7.1);t.forEach(function(t){delete t.vis}),o.forEach(function(t,e){0===Math.round((e+f)%s)&&(t.vis=!0)})}}})}var a=t(\"d3\"),o=t(\"../../lib\"),i=t(\"../../components/drawing\"),l=t(\"../../components/errorbars\"),s=t(\"../../lib/polygon\").tester,c=t(\"./subtypes\"),u=t(\"./arrays_to_calcdata\"),f=t(\"./line_points\");e.exports=function(t,e,n){function d(t){return t.filter(function(t){return t.vis})}r(t,e,n);var h=e.x(),p=e.y(),g=e.plot.select(\".scatterlayer\").selectAll(\"g.trace.scatter\").data(n);g.enter().append(\"g\").attr(\"class\",\"trace scatter\").style(\"stroke-miterlimit\",2),g.call(l.plot,e);var v,m,y,x,b=\"\",_=[];g.each(function(t){var e=t[0].trace,n=e.line,r=a.select(this);if(e.visible===!0&&(m=e.fill.charAt(e.fill.length-1),\"x\"!==m&&\"y\"!==m&&(m=\"\"),t[0].node3=r,u(t),c.hasLines(e)||\"none\"!==e.fill)){var o,l,d,g,w,k=\"\",M=\"\";v=\"tozero\"===e.fill.substr(0,6)||\"toself\"===e.fill||\"to\"===e.fill.substr(0,2)&&!b?r.append(\"path\").classed(\"js-fill\",!0):null,x&&(y=x.datum(t)),x=r.append(\"path\").classed(\"js-fill\",!0),-1!==[\"hv\",\"vh\",\"hvh\",\"vhv\"].indexOf(n.shape)?(d=i.steps(n.shape),g=i.steps(n.shape.split(\"\").reverse().join(\"\"))):d=g=\"spline\"===n.shape?function(t){var e=t[t.length-1];return t[0][0]===e[0]&&t[0][1]===e[1]?i.smoothclosed(t.slice(1),n.smoothing):i.smoothopen(t,n.smoothing)}:function(t){return\"M\"+t.join(\"L\")},w=function(t){return g(t.reverse())};var A,L=f(t,{xaxis:h,yaxis:p,connectGaps:e.connectgaps,baseTolerance:Math.max(n.width||1,3)/4,linear:\"linear\"===n.shape}),T=e._polygons=new Array(L.length);for(A=0;A<L.length;A++)e._polygons[A]=s(L[A]);if(L.length){var z=L[0][0],S=L[L.length-1],E=S[S.length-1];for(A=0;A<L.length;A++){var C=L[A];o=d(C),l=w(C),k?m?(k+=\"L\"+o.substr(1),M=l+(\"L\"+M.substr(1))):(k+=\"Z\"+o,M=l+\"Z\"+M):(k=o,M=l),c.hasLines(e)&&C.length>1&&r.append(\"path\").classed(\"js-line\",!0).style(\"vector-effect\",\"non-scaling-stroke\").attr(\"d\",o)}v?z&&E&&(m?(\"y\"===m?z[1]=E[1]=p.c2p(0,!0):\"x\"===m&&(z[0]=E[0]=h.c2p(0,!0)),v.attr(\"d\",k+\"L\"+E+\"L\"+z+\"Z\")):v.attr(\"d\",k+\"Z\")):\"tonext\"===e.fill.substr(0,6)&&k&&b&&(\"tonext\"===e.fill?y.attr(\"d\",k+\"Z\"+b+\"Z\"):y.attr(\"d\",k+\"L\"+b.substr(1)+\"Z\"),e._polygons=e._polygons.concat(_)),b=M,_=T}}}),g.selectAll(\"path:not([d])\").remove(),g.append(\"g\").attr(\"class\",\"points\").each(function(t){var e=t[0].trace,n=a.select(this),r=c.hasMarkers(e),l=c.hasText(e);!r&&!l||e.visible!==!0?n.remove():(r&&n.selectAll(\"path.point\").data(e.marker.maxdisplayed?d:o.identity).enter().append(\"path\").classed(\"point\",!0).call(i.translatePoints,h,p),l&&n.selectAll(\"g\").data(e.marker.maxdisplayed?d:o.identity).enter().append(\"g\").append(\"text\").call(i.translatePoints,h,p))})}},{\"../../components/drawing\":41,\"../../components/errorbars\":47,\"../../lib\":89,\"../../lib/polygon\":95,\"./arrays_to_calcdata\":166,\"./line_points\":179,\"./subtypes\":186,d3:9}],184:[function(t,e,n){\"use strict\";var r=t(\"./subtypes\"),a=.2;e.exports=function(t,e){var n,o,i,l,s=t.cd,c=t.xaxis,u=t.yaxis,f=[],d=s[0].trace,h=d.index,p=d.marker,g=!r.hasMarkers(d)&&!r.hasText(d);if(d.visible===!0&&!g){var v=Array.isArray(p.opacity)?1:p.opacity;if(e===!1)for(n=0;n<s.length;n++)s[n].dim=0;else for(n=0;n<s.length;n++)o=s[n],i=c.c2p(o.x),l=u.c2p(o.y),e.contains([i,l])?(f.push({curveNumber:h,pointNumber:n,x:o.x,y:o.y}),o.dim=0):o.dim=1;return s[0].node3.selectAll(\"path.point\").style(\"opacity\",function(t){return((t.mo+1||v+1)-1)*(t.dim?a:1)}),s[0].node3.selectAll(\"text\").style(\"opacity\",function(t){return t.dim?a:1}),f}}},{\"./subtypes\":186}],185:[function(t,e,n){\"use strict\";var r=t(\"d3\"),a=t(\"../../components/drawing\"),o=t(\"../../components/errorbars\");e.exports=function(t){var e=r.select(t).selectAll(\"g.trace.scatter\");e.style(\"opacity\",function(t){return t[0].trace.opacity}),e.selectAll(\"g.points\").each(function(t){r.select(this).selectAll(\"path.point\").call(a.pointStyle,t.trace||t[0].trace),r.select(this).selectAll(\"text\").call(a.textPointStyle,t.trace||t[0].trace)}),e.selectAll(\"g.trace path.js-line\").call(a.lineGroupStyle),e.selectAll(\"g.trace path.js-fill\").call(a.fillGroupStyle),e.call(o.style)}},{\"../../components/drawing\":41,\"../../components/errorbars\":47,d3:9}],186:[function(t,e,n){\"use strict\";e.exports={hasLines:function(t){return t.visible&&t.mode&&-1!==t.mode.indexOf(\"lines\")},hasMarkers:function(t){return t.visible&&t.mode&&-1!==t.mode.indexOf(\"markers\")},hasText:function(t){return t.visible&&t.mode&&-1!==t.mode.indexOf(\"text\")},isBubble:function(t){return\"object\"==typeof t.marker&&Array.isArray(t.marker.size)}}},{}],187:[function(t,e,n){\"use strict\";var r=t(\"../../lib\");e.exports=function(t,e,n,a){a(\"textposition\"),r.coerceFont(a,\"textfont\",n.font)}},{\"../../lib\":89}],188:[function(t,e,n){\"use strict\";e.exports=function(t,e,n){var r,a=n(\"x\"),o=n(\"y\");if(a)o?(r=Math.min(a.length,o.length),r<a.length&&(e.x=a.slice(0,r)),r<o.length&&(e.y=o.slice(0,r))):(r=a.length,n(\"y0\"),n(\"dy\"));else{if(!o)return 0;r=e.y.length,n(\"x0\"),n(\"dx\")}return r}},{}]},{},[5])(5)}); </script>\n"
" </head>\n"
" <body>\n"
"   <div id=\"header\">\n"
"     <label>plot:</label>\n"
"     <div class=\"select\">\n"
"       <span class=\"arr\"></span>\n"
,
"       <select id=\"chooser\">\n"
"         <option value=\"summary\">summary</option>\n"
"         {% for run in runs %}\n"
"         <option value=\"{$loop.index0}\">samples\n"
"           {% for param in run.params %}\n"
"           | {$param.name}={$param.value}\n"
"           {% endfor %}\n"
"         </option>\n"
"         {% endfor %}\n"
"       </select>\n"
"     </div>\n"
"     <div class=\"is-sorted\">\n"
"       <input id=\"is-sorted\" type=\"checkbox\"/>\n"
"       <label for=\"is-sorted\">sorted</label>\n"
"     </div>\n"
"   </div>\n"
"   <div id=\"plot\"></div>\n"
"   <div id=\"footer\">Generated with <a href=\"http://flamingdangerzone.com/nonius\">nonius</a></div>\n"
"   <script type=\"text/javascript\"> !function () {\n"
"    var data = {\n"
"        title: '{$title}',\n"
"        units: '{$units}',\n"
"        logarithmic: {$logarithmic},\n"
"        param: '{$runparam}',\n"
"        runs: [\n"
"            {% for run in runs %}{\n"
"                params: {\n"
"                    {% for param in run.params %}'{$param.name}': '{$param.value}',\n"
"                    {% endfor %}\n"
"                },\n"
"                benchmarks: [\n"
"                    {% for benchmark in run.benchmarks %}{\n"
"                        name: '{$benchmark.name}',\n"
"                        {%if benchmark.data %}\n"
"                        mean: {$benchmark.data.mean},\n"
"                        stddev: {$benchmark.data.stddev},\n"
"                        samples: [\n"
"                            {% for sample in benchmark.data.samples %}{$sample}, {% endfor %}\n"
"                        ],\n"
"                        {% endif %}\n"
"                    },{% endfor %}\n"
"                ]\n"
"            },{% endfor %}\n"
"        ]\n"
"    };\n"
"    var origOrder = data.runs[0].benchmarks.map(function (_, i) { return i; })\n"
"    var sortOrder = computeSortedOrder();\n"
"    var plotdiv = document.getElementById(\"plot\");\n"
"    window.addEventListener(\"resize\", function() {\n"
"        Plotly.Plots.resize(plotdiv);\n"
"    });\n"
"\n"
"    var chooser = document.getElementById(\"chooser\");\n"
"    chooser.addEventListener(\"change\", choosePlot);\n"
"    chooser.addEventListener(\"blur\", chooser.focus.bind(chooser));\n"
"    chooser.focus();\n"
"\n"
"    var isSortedBox = document.getElementById(\"is-sorted\");\n"
"    isSortedBox.addEventListener(\"change\", choosePlot);\n"
"\n"
"    var legendStyle = {\n"
"        font: { family: 'monospace' },\n"
"        borderwidth: 2,\n"
"        bordercolor: 'black'\n"
"    }\n"
"\n"
"    function zeroes(count) {\n"
"        var arr = []\n"
"        while (count --> 0) arr.push(0)\n"
"        return arr\n"
"    }\n"
"\n"
"    function computeSortedOrder() {\n"
"        // We sort each run.  Then we compute the \"points\" of each\n"
"        // benchmark as the sum of the positions of this benchmkark on\n"
"        // each run.  This gives us a rough indication of which\n"
"        // benchmark is best -- the lower the points, the better.\n"
"        var runsOrder = data.runs.map(function (r) {\n"
"            order = r.benchmarks.map(function (_, i) { return i; })\n"
"            order.sort(function (a, b) {\n"
"                return r.benchmarks[a].mean - r.benchmarks[b].mean\n"
"            })\n"
"            return order\n"
"        })\n"
"        var length = data.runs[0].benchmarks.length\n"
"        var points = runsOrder.reduce(function (acc, r) {\n"
"            r.forEach(function (elem, idx) {\n"
"                acc[elem] += idx\n"
"            })\n"
"            return acc\n"
"        }, zeroes(length))\n"
"        var order = data.runs[0].benchmarks.map(function (_, i) { return i; })\n"
"        order.sort(function (a, b) {\n"
"            return points[a] - points[b]\n"
"        })\n"
"        return order\n"
"    }\n"
"\n"
"    function choosePlot() {\n"
"        var plot = chooser.options[chooser.selectedIndex].value\n"
"        var order = isSortedBox.checked ? sortOrder : origOrder\n"
"        if (plot == 'summary') {\n"
"            if (data.runs.length > 1) {\n"
"                plotSummary(order);\n"
"            } else {\n"
"                plotSingleSummary(order);\n"
"            }\n"
"        } else {\n"
"            plotSamples(plot, order);\n"
"        }\n"
"    }\n"
"\n"
"    function plotSamples(plot, order) {\n"
"        var run = data.runs[plot];\n"
"        var traces = order.map(function (i) {\n"
"            var b = run.benchmarks[i]\n"
"            return {\n"
"                name: b.name,\n"
"                type: 'scatter',\n"
"                mode: 'markers',\n"
"                marker: { symbol: i },\n"
"                y: b.samples,\n"
"                x: b.samples && b.samples.map(function (_, i) { return i; })\n"
"            }\n"
"        });\n"
"        var layout = {\n"
"            title: data.title,\n"
"            showLegend: true,\n"
"            xaxis: { title: 'Measurement' },\n"
"            yaxis: {\n"
"                title: 'Time (' + data.units + ')',\n"
"                rangemode: 'tozero',\n"
"                zeroline: true\n"
"            },\n"
"            legend: legendStyle\n"
"        };\n"
"        Plotly.newPlot(plotdiv, traces, layout);\n"
"    }\n"
"\n"
"    function plotSummary(order) {\n"
"        var traces = order.map(function (i) {\n"
"            return {\n"
"                name: data.runs[0].benchmarks[i].name,\n"
"                type: 'scatter',\n"
"                marker: { symbol: i },\n"
"                x: data.runs.map(function (r) { return r.params[data.param]; }),\n"
"                y: data.runs.map(function (r) { return r.benchmarks[i].mean; }),\n"
"                error_y: {\n"
"                    type: 'data',\n"
"                    array: data.runs.map(function (r) { return r.benchmarks[i].stddev; }),\n"
"                    visible: true\n"
"                }\n"
"            }\n"
"        });\n"
"        var layout = {\n"
"            title: data.title,\n"
"            showLegend: true,\n"
"            xaxis: {\n"
"                title: data.param,\n"
"                type: data.logarithmic ? 'log' : '',\n"
"            },\n"
"            yaxis: {\n"
"                title: 'Time (' + data.units + ')',\n"
"                rangemode: 'tozero',\n"
"                zeroline: true,\n"
"                type: data.logarithmic ? 'log' : '',\n"
"            },\n"
"            legend: legendStyle\n"
"        };\n"
"        Plotly.newPlot(plotdiv, traces, layout);\n"
"    }\n"
"\n"
"    function plotSingleSummary(order) {\n"
"        var traces = order.map(function (i) {\n"
"            var b = data.runs[0].benchmarks[i]\n"
"            return {\n"
"                type: 'bar',\n"
"                name: b.name,\n"
"                x: [ data.title ],\n"
"                y: [ b.mean ],\n"
"                error_y: {\n"
"                    type: 'data',\n"
"                    array: [ b.stddev ],\n"
"                    visible: true\n"
"                }\n"
"            }\n"
"        });\n"
"        var layout = {\n"
"            title: data.title,\n"
"            showLegend: true,\n"
"            xaxis: {\n"
"                title: '',\n"
"                showticklabels: false,\n"
"            },\n"
"            yaxis: {\n"
"                title: 'Time (' + data.units + ')',\n"
"                rangemode: 'tozero',\n"
"                zeroline: true\n"
"            },\n"
"            legend: legendStyle\n"
"        };\n"
"        Plotly.newPlot(plotdiv, traces, layout);\n"
"    }\n"
"\n"
"    choosePlot();\n"
"}();\n"
" </script>\n"
" </body>\n"
"</html>\n"
            };
            static std::string const the_template = []() -> std::string {
                std::string s;
                for(auto part : template_parts) {
                    s += part;
                }
                return s;
            }();
            return the_template;
        }

        std::string description() override {
            return "outputs an HTML file with a single interactive chart of all benchmarks";
        }

        void do_configure(configuration& cfg) override {
            cfg.no_analysis = false;
            title = cfg.title;
            n_samples = cfg.samples;
            verbose = cfg.verbose;
            logarithmic = cfg.params.run && cfg.params.run->op == "*";
            run_param = cfg.params.run ? cfg.params.run->name : "";
        }

        void do_warmup_start() override {
            if(verbose) progress_stream() << "warming up\n";
        }
        void do_estimate_clock_resolution_start() override {
            if(verbose) progress_stream() << "estimating clock resolution\n";
        }
        void do_estimate_clock_cost_start() override {
            if(verbose) progress_stream() << "estimating cost of a clock call\n";
        }

        void do_params_start(parameters const& params) override {
            if(verbose) progress_stream() << "\n\nnew parameter round\n" << params;
            runs.emplace_back();
            runs.back().params = params;
        }
        void do_benchmark_start(std::string const& name) override {
            if(verbose) progress_stream() << "\nbenchmarking " << name << "\n";
            runs.back().data.push_back({name, {}, {}});
        }

        void do_measurement_start(execution_plan<fp_seconds> plan) override {
            progress_stream() << std::setprecision(7);
            progress_stream().unsetf(std::ios::floatfield);
            if(verbose) progress_stream() << "collecting " << n_samples << " samples, " << plan.iterations_per_sample << " iterations each, in estimated " << detail::pretty_duration(plan.estimated_duration) << "\n";
        }
        void do_measurement_complete(std::vector<fp_seconds> const& samples) override {
            runs.back().data.back().samples = samples;
        }
        void do_analysis_complete(sample_analysis<fp_seconds> const& analysis) override {
            runs.back().data.back().analysis = analysis;
        }
        void do_benchmark_failure(std::exception_ptr) override {
            error_stream() << runs.back().data.back().name << " failed to run successfully\n";
        }

        void do_suite_complete() override {
            if(verbose) progress_stream() << "\ngenerating HTML report\n";

            auto&& templ = template_string();
            auto magnitude = ideal_magnitude();

            cpptempl::data_map map;
            map["title"] = escape(title);
            map["units"] = detail::units_for_magnitude(magnitude);
            map["logarithmic"] = logarithmic;
            map["runparam"] = run_param;
            for (auto&& r : runs) {
                cpptempl::data_map run_item;
                cpptempl::data_list params;
                for (auto&& p : r.params) {
                    cpptempl::data_map item;
                    item["name"] = p.first;
                    item["value"] = p.second;
                    params.push_back(item);
                }
                run_item["params"] = cpptempl::make_data(params);
                for(auto&& d : r.data) {
                    cpptempl::data_map item;
                    item["name"] = escape(d.name);
                    cpptempl::data_map data;
                    if (!d.samples.empty()) {
                        data["mean"] = truncate(d.analysis.mean.point.count() * magnitude);
                        data["stddev"] = truncate(d.analysis.standard_deviation.point.count() * magnitude);
                        for(auto e : d.samples)
                            data["samples"].push_back(truncate(e.count() * magnitude));
                    }
                    item["data"] = data;
                    run_item["benchmarks"].push_back(item);
                }
                map["runs"].push_back(run_item);
            }

            cpptempl::parse(report_stream(), templ, map);
            report_stream() << std::flush;
            if(verbose) {
                progress_stream() << "\n\nresult summary ("
                                  << detail::units_for_magnitude(magnitude)
                                  << ")\n";
                for (auto&& r : runs) {
                    for (auto&& p : r.params)
                        progress_stream() << "\n  " << p.first << " = " << p.second;
                    progress_stream() << "\n";
                    for(auto&& d : r.data) {
                        progress_stream() << "  " << d.name << "\t "
                                  << truncate(d.analysis.mean.point.count() * magnitude) << "\t "
                                  << truncate(d.analysis.standard_deviation.point.count() * magnitude)
                                  << "\n";
                    }
                }
                progress_stream() << "\ndone\n";
                progress_stream() << std::flush;
            }
        }

        static double truncate(double x) {
            return std::trunc(x * 1000.) / 1000.;
        }

        double ideal_magnitude() const {
            std::vector<fp_seconds> mins;
            mins.reserve(runs.size() * runs.front().data.size());
            for (auto&& r : runs) {
                for(auto&& d : r.data) {
                    if (d.samples.begin() != d.samples.end())
                        mins.push_back(*std::min_element(d.samples.begin(), d.samples.end()));
                }
            }
            auto min = *std::min_element(mins.begin(), mins.end());
            return detail::get_magnitude(min);
        }

        static std::string escape(std::string const& source) {
            static const std::unordered_map<char, std::string> escapes {
                { '\'', "&apos;" },
                { '"',  "&quot;" },
                { '<',  "&lt;"   },
                { '>',  "&gt;"   },
                { '&',  "&amp;"  },
                { '\\',  "\\\\"  },
            };
            return detail::escape(source, escapes);
        }

        struct result_t {
            std::string name;
            std::vector<fp_seconds> samples;
            sample_analysis<fp_seconds> analysis;
        };

        struct run_t {
            parameters params;
            std::vector<result_t> data;
        };

        int n_samples;
        bool verbose;
        std::string title;
        bool logarithmic;
        std::string run_param;
        std::vector<run_t> runs;
    };

    NONIUS_REPORTER("html", html_reporter);
} // namespace nonius

#endif // NONIUS_DISABLE_HTML_REPORTER
#endif // NONIUS_DISABLE_EXTRA_REPORTERS

#endif // NONIUS_HPP
// #included from: main.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Executable building kit

#define NONIUS_MAIN_HPP

// #included from: detail/argparse.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// Command-line argument parsing

#define NONIUS_ARGPARSE_HPP

// #included from: detail/mismatch.h++
// Nonius - C++ benchmarking tool
//
// Written in 2014- by the nonius contributors <nonius@rmf.io>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>

// mismatch algorithm

#define NONIUS_DETAIL_MISMATCH_HPP

#include <utility>

namespace nonius {
    namespace detail {
        template <typename InputIt1, typename InputIt2, typename BinaryPredicate>
        std::pair<InputIt1, InputIt2> mismatch(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, BinaryPredicate p) {
            while(first1 != last1 && first2 != last2 && p(*first1, *first2)) {
                ++first1, ++first2;
            }
            return std::make_pair(first1, first2);
        }
    } // namespace detail
} // namespace nonius

#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <ostream>
#include <iomanip>
#include <tuple>
#include <functional>

namespace nonius {
    namespace detail {
        struct option {
            bool matches_short(std::string const& s) const {
                return s == ("-" + short_form);
            }
            std::tuple<bool, std::string::const_iterator> long_separator(std::string const& s) const {
                auto l = "--" + long_form;
                auto its = detail::mismatch(s.begin(), s.end(), l.begin(), l.end(), [](char a, char b) { return a == b; });
                return std::make_tuple(its.second == l.end(), its.first);
            }
            bool matches_long(std::string const& s) const {
                return std::get<0>(long_separator(s));
            }
            bool matches_long(std::string const& s, std::string& argument) const {
                bool match; std::string::const_iterator it;
                std::tie(match, it) = long_separator(s);
                if(match && it != s.end()) {
                    if(*it == '=') argument.assign(it+1, s.end());
                    else return false;
                }
                return match;
            }

            option(std::string long_form, std::string short_form, std::string description, std::string argument = std::string(), bool multiple = false)
            : long_form(std::move(long_form)), short_form(std::move(short_form)), description(std::move(description)), argument(std::move(argument)), multiple(multiple) {}

            std::string long_form;
            std::string short_form;
            std::string description;
            std::string argument;
            bool multiple;
        };

        using option_set = std::vector<option>;

        struct help_text {
            help_text(std::string name, option_set const& options) : name(std::move(name)), options(options) {}
            std::string name;
            option_set const& options;
        };

        template <typename Iterator, typename Projection>
        int get_max_width(Iterator first, Iterator last, Projection proj) {
            auto it = std::max_element(first, last, [&proj](option const& a, option const& b) { return proj(a) < proj(b); });
            return static_cast<int>(proj(*it));
        }

        inline std::ostream& operator<<(std::ostream& os, help_text h) {
            os << "Usage: " << h.name << " [OPTIONS]\n\n";

            auto lwidth = 2 + get_max_width(h.options.begin(), h.options.end(), [](option const& o) { return 2 + o.long_form.size() + 1 + o.argument.size(); });
            auto swidth = 2 + get_max_width(h.options.begin(), h.options.end(), [](option const& o) { return 1 + o.short_form.size() + 1 + o.argument.size(); });

            os << std::left;
            for(auto o : h.options) {
                auto l = "--" + o.long_form;
                auto s = "-" + o.short_form;
                if(!o.argument.empty()) {
                    l += "=" + o.argument;
                    s += " " + o.argument;
                }
                os << std::setw(lwidth) << l
                   << std::setw(swidth) << s
                   << o.description
                   << '\n';
            }
            return os;
        }

        using arguments = std::unordered_multimap<std::string, std::string>;

        struct argument_error {
            virtual ~argument_error() = default;
        };

        template <typename Iterator>
        void parse_short(option const& o, arguments& args, Iterator& first, Iterator last) {
            if(!o.argument.empty()) {
                if(++first != last) {
                    args.emplace(o.long_form, *first);
                } else {
                    throw argument_error();
                }
            } else {
                args.emplace(o.long_form, "");
            }
        }
        inline void parse_long(option const& o, arguments& args, std::string&& arg) {
            args.emplace(o.long_form, std::move(arg));
        }

        template <typename Iterator>
        arguments parse_arguments(option_set const& options, Iterator first, Iterator last) {
            arguments args;
            for(; first != last; ++first) {
                bool parsed = false;
                for(auto&& option : options) {
                    if(option.matches_short(*first)) {
                        parse_short(option, args, first, last);
                        parsed = true;
                    } else {
                        std::string arg;
                        if(option.matches_long(*first, arg)) {
                            parse_long(option, args, std::move(arg));
                            parsed = true;
                        }
                    }
                }
                if(!parsed) {
                    throw argument_error();
                }
            }
            return args;
        }
    } // namespace detail
} // namespace nonius

#include <boost/algorithm/string.hpp>

#include <vector>
#include <string>
#include <stdexcept>
#include <exception>
#include <iostream>
#include <iomanip>
#include <utility>

namespace nonius {
    namespace detail {
        template <typename T>
        struct parser;
        template <>
        struct parser<int> {
            static int parse(std::string const& s) { return std::stoi(s); }
        };
        template <>
        struct parser<double> {
            static double parse(std::string const& s) { return std::stod(s); }
        };
        template <>
        struct parser<std::string> {
            static std::string parse(std::string const& s) { return s; }
        };
        template <>
        struct parser<bool> {
            static bool parse(std::string const&) { return true; }
        };
        template <>
        struct parser<param_configuration> {
            static param_configuration parse(std::string const& param) {
                auto v = std::vector<std::string>{};
                boost::split(v, param, boost::is_any_of(":"));
                try {
                    if (v.size() > 0) {
                        auto name = v[0];
                        auto def  = global_param_registry().defaults().at(name);
                        if (v.size() == 2)
                            return {{{name, def.parse(v[1])}}, {}};
                        else if (v.size() == 5) {
                            auto oper  = v[1];
                            auto init  = def.parse(v[2]);
                            auto step  = def.parse(v[3]);
                            auto count = boost::lexical_cast<std::size_t>(v[4]);
                            return {{}, run_configuration{name, oper, init, step, count}};
                        }
                    }
                }
                catch (boost::bad_lexical_cast const&) {}
                catch (std::out_of_range const&) {}
                return {};
            }
        };
        struct assign_fn {
            template <typename T, typename U>
            void operator() (T& dest, U&& src) const { dest = std::forward<U>(src); }
        };
        template <typename T, typename Predicate, typename Assignment=assign_fn>
        void parse(T& variable, detail::arguments& args, std::string const& option, Predicate&& is_valid, Assignment&& assign={}) {
            auto rng = args.equal_range(option);
            for (auto it = rng.first; it != rng.second; ++it) {
                if(it != args.end()) {
                    auto value = parser<T>::parse(it->second);
                    if(is_valid(value)) {
                        std::forward<Assignment>(assign) (variable, std::move(value));
                    } else {
                        throw argument_error();
                    }
                }
            }
        }
        template <typename T>
        void parse(T& variable, detail::arguments& args, std::string const& option) {
            return parse(variable, args, option, [](T const&) { return true; });
        }

        inline detail::option_set const& command_line_options() {
            static detail::option_set the_options {
                detail::option("help", "h", "show this help message"),
                detail::option("samples", "s", "number of samples to collect (default: 100)", "SAMPLES"),
                detail::option("resamples", "rs", "number of resamples for the bootstrap (default: 100000)", "RESAMPLES"),
                detail::option("confidence-interval", "ci", "confidence interval for the bootstrap (between 0 and 1, default: 0.95)", "INTERVAL"),
                detail::option("param", "p", "set a benchmark parameter", "PARAM"),
                detail::option("output", "o", "output file (default: <stdout>)", "FILE"),
                detail::option("reporter", "r", "reporter to use (default: standard)", "REPORTER"),
                detail::option("title", "t", "set report title", "TITLE"),
                detail::option("no-analysis", "A", "perform only measurements; do not perform any analysis"),
                detail::option("filter", "f", "only run benchmarks whose name matches the regular expression pattern", "PATTERN"),
                detail::option("list", "l", "list benchmarks"),
                detail::option("list-params", "lp", "list available parameters"),
                detail::option("list-reporters", "lr", "list available reporters"),
                detail::option("verbose", "v", "show verbose output (mutually exclusive with -q)"),
                detail::option("summary", "q", "show summary output (mutually exclusive with -v)")
            };
            return the_options;
        }

        template <typename Iterator>
        configuration parse_args(std::string const& name, Iterator first, Iterator last) {
            try {
                auto args = detail::parse_arguments(command_line_options(), first, last);

                configuration cfg;

                auto is_positive = [](int x) { return x > 0; };
                auto is_ci = [](double x) { return x > 0 && x < 1; };
                auto is_reporter = [](std::string const x) { return global_reporter_registry().count(x) > 0; };
                auto is_param = [](param_configuration const& x) {
                    return !x.map.empty() || x.run;
                };
                auto merge_params = [](param_configuration& x, param_configuration&& y) {
                    x.map = std::move(x.map).merged(std::move(y.map));
                    if (y.run) x.run = y.run;
                };

                parse(cfg.help, args, "help");
                parse(cfg.samples, args, "samples", is_positive);
                parse(cfg.resamples, args, "resamples", is_positive);
                parse(cfg.confidence_interval, args, "confidence-interval", is_ci);
                parse(cfg.params, args, "param", is_param, merge_params);
                parse(cfg.output_file, args, "output");
                parse(cfg.reporter, args, "reporter", is_reporter);
                parse(cfg.no_analysis, args, "no-analysis");
                parse(cfg.filter_pattern, args, "filter");
                parse(cfg.list_benchmarks, args, "list");
                parse(cfg.list_params, args, "list-params");
                parse(cfg.list_reporters, args, "list-reporters");
                parse(cfg.verbose, args, "verbose");
                parse(cfg.summary, args, "summary");
                parse(cfg.title, args, "title");
                if(cfg.verbose && cfg.summary) throw argument_error();

                return cfg;
            } catch(...) {
                std::cout << help_text(name, command_line_options());
                throw argument_error();
            }
        }
    } // namespace detail

    inline int print_help(std::string const& name) {
        std::cout << detail::help_text(name, detail::command_line_options());
        return 0;
    }
    inline int list_benchmarks() {
        std::cout << "All available benchmarks:\n";
        for(auto&& b : global_benchmark_registry()) {
            std::cout << "  " << b.name << "\n";
        }
        std::cout << global_benchmark_registry().size() << " benchmarks\n\n";
        return 0;
    }
    inline int list_params() {
        std::cout << "Available parameters (= default):\n"
                  << global_param_registry().defaults();
        return 0;
    }
    inline int list_reporters() {
        using reporter_entry_ref = decltype(*global_reporter_registry().begin());
        auto cmp = [](reporter_entry_ref a, reporter_entry_ref b) { return a.first.size() < b.first.size(); };
        auto width = 2 + std::max_element(global_reporter_registry().begin(), global_reporter_registry().end(), cmp)->first.size();

        std::cout << "Available reporters:\n";
        std::cout << std::left;
        for(auto&& r : global_reporter_registry()) {
            if(!r.first.empty()) {
                std::cout << "  " << std::setw(width) << r.first << r.second->description() << "\n";
            }
        }
        std::cout << '\n';
        return 0;
    }
    inline int run_it(configuration cfg) {
        try {
            nonius::go(cfg);
        } catch(...) {
            std::cerr << "PANIC: clock is on fire\n";
            try {
                throw;
            } catch(std::exception const& e) {
                std::cerr << "  " << e.what() << "\n";
            } catch(...) {}
            return 23;
        }
        return 0;
    }

    template <typename Iterator>
    int main(std::string const& name, Iterator first, Iterator last) {
        configuration cfg;

        try {
            cfg = detail::parse_args(name, first, last);
        } catch(detail::argument_error const&) {
            return 17;
        }

        if(cfg.help) return print_help(name);
        else if(cfg.list_benchmarks) return list_benchmarks();
        else if(cfg.list_params) return list_params();
        else if(cfg.list_reporters) return list_reporters();
        else return run_it(cfg);
    }
    inline int main(int argc, char** argv) {
        std::string name(argv[0]);
        std::vector<std::string> args(argv+1, argv+argc);
        return main(name, args.begin(), args.end());
    }
}

#ifdef NONIUS_RUNNER
int main(int argc, char** argv) {
    return nonius::main(argc, argv);
}
#endif // NONIUS_RUNNER

#endif // NONIUS_SINGLE_INCLUDE_HPP
