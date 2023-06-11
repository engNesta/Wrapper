#pragma once

#include <JuceHeader.h>
#include <juce_audio_plugin_client/juce_audio_plugin_client_VST3.cpp>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component, public juce::Button::Listener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void buttonClicked(juce::Button* button) override;
    void initialiseVST3Hosting();
    void loadVST3Plugin();


private:
    //==============================================================================
    // Your private member variables go here...
    juce::TextButton loadButton;
    std::unique_ptr<juce::FileChooser> chooser;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};


