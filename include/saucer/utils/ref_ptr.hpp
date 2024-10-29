#pragma once

namespace saucer::utils
{
    template <typename T, auto Ref, auto Unref>
    class ref_ptr
    {
        T *m_ptr;

      private:
        template <auto Action>
        static T *perform(T *);

      public:
        ref_ptr();

      public:
        ref_ptr(T *);
        ref_ptr(const ref_ptr &);
        ref_ptr(ref_ptr &&) noexcept;

      public:
        ~ref_ptr();

      public:
        ref_ptr &operator=(const ref_ptr &);
        ref_ptr &operator=(ref_ptr &&) noexcept;

      public:
        [[nodiscard]] T *get() const;
        [[nodiscard]] explicit operator bool() const;

      public:
        void reset(T * = nullptr);

      public:
        static ref_ptr ref(T *);
    };
} // namespace saucer::utils

#include "ref_ptr.inl"
