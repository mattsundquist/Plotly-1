pkgname <- "plotly"
source(file.path(R.home("share"), "R", "examples-header.R"))
options(warn = 1)
library('plotly')

base::assign(".oldSearch", base::search(), pos = 'CheckExEnv')
cleanEx()
nameEx("plotly-package")
### * plotly-package

flush(stderr()); flush(stdout())

### Name: plotly-package
### Title: A R API for plot.ly
### Aliases: plotly-package
### Keywords: package

### ** Examples

# Up-to-date documentation and examples at https://plot.ly/API
# These examples may not be up-to-date




cleanEx()
nameEx("plotly")
### * plotly

flush(stderr()); flush(stdout())

### Name: plotly
### Title: main interface to plotly
### Aliases: plotly

### ** Examples

## View https://plot.ly/API for more examples
## Generate a simple plot 
# username <- "anna.lyst" # fill in with your plotly username
# api_key <- "y37zkd" # fill in with your plotly API key
# py <- plotly(username, api_key)
## generate some data
# x <- c(0,1,2)
# y <- c(10,11,12)
## send data to Plotly. Plotly will render an interactive graph and will return a URL where you can view your plot
# response <- py$plot(x,y) # sends data to Plotly, Plotly renders an interactive graph, and returns a URL where you can view your plot
# url = response$url # view your plot at this URL



cleanEx()
nameEx("signup")
### * signup

flush(stderr()); flush(stdout())

### Name: signup
### Title: Sign up to plotly
### Aliases: signup

### ** Examples

# See up-to-date documentation and examples at https://plot.ly/API
# username <- 'anna.lyst'
# email <- 'anna.lyst@plot.ly'
# response <- signup(username, email)
# response$api_key # key to access plotly with
# response$tmp_pw # temporary password to access your plotly account



### * <FOOTER>
###
options(digits = 7L)
base::cat("Time elapsed: ", proc.time() - base::get("ptime", pos = 'CheckExEnv'),"\n")
grDevices::dev.off()
###
### Local variables: ***
### mode: outline-minor ***
### outline-regexp: "\\(> \\)?### [*]+" ***
### End: ***
quit('no')
