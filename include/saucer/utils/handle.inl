#pragma once

#include "handle.hpp"

#include <utility>

namespace saucer::utils
{
    template <typename T, auto Release, T Empty>
    handle<T, Release, Empty>::handle() : m_handle(Empty)
    {
    }

    template <typename T, auto Release, T Empty>
    handle<T, Release, Empty>::handle(T handle) : m_handle(std::move(handle))
    {
    }

    template <typename T, auto Release, T Empty>
    handle<T, Release, Empty>::handle(handle &&other) noexcept : m_handle(std::exchange(other.m_handle, Empty))
    {
    }

    template <typename T, auto Release, T Empty>
    handle<T, Release, Empty>::~handle()
    {
        reset();
    }

    template <typename T, auto Release, T Empty>
    handle<T, Release, Empty> &handle<T, Release, Empty>::operator=(handle &&other) noexcept
    {
        if (this != &other)
        {
            reset(std::exchange(other.m_handle, Empty));
        }

        return *this;
    }

    template <typename T, auto Release, T Empty>
    const T &handle<T, Release, Empty>::get() const
    {
        return m_handle;
    }

    template <typename T, auto Release, T Empty>
    T &handle<T, Release, Empty>::reset(T other)
    {
        if (m_handle != Empty)
        {
            Release(m_handle);
        }

        m_handle = std::move(other);

        return m_handle;
    }
} // namespace saucer::utils
