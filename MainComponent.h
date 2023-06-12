#pragma once

#include <JuceHeader.h>
#include <juce_audio_plugin_client/juce_audio_plugin_client_VST3.cpp>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component, public juce::Button::Listener, public juce::AudioProcessorListener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void buttonClicked(juce::Button* button) override;
    void initialiseVST3Hosting(File& vst3File);
    void loadVST3Plugin();
    void openPluginEditor();


private:
    //==============================================================================
    // Your private member variables go here...
    juce::TextButton loadButton;
    std::unique_ptr<juce::FileChooser> chooser;
    AudioPluginFormatManager formatManager;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};


