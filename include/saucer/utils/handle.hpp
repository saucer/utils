#pragma once

namespace saucer::utils
{
    template <typename T, auto Release, T Empty = {}>
    class handle
    {
        T m_handle;

      public:
        handle();

      public:
        handle(T);
        handle(handle &&) noexcept;

      public:
        ~handle();

      public:
        handle &operator=(handle &&) noexcept;

      public:
        [[nodiscard]] const T &get() const;

      public:
        T &reset(T = Empty);
    };
} // namespace saucer::utils

#include "handle.inl"
