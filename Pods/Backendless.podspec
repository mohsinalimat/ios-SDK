Pod::Spec.new do |s|
  s.name         = 'Backendless'
  s.version      = '4.0.6'
  s.summary      = 'Backendless provides an instant backend to help developers build better apps faster.'
  s.description  = 'Backendless is a development and a run-time platform. It helps software developers to create \nmobile and desktop applications while removing the need for server-side coding. The platform \nconsists of six core backend services which developers typically spend time implementing for \neach new applications. These services include:\n\n\tUser Service – facilitates user registrations, login, logout, session management.\n\tData Service – is responsible for data management – storage, retrieval, updates and deletion.\n\tMessaging Service – handles message publishing, broadcast, filtered message delivery and native mobile push notifications.\n\tFiles Service – is responsible for file uploads, downloads and file sharing.\n\tGeo-Location Service – supports geo spatial data imports and geo queries.\n\n\tThe Backendless services can be accessed through an easy-to-use APIs which we packaged into our \n\tSDKs. The behavior of the services and the business logic behind them can be customized through \n\tthe Development Console.'
  s.homepage    = 'http://backendless.com'
  s.license	 = { :type => 'Apache', :text => 'Copyright (c) 2012-2017 by Backendless.com' }
  s.author      = { 'Mark Piller' => 'mark@backendless.com' }

  s.platform       = :ios, '8.0'
  s.requires_arc   = true
  s.source         = { 
	:git => 'https://github.com/Backendless/ios-SDK.git',
	:tag => '4.0.6'
  }

  s.preserve_paths = 'SDK/ios/**/*.a'
  s.source_files = 'SDK/ios/**/*.h'

  s.frameworks     = 'CFNetwork', 'CoreLocation', 'Foundation', 'MapKit', 'Security', 'SystemConfiguration', 'SafariServices'
  s.libraries 	   = 'backendless'
  s.xcconfig       =  { 'LIBRARY_SEARCH_PATHS' => '"$(SRCROOT)/Pods/Backendless/SDK/ios/backendless"' }

  s.prepare_command = <<-CMD

    pushd SDK/ios/backendless/
	  ln -s backendless.a libbackendless.a

	popd	
    CMD
end
