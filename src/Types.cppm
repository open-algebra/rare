module;

#include <string>

#include <SDL3/SDL_error.h>
#include <boost/leaf.hpp>

export module RARE.Types;

namespace rare {

export template <typename T>
using Result = boost::leaf::result<T>;

using Error = boost::leaf::error_id;

export template <typename... Args>
auto NewError(Args&&... args) -> Error
{
    return boost::leaf::new_error(std::forward<Args>(args)...);
}

export template <typename T, auto CreateFunc, auto DestroyFunc>
class RAII_Wrapper {
public:
    template <typename... Args>
    static auto Create(Args... args) -> Result<RAII_Wrapper>
    {
        T* underlying = CreateFunc(std::forward<Args>(args)...);
        if (not underlying)
            return NewError<std::string>(SDL_GetError());

        return RAII_Wrapper { underlying };
    }

    RAII_Wrapper(const RAII_Wrapper& other) = delete;

    RAII_Wrapper(RAII_Wrapper&& other) noexcept
        : m_underlying(other.m_underlying)
    {
        other.m_underlying = nullptr;
    }

    auto operator=(const RAII_Wrapper& other) -> RAII_Wrapper& = delete;

    auto operator=(RAII_Wrapper&& other) noexcept -> RAII_Wrapper&
    {
        if (this == &other)
            return *this;
        m_underlying = other.m_underlying;
        other.m_underlying = nullptr;
        return *this;
    }

    [[nodiscard]] auto GetUnderlying() const -> T*
    {
        return m_underlying;
    }

    ~RAII_Wrapper()
    {
        if (m_underlying)
            DestroyFunc(m_underlying);
    }

private:
    explicit RAII_Wrapper(T* underlying)
        : m_underlying { underlying }
    {
    }

    T* m_underlying;
};

}