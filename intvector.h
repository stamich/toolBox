#ifndef TOOLBOX_INTVECTOR_H
#define TOOLBOX_INTVECTOR_H

template <int... Ints>
struct intVector {
    using type = intVector<Ints...>;
    static constexpr int length = sizeof...(Ints);
};

// Two empty intVectors are equal
constexpr bool intVectorEqual(intVector<>, intVector<>){
    return true;
}

// Two non-empty intVectors are equal if the first ints are equal
// and the tail recursively compares as equal
template <int Int1, int... Ints1, int Int2, int... Ints2>
constexpr bool intVectorEqual(intVector<Int1, Ints1...>, intVector<Int2, Ints2...>){
    static_assert(sizeof...(Ints1) == sizeof...(Ints2), "vector lengths must be equal");
    return (Int1 == Int2) && intVectorEqual(intVector<Ints1...>(), intVector<Ints2...>());
}

// Prepends an int to the beginning of an intVector
template <int, typename>
struct intVectorPrepend;

template <int Int, int... Ints>
struct intVectorPrepend<Int, intVector<Ints...>>{
    using type = intVector<Int, Ints...>;
};

// Produces a new intVector that is the pointwise sum of two intVectors
template <typename...>
struct intVectorAdd;

template <>
struct intVectorAdd<intVector<>, intVector<>>{
    using type = intVector<>;
};

template <int Int1, int... Ints1, int Int2, int... Ints2>
struct intVectorAdd<intVector<Int1, Ints1...>, intVector<Int2, Ints2...>>{
    static_assert(sizeof...(Ints1) == sizeof...(Ints2), "vector lengths must be equal");
    using type = typename intVectorPrepend<
            Int1 + Int2,
            typename intVectorAdd<intVector<Ints1...>, intVector<Ints2...>>::type
    >::type;
};

// Produces a new intVector that is the pointwise difference between two intVectors
template <typename...>
struct intVectorSubtract;

template <>
struct intVectorSubtract<intVector<>, intVector<>>{
    using type = intVector<>;
};

template <int Int1, int... Ints1, int Int2, int... Ints2>
struct intVectorSubtract<intVector<Int1, Ints1...>, intVector<Int2, Ints2...>>{
    static_assert(sizeof...(Ints1) == sizeof...(Ints2), "vector lengths must be equal");
    using type = typename intVectorPrepend<
            Int1 - Int2,
            typename intVectorSubtract<intVector<Ints1...>, intVector<Ints2...>>::type
    >::type;
};

void intVectorTests(){
    static_assert(intVectorEqual(intVector<>(), intVector<>()), "");
    static_assert(intVectorEqual(intVector<1, 2>(), intVector<1, 2>()), "");

    using v = intVector<1, 2, 3>;
    using u = intVector<0, -1, 2>;
    using sum = typename intVectorAdd<u, v>::type;
    using diff = typename intVectorSubtract<u, v>::type;
    static_assert(intVectorEqual(sum(), intVector<1, 1, 5>()), "");
    static_assert(intVectorEqual(diff(), intVector<-1, -3, -1>()), "");
}

#endif //TOOLBOX_INTVECTOR_H
