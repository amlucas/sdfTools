#define LIST_OPERATIONS(_) \
    _(apply) \
    _(applyComplement) \
    _(interiorUnion) \
    _(interiorIntersection) \
    _(interiorSubtractToGrid) \
    _(interiorSubtractGrid)

#define GENERATE_IMPL(op)                                 \
    void CLASS_NAME::op(Grid *grid) const                 \
    {                                                     \
        common::op(this, grid);                           \
    }

#define GENERATE_DECL(op)                       \
    void op(Grid *grid) const override;


#define GENERATE_IMPL_OPERATIONS()              \
    LIST_OPERATIONS(GENERATE_IMPL)

#define GENERATE_DECL_OPERATIONS()              \
    LIST_OPERATIONS(GENERATE_DECL)
