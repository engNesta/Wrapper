#include "MainComponent.h"
//include vst3 headers
#include <juce_audio_plugin_client/juce_audio_plugin_client_VST3.cpp>

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);
    loadButton.setButtonText("Load VST3");
    loadButton.addListener(this);
    addAndMakeVisible(loadButton);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setFont (juce::Font (16.0f));
    g.setColour (juce::Colours::white);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    loadButton.setBounds(getLocalBounds().reduced(20));
}

void MainComponent::initialiseVST3Hosting() {
    //

}

void MainComponent::loadVST3Plugin() {
    chooser = std::make_unique<juce::FileChooser>("Select a VST3 plugin to load",
                                                  juce::File::getSpecialLocation(juce::File::userHomeDirectory),
                                                  "*.vst3");

    auto fileFlags = juce::FileBrowserComponent::canSelectFiles | juce::FileBrowserComponent::openMode;


    chooser ->launchAsync(fileFlags, [this] (const FileChooser& chooser)
    {
        File vst3File = chooser.getResult();

        if(vst3File.hasFileExtension(".vst3"))
        {
            loadButton.setButtonText("Correct File");
        }
        else
        {
            loadButton.setButtonText("Incorrect File");
        }


    });


}

void MainComponent::buttonClicked(juce::Button *button) {
    if (button == &loadButton) {

        button->setButtonText("Loading...");

        loadVST3Plugin();
    }
}