
Pod::Spec.new do |s|
  s.name         = "react-native-yeefx"
  s.version      = "1.0.0"
  s.summary      = "react-native-yeefx"
  s.description  = <<-DESC
                  react-native-yeefx
                   DESC
  s.homepage     = ""
  s.license      = "MIT"
  # s.license      = { :type => "MIT", :file => "FILE_LICENSE" }
  s.author             = { "author" => "author@domain.cn" }
  s.platform     = :ios, "7.0"
  s.source       = { :git => "https://github.com/yeefx/react-native-yeefx.git", :tag => "master" }
  s.source_files  = "react-native-yeefx/**/*.{h,m}"
  s.requires_arc = true
  s.dependency "React"

end

  