#pragma once

// To help setting up window width
// 456789a123456789b123456789c123456789d123456789e123456789f123456789g123456789h

#define CONCAT_IMP(m1, m2) m1 ## m2
#define CONCAT(m1, m2) CONCAT_IMP(m1, m2)

#define CONST __attribute__ ((const))
#define PURE __attribute__ ((pure))

#define UNUSED(expr) do { (void)(expr); } while (0)

/*
#ifdef __cplusplus
#define CAST(m_type, m_expr) static_cast<m_type>(m_expr)
#else
#define CAST(m_type, m_expr) (m_type)( m_expr )
#endif

#ifdef __cplusplus
#define PREFIX(prefix, root) root
#else
#define PREFIX(prefix, root) CONCAT(prefix, root)
#endif
*/