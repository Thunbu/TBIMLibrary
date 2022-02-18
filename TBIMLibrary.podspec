#
# Be sure to run `pod lib lint TBIMLibrary.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'TBIMLibrary'
  s.version = '1.0.8'
  s.summary          = 'TBIMLibrary is easy to use'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TBIMLibrary is easy to use !
                       DESC

  s.homepage         = 'https://github.com/Thunbu/TBIMLibrary.git'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Sunshine218' => '215206318@qq.com' }
  s.source           = { :git => 'https://github.com/Thunbu/TBIMLibrary.git', :tag => "#{s.version}" }

  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '9.0'
 
  s.source_files = 'TBIMLibrary/Classes/TBIM.framework/Headers/**/*','TBIMLibrary/Classes/TBIM.framework/TBIM'
  s.ios.vendored_frameworks = 'TBIMLibrary/Classes/TBIM.framework'
  s.xcconfig = { 'HEADER_SEARCH_PATHS' => '"${PODS_ROOT}/TBIMLibrary/TBIMLibrary/Classes/TBIM.framework/Headers"' }
  
  # s.resource_bundles = {
  #   'TBIMLibrary' => ['TBIMLibrary/Assets/*.png']
  # }

  s.public_header_files = 'TBIMLibrary/Classes/TBIM.framework/Headers/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  s.dependency 'AFNetworking'
  s.dependency 'YYModel'
  s.dependency 'SocketRocket'
  s.dependency 'RealReachability', '~> 1.3.0'
  s.dependency 'AliyunOSSiOS', '~> 2.10.7'
end
