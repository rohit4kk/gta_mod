#pragma once
#include "interface/ifeature.hpp"

/*
    VehPaintMgr Class 
    Handles neon, textures for vehicle
*/
class VehCustmzrMgr : public IFeature<VehCustmzrMgr>
{
private:
    ResourceStore m_TuneData { "components", eResourceType::TYPE_IMAGE_TEXT, ImVec2(100, 80) };
    ResourceStore m_CustomizeData { "customizations", eResourceType::TYPE_TEXT };
    std::vector<std::vector<float>> m_ColorData;    // vehicle color data from carcols.dat
    std::map<int, std::string> m_VehicleIDE;
    char m_nLabel[32] {"Untitled"};

    struct
    {
        float m_fColorPicker[3] { 0, 0, 0 };
        bool m_bRainbowEffect;
        unsigned int m_nRainbowTimer;
        bool m_bApplyOnTraffic;
        unsigned int m_nTrafficTimer;
    } m_Neon;

    friend class IFeature;
    VehCustmzrMgr();
    VehCustmzrMgr(const VehCustmzrMgr&);

    // Add/ Remove vehicle mod
    void AddComponent(const std::string& component, bool displayMessage = true);
    void RemoveComponent(const std::string& component, bool displayMessage = true);

    // customization
    void ApplyCustomizations(std::string& cat, std::string& key, std::string& val);
    void SaveCustomizations();

public:
    struct
    {
        bool m_bEnabled;
        bool m_bCompAdded;
    } m_Nitro;
    
    // Draw color, neon & texture tabs
    void Draw();
};

extern VehCustmzrMgr& VehCustmzr;