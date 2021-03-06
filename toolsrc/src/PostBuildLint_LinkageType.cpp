#include "pch.h"
#include "PostBuildLint_LinkageType.h"
#include "vcpkg_Enums.h"

namespace vcpkg::PostBuildLint::LinkageType
{
    static const std::string NULLVALUE_STRING = Enums::nullvalue_toString(ENUM_NAME);

    static const std::string NAME_DYNAMIC = "dynamic";
    static const std::string NAME_STATIC = "static";

    const std::string& type::toString() const
    {
        switch (this->backing_enum)
        {
        case LinkageType::DYNAMIC:
            return NAME_DYNAMIC;
        case LinkageType::STATIC:
            return NAME_STATIC;
        case LinkageType::NULLVALUE:
            return NULLVALUE_STRING;
        default:
            Enums::unreachable(ENUM_NAME);
        }
    }

    type value_of(const std::string& as_string)
    {
        if (as_string == NAME_DYNAMIC)
        {
            return LinkageType::DYNAMIC;
        }

        if (as_string == NAME_STATIC)
        {
            return LinkageType::STATIC;
        }

        return LinkageType::NULLVALUE;
    }
}
